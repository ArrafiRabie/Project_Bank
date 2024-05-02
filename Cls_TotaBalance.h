#pragma once
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Client.h"

using namespace std;

class Cls_TotaBalance : protected Cls_HeaderScreen
{

private:

	static vector<string> _ScreenTotaleBalance(float& TotalBalance)
	{
		vector<string>vRead;
		vRead = Cls_Bank_Client::ReadBalancClient();
		short Counter = 0;
		TotalBalance = 0;

		for (string& Str : vRead)
		{
			cout << left << setw(31) << Str;
			Counter++;

			if (Counter == 3)
			{
				TotalBalance += stof(Str);
			}

			if (Counter == 3)
			{
				Endl(1);
				Counter = 0;
				cout << Endl(1) << Tabs(75, "~") << Endl(2);
			}

		}
		return vRead;
	}


protected:

public:


	static void HreaderScreenTotaleBalance()
	{
		vector<string>vRead;
		string Message;
		Message = "TotalBalance List Screen \n " + Tabs(5, " ") + "(" + to_string(vRead.size() / 3) + ") Client (S) \n";
		HeaderSecreen(Message, 5);

		cout << Tabs(75, "_") << Endl(1);
		cout << left << setw(31) << "Account Number";
		cout << left << setw(31) << "Client Name";
		cout << left << setw(31) << "Balance";
		cout << Endl(1) << Tabs(75, "_") << Endl(2);
		float TotalBalance = 0;
		_ScreenTotaleBalance(TotalBalance);

		cout << Tabs(15, " ") << " Total Balance ---> " << TotalBalance << Endl(2);
	}

	static void TotalBalane()
	{
		system("cls");
		HreaderScreenTotaleBalance();
	}

};

