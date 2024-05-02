#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Client.h"
#include"CLs_Utility.h"

using namespace std;

class CLs_UpdateClient : protected Cls_HeaderScreen, public Cls_Utility, public Cls_Bank_Client
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

protected:

public:


	static void ReadUpdateData(Cls_Bank_Client&Client)
	{                                                                                                                                                                                                                                                                                                                                                                                                                      
		string Read;
		cout << Endl(2) << Tabs(27,"~") << Endl(1);
		cout << " Plaes Enter Update To Data " << Endl(1);
		cout << Tabs(27, "~") << Endl(2);
		cout << "Please Enter LastName        : ";
		getline(cin >> ws, Read); Client.SetLastName(Read);
		cout << "Please Enter Email           : ";
		getline(cin >> ws, Read); Client.SetEmail(Read);
		cout << "Please Enter AccotBalane     : ";
		getline(cin >> ws, Read); Client.SetAccountBalance(stof(Read));
	}

	static  void UpdateClien()
	{
		system("cls");

		HeaderSecreen("Update Client Screen", 8);

		string AccoutNumber = "";
		cout << " Please Enter AccoutNumber : "; getline(cin >> ws, AccoutNumber);
		//CLs_UpdateClient Client;
		while (!CLs_UpdateClient::IsClientExit(AccoutNumber)) 
		{
			cout << " Account Number Is Already Used Choose Another One : "; getline(cin >> ws, AccoutNumber);
		}

		Cls_Bank_Client Cli = Find(AccoutNumber);
		_Print(Cli);


		//===========================================

		Cls_Bank_Client A = Find(AccoutNumber); 
		ReadUpdateData(A);


		char CheckDelet = 'n';
		cout << " Are you sure you want to delete this client [Y/N]? : ";
		cin >> CheckDelet;

		if (CheckDelet == 'Y' || CheckDelet == 'y')
		{
			A.UpdateClient(AccoutNumber, "MyFile.Txt");
		}

		_Print(A);

		// Update...
	}

};

