#include<iostream>
#include<string>
#include<windows.h>
#include "manager.h"
#include<fstream>
using namespace std;

void managerClass::recordman()
{
	 system("cls");
	 cout<<"\n\n\n\t\t\t\tManagement Record";
	 cout<<"\n\n Press 1 for Insert Manager Record";
	 cout<<"\n Press 2 for Update Manager Detail";
	 cout<<"\n Press 3 for Delete Some Manager Detail";
	 cout<<"\n Press 4 for Display Manager Record";
	 cout<<"\n Press 5 for Exit on Management System ";
	 cout<<"\n Press 6 for Exit on Main Dashboard ";
	 cout<<"\n\n Select Your Choice : ";
}

 void managerClass::insertMan(fstream& managerDetail)  // Insert manager Details
 {  
     system("cls");
	 managerDetail.open("Manager_Details.txt", ios::app | ios::out);
	 cout<<"\n\t\t\tInsert Manager Details\n";
	 cin.ignore();
     cout<<"\n\t Manager Name  : "; 
	 getline(cin,mname);
     cout<<"\n\t Manager Age   : ";                       
	 getline(cin,mage);
     cout<<"\n\tManager Adress : ";
	 getline(cin,madress);
     cout<<"\n\t Manager CNIC  : ";
	 getline(cin,mcnic);

        //Store Manager Detail
     managerDetail << " " << mname << " " << mage << " " << madress << " " << mcnic << "\n";
	 managerDetail.close();
   }

void managerClass::displayman(fstream& managerDetail)
{ 
	 system("cls");
     int totalm = 0;
     managerDetail.open("Manager_Details.txt", ios::in | ios::out);  
    if(!managerDetail)
    {
         cout << "\n\t\t\tNo Manager Detail File Is Present...";
    }else
    {
         managerDetail >> mname >> mage >> madress >> mcnic ;
        while (!managerDetail.eof())
        { 
		     cout<<"\n\t\t\t---------------------------";			
			 cout<<"\n\t\t\t  Display Manager Details";
		     cout<<"\n\t\t\t---------------------------";			
             cout << "\n\n\t\t   Manager Name : " << mname;
             cout << "\n\t\t    Manager Age : " << mage;
             cout << "\n\t\t Manager Address: " << madress;
             cout << "\n\t\t   Manager Cnic :" << mcnic;
             managerDetail >> mname >> mage >> madress >> mcnic ;
		     totalm++;
        }
        if (totalm == 0)
        {
             cout << "\n\t\t\tNo Manager Data Is Present...";
        }
    }
     managerDetail.close();
}

void managerClass::m_update(fstream& managerDetail)                                           //Manager update
{
    system("cls");
    fstream  ma;
    string name;
    int foundm = 0;
    managerDetail.open("Manager_Details.txt", ios::in);
    if (!managerDetail)
    {
         cout << "\n\t\t\tNo Manager Detail File Is Present...";
    }
    else
    {
		 cin.ignore();
         cout << "\nEnter Name of Manager for update: ";
	     getline(cin, name);
         ma.open("record.txt", ios::app | ios::out);
         managerDetail >> mname >> mage >> madress>> mcnic ;
        while (!managerDetail.eof())
        {
            if (name != mname){

                ma << " " << mname << " " << mage << " " << madress << " " << mcnic << "\n";
		     }
            else
            {
                cout<<"\n\n\t\t\t\tInsert Record"<<endl;
                cin.ignore();
    
	         	cout<<"\n\t Manager Name   : ";
	            getline(cin, mname);
	            
	            cout<<"\n\t  Manager Age   : ";
	            getline(cin, mage);
	 
	            cout<<"\n\t Manager Address : ";
	            getline(cin, madress);
	
	            cout<<"\n\t  Manager Cnic  : ";
	            getline(cin, mcnic);
    
                ma << " " << mname << "  " << mage << " " << madress << " " << mcnic << "\n";
                foundm++;
            }
            managerDetail >> mname >> mage >> madress >> mcnic;
        }
            if (foundm == 0)
            {
            cout << "\n\t\t\t Manager "<<name <<" Not Found....";
            }
        }
        ma.close();
        managerDetail.close();
        remove("Manager_Details.txt");
        rename("record.txt", "Manager_Details.txt");
    
}

void managerClass::m_delete(fstream& managerDetail)                                          //manager delete
{ 
	 system("cls");
     fstream  ma;
     int foundm = 0;
     string name;
     managerDetail.open("Manager_Details.txt", ios::in);
    if (!managerDetail)
    {
         cout << "\n\t\t\tNo Manager Detail File Is Present...";
         managerDetail.close();
    }
    else
    {
		 cin.ignore();
         cout << "\nEnter Name of Manager For Delete Data: ";
         getline(cin,name);
         ma.open("record.txt", ios::app | ios::out);
         managerDetail >> mname >> mage >> madress>>mcnic;
        while (!managerDetail.eof())
        {
            if (name != mname)
            {
                ma << " " << mname << " " << mage << " " << madress << " " << mcnic << "\n";
            }
            else
            {
                foundm++;
                cout << "\n\t\t\tSuccessfully "<<name<< " name of Data Deleted";
            }
            managerDetail >> mname >> mage >> madress>>mcnic;
        }
        if (foundm == 0)
        {
            cout << "\n\t\t\t Manager "<< name <<" Not Found....";
        }
        ma.close();
        managerDetail.close();
        remove("Manager_Details.txt");
        rename("record.txt", "Manager_Details.txt");
    }
}
