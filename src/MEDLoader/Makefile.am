# Copyright (C) 2007-2012  CEA/DEN, EDF R&D
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
# Author : Anthony Geay (CEA/DEN)

include $(top_srcdir)/adm_local/unix/make_common_starter.am

MEDLOADER_SUBDIRS =

if !MED_ENABLE_MICROMED
   MEDLOADER_SUBDIRS += . Swig
if CPPUNIT_IS_OK
   MEDLOADER_SUBDIRS += Test
endif
endif

SUBDIRS = $(MEDLOADER_SUBDIRS)

#DIST_SUBDIRS = Swig

lib_LTLIBRARIES = libmedloader.la

salomeinclude_HEADERS= \
MEDLoaderDefines.hxx \
MEDLoader.hxx MEDLoaderBase.hxx MEDFileUtilities.hxx MEDFileMesh.hxx MEDFileMeshLL.hxx \
MEDFileMeshElt.hxx MEDFileBasis.hxx MEDFileField.hxx MEDFileData.hxx \
SauvMedConvertor.hxx SauvReader.hxx SauvWriter.hxx SauvUtilities.hxx

dist_libmedloader_la_SOURCES= \
MEDLoader.cxx MEDLoaderBase.cxx MEDFileUtilities.cxx      \
MEDFileMesh.cxx MEDFileMeshElt.cxx MEDFileBasis.cxx       \
MEDFileMeshLL.cxx MEDFileField.cxx MEDFileData.cxx      \
SauvMedConvertor.cxx SauvReader.cxx SauvWriter.cxx

libmedloader_la_CPPFLAGS= $(MED3_INCLUDES) $(HDF5_INCLUDES) @CXXTMPDPTHFLAGS@ \
	-I$(srcdir)/../INTERP_KERNEL \
	-I$(srcdir)/../INTERP_KERNEL/Geometric2D \
	-I$(srcdir)/../INTERP_KERNEL/Bases \
	-I$(srcdir)/../MEDCoupling

libmedloader_la_LDFLAGS= ../MEDCoupling/libmedcoupling.la \
../INTERP_KERNEL/libinterpkernel.la $(MED3_LIBS_C_ONLY) $(HDF5_LIBS)
