# Copyright (C) 2007-2012  CEA/DEN, EDF R&D, OPEN CASCADE
#
# Copyright (C) 2003-2007  OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN,
# CEDRAT, EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
#

#  File   : 
#  Author : 
#  Module : 
#  $Header: /home/server/cvs/MED/MED_SRC/src/MEDWrapper/V2_1/Core/Makefile.am,v 1.3.20.7 2012-08-09 10:47:18 jfa Exp $
#
include $(top_srcdir)/adm_local/unix/make_common_starter.am

lib_LTLIBRARIES= libmed_V2_1.la

LIB_SRC_TOOLS_HDFI= \
MEDattrFermer.cxx \
MEDattrNumEcrire.cxx \
MEDattrNumLire.cxx \
MEDattrOuvrir.cxx \
MEDattrStringEcrire.cxx \
MEDattrStringLire.cxx \
MEDdatagroupCreer.cxx \
MEDdatagroupFermer.cxx \
MEDdatagroupOuvrir.cxx \
MEDdatasetFermer.cxx \
MEDdatasetNumEcrire.cxx \
MEDdatasetNumLire.cxx \
MEDdatasetOuvrir.cxx \
MEDdatasetStringEcrire.cxx \
MEDdatasetStringLire.cxx \
MEDfichierCreer.cxx \
MEDfichierFermer.cxx \
MEDfichierOuvrir.cxx \
MEDindiceInfo.cxx \
MEDindiceNum.cxx \
MEDmodeErreurVerrouiller.cxx \
MEDnObjets.cxx \
MEDobjetIdentifer.cxx 

LIB_SRC_TOOLS_MISC= \
MED1cstring.cxx             MEDnomDataset.cxx \
MED2cstring.cxx             MEDnomEntite.cxx \
MEDGeometrieElement.cxx     MEDnomGeometrie.cxx \
MEDcstringFree.cxx          MEDparametresGeometrie.cxx \
MEDfstring.cxx

LIB_SRC_API_CI= \
MEDchampCr.cxx \
MEDchampEcr.cxx \
MEDchampInfo.cxx \
MEDchampLire.cxx \
MEDconnEcr.cxx \
MEDconnLire.cxx \
MEDcoordEcr.cxx \
MEDcoordLire.cxx \
MEDdimLire.cxx \
MEDelementsEcr.cxx \
MEDelementsLire.cxx \
MEDequivCr.cxx \
MEDequivEcr.cxx \
MEDequivInfo.cxx \
MEDequivLire.cxx \
MEDfam2groA.cxx \
MEDfam2groB.cxx \
MEDfamCr.cxx \
MEDfamEcr.cxx \
MEDfamInfo.cxx \
MEDfamLire.cxx \
MEDfamMaaCr.cxx \
MEDfamMaaInfo.cxx \
MEDfamMaaLire.cxx \
MEDfermer.cxx \
MEDfichDesEcr.cxx \
MEDfichEntete.cxx \
MEDgro2famA.cxx \
MEDgro2famB.cxx \
MEDlFichDes.cxx \
MEDmaaCr.cxx \
MEDmaaInfo.cxx \
MEDnChamp.cxx \
MEDnCorres.cxx \
MEDnEntMaa.cxx \
MEDnEntites.cxx \
MEDnEquiv.cxx \
MEDnFam.cxx \
MEDnMaa.cxx \
MEDnPasdetemps.cxx \
MEDnProfil.cxx \
MEDnVal.cxx \
MEDnValProfil.cxx \
MEDnbnoisEcr.cxx \
MEDnbnoisLire.cxx \
MEDnbnomaEcr.cxx \
MEDnbnomaLire.cxx \
MEDnbnosoEcr.cxx \
MEDnbnosoLire.cxx \
MEDnoeudsEcr.cxx \
MEDnoeudsLire.cxx \
MEDnomEcr.cxx \
MEDnomLire.cxx \
MEDnumEcr.cxx \
MEDnumLire.cxx \
MEDouvrir.cxx \
MEDpasdetempsInfo.cxx \
MEDprofilEcr.cxx \
MEDprofilLire.cxx \
MEDprofilInfo.cxx \
MEDunvCr.cxx \
MEDunvLire.cxx \
MEDformatConforme.cxx \
MEDversionConforme.cxx \
MEDversionDonner.cxx \
MEDversionLire.cxx \
MEDbodyFittedEcr.cxx \
MEDbodyFittedLire.cxx \
MEDfamGridEcr.cxx \
MEDfamGridLire.cxx \
MEDgridCr.cxx \
MEDgridEcr.cxx \
MEDgridInfo.cxx \
MEDgridLire.cxx \
MEDnGrid.cxx

dist_libmed_V2_1_la_SOURCES= \
	$(LIB_SRC_TOOLS_HDFI) \
	$(LIB_SRC_TOOLS_MISC) \
	$(LIB_SRC_API_CI)

salomeinclude_HEADERS= \
	med.hxx \
	med_proto.hxx \
	hdf5_version2api.hxx

EXTRA_DIST+= med_outils.hxx \
	med_misc.hxx \
	med_hdfi.hxx \
	med_utils.hxx

libmed_V2_1_la_CPPFLAGS= -D@MACHINE@ $(HDF5_INCLUDES) $(MED_CPPFLAGS)
libmed_V2_1_la_LDFLAGS= $(HDF5_LIBS)

# Executables targets
bin_PROGRAMS= mdump_V2_1 test1_V2_1

dist_mdump_V2_1_SOURCES= mdump_V2_1.cxx
mdump_V2_1_CPPFLAGS= $(libmed_V2_1_la_CPPFLAGS)
mdump_V2_1_LDADD= $(HDF5_LIBS) libmed_V2_1.la

dist_test1_V2_1_SOURCES= test1_V2_1.cxx
test1_V2_1_CPPFLAGS= $(libmed_V2_1_la_CPPFLAGS)
test1_V2_1_LDADD= $(HDF5_LIBS) libmed_V2_1.la
