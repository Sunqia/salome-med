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

INCLUDE_DIRECTORIES(
  ${HDF5_INCLUDE_DIRS}
  ${BOOST_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/../../Base
  ${CMAKE_CURRENT_SOURCE_DIR}/../Core
  )

IF(MED_ENABLE_KERNEL)
  INCLUDE_DIRECTORIES(${KERNEL_ROOT_DIR}/include/salome)
ELSE(MED_ENABLE_KERNEL)
  INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/adm_local_without_kernel)
ENDIF(MED_ENABLE_KERNEL)  

SET(MEDWrapper_V2_1_SOURCES
  MED_V2_1_Wrapper.cxx
  )

ADD_LIBRARY(MEDWrapper_V2_1 SHARED ${MEDWrapper_V2_1_SOURCES})
SET_TARGET_PROPERTIES(MEDWrapper_V2_1 PROPERTIES COMPILE_FLAGS "-D${MACHINE} ${BOOST_DEFINITIONS} ${HDF5_DEFINITIONS} ${PLATFORM_DEFINITIONS}")
TARGET_LINK_LIBRARIES(MEDWrapper_V2_1 med_V2_1 MEDWrapperBase ${PLATFORM_LIBS})
INSTALL(TARGETS MEDWrapper_V2_1 DESTINATION ${MED_salomelib_LIBS})

FILE(GLOB med_V2_1_HEADERS_HXX "${CMAKE_CURRENT_SOURCE_DIR}/*.hxx")
INSTALL(FILES ${med_V2_1_HEADERS_HXX} DESTINATION ${MED_salomeinclude_HEADERS})
