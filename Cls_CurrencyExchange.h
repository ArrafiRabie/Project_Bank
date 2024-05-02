#pragma once
#include<iostream>
#include"Cls_HeaderScreen.h"
#include"Cls_List_Currencies.h"
#include"Cls_FindCurrencey.h"
#include"Cls_UpdateRate.h"
#include"Cls_CurrencyCalculator.h"

using namespace std;

class Cls_CurrencyExchange : protected Cls_HeaderScreen
{
private:

	enum _enCurrenceis
	{
		List_Currencies     = 1,
		Find_Currencey      = 2,
		Update_Rate         = 3,
		Currency_Calculator = 4,
		Main_Minue          = 5,
	};

	static void _ListCurrencies()
	{
		Cls_List_Currencies::ListCurrencies(); 
	}
	static void _FindCurrencey()
	{
		Cls_FindCurrencey::Find_Currencey();
	}
	static void _UpdateRate()
	{
		Cls_UpdateRate::Update_Rate();
	}
	static void _CurrencyCalculator()
	{
		Cls_CurrencyCalculator::Currency_Calculator();
	}
	static void _Main_Minue()
	{
		system("cls");
		cout << " Main Minue Update..." << endl;
	}

	static _enCurrenceis _ReadNumberToUsser(short From, short TO)
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

		return _enCurrenceis(Number);
	}

	static void Switch_Currency_Exchange(_enCurrenceis Currencies)
	{
		switch (Currencies)
		{
		case Cls_CurrencyExchange::List_Currencies:
			_ListCurrencies();
			GoBackToCurrency_Exchange();
			break;
		case Cls_CurrencyExchange::Find_Currencey:
			_FindCurrencey();
			GoBackToCurrency_Exchange();
			break;
		case Cls_CurrencyExchange::Update_Rate:
			_UpdateRate();
			GoBackToCurrency_Exchange();
			break;
		case Cls_CurrencyExchange::Currency_Calculator:
			_CurrencyCalculator();
			GoBackToCurrency_Exchange();
			break;
		case Cls_CurrencyExchange::Main_Minue:
			_Main_Minue();
			break;
		default:
			break;
		}
	}

//protected:

public:

	static void Currency_Exchange()
	{
		system("cls");
		HeaderSecreen("Currency Exchange Main Screen",2);
		cout << Tabs(51, "=") << endl;
		cout << Tabs(14," ") << "Currency Exchange Menue" << endl;
		cout << Tabs(51, "=") << endl;
		printf(" [1] : List Currencies.\n");
		printf(" [2] : Find Currencey.\n");
		printf(" [3] : Update Rate.\n");
		printf(" [4] : Currency Calculator.\n");
		printf(" [5] : Main Minue.\n");
		cout << Tabs(51, "=") << endl;
		Switch_Currency_Exchange(Cls_CurrencyExchange::_ReadNumberToUsser(1, 5));
	}

	static void GoBackToCurrency_Exchange()
	{
		system("pause");
		Currency_Exchange();
	}
};

