#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Client.h"
#include"CLs_Utility.h"
#include"Cls_Deposit.h"
#include"Cls_Withdraw.h"
#include"Cls_TotaBalance.h"
#include"Cls_Transfer.h"

using namespace std;

class CLs_Transactions : protected Cls_HeaderScreen
{

private:

	enum enTransaction
	{
		Deposit       = 1,
		Withdraw      = 2,
		Total_Balance = 3,
		transfer      = 4,
		Main_Menue    = 5,
	};

	static short _ReadNumberToTransactionMaine(short From, short TO)
	{
		short Number = 0;
		cout << " Choose What Do You Want To Do [" << From << " To " << TO << "] ? : ";
		cin >> Number;
		//<><><> Validete <><><>//
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			cout << "\t\t Invalid Number, Enter A Valid One: " << endl;
			printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			cout << "\t\t"; cin >> Number;
			cin.ignore(1, '\n');
		}
		//<><><><><><><><><><><>//
		while (Number > TO || Number < From)
		{
			printf("\n\t\t<><><><><><><><><><><><><><><><>\n");
			printf("\t\t Please Enter The Required Number \n");
			printf("\t\t<><><><><><><><><><><><><><><><>\n");
			printf("\t\tChoose What Do You Want To Do ? [1 To 8] ? : ");
			cin >> Number;
			//=== Validete ===//
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				cout << "\t\t Invalid Number, Enter A Valid One: " << endl;
				printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				cout << "\t\t"; cin >> Number;
				cin.ignore(1, '\n');
			}
			//===============//
		}
		return Number;
	}
	static void _Deposit()
	{
		Cls_Deposit::Deposit();
	}
	static void _Withdraw()
	{
		Cls_Withdraw::Withdraw();
	}
	static void _TotalBalance()
	{
		Cls_TotaBalance::TotalBalane();
	} 
	static void _Transfeer()
	{
		Cls_Transfer::Transfer();
	}
	static void _MainMenue()
	{
		
	}

	static void _SwitchTransactionMaine(enTransaction Transaction)
	{
		switch (Transaction)
		{
		case CLs_Transactions::Deposit:
			_Deposit();
			GoBackToMainMenue();
			break;
		case CLs_Transactions::Withdraw:
			_Withdraw();
			GoBackToMainMenue();
			break;
		case CLs_Transactions::Total_Balance:
			_TotalBalance();
			GoBackToMainMenue();
			break;
		case CLs_Transactions::transfer:
			_Transfeer();
			GoBackToMainMenue();
			break;
		case CLs_Transactions::Main_Menue:
			_MainMenue();
			break;
		default:
			break;
		}
	}

//protected:

public:

	static void TransactionMaine()
	{
		HeaderSecreen("Transaction Screen", 8);
		system("Color 0");;
		cout << Tabs(36, "=") << Endl(1);
		cout << Tabs(8, " "); printf("\nTransaction Menue\t\n");
		cout << Tabs(36, "=") << endl;
		cout << Tabs(36, "=") << Endl(1);
		cout << " [1] : Deposit.\n";
		cout << " [2] : Withdraw.\n";
		cout << " [3] : Total Balance.\n";
		cout << " [4] : Transfer.\n";
		cout << " [5] : Main Menue.\n";
		cout << Tabs(36, "=") << Endl(1);
		_SwitchTransactionMaine(enTransaction(_ReadNumberToTransactionMaine(1, 5)));
	}


	static void GoBackToMainMenue()
	{
		//printf(" \nPreess Any Key Go To Back To Main Menue...");

		system("\n\n\npause");
		TransactionMaine();
	}


	static void Transaction()
	{
		system("cls");
		TransactionMaine();
	}

};

