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

INCLUDE(${SALOME_MACROS_DIR}/InstallAndCompilePythonFile.cmake)
FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})

INCLUDE_DIRECTORIES(
  ${PYTHON_INCLUDE_DIRS}
  ${PTHREAD_INCLUDE_DIRS}
  ${OMNIORB_INCLUDE_DIRS}
  ${MED3_INCLUDE_DIRS}
  ${HDF5_INCLUDE_DIRS}
  ${XDR_INCLUDE_DIRS}
  ${KERNEL_ROOT_DIR}/include/salome
  ${CMAKE_CURRENT_BINARY_DIR}/../../../../idl
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../../src
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../MED
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../MEDMEM_I
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../MEDMEM
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../MEDMEM_SWIG
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../MedCorba_Swig
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../INTERP_KERNEL
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../INTERP_KERNEL/Bases
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../INTERP_KERNEL/GaussPoints
  )

SET_SOURCE_FILES_PROPERTIES(libCompo2.i PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(libCompo2.i PROPERTIES SWIG_DEFINITIONS "-shadow")

SWIG_ADD_MODULE(libCompo2 python libCompo2.i Compo2.cxx)
SWIG_LINK_LIBRARIES(libCompo2 ${PYTHON_LIBS} MEDClientcmodule)
SET_TARGET_PROPERTIES(_libCompo2 PROPERTIES COMPILE_FLAGS "${OMNIORB_DEFINITIONS} ${HDF5_DEFINITIONS} ${MED3_DEFINITIONS} ${XDR_DEFINITIONS} ${PLATFORM_DEFINITIONS}")

IF(${MACHINE} STREQUAL WINDOWS)
  SET_TARGET_PROPERTIES(_libCompo2 PROPERTIES DEBUG_OUTPUT_NAME _libCompo2_d)
ENDIF(${MACHINE} STREQUAL WINDOWS)

INSTALL(TARGETS _libCompo2 DESTINATION ${MED_salomepythondir})
INSTALL_AND_COMPILE_PYTHON_FILE(${CMAKE_CURRENT_BINARY_DIR}/libCompo2.py ${MED_salomescript_PYTHON})

FILE(GLOB libCompo2_HEADERS_HXX "${CMAKE_CURRENT_SOURCE_DIR}/*.hxx")
INSTALL(FILES ${libCompo2_HEADERS_HXX} DESTINATION ${MED_salomeinclude_HEADERS})
