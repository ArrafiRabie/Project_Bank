#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Client.h"
#include"CLs_Utility.h"

using namespace std;

class Cls_Show_Cleint_List : protected Cls_HeaderScreen, public Cls_Bank_Client, public Cls_Utility
{
private:

	static vector<string> _Show_Cleint_List()
	{
		system("cls");
		vector<string>vReadData;
		vReadData = ReadInformationFromTheFile();
		string Message = "Client List (" + to_string(vReadData.size() / 6) + ") Client (S) \n";
		HeaderSecreen(Message, 5);
		return vReadData;
	}

protected:
public:


	static void Header_Show_Cleint_List()
	{
		vector<string>vReadData;
		short Counter = 0;
		vReadData = _Show_Cleint_List();

		cout << Tabs(117, "_") << Endl(1);
		cout << left << setw(21) << "Account Number";
		cout << left << setw(21) << "Client Name";
		cout << left << setw(21) << "Phone";
		cout << left << setw(21) << "Email";
		cout << left << setw(21) << "PinCode";
		cout << left << setw(21) << "Balance";
		cout << Endl(1) << Tabs(117, "_") << Endl(2);
		

		for (string& Str : vReadData)
		{
			Counter++;
			cout << left << setw(21) << Str;
			if (Counter == 6)
			{
				cout << Endl(1);
				cout << Tabs(117, "~") << Endl(1);
				Counter = 0;
			}
		}
	}

	static void Show_Cleint_List()
	{
		Header_Show_Cleint_List();
	}
};

