/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the files COPYING and Copyright.html.  COPYING can be found at the root   *
 * of the source code distribution tree; Copyright.html can be found at the  *
 * root level of an installed copy of the electronic HDF5 document set and   *
 * is linked from the top-level documents page.  It can also be found at     *
 * http://hdfgroup.org/HDF5/doc/Copyright.html.  If you do not have          *
 * access to either file, you may request a copy from help@hdfgroup.org.     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "hdf5.h"
#include "H5private.h"
#include "h5tools.h"
#include "h5tools_utils.h"

/* Name of tool */
#define PROGRAMNAME "h5unjam"

#define TRUE 1
#define FALSE 0
#define COPY_BUF_SIZE 1024

hsize_t write_pad( int , hsize_t );
hsize_t compute_pad( hsize_t );
herr_t copy_to_file( int , int , ssize_t, ssize_t );

int do_delete = FALSE;
char *output_file = NULL;
char *input_file = NULL;
char *ub_file = NULL;

/*
 * Command-line options: The user can specify short or long-named
 * parameters. The long-named ones can be partially spelled. When
 * adding more, make sure that they don't clash with each other.
 */
static const char *s_opts = "hu:i:o:d:V";
static struct long_options l_opts[] = {
    { "help", no_arg, 'h' },
    { "hel", no_arg, 'h' },
  {"i", require_arg, 'i'},  /* input file */
  {"u", require_arg, 'u'},  /* user block file */
  {"o", require_arg, 'o'},  /* output file */
  {"delete", no_arg, 'd'},  /* delete ub */
  {"delet", no_arg, 'd'},
  {"dele", no_arg, 'd'},
  {"del", no_arg, 'd'},
  {"de", no_arg, 'd'},
    { NULL, 0, '\0' }
};

/*-------------------------------------------------------------------------
 * Function:    usage
 *
 * Purpose:     Print the usage message
 *
 * Return:      void
 *
 * Programmer:
 *
 * Modifications:
 *
 *-------------------------------------------------------------------------
 */
static void
usage(const char *prog)
{
    HDfflush(stdout);
    HDfprintf(stdout,
    "usage: %s -i <in_file.h5>  [-o <out_file.h5> ] [-u <out_user_file> | --delete]\n", prog);
    HDfprintf(stdout, "\n");
    HDfprintf(stdout,
    "Splits user file and HDF5 file into two files: user block data and HDF5 data.\n");
    HDfprintf(stdout, "\n");
    HDfprintf(stdout,
    "OPTIONS\n");
    HDfprintf(stdout,
    "  -i in_file.h5   Specifies the HDF5 as input.  If the input HDF5 file\n");
    HDfprintf(stdout,
    "                  contains no user block, exit with an error message.\n");
    HDfprintf(stdout,
    "  -o out_file.h5  Specifies output HDF5 file without a user block.\n");
    HDfprintf(stdout,
    "                  If not specified, the user block will be removed from the\n");
    HDfprintf(stdout,
    "                  input HDF5 file.\n");
    HDfprintf(stdout,
    "  -u out_user_file\n");
    HDfprintf(stdout,
    "                  Specifies the output file containing the data from the\n");
    HDfprintf(stdout,
    "                  user block.\n");
    HDfprintf(stdout,
    "                  Cannot be used with --delete option.\n");
    HDfprintf(stdout,
    "  --delete        Remove the user block from the input HDF5 file. The content\n");
    HDfprintf(stdout,
    "                  of the user block is discarded.\n");
    HDfprintf(stdout,
    "                  Cannot be used with the -u option.\n");
    HDfprintf(stdout, "\n");
    HDfprintf(stdout,
    "  -h              Prints a usage message and exits.\n");
    HDfprintf(stdout,
    "  -V              Prints the HDF5 library version and exits.\n");
    HDfprintf(stdout, "\n");
    HDfprintf(stdout,
    "  If neither --delete nor -u is specified, the user block from the input file\n");
    HDfprintf(stdout,
    "  will be displayed to stdout.\n");
    HDfprintf(stdout, "\n");
    HDfprintf(stdout,
    "Exit Status:\n");
    HDfprintf(stdout,
    "  0      Succeeded.\n");
    HDfprintf(stdout,
    "  >0    An error occurred.\n");
}

/*-------------------------------------------------------------------------
 * Function:    leave
 *
 * Purpose:     Shutdown and call exit()
 *
 * Return:      Does not return
 *
 *-------------------------------------------------------------------------
 */
