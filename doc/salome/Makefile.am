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

# -* Makefile *- 
# Author : Patrick GOLDBRONN (CEA)
# Date : 30/11/2001
# $Header: /home/server/cvs/MED/MED_SRC/doc/salome/Makefile.am,v 1.3.20.4 2012-10-09 15:11:07 vsr Exp $
#

include $(top_srcdir)/adm_local/unix/make_common_starter.am

SUBDIRS    = tui
SUBDIRSTUI = tui

dev_docs:
	@@SETX@; for d in $(SUBDIRSTUI); do 	\
	   (cd $$d && $(MAKE) $@) || exit 1; 	\
	done;