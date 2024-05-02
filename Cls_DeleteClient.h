#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"CLs_Utility.h"
#include"Cls_Bank_Client.h"

using namespace std;

class Cls_DeleteClient : public Cls_Bank_Client, public Cls_Utility, protected Cls_HeaderScreen
{
private:

	static void _Print(Cls_Bank_Client Client)
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

	static void DeleteClient()
	{
		system("cls");

		HeaderSecreen("Delete Client Screen",8);

		string AccoutNumber = "";
		cout << " Please Enter AccoutNumber : "; getline(cin >> ws, AccoutNumber);
		Cls_DeleteClient Client;
		while (!Client.IsClientExit(AccoutNumber))
		{
			cout << " Account Number Is Already Used Choose Another One : "; getline(cin >> ws, AccoutNumber);
		}

		Cls_Bank_Client Cli = Cli.Find(AccoutNumber);
		_Print(Find(AccoutNumber));
		char CheckDelet = 'n';
		cout << " Are you sure you want to delete this client [Y/N]? : ";
		cin >> CheckDelet;

		if (CheckDelet == 'Y' || CheckDelet == 'y')
		{
			cout << Delete(AccoutNumber) << endl;
			_Print(Find(AccoutNumber));
		}
		else if (CheckDelet != 'Y' || CheckDelet != 'y')
		{
			cout << " T'dont Client Deleted Succssefully ";
			_Print(Find(AccoutNumber));
		}
	}
};