static void
leave(int ret)
{
    if (ub_file)
        HDfree (ub_file);
    if (input_file)
        HDfree (input_file);
    if (output_file)
        HDfree (output_file);

    h5tools_close();

    HDexit(ret);
}

/*-------------------------------------------------------------------------
 * Function:    parse_command_line
 *
 * Purpose:     Parse the command line for the h5dumper.
 *
 * Return:      Success:
 *
 *              Failure:    Exits program with EXIT_FAILURE value.
 *
 * Programmer:
 *
 * Modifications:
 *
 *-------------------------------------------------------------------------
 */

static void
parse_command_line(int argc, const char *argv[])
{
    int opt = FALSE;

    /* parse command line options */
    while ((opt = get_option(argc, argv, s_opts, l_opts)) != EOF) {
        switch ((char) opt) {
        case 'o':
            output_file = HDstrdup (opt_arg);
            break;
        case 'i':
            input_file = HDstrdup (opt_arg);
            break;
        case 'u':
            ub_file = HDstrdup (opt_arg);
            break;
        case 'd':
            do_delete = TRUE;
            break;
        case 'h':
            usage(h5tools_getprogname());
            leave(EXIT_SUCCESS);
        case 'V':
            print_version(h5tools_getprogname());
            leave(EXIT_SUCCESS);
        case '?':
        default:
            usage(h5tools_getprogname());
            leave(EXIT_FAILURE);
        }
    }

    /* check for file name to be processed */
/*
    if (argc <= opt_ind+2) {
        error_msg("missing file name\n");
        usage(h5tools_getprogname());
        HDexit(EXIT_FAILURE);
    }
*/
}

/*-------------------------------------------------------------------------
 * Function:    main
 *
 * Purpose:     HDF5 user block unjammer
 *
 * Return:      Success:    0
 *              Failure:    1
 *
 * Programmer:
 *
 * Modifications:
 *
 *-------------------------------------------------------------------------
 */
