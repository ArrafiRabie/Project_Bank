#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"Cls_Bank_Client.h"
#include"Cls_HeaderScreen.h"
using namespace std;

class Cls_Add_New_Client : public Cls_Bank_Client, protected Cls_HeaderScreen
{
private:

	static void Recorde_Data_To_File(Cls_Add_New_Client Client)
	{
		
	}

protected:

public:

	static void AddNewClient()
	{
		system("cls");
		Cls_Add_New_Client Client;
		string ReadData;
		float  ReadData_ACB;

		HeaderSecreen("Add New Client",9);
		cout << "Please Enter FristName       : "; getline(cin >> ws, ReadData); Client.SetFristName(ReadData);
		cout << "Please Enter LastName        : "; getline(cin >> ws, ReadData); Client.SetLastName(ReadData);
		cout << "Please Enter Phone           : "; getline(cin >> ws, ReadData); Client.SetEmail(ReadData);
		cout << "Please Enter Email           : "; getline(cin >> ws, ReadData); Client.SetPhone(ReadData);
		cout << "Please Enter AccoutNumber    : "; getline(cin >> ws, ReadData); Client.SetAccountNumber(ReadData);
		while (Client.IsClientExit(Client.GetAccouNumber()))/////
		{
			cout << " Account Number Is Already Used Choose Another One : "; getline(cin >> ws, ReadData); Client.SetAccountNumber(ReadData);
		}
		cout << "Please Enter PnCode          : "; getline(cin >> ws, ReadData); Client.SetPinCoude(ReadData);
		cout << "Please Enter AccotBalane     : "; cin >> ReadData_ACB; Client.SetAccountBalance(ReadData_ACB);
		//<><><> Validete <><><>//
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Tabs(35, "~") << endl;
			cout << "Invalid Number, Enter A Valid One: " << endl;
			cout << Tabs(35, "~") << endl;
			cout << "Please Enter AccotBalane     : "; cin >> ReadData_ACB; Client.SetAccountBalance(ReadData_ACB);
			cin.ignore(1, '\n');
		}
		//<><><><><><><><><><><>//
		cout << Tabs(35, "=") << endl;
		string Check;
		cout << " Are You Sure You Want to Add This Client?  [Y/N] : ";
		cin >> Check;
		if (Check == "Y" || Check == "y")
		{
			Client.AddingNewClient();
			printf(" The Customer Has Been Added Successfully \n");
		} 
	}


};

