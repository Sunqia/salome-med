/*************************************************************************
* COPYRIGHT (C) 1999 - 2002  EDF R&D
* THIS LIBRARY IS FREE SOFTWARE; YOU CAN REDISTRIBUTE IT AND/OR MODIFY
* IT UNDER THE TERMS OF THE GNU LESSER GENERAL PUBLIC LICENSE 
* AS PUBLISHED BY THE FREE SOFTWARE FOUNDATION; 
* EITHER VERSION 2.1 OF THE LICENSE, OR (AT YOUR OPTION) ANY LATER VERSION.
*  
* THIS LIBRARY IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT
* WITHOUT ANY WARRANTY; WITHOUT EVEN THE IMPLIED WARRANTY OF
* MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. SEE THE GNU
* LESSER GENERAL PUBLIC LICENSE FOR MORE DETAILS.
*
* YOU SHOULD HAVE RECEIVED A COPY OF THE GNU LESSER GENERAL PUBLIC LICENSE
* ALONG WITH THIS LIBRARY; IF NOT, WRITE TO THE FREE SOFTWARE FOUNDATION,
* INC., 59 TEMPLE PLACE, SUITE 330, BOSTON, MA 02111-1307 USA
*
*************************************************************************/


#include "med.hxx"
#include "med_outils.hxx"

#include <cstring>

/*
 * - Nom de la fonction : _MEDindiceInfo
 * - Description : en argument de H5Giterate, donne le nom
 *                 de l'objet HDF (data set ou data group)
 *                 contenu dans l'objet HDF passe en argument
 * - Parametres :
 *     - id      (IN)     : l'ID de l'objet HDF
 *     - nom     (OUT)    : le nom recupere 
 *     - donnees  (OUT)    : tampon
 * - Resultat : 1 en cas de succes, -1 sinon
 */ 

namespace med_2_1{

med_err 
_MEDindiceInfo(med_idt id, const char *nom, void *donnees)
{
  if (donnees != NULL)
    strcpy((char*)donnees,nom);
  else 
    return -1;

  return 1;
}

}
