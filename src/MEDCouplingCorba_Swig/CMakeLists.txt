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

ADD_SUBDIRECTORY(Client)

INCLUDE(${SALOME_MACROS_DIR}/InstallAndCompilePythonFile.cmake)
FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})

SET_SOURCE_FILES_PROPERTIES(MEDCouplingCorba.i PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(MEDCouplingCorba.i PROPERTIES SWIG_DEFINITIONS "-shadow")

INCLUDE_DIRECTORIES(
  ${PYTHON_INCLUDE_DIRS}
  ${OMNIORB_INCLUDE_DIRS}
  ${KERNEL_ROOT_DIR}/include/salome
  ${CMAKE_CURRENT_BINARY_DIR}/../../idl
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../MEDCouplingCorba
  ${CMAKE_CURRENT_SOURCE_DIR}/../MEDCoupling_Swig
  ${CMAKE_CURRENT_SOURCE_DIR}/../MEDCoupling
  ${CMAKE_CURRENT_SOURCE_DIR}/../INTERP_KERNEL
  ${CMAKE_CURRENT_SOURCE_DIR}/../INTERP_KERNEL/Bases
  )

SWIG_ADD_MODULE(MEDCouplingCorba python MEDCouplingCorba.i)
SWIG_LINK_LIBRARIES(MEDCouplingCorba ${PYTHON_LIBS} medcouplingcorba ${PLATFORM_LIBS})
SET_TARGET_PROPERTIES(_MEDCouplingCorba PROPERTIES COMPILE_FLAGS "${OMNIORB_DEFINITIONS} ${PLATFORM_DEFINITIONS}")
IF(${MACHINE} STREQUAL WINDOWS)
  SET_TARGET_PROPERTIES(_MEDCouplingCorba PROPERTIES DEBUG_OUTPUT_NAME _MEDCouplingCorba_d)
ENDIF(${MACHINE} STREQUAL WINDOWS)

INSTALL(TARGETS _MEDCouplingCorba DESTINATION ${MED_salomepythondir})
INSTALL(FILES MEDCouplingCorba.i MEDCouplingCorbaTypemaps.i DESTINATION ${MED_salomeinclude_HEADERS})
SET(PYFILES_TO_INSTALL ${CMAKE_CURRENT_BINARY_DIR}/MEDCouplingCorba.py)
INSTALL_AND_COMPILE_PYTHON_FILE("${PYFILES_TO_INSTALL}" ${MED_salomescript_PYTHON})
