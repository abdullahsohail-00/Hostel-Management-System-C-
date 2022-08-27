#include <iostream>
#include <string>
#include <windows.h>
#include "manager.h"
#include <fstream>
#include "manager.cpp"
#include "room.h"
#include "room.cpp"
#include "bill.h"
#include "bill.cpp"
#include "staff.h"
#include "staff.cpp"
#include "admin.h"
#include "login.cpp"
using namespace std;

int main()
{
	system("cls");
	system("Color E4");
	roomClass rc;
	billPayment bi;
	AdminClass a1;
	fstream managerDetail, staffDetaill, roomDetaill, billDetail;
	a1.login();
	char b, a, z, n;
	system("cls");

	cout << " Our Project Is:";
	cout << "\n\t\t  Hotel All Managment System ";
	cout << " \n Prepared BY:";
	cout << "\n\t\t  Naqeeb Masood\n\t\t Abdullah Sohail\n\t\t Muhammad Anas";
p:
	cout << "\n\n\n\t\t\t\tMAIN DASHBOARD\n";
	cout << "\n\n\t\tPress 1 for Employee Detail.";
	cout << "\n\t\tPress 2 for Serving System.";
	cout << "\n\t\tPress 3 for Room System.";
	cout << "\n\t\tPress 4 for Exit.\n";
	cin >> n; // MANAGEMENT SYSTEM
	//------------------------------------------------------------------------------------------------------------------------------------------
	switch (n)
	{
	case '1':
	d:
		system("cls");
	z:
		cout << "\n\t\t\tManagement System\n";
		cout << "\n\tPress 1 for Enter Manager Details\n";
		cout << "\tPess 2 for Enter Staff Details\n";
		cout << "\tPress 3 for Exit on Main Dashboard\n";
		cin >> a;
		if (a == '1')
		{  // MANAGER DETAILS
		a: //----------------------------------------------------------------------
			system("cls");
			rc.recordman();
			cin >> b;
			if (b == '1')
			{
			q: // Insert Record
				cout << "\n";
				rc.insertMan(managerDetail);
			r:
				cout << "Add more data(Y/N)";
				cin >> z;
				if ((z == 'N') || (z == 'n'))
				{
					system("cls");
					Sleep(700);
					goto a;
				}
				else if ((z == 'Y') || (z == 'y'))
				{
					Sleep(700);
					goto q;
				}
				else if ((z >= 'a' && z <= 'm') || (z >= 'A' && z <= 'M') || (z >= 'o' && z <= 'x') || (z >= 'O' && z <= 'X') || (z == 'z') || (z == 'Z'))
				{
					cout << "\n\tPress Correct Number\n";
					Sleep(2000);
					goto r;
				}
			}
			else if (b == '2')
			{
				rc.m_update(managerDetail); // Update Manager
				cout << "\n\n\tPress any key for Continue\n";
				cin >> z;
				Sleep(900);
				system("cls");
				goto a;
			}
			else if (b == '3')
			{
				rc.m_delete(managerDetail);
				cout << "\n\n\tPress any key for Continue\n";
				cin >> z;
				Sleep(900);
				system("cls");
				goto a;
			}
			else if (b == '4') // Desplay Record
			{
				rc.displayman(managerDetail);
				cout << "\n\n\tPress any key for Continue\n";
				cin >> z;
				Sleep(900);
				system("cls");
				goto a;
			}
			else if (b == '5')
			{
				system("cls");
				goto d;
			}
			else if (b == '6')
			{
				system("cls");
				goto p;
			}
			else
			{
				cout << "\n\tPress Correct Number\n";
				Sleep(2000);
				goto a;
			} // STAFF DETAILS
		}
		else if (a == '2')
		{
		s:
			system("cls");
			rc.recordsta();
			cin >> b;
			if (b == '1')
			{ // Insert  Staff Record
			w:
				cout << "\n";
				rc.insertstaff(staffDetaill);
			t:
				cout << "Add more data(Y/N)";
				cin >> z;
				if ((z == 'N') || (z == 'n'))
				{
					system("cls");
					Sleep(800);
					goto s;
				}
				else if ((z == 'Y') || (z == 'y'))
				{
					Sleep(700);
					goto w;
				}
				else if ((z >= 'a' && z <= 'm') || (z >= 'A' && z <= 'M') || (z >= 'o' && z <= 'x') || (z >= 'O' && z <= 'X') || (z == 'z') || (z == 'Z'))
				{
					cout << "\n\tPress Correct Number\n";
					Sleep(2000);
					goto t;
				}
			}
			else if (b == '2')
			{
				rc.s_update(staffDetaill);
				cout << "\n\n\tPress any key for Continue\n";
				cin >> z;
				Sleep(900);
				system("cls");
				goto s;
			}
			else if (b == '3')
			{
				rc.s_delete(staffDetaill);
				cout << "\n\n\tPress any key for Continue\n";
				cin >> z;
				Sleep(900);
				system("cls");
				goto s;
			}
			else if (b == '4') // Desplay Staff Record
			{
				rc.displaystaff(staffDetaill);
				cout << "\n\n\tPress any key for Continue\n";
				cin >> z;
				Sleep(900);
				system("cls");
				goto s;
			}
			else if (b == '5')
			{
				system("cls");
				goto d;
			}
			else if (b == '6')
			{
				system("cls");
				goto p;
			}
			else
			{
				cout << "\n\tPress Correct Number\n";
				Sleep(2000);
				goto s;
			}
		}
		else if (a == '3')
		{
			system("cls");
			goto p;
		}
		else
		{
			cout << "\n\tPress Correct Number\n";
			Sleep(2000);
			system("cls");
			goto z;
		}
		break; // Serving System
			   //--------------------------------------------------------------------

	case '2':
	m:
		system("cls");
		cout << "\n\t\t\t\tHotel Food Serving System\n";
		cout << "\n\t\tPress 1 for Order Your Food";
		cout << "\n\t\tPress 2 for Display your Payment";
		cout << "\n\t\tPress 3 for Delete Specific Item";
		cout << "\n\t\tPress 4 for Exit on Main Dashboard\n";
		cin >> a;
		if (a == '1')
		{
			system("cls");
			bi.insertBill();
			goto m;
		}
		else if (a == '2')
		{
			system("cls");
			bi.Displaybill();
			Sleep(1000);
			cout << "\n\tPress Any Key For Continue\n";
			cin >> z;
			Sleep(800);
			goto m;
		}
		else if (a == '3')
		{
			system("cls");
			bi.deleteOrder();
			cout << "*" << endl;
			cout << "Record Deleted" << endl;
			cout << "*" << endl;
			Sleep(1000);
			cout << "\n\tPress Any Key For Continue\n";
			cin >> z;
			Sleep(800);
			goto m;
		}
		else if (a == '4')
		{
			system("cls");
			goto p;
		}
		else
		{
			cout << "\n\tPress Correct Number\n";
			Sleep(1000);
			goto m;
		}
		break;

	case '3': // Room DETAILS
	//----------------------------------------------------------------------
	j:
		system("cls");
		cout << "\n\t\t\t\tHotel Room System\n";
		cout << "\n\t\tPress 1 For Book Your Room";
		cout << "\n\t\tPress 2 For Check Your Room Detail";
		cout << "\n\t\tPress 3 For Update Your Room Details By Room Number";
		cout << "\n\t\tPress 4 For Delete Your Room Detail";
		cout << "\n\t\tPress 5 For Exit on Main Dashboard\n";
		cin >> a;
		if (a == '1')
		{ // Insert Record
		o:
			system("cls");
			cout << "\n";
			rc.insertroom(roomDetaill);
		i:
			cout << "Add more data(Y/N)";
			cin >> z;
			if ((z == 'N') || (z == 'n'))
			{
				system("cls");
				Sleep(700);
				goto j;
			}
			else if ((z == 'Y') || (z == 'y'))
			{
				Sleep(700);
				goto o;
			}
			else if ((z >= 'a' && z <= 'm') || (z >= 'A' && z <= 'M') || (z >= 'o' && z <= 'x') || (z >= 'O' && z <= 'X') || (z == 'z') || (z == 'Z'))
			{
				cout << "\n\tPress Correct Number\n";
				Sleep(2000);
				goto i;
			}
		}
		else if (a == '2')
		{ // Desplay Record
			rc.displayroom(roomDetaill);
			cout << "\n\n\tPress any key for Continue\n";
			cin >> z;
			Sleep(900);
			system("cls");
			goto j;
		}
		else if (a == '3')
		{ // Room Update Record
			rc.r_update(roomDetaill);
			cout << "\n\n\tPress any key for Continue\n";
			cin >> z;
			Sleep(900);
			system("cls");
			goto j;
		}
		else if (a == '4')
		{ // Room Delete Record
			rc.r_delete(roomDetaill);
			cout << "\n\n\tPress any key for Continue\n";
			cin >> z;
			Sleep(900);
			system("cls");
			goto j;
		}
		else if (a == '5')
		{
			system("cls");
			goto p;
		}
		else
		{
			cout << "\n\tPress Correct Number\n";
			Sleep(2000);
			goto j;
		}
		break;

	case '4':
		system("cls");
		Sleep(900);
		billDetail.close();
		cout << "\n\t\t\tThanks BY Naqeeb Masood\n\t\t\t    Abdullah Sohail\n\t\t\t     Muhammad Anas\n";
		Sleep(1000);
		cout << "\n\t\t\t\t\tThank You\n\n";
		Sleep(2000);
		break;

	default:
		cout << "\n\tPress Correct Number";
		Sleep(1000);
		system("cls");
		goto p;
		break;
	}
	return 0;
}
