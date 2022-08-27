#ifndef ROOM_H
#define ROOM_H
#include<fstream>
#include "staff.h"
using namespace std;
struct rom;
class roomClass: public staffClass{
private:
  string rnum,rname,rage,rcnic;   
public:
   void insertroom(fstream& roomDetaill);              // Insert room Details
     
   void displayroom(fstream& roomDetaill);             //Display Room Details
	 
   void r_update(fstream& roomDetaill);                //Staff update

   void r_delete(fstream& roomDetaill);                //room delete

};
#endif