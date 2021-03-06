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
//  $Header: /home/server/cvs/MED/MED_SRC/src/MEDWrapper/Factory/MED_Factory.hxx,v 1.7.2.1.6.3 2012-06-05 11:55:33 vsr Exp $
//
#ifndef MED_Factory_HeaderFile
#define MED_Factory_HeaderFile

#include "MED_WrapperFactory.hxx"
#include "MED_Wrapper.hxx"

namespace MED
{
  MEDWRAPPER_FACTORY_EXPORT
  EVersion  
  GetVersionId(const std::string& theFileName,
               bool theDoPreCheckInSeparateProcess = false);

  MEDWRAPPER_FACTORY_EXPORT
    bool getMEDVersion( const std::string&, int&, int&, int& );
  
  MEDWRAPPER_FACTORY_EXPORT
  PWrapper 
  CrWrapper(const std::string& theFileName,
            bool theDoPreCheckInSeparateProcess = false);

  MEDWRAPPER_FACTORY_EXPORT
  PWrapper 
  CrWrapper(const std::string& theFileName, EVersion theId);
}

#endif
