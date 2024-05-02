#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Client.h"
#include"CLs_Utility.h"

using namespace std;

class Cls_Find_Client : protected Cls_HeaderScreen, public Cls_Utility, public Cls_Bank_Client
{
private:
	static void _Print(Cls_Bank_Client& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FristName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.GetFullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nPassword    : " << Client.PinCoude;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

//protected:

public:

	static void FindClient()
	{
		system("cls");

		HeaderSecreen("Find Client Screen", 8);

		string AccoutNumber = "";
		cout << " Please Enter AccoutNumber : "; getline(cin >> ws, AccoutNumber);
		//CLs_UpdateClient Client;
		while (!IsClientExit(AccoutNumber))
		{
			cout << " Account Number Is Already Used Choose Another One : "; getline(cin >> ws, AccoutNumber);
		}

		Cls_Bank_Client Client = Find(AccoutNumber);
		printf("\n\nClient Found :-) ");
		_Print(Client);
	}

};

