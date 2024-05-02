#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"

using namespace std;


class Cls_CurrencyCalculator : protected Cls_HeaderScreen
{
private:

	static void _Print_Currency_Card(Cls_Currencie Currency)
	{
		cout << "\n\n Currncey Card ;-) : " << endl;
		cout << Tabs(25, "_") << Endl(1);
		cout << " Country : " << Currency.GetCountry() << endl;
		cout << " Code    : " << Currency.GetCurrencyCoud() << endl;
		cout << " Name    : " << Currency.GetCurrencyName() << endl;
		cout << " Rate($) : " << Currency.GetRate() << endl;
		cout << Tabs(25, "_") << Endl(1);
	}

protected:
public:

	static void Currency_Calculator()
	{
		system("cls");
		HeaderSecreen("Currency Calculator Screen",7);
		string CurrencyCalculator1 = "", CurrencyCalculator2 = "";

		//============== Object One ==============//
		cout << " Please Enter Currency 1 Code : ";
		getline(cin >> ws, CurrencyCalculator1);
		Cls_Currencie Currency1 = Cls_Currencie::FindCod(CurrencyCalculator1);
		while (Currency1.IsEmpty())
		{
			cout << " There Is Not CurrencyCode With This Name \n";
			cout << " Please Enter Currency 1 Code : ";
			getline(cin >> ws, CurrencyCalculator1);
			Currency1 = Cls_Currencie::FindCod(CurrencyCalculator1);
		}

		//============== Object Tow ==============//
		cout << "\n\n\n Please Enter Currency 2 Code : ";
		getline(cin >> ws, CurrencyCalculator2);
		Cls_Currencie Currency2 = Cls_Currencie::FindCod(CurrencyCalculator2);
		while (Currency2.IsEmpty())
		{
			cout << " There Is Not CurrencyCode With This Name \n";
			cout << " Please Enter 2 CurrencyCode : ";
			getline(cin >> ws, CurrencyCalculator2);
			Currency2 = Cls_Currencie::FindCod(CurrencyCalculator2);
		}

		float Amount = 0, Total = 0;
		cout << "\n Please Enter Amount To Exchange : "; cin >> Amount;

		cout << "\n\n Convert From : ";
		//======= Print Object One =======//
		_Print_Currency_Card(Currency1);

		Total = Cls_Currencie::Convert_Currency(Amount, Currency1, Currency2);

		cout << Endl(2) << Tabs(21,"=") << endl;
		cout << Amount << " " << Currency1.GetCurrencyCoud() << " = "
			<< Total << " " << Currency2.GetCurrencyCoud();
		cout << Endl(1) << Tabs(21, "=") << Endl(2);
	}
};


