#ifndef MANAGER_H
#define MANAGER_H
#include <fstream>
using namespace std;

class managerClass
{
  private:
    string mname,mage,madress,mcnic;
  public:
   void recordman();                                         //RECORD      for      Management System;
  
   void insertMan( fstream& managerDetail);                  // Insert manager Details
     
   void displayman(fstream& managerDetail);                  //Display Manager Details
	
   void m_update(fstream& managerDetail);                    //Manager update

   void m_delete(fstream& managerDetail);                    //manager delete

};

#endif