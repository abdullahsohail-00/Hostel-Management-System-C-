#ifndef STAFF_H
#define STAFF_H
#include<fstream>
#include "manager.h"
using namespace std;

class staffClass : public managerClass{
  private:
   string sname,sage,sadress,scnic;
  public:   
   void recordsta();                                   //RECORD      for      Staff System;

   void insertstaff(fstream& staffDetail);             // Insert Staff Details

   void displaystaff(fstream& staffDetail);            //Display Staff Detail

   void s_update(fstream& staffDetail);                 //Staff update

   void s_delete(fstream& staffDetail);                 //Staff delete

};
#endif