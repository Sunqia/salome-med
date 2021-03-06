// Copyright (C) 2007-2012  CEA/DEN, EDF R&D
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
#ifndef MESHCOLLECTIONMEDASCIIDRIVER_HXX_
#define MESHCOLLECTIONMEDASCIIDRIVER_HXX_

#include "MEDSPLITTER_MESHCollectionDriver.hxx"

namespace MEDSPLITTER
{
  class MESHCollection;

  class MESHCollectionMedAsciiDriver:public MESHCollectionDriver
  {
  public:

    MESHCollectionMedAsciiDriver(MESHCollection*);
    virtual ~MESHCollectionMedAsciiDriver(){}

    int read(char*, ParaDomainSelector* sel=0);

    void write(char*, ParaDomainSelector* sel=0);

    void readFields(vector <MEDMEM::FIELD<int> *>& filenames, char* fieldname,
                    int itnumber, int ordernumber)
    {
      _readFields(filenames,fieldname,itnumber,ordernumber);
    }
    void readFields(vector <MEDMEM::FIELD<double> *>& filenames, char* fieldname,
                    int itnumber, int ordernumber)
    {
      _readFields(filenames,fieldname,itnumber,ordernumber);
    }

    void writeFields(vector <MEDMEM::FIELD<int> *>& filenames, char* fieldname)
    {
      _writeFields( filenames, fieldname);
    }

    void writeFields(vector <MEDMEM::FIELD<double> *>& filenames, char* fieldname)
    {
      _writeFields( filenames, fieldname);
    }


  private :
    template <class T> void _readFields(vector <MEDMEM::FIELD<T> *>& filenames, char* fieldname,
                                        int itnumber, int ordernumber);

    template <class T>
    void _writeFields(vector <MEDMEM::FIELD<T> *>& filenames, char* fieldname);



    std::string _master_filename;
  };

}


#endif /*MESHCOLLECTIONDRIVER_HXX_*/