int
main(int argc, const char *argv[])
{
    int                 ifid = -1;
    int                 ufid = -1;
    int                 h5fid = -1;
    void               *edata;
    H5E_auto2_t         func;
    hid_t               ifile = -1;
    hid_t               plist = -1;
    off_t               fsize;
    hsize_t             usize;
    htri_t              testval;
    herr_t              status;
    int                 res;
    h5_stat_t           sbuf;

    h5tools_setprogname(PROGRAMNAME);
    h5tools_setstatus(EXIT_SUCCESS);

    /* Disable error reporting */
    H5Eget_auto2(H5E_DEFAULT, &func, &edata);
    H5Eset_auto2(H5E_DEFAULT, NULL, NULL);

    /* Initialize h5tools lib */
    h5tools_init();

    parse_command_line(argc, argv);

    if (input_file == NULL) {
        /* no user block */
        error_msg("missing arguemnt for HDF5 file input.\n");
        help_ref_msg(stderr);
        leave (EXIT_FAILURE);
    }

    testval = H5Fis_hdf5(input_file);

    if (testval <= 0) {
        error_msg("Input HDF5 file \"%s\" is not HDF\n", input_file);
        help_ref_msg (stderr);
        h5tools_setstatus(EXIT_FAILURE);
        goto done;
    }

    ifile = H5Fopen(input_file, H5F_ACC_RDONLY , H5P_DEFAULT);

    if (ifile < 0) {
        error_msg("Can't open input HDF5 file \"%s\"\n", input_file);
        h5tools_setstatus(EXIT_FAILURE);
        goto done;
    }

    plist = H5Fget_create_plist(ifile);
    if (plist < 0) {
        error_msg("Can't get file creation plist for file \"%s\"\n", input_file);
        h5tools_setstatus(EXIT_FAILURE);
        goto done;
    }

    status = H5Pget_userblock(plist, & usize);
    if (status < 0) {
        error_msg("Can't get user block for file \"%s\"\n", input_file);
        h5tools_setstatus(EXIT_FAILURE);
        goto done;
    }

    H5Pclose(plist);
    H5Fclose(ifile);

    if (usize == 0) {
  /* no user block to remove: message? */
        error_msg("\"%s\" has no user block: no change to file\n", input_file);
        h5tools_setstatus(EXIT_SUCCESS);
        goto done;
    }

    ifid = HDopen(input_file,O_RDONLY,0);
    if(ifid < 0) {
        error_msg("unable to open input HDF5 file \"%s\"\n", input_file);
        h5tools_setstatus(EXIT_FAILURE);
        goto done;
    }

    res = HDfstat(ifid, &sbuf);
    if(res < 0) {
        error_msg("Can't stat file \"%s\"\n", input_file);
        h5tools_setstatus(EXIT_FAILURE);
        goto done;
    }

    fsize = sbuf.st_size;

    if (do_delete && (ub_file != NULL)) {
        error_msg("??\"%s\"\n", ub_file);
        h5tools_setstatus(EXIT_FAILURE);
        goto done;
    }

    if (ub_file == NULL) {
        /* write to sdtout */
        ufid = HDdup(1);
    } 
    else {
        ufid = HDopen(ub_file,O_WRONLY|O_CREAT|O_TRUNC, 0644 );

        if (ufid < 0) {
            error_msg("unable to open user block file for output\"%s\"\n", ub_file);
            h5tools_setstatus(EXIT_FAILURE);
            goto done;
        }
    }

    if (output_file == NULL) {
        h5fid = HDopen(input_file,O_WRONLY, 0);

        if (h5fid < 0) {
            error_msg("unable to open output HDF5 file \"%s\"\n", input_file);
            h5tools_setstatus(EXIT_FAILURE);
            goto done;
        }
    } 
    else {
        h5fid = HDopen(output_file,O_WRONLY|O_CREAT|O_TRUNC, 0644 );

        if (h5fid < 0) {
            error_msg("unable to open output HDF5 file \"%s\"\n", output_file);
            h5tools_setstatus(EXIT_FAILURE);
            goto done;
        }
    }


    /* copy from 0 to 'usize - 1' into ufid */
    if (!do_delete) {
        if(copy_to_file(ifid, ufid, 0, (ssize_t) usize) < 0) {
            error_msg("unable to copy user block to output file \"%s\"\n", ub_file);
            h5tools_setstatus(EXIT_FAILURE);
            goto done;
        }
    }

    /* copy from usize to end of file into h5fid,
     * starting at end of user block if present
     */
    if(copy_to_file(ifid, h5fid, (ssize_t) usize, (ssize_t)(fsize - (ssize_t)usize)) < 0) {
        error_msg("unable to copy hdf5 data to output file \"%s\"\n", output_file);
        h5tools_setstatus(EXIT_FAILURE);
        goto done;
    }

done:
    if (ub_file) {
        HDfree (ub_file);
        if (ufid >= 0) HDclose(ufid);
    }
    if (input_file)
        HDfree (input_file);
    if (output_file)
        HDfree (output_file);

    if (h5fid >= 0) HDclose(h5fid);
    if (ifid >= 0) HDclose(ifid);

    return h5tools_getstatus();
}

/*
 *  Copy 'how_much' bytes from the input file to the output file,
 *  starting at byte 'where' in the input file.
 *
 *  Returns 0 on success, -1 on failure.
 */
herr_t
copy_to_file( int infid, int ofid, ssize_t where, ssize_t how_much )
{
    static char buf[COPY_BUF_SIZE];
    off_t to;
    off_t from;
    ssize_t nchars = -1;
    ssize_t wnchars = -1;
    herr_t ret_value = 0;

    /* nothing to copy */
    if(how_much <= 0)
        goto done;

    from = where;
    to = 0;

    while(how_much > 0) {
        /* Seek to correct position in input file */
        HDlseek(infid,from,SEEK_SET);

        /* Read data to buffer */
        if (how_much > COPY_BUF_SIZE)
            nchars = HDread(infid,buf,(unsigned)COPY_BUF_SIZE);
        else
            nchars = HDread(infid,buf,(unsigned)how_much);
        if(nchars < 0) {
            ret_value = -1;
            goto done;
        } /* end if */

        /* Seek to correct position in output file */
        HDlseek(ofid,to,SEEK_SET);

        /* Update positions/size */
        how_much -= nchars;
        from += nchars;
        to += nchars;

        /* Write nchars bytes to output file */
        wnchars = nchars;
        while(nchars > 0) {
            wnchars = HDwrite(ofid,buf,(unsigned)nchars);
            if(wnchars < 0) {
                ret_value = -1;
                goto done;
            } /* end if */
            nchars -= wnchars;
        } /* end while */
    } /* end while */

done:
    return ret_value;
}  /* end copy_to_file */

