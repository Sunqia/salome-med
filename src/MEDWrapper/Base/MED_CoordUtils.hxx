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

//  File   : 
//  Author : 
//  Module : 
//  $Header: /home/server/cvs/MED/MED_SRC/src/MEDWrapper/Base/MED_CoordUtils.hxx,v 1.5.2.1.6.3 2012-06-05 11:55:32 vsr Exp $
//
#ifndef MED_CoordUtils_HeaderFile
#define MED_CoordUtils_HeaderFile

#include "MED_WrapperBase.hxx"

#include "MED_Structures.hxx"

namespace MED
{
  typedef TFloat (*TGetCoord)(const TCCoordSlice& theCoordSlice);


  //---------------------------------------------------------------
  class MEDWRAPPER_EXPORT TCoordHelper
  {
    TGetCoord* myGetCoord;
    
  public:
    TCoordHelper(TGetCoord* theGetCoord);

    TFloat 
    GetCoord(TCCoordSlice& theCoordSlice, 
             TInt theCoordId);
  };
  typedef SharedPtr<TCoordHelper> PCoordHelper;


  //---------------------------------------------------------------
  MEDWRAPPER_EXPORT 
  PCoordHelper
  GetCoordHelper(PNodeInfo theNodeInfo);

}

#endif
