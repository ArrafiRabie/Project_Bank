#pragma once
#include<iostream>
#include"Cls_Bank_Rogister.h"
#include"CLs_Utility.h"
#include"Cls_HeaderScreen.h"

using namespace std;

class Cls_LoginRogister : public Cls_Utility
{
private:

//protected:

public:

	static void LoginRogiister()
	{
		system("cls");
		Cls_Bank_Rogister Rogister;
		vector<string> vRead;
		vRead = Rogister.Read_Data_To_File();

		Cls_HeaderScreen Header;
		string Message = "Client List (" + to_string(vRead.size() / 4) + ") Client (S) \n";
		Header.HeaderSecreen(Message,5);

		cout << Tabs(108, "_") << Endl(1);
		cout << left << setw(31) << "Date/Time";
		cout << left << setw(31) << "UsserName";
		cout << left << setw(31) << "Password";
		cout << left << setw(31) << "Permission";
		cout << Endl(1) << Tabs(108, "_") << Endl(2);

		short Counter = 0;
		for (string& Str : vRead)
		{
			Counter++;

			cout << left << setw(31) << Str;

			if (Counter == 4)
			{
				cout << endl;
				cout << Tabs(108, "~") << Endl(1);
				Counter = 0;
			}
		}
	}
};

