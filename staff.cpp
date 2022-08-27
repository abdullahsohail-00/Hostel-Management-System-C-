#include<iostream>
#include<string>
#include<windows.h>
#include "manager.h"
#include "staff.h"
#include<fstream>
using namespace std;

  void staffClass::recordsta()                                  //RECORD      for      Staff System;
  {                                
	 system("cls");
	 cout<<"\n\n\n\t\t\t\tStaff Record";
	 cout<<"\n\n Press 1 for Insert Staff Record";
	 cout<<"\n Press 2 for Update Staff Record";
     cout<<"\n Press 3 for Delete Some Staff Detail";	 
	 cout<<"\n Press 4 for Display Staff Record";
	 cout<<"\n Press 5 for Exit on Management System ";
	 cout<<"\n Press 6 for Exit on Main Dashboard ";
   	 Sleep(900);
	 cout<<"\n\n Select Your Choice : ";
   }

  void staffClass::insertstaff(fstream& staffDetail)                    // Insert Staff Details
  {   
     system("cls");
	 staffDetail.open("Staff_Details.txt", ios::app | ios::out);
	 cout<<"\n\t\t\tInsert Staff Details\n";
	 cin.ignore();	
	 cout<<"\n\t  Staff Name  : ";
	 getline(cin,sname);    
     cout<<"\n\t  Staff Age  : ";
	 getline(cin,sage);
	 cout<<"\n\tStaff Adress : ";
	 getline(cin,sadress);
     cout<<"\n\t Staff CNIC  : ";
	 getline(cin,scnic);

    // Store Staff Detail
     staffDetail << " " << sname << " " << sage << " " << sadress << " " << scnic << "\n";
	 staffDetail.close();

   }

  void staffClass::displaystaff(fstream& staffDetail)              //Display Staff Details
	{
	 system("cls");
     int totals = 0;
     staffDetail.open("Staff_Details.txt", ios::in);
    if(!staffDetail)
    {
        cout << "\n\t\t\tNo Staff Detail File Is Present...";
    }
    else
    {
        staffDetail >> sname >> sage >> sadress >> scnic ;
        while (!staffDetail.eof())
        { 
		     cout<<"\n\t\t\t---------------------------";			
			 cout<<"\n\t\t\t  Display Staff Details";
		     cout<<"\n\t\t\t---------------------------";			
             cout<<"\n\n\t\t Staff Name : " << sname;
             cout<<"\n\t\t Staff Age : " << sage;
             cout<<"\n\t\t Staff Address: " << sadress;
             cout<<"\n\t\t Staff Cnic :" << scnic;
             staffDetail >> sname >> sage >> sadress >> scnic ;
		     totals++;
        }
        if(totals == 0)
        {
             cout << "\n\t\t\tNo Staff Data Is Present...";
        }
    }
     staffDetail.close();
   }

void staffClass::s_update(fstream& staffDetail)             //Staff update
{

 system("cls");
    fstream  sa;
    string name;
    int foundss = 0;
    staffDetail.open("Staff_Details.txt", ios::in);
    if (!staffDetail)
    {
        cout << "\n\t\t\tNo Staff Detail File Is Present...";
    }
    else
    {
		cin.ignore();
        cout << "\nEnter Name of Staff for update: ";
	    getline(cin, name);
        sa.open("record.txt", ios::app | ios::out);
        staffDetail >> sname >> sage >> sadress >> scnic ;
        while (!staffDetail.eof())
        {
            if (name != sname){
                sa << " " << sname << " " << sage << " " << sadress << " " << scnic << "\n";
		     }
            else
            {
                cout<<"\n\n\t\t\t\tInsert Record"<<endl;
                cin.ignore();
    
	         	cout<<"\n\t Staff Name   : ";
	            getline(cin, sname);
	            
	            cout<<"\n\t  Staff Age   : ";
	            getline(cin, sage);
	 
	            cout<<"\n\t Staff Address : ";
	            getline(cin, sadress);
	
	            cout<<"\n\t  Staff Cnic  : ";
	            getline(cin, scnic);
    
                sa << " " << sname << " " << sage << " " << sadress << " " << scnic << "\n";
                foundss++;
            }   
            staffDetail >> sname >> sage >> sadress >> scnic ;
        }   
            if (foundss == 0)
            {
            cout << "\n\t\t\t Staff "<<name <<" Not Found....";
            }
        
        sa.close();
        staffDetail.close();
        remove("Staff_Details.txt");
        rename("record.txt", "Staff_Details.txt");
    }

}

void staffClass::s_delete(fstream& staffDetail)        //Staff delete
{
 system("cls");
    fstream  sa;
    int founds = 0;
    string name;
    staffDetail.open("Staff_Details.txt", ios::in);
    if (!staffDetail)
    {
        cout << "\n\t\t\tNo Staff Detail File Is Present...";
        staffDetail.close();
    }
    else
    {
		cin.ignore();
        cout << "\nEnter Name of Staff For Delete Data: ";
         getline(cin,name);
        sa.open("record.txt", ios::app | ios::out);
           staffDetail >> sname >> sage >> sadress >> scnic ;
        while (!staffDetail.eof())
        {
            if (name != sname)
            {
                sa << " " << sname << " " << sage << " " << sadress << " " << scnic << "\n";
            }
            else
            {
                founds++;
                cout << "\n\t\t\tSuccessfully "<<name<< " name of Data Deleted";
            }
           staffDetail >> sname >> sage >> sadress >> scnic ;
        }
        if (founds == 0)
        {
            cout << "\n\t\t\t Staff "<<name <<" Not Found....";
        }
        sa.close();
        staffDetail.close();
        remove("Staff_Details.txt");
        rename("record.txt", "Staff_Details.txt");
    }	
}
