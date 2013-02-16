#!/bin/sh
# 
# This script installs or updates a SALOME application for testing the
# XMED module. The application is installed in the
# directory ./appli. The configuration file is supposed to be adapted
# to your own environment (see config_appli.xml).
#
# To run this script, you should have first configure your
# shell with the SALOME environment, i.e. source the files
# prerequis.sh and envSalome.sh (or equivalent) that fit
# your configuration. You can alternatively customize the env.sh file
# to fit your SALOME environment and let the script do the job (see
# source below).
#
# (gboulant - 3/2/2011)
#

here=$(dirname $0)

# Finalize the configuration xml file


#
# Run the appli_gen.py
#
APPLIDIR="./appli"
/dn47/SALOME/series6xDEV/CURRENT/current06.12.2012/Mandriva2010/KERNEL/bin/salome/appli_gen.py --prefix=$APPLIDIR --config=$here/config_appli.xml

#
# Copy customized configuration files in the application
#
cp $here/SalomeApp.xml $APPLIDIR/.

# This write an executable program that run a medop text interface
# (could be usefull for most of the tests and sometimes for real
# works).
write_medop_exe() {
    echo '#!/bin/sh'
    echo 'appliroot=$(dirname $0)'
    echo 'logfile="/tmp/medop.log"'
    echo '$appliroot/runAppli -k -t 2>$logfile'
    echo 'xterm -e tail -f $logfile &'
    echo '$appliroot/runSession "python -i $appliroot/lib/python2.6/site-packages/salome/xmed/medop.py"'
}

write_medop_exe > $APPLIDIR/medop.sh
chmod +x $APPLIDIR/medop.sh
