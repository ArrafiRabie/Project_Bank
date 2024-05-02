#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Client.h"

using namespace std;

class Cls_Transfer : protected Cls_HeaderScreen
{
private:

	Cls_Bank_Client _ReadDataToFile(string AccoutNuber)
	{
		Cls_Bank_Client Client;
		Client = Cls_Bank_Client::Find(AccoutNuber);
		return Client;

	}

	void _Print(Cls_Bank_Client& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.GetFullName();
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
		cout <<Endl(2);
	}

//protected:

public:

	void static Transfer()
	{
		system("cls");
		HeaderSecreen("Transfer Screen",9);

		string AccoutNumber1 = "", AccoutNumber2 = "";
		printf("Please Enter AccoutNumber To Tranfer Frome : ");
		getline(cin>> ws,AccoutNumber1);
		while (!CLs_UpdateClient::IsClientExit(AccoutNumber1))
		{
			cout << " Account Number Is Already Used Choose Another One : "; getline(cin >> ws, AccoutNumber1);
		}

		Cls_Transfer Client1, Client2;
		Cls_Bank_Client CL1,CL2;
		CL1 = Client1._ReadDataToFile(AccoutNumber1);
		Client1._Print(CL1);

		printf("Please Enter AccoutNumber To Tranfer To : ");
		getline(cin >> ws, AccoutNumber2);
		while (!CLs_UpdateClient::IsClientExit(AccoutNumber2))
		{
			cout << " Account Number Is Already Used Choose Another One : "; getline(cin >> ws, AccoutNumber2);
		}

		CL2 = Client2._ReadDataToFile(AccoutNumber2);
		Client2._Print(CL2);
		float Amount = 0;
		cout << " Please Enter Transfer Amount : ";
		cin >> Amount;

		while (Amount > CL1.AccountBalance)
		{
			printf("Amount Exceeds The Available Balance, Enter Another Amount ");
			cin >> Amount;
		}

		char CheckTranfer = 'n';
		printf(" Are You Sure You Want To Perfome This Operation? [Y/N]? : ");
		cin >> CheckTranfer;
		if (CheckTranfer == 'Y' || CheckTranfer == 'y')
		{
			float Total1, Total2;
			Total1 = 0;
			Total1 = CL1.GetAccountBalance() - Amount;
			CL1.SetAccountBalance(Total1);
			CL1.UpdateClient(AccoutNumber1, "MyFile.Txt");
			//===========================================

			// Errour Update AccountNumber...
			Total2 = 0;
			Total2 = CL2.GetAccountBalance() + Amount;
			CL2.SetAccountBalance(Total2);
			CL2.UpdateClient(AccoutNumber2, "MyFile.Txt");
			printf("Transfer Done Seccessfully \n\n");


			Client1._Print(CL1);
			Client2._Print(CL2);

		}

	}


};

