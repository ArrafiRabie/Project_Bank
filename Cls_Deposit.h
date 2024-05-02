#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Client.h"

using namespace std;

class Cls_Deposit : protected Cls_HeaderScreen
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

	static void _ReadAmountClient(Cls_Bank_Client& Client, string AccoutNumber,float Amount, char Operatour)
	{
		if (Operatour == '+')
		{
			Client.SetAccountBalance(Client.GetAccountBalance() + Amount);
		}
		else if (Operatour == '-')
		{
			Client.SetAccountBalance(Client.GetAccountBalance() - Amount);
		}

		Client.UpdateClient(AccoutNumber, "MyFile.Txt");
	}

//protected:

public:

	static void ReadAmountClient(Cls_Bank_Client& Client, string AccoutNumber, float Amount, char Operatour)
	{
		_ReadAmountClient(Client, AccoutNumber, Amount, Operatour);
	}

	static void Deposit()
	{
		system("cls");
		string AccoutNumber;

		HeaderSecreen("Deposit Screen",8);
		printf("Please Enter AccoutNumber : ");
		cin >> AccoutNumber;
		while (!Cls_Bank_Client::IsClientExit(AccoutNumber))
		{
			cout << " CLient With [" << AccoutNumber <<"] Does Not Exist : "; getline(cin >> ws, AccoutNumber);
		}

		Cls_Bank_Client Client = Cls_Bank_Client::Find(AccoutNumber);
		_Print(Client);

		float Amount = 0;
		printf("\nPlease Enter Deposit Amount : ");
		cin >> Amount;

		char CheckAmount = 'n';
		cout << "\nAre you sure you want to Perfome This Transaction ? [Y/N] : ";
		cin >> CheckAmount;
		if (CheckAmount == 'Y' || CheckAmount == 'y')
		{
			ReadAmountClient(Client, AccoutNumber, Amount,'+');
			printf("\nAmount Deposited Successfully \n");
			cout << "New Balance Is : " << Client.GetAccountBalance() << Endl(2);
		}
	}

};

