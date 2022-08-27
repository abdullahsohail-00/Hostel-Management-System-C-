#include<iostream>
#include<string>
#include<windows.h>
#include "manager.h"
#include "staff.h"
#include "room.h"
#include<fstream>
using namespace std;

 void roomClass::insertroom(fstream& roomDetaill)         // Insert room Details
 {       
     
     system("cls");
	 Sleep(800);
	 roomDetaill.open("Room_Details.txt", ios::app | ios::out);	 
	 cout<<"\n\t\t\tInsert Customer Details\n";
	 cin.ignore();
	 cout<<"\n\t Room Number  : ";
	 getline(cin,rnum);                      
     cout<<"\n\tCustomer Name : ";
	 getline(cin,rname);
     cout<<"\n\tCustomer Age  : ";
	 getline(cin,rage);
     cout<<"\n\tCustomer CNIC : ";
	 getline(cin,rcnic);

     roomDetaill << " " << rnum << " " << rname << " " << rage << " " << rcnic << "\n";
	 roomDetaill.close();
 }
 
 void roomClass::displayroom(fstream& roomDetaill)               //Display Room Details
{
	system("cls");
    int totalr = 0;
    roomDetaill.open("Room_Details.txt", ios::in);
    if (!roomDetaill)
    {
        cout << "\n\t\t\tNo Room Detail File Is Present...";
    }
    else
    {
        roomDetaill >> rnum >> rname >> rage >> rcnic ;
        while (!roomDetaill.eof())
        { 
		    cout<<"\n\t\t\t---------------------------";			
			cout<<"\n\t\t\t  Display Room Details";
		    cout<<"\n\t\t\t---------------------------";			
            cout << "\n\n\t\t Room Number : " << rnum;
            cout << "\n\t\t Customer Name : " << rname;
            cout << "\n\t\t Customer Age  : " << rage;
            cout << "\n\t\t Customer Cnic :"  << rcnic;
        roomDetaill >> rnum >> rname >> rage >> rcnic ;
		   totalr++;
        }
        if (totalr == 0)
        {
            cout << "\n\t\t\tNo Room Data Is Present...";
        }
    }
    roomDetaill.close();
}
 
 void roomClass::r_update(fstream& roomDetaill)                                //Staff update
{
system("cls");
    fstream  ra;
    string num;
    int foundr = 0;
    roomDetaill.open("Room_Details.txt", ios::in);
    if (!roomDetaill)
    {
        cout << "\n\t\t\tNo Room Detail File Is Present...";
    }
    else
    {
		cin.ignore();
        cout << "\nEnter Room Number of Customer for update: ";
	    getline(cin, num);
        ra.open("record.txt", ios::app | ios::out);
        roomDetaill >> rnum >> rname >> rage >> rcnic ;
        while (!roomDetaill.eof())
        {
            if (num != rnum){

                ra <<" "<< rnum <<" "<< rname <<" "<< rage <<" "<< rcnic <<"\n";
		     }
            else
            {
                cout<<"\n\n\t\t\t\tInsert Record"<<endl;
                cin.ignore();
	         	cout<<"\n\t Room Number   : ";
	            getline(cin, rnum);
	            cout<<"\n\t  Customer Name   : ";
	            getline(cin, rname);
	            cout<<"\n\t Customer Age : ";
	            getline(cin, rage);	
	            cout<<"\n\t  Customer Cnic  : ";
	            getline(cin, rcnic);  
                ra << " " << rnum << " " << rname << " " << rage << " " << rcnic << "\n";
                foundr++;
            }
             roomDetaill >> rnum >> rname >> rage >> rcnic ;
        }
            if (foundr == 0)
            {
             cout << "\n\t\t\t "<<num<<" Room Number Not Found....";
            }
        
         ra.close();
         roomDetaill.close();
         remove("Room_Details.txt");
         rename("record.txt", "Room_Details.txt");
    }
	}  

 void roomClass::r_delete(fstream& roomDetaill)              //room delete
{
     system("cls");
     fstream  ra;
     int founds = 0;
     string roomno;
     roomDetaill.open("Room_Details.txt", ios::in);
    if(!roomDetaill)
    {
        cout <<"\n\t\t\tNo Room Detail File Is Present...";
        roomDetaill.close();
    }
    else
    {
		cin.ignore();
        cout << "\nEnter Room Number of Customer for Delete: ";
         getline(cin,roomno);
        ra.open("record.txt", ios::app | ios::out);
        roomDetaill >> rnum >> rname >> rage >> rcnic ;
        while (!roomDetaill.eof())
        {
          if (roomno != rnum)
          {
            ra << " " << rnum << " " << rname << " " << rage << " " << rcnic << "\n";
          }else
          {
            founds++;
            cout << "\n\t\t\tSuccessfully "<<roomno<< " Room Number of Data Deleted";
          }
        roomDetaill >> rnum >> rname >> rage >> rcnic ;
        }
        if(founds == 0)
        {
            cout<<"\n\t\t\t Customer "<<roomno <<" Room Number Not Found....";
        }
         ra.close();
         roomDetaill.close();
         remove("Room_Details.txt");
         rename("record.txt", "Room_Details.txt");
    }	
}
