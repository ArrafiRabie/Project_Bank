#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Usser.h"

using namespace std;

class Cls_ListUsser : protected Cls_HeaderScreen
{
private:

	static vector<string> _Show_Cleint_List()
	{
		vector<string> vReadData;
		vReadData = Cls_Bank_Usser::Read_data_To_File();
		
		return vReadData;
	}

protected:

public:

	static vector<string> HeaderListUsser(vector<string>& vReadData)
	{
		system("cls");

		string Message = "Usser List Screen \n\t(" + to_string(vReadData.size() / 6) + ") Usser (S) \n";
		HeaderSecreen(Message, 5);

		cout << Tabs(117, "_") << Endl(1);
		cout << left << setw(21) << "UsserName";
		cout << left << setw(21) << "Full Name";
		cout << left << setw(21) << "Phone";
		cout << left << setw(21) << "Email";
		cout << left << setw(21) << "Password";
		cout << left << setw(21) << "Permission";
		cout << Endl(1) << Tabs(117, "_") << Endl(2);

		if (vReadData.size() == 0)
		{
			cout << Tabs(48," ") << " Idon't Usser... " << endl;
			return vReadData;
		}
		
		return vReadData;
	}

	static void ListUsser()
	{
		system("cls");
		vector<string> vReadData;
		vReadData = _Show_Cleint_List();
		HeaderListUsser(vReadData);
		short Counter = 0;
		for (string& Str : vReadData)
		{
			Counter++;
			cout << left << setw(21) << Str;
			if (Counter == 6)
			{
				cout << Endl(1) << Tabs(117, "~") << Endl(2);
				Counter = 0;
			}
		}
	}

};