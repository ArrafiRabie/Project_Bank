#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Client.h"
#include"Cls_Deposit.h"

using namespace std;

class Cls_Withdraw : protected Cls_HeaderScreen, public Cls_Deposit
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

	static void Withdraw()
	{
		system("cls");

		HeaderSecreen("Withdraw Screen",8);


		string AccoutNumber;
		printf("Please Enter AccoutNumber : ");
		cin >> AccoutNumber;
		while (!Cls_Bank_Client::IsClientExit(AccoutNumber))
		{
			cout << " CLient With [" << AccoutNumber << "] Does Not Exist : "; getline(cin >> ws, AccoutNumber);
		}

		Cls_Bank_Client Client = Cls_Bank_Client::Find(AccoutNumber);
		_Print(Client);

		float Amount = 0;
		printf("\nPlease Enter Withdraw Amount : ");
		cin >> Amount;

		char CheckAmount = 'n';
		cout << " Are you sure you want to Perfome This Withdraw ? [Y/N] : ";
		cin >> CheckAmount;

		if (CheckAmount == 'Y' || CheckAmount == 'y')
		{
			ReadAmountClient(Client, AccoutNumber, Amount, '-');
			printf("\nAmount Deposited Successfully \n");
			cout << "New Balance Is : " << Client.GetAccountBalance() << Endl(1);
		}
	}

};

