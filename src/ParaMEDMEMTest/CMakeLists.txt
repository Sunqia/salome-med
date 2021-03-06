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
  ${MPI_INCLUDE_DIRS}
  ${CPPUNIT_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../ParaMEDLoader
  ${CMAKE_CURRENT_SOURCE_DIR}/../ParaMEDMEM
  ${CMAKE_CURRENT_SOURCE_DIR}/../MEDLoader
  ${CMAKE_CURRENT_SOURCE_DIR}/../MEDCoupling
  ${CMAKE_CURRENT_SOURCE_DIR}/../INTERP_KERNEL
  ${CMAKE_CURRENT_SOURCE_DIR}/../INTERP_KERNEL/Bases
  )

SET(ParaMEDMEMTest_SOURCES
  ParaMEDMEMTest.cxx
  ParaMEDMEMTest_MPIProcessorGroup.cxx
  ParaMEDMEMTest_BlockTopology.cxx
  ParaMEDMEMTest_InterpKernelDEC.cxx
  ParaMEDMEMTest_StructuredCoincidentDEC.cxx
  ParaMEDMEMTest_MEDLoader.cxx
  ParaMEDMEMTest_ICocoTrio.cxx
  ParaMEDMEMTest_Gauthier1.cxx
  ParaMEDMEMTest_FabienAPI.cxx
  ParaMEDMEMTest_NonCoincidentDEC.cxx
  ParaMEDMEMTest_OverlapDEC.cxx
  MPIAccessDECTest.cxx
  test_AllToAllDEC.cxx
  test_AllToAllvDEC.cxx
  test_AllToAllTimeDEC.cxx
  test_AllToAllvTimeDEC.cxx
  test_AllToAllvTimeDoubleDEC.cxx
  MPIAccessTest.cxx
  test_MPI_Access_Send_Recv.cxx
  test_MPI_Access_Cyclic_Send_Recv.cxx
  test_MPI_Access_SendRecv.cxx
  test_MPI_Access_ISend_IRecv.cxx
  test_MPI_Access_Cyclic_ISend_IRecv.cxx
  test_MPI_Access_ISendRecv.cxx
  test_MPI_Access_Probe.cxx
  test_MPI_Access_IProbe.cxx
  test_MPI_Access_Cancel.cxx
  test_MPI_Access_Send_Recv_Length.cxx
  test_MPI_Access_ISend_IRecv_Length.cxx
  test_MPI_Access_ISend_IRecv_Length_1.cxx
  test_MPI_Access_Time.cxx
  test_MPI_Access_Time_0.cxx
  test_MPI_Access_ISend_IRecv_BottleNeck.cxx
  )

ADD_LIBRARY(ParaMEDMEMTest SHARED ${ParaMEDMEMTest_SOURCES})
SET_TARGET_PROPERTIES(ParaMEDMEMTest PROPERTIES COMPILE_FLAGS "${MPI_DEFINITIONS} ${CPPUNIT_DEFINITIONS}")
TARGET_LINK_LIBRARIES(ParaMEDMEMTest paramedmem paramedloader ${CPPUNIT_LIBS})
INSTALL(TARGETS ParaMEDMEMTest DESTINATION ${MED_salomelib_LIBS})

SET(TESTSParaMEDMEM)
SET(TestParaMEDMEM_SOURCES
  TestParaMEDMEM.cxx
  )
SET(TESTSParaMEDMEM ${TESTSParaMEDMEM} TestParaMEDMEM)

SET(TestMPIAccessDEC_SOURCES
  TestMPIAccessDEC.cxx
  )
SET(TESTSParaMEDMEM ${TESTSParaMEDMEM} TestMPIAccessDEC)

SET(TestMPIAccess_SOURCES
  TestMPIAccess.cxx
  )
SET(TESTSParaMEDMEM ${TESTSParaMEDMEM} TestMPIAccess)

SET(test_perf_SOURCES
  test_perf.cxx
  )
SET(TESTSParaMEDMEM ${TESTSParaMEDMEM} test_perf)

IF(MPI2_IS_OK)
  SET(ParaMEDMEMTestMPI2_1_SOURCES
    MPI2Connector.cxx
    ParaMEDMEMTestMPI2_1.cxx
    )
  SET(TESTSParaMEDMEM ${TESTSParaMEDMEM} ParaMEDMEMTestMPI2_1)
  
  SET(ParaMEDMEMTestMPI2_2_SOURCES
    MPI2Connector.cxx
    ParaMEDMEMTestMPI2_2.cxx
    )
  SET(TESTSParaMEDMEM ${TESTSParaMEDMEM} ParaMEDMEMTestMPI2_2)
ENDIF(MPI2_IS_OK)

FOREACH(bintestparamem ${TESTSParaMEDMEM})
  ADD_EXECUTABLE(${bintestparamem} ${${bintestparamem}_SOURCES})
  SET_TARGET_PROPERTIES(${bintestparamem} PROPERTIES COMPILE_FLAGS "${MPI_FLGAS} ${CPPUNIT_DEFINITIONS}")
  TARGET_LINK_LIBRARIES(${bintestparamem} ParaMEDMEMTest)
ENDFOREACH(bintestparamem ${TESTSParaMEDMEM})

INSTALL(TARGETS ${TESTSParaMEDMEM} DESTINATION ${MED_salomebin_BINS})
SET(COMMON_HEADERS_HXX
  MPIMainTest.hxx
  MPIAccessDECTest.hxx
  MPIAccessTest.hxx
  ParaMEDMEMTest.hxx
  MPI2Connector.hxx
)
INSTALL(FILES ${COMMON_HEADERS_HXX} DESTINATION ${MED_salomeinclude_HEADERS})

					