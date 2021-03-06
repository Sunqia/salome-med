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

include $(top_srcdir)/adm_local/unix/make_common_starter.am

lib_LTLIBRARIES = libParaMEDMEMTest.la

salomeinclude_HEADERS = \
	MPIMainTest.hxx \
	MPIAccessDECTest.hxx \
	MPIAccessTest.hxx \
	ParaMEDMEMTest.hxx \
	MPI2Connector.hxx	

dist_libParaMEDMEMTest_la_SOURCES = \
	ParaMEDMEMTest.cxx \
	ParaMEDMEMTest_MPIProcessorGroup.cxx \
	ParaMEDMEMTest_BlockTopology.cxx \
	ParaMEDMEMTest_InterpKernelDEC.cxx \
	ParaMEDMEMTest_StructuredCoincidentDEC.cxx \
	ParaMEDMEMTest_MEDLoader.cxx \
	ParaMEDMEMTest_ICocoTrio.cxx \
	ParaMEDMEMTest_Gauthier1.cxx \
	ParaMEDMEMTest_FabienAPI.cxx \
	ParaMEDMEMTest_NonCoincidentDEC.cxx \
	ParaMEDMEMTest_OverlapDEC.cxx \
	MPIAccessDECTest.cxx \
	test_AllToAllDEC.cxx \
	test_AllToAllvDEC.cxx \
	test_AllToAllTimeDEC.cxx \
	test_AllToAllvTimeDEC.cxx \
	test_AllToAllvTimeDoubleDEC.cxx \
	MPIAccessTest.cxx \
	test_MPI_Access_Send_Recv.cxx \
	test_MPI_Access_Cyclic_Send_Recv.cxx \
	test_MPI_Access_SendRecv.cxx \
	test_MPI_Access_ISend_IRecv.cxx \
	test_MPI_Access_Cyclic_ISend_IRecv.cxx \
	test_MPI_Access_ISendRecv.cxx \
	test_MPI_Access_Probe.cxx \
	test_MPI_Access_IProbe.cxx \
	test_MPI_Access_Cancel.cxx \
	test_MPI_Access_Send_Recv_Length.cxx \
	test_MPI_Access_ISend_IRecv_Length.cxx \
	test_MPI_Access_ISend_IRecv_Length_1.cxx \
	test_MPI_Access_Time.cxx \
	test_MPI_Access_Time_0.cxx \
	test_MPI_Access_ISend_IRecv_BottleNeck.cxx

libParaMEDMEMTest_la_CPPFLAGS = \
	@CPPUNIT_INCLUDES@ \
	$(MPI_INCLUDES) \
	-I$(srcdir)/../INTERP_KERNEL \
	-I$(srcdir)/../INTERP_KERNEL/Bases \
	-I$(srcdir)/../INTERP_KERNEL/Geometric2D \
	-I$(srcdir)/../ParaMEDMEM \
	-I$(srcdir)/../MEDCoupling \
	-I$(srcdir)/../MEDLoader  \
	-I$(srcdir)/../ParaMEDLoader

libParaMEDMEMTest_la_LDFLAGS = \
	../ParaMEDMEM/libparamedmem.la \
	../ParaMEDLoader/libparamedloader.la \
	@CPPUNIT_LIBS@ $(MPI_LIBS)

# Executables targets
bin_PROGRAMS = \
	TestParaMEDMEM \
	TestMPIAccessDEC \
	TestMPIAccess \
	test_perf

dist_TestParaMEDMEM_SOURCES = TestParaMEDMEM.cxx
dist_TestMPIAccessDEC_SOURCES = TestMPIAccessDEC.cxx
dist_TestMPIAccess_SOURCES = TestMPIAccess.cxx
dist_test_perf_SOURCES = test_perf.cxx

if MPI2_IS_OK
bin_PROGRAMS += \
	ParaMEDMEMTestMPI2_1 \
	ParaMEDMEMTestMPI2_2

dist_ParaMEDMEMTestMPI2_1_SOURCES = \
	MPI2Connector.cxx \
	ParaMEDMEMTestMPI2_1.cxx

dist_ParaMEDMEMTestMPI2_2_SOURCES = \
	MPI2Connector.cxx \
	ParaMEDMEMTestMPI2_2.cxx

endif

LDADD = $(MED3_LIBS_C_ONLY) $(libMEDMEMTest_la_LDFLAGS) -lm $(MPI_LIBS) \
	libParaMEDMEMTest.la \
	../INTERP_KERNEL/libinterpkernel.la $(CPPUNIT_LIBS) \
	../ParaMEDMEM/libparamedmem.la \
	../MEDCoupling/libmedcoupling.la \
	../MEDLoader/libmedloader.la
	../INTERP_KERNEL/libinterpkernel.la 

if MED_ENABLE_FVM
	LDADD += $(FVM_LIBS)
	libParaMEDMEMTest_la_CPPFLAGS += -DMED_ENABLE_FVM $(FVM_INCLUDES)
	libParaMEDMEMTest_la_LDFLAGS += $(FVM_LIBS)
endif

AM_CPPFLAGS += $(libParaMEDMEMTest_la_CPPFLAGS)

UNIT_TEST_PROG = TestParaMEDMEM
