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
  ${OMNIORB_INCLUDE_DIRS}
  ${HDF5_INCLUDE_DIRS}
  ${MED3_INCLUDE_DIRS}
  ${PTHREAD_INCLUDE_DIRS}
  ${XDR_INCLUDE_DIRS}
  ${KERNEL_ROOT_DIR}/include/salome
  ${CMAKE_CURRENT_BINARY_DIR}/../..
  ${CMAKE_CURRENT_BINARY_DIR}/../../idl
  ${CMAKE_CURRENT_SOURCE_DIR}/../MEDMEM_I
  ${CMAKE_CURRENT_SOURCE_DIR}/../MEDMEM
  ${CMAKE_CURRENT_SOURCE_DIR}/../INTERP_KERNEL
  ${CMAKE_CURRENT_SOURCE_DIR}/../INTERP_KERNEL/Bases
  ${CMAKE_CURRENT_SOURCE_DIR}/../INTERP_KERNEL/GaussPoints
)

SET(MEDEngine_SOURCES
  Med_Gen_i.cxx
  Med_Gen_Driver_i.cxx
)

SET(COMMON_FLAGS "${OMNIORB_DEFINITIONS} ${HDF5_DEFINITIONS} ${MED3_DEFINITIONS} ${XDR_DEFINITIONS} ${PLATFORM_DEFINITIONS}")
IF(WINDOWS)
  SET(COMMON_FLAGS "${COMMON_FLAGS} -DNOGDI")
ENDIF(WINDOWS
)

ADD_LIBRARY(MEDEngine SHARED ${MEDEngine_SOURCES})
SET_TARGET_PROPERTIES(MEDEngine PROPERTIES COMPILE_FLAGS "${COMMON_FLAGS}")
TARGET_LINK_LIBRARIES(MEDEngine MEDMEMImpl SalomeIDLMED ${TOOLSDS} ${SalomeHDFPersist} 
  ${SalomeContainer} ${SalomeCommunication} ${SalomeLifeCycleCORBA} ${PLATFORM_LIBS})
INSTALL(TARGETS MEDEngine DESTINATION ${MED_salomelib_LIBS})

SET(MED_MED_salomescript_DATA
  MED_test1.py MED_test2.py Med_Gen_test.py testMedAlliances.py testMedAlliances1.py
  )

FILE(GLOB MEDEngine_HEADERS_HXX "${CMAKE_CURRENT_SOURCE_DIR}/*.hxx")
INSTALL(FILES ${MEDEngine_HEADERS_HXX} DESTINATION ${MED_salomeinclude_HEADERS})
INSTALL(FILES ${MED_MED_salomescript_DATA} DESTINATION ${MED_salomescript_DATA})
