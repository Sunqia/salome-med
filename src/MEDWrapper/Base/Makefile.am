# Copyright (C) 2007-2012  CEA/DEN, EDF R&D, OPEN CASCADE
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
#  $Header: /home/server/cvs/MED/MED_SRC/src/MEDWrapper/Base/Makefile.am,v 1.3.2.2.8.3 2012-06-05 11:55:33 vsr Exp $
#
include $(top_srcdir)/adm_local/unix/make_common_starter.am

lib_LTLIBRARIES= libMEDWrapperBase.la

salomeinclude_HEADERS= \
	MED_Common.hxx \
	MED_Vector.hxx \
	MED_SharedPtr.hxx \
	MED_SliceArray.hxx \
	MED_Wrapper.hxx \
	MED_TWrapper.hxx \
	MED_Structures.hxx \
	MED_TStructures.hxx \
	MED_Algorithm.hxx \
	MED_GaussUtils.hxx \
	MED_CoordUtils.hxx \
	MED_Utilities.hxx \
	MED_GaussDef.hxx \
	MED_WrapperBase.hxx

dist_libMEDWrapperBase_la_SOURCES= \
	MED_Structures.cxx \
	MED_Wrapper.cxx \
	MED_Algorithm.cxx \
	MED_GaussUtils.cxx \
	MED_CoordUtils.cxx \
	MED_Utilities.cxx \
	MED_GaussDef.cxx

libMEDWrapperBase_la_CPPFLAGS= $(BOOST_CPPFLAGS) $(HDF5_INCLUDES) -D@MACHINE@
if MED_ENABLE_KERNEL
  libMEDWrapperBase_la_CPPFLAGS+= -I$(KERNEL_ROOT_DIR)/include/salome
else
  libMEDWrapperBase_la_CPPFLAGS+= -I$(top_builddir)/adm_local_without_kernel/unix
endif
libMEDWrapperBase_la_CPPFLAGS+= $(MED_CPPFLAGS)
libMEDWrapperBase_la_LDFLAGS= $(BOOST_LIB_THREAD) $(BOOST_LIB_DATE_TIME)
