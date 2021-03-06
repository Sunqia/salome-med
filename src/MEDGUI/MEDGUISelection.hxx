// Copyright (C) 2007-2012  CEA/DEN, EDF R&D, OPEN CASCADE
//
// Copyright (C) 2003-2007  OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN,
// CEDRAT, EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//

//  MED MEDGUI_Selection
//  File   : MEDGUI_Selection.h
//  Author : Alexander SOLOVYOV
//  Module : MED
//  $Header: /home/server/cvs/MED/MED_SRC/src/MEDGUI/Attic/MEDGUISelection.hxx,v 1.1.6.4 2012-06-05 11:55:16 vsr Exp $
//
#ifndef __MEDGUISELECTION_HXX__
#define __MEDGUISELECTION_HXX__

#include "LightApp_Selection.h"

class MEDGUISelection : public LightApp_Selection
{
public:
  MEDGUISelection();
  virtual ~MEDGUISelection();
};

#endif
