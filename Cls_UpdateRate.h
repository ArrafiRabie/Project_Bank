#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"

using namespace std;


class Cls_UpdateRate : protected Cls_HeaderScreen
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

//protected:

public:

	static void Update_Rate()
	{
		system("cls");
		HeaderSecreen("Update Currency Screen",9);
		string CurrencyCode = "";
		cout << "Please Enter Currency Code : ";
		getline(cin >> ws, CurrencyCode);

		Cls_Currencie Currency = Cls_Currencie::FindCod(CurrencyCode);

		while (Currency.IsEmpty())
		{
			cout << " There Is Not CurrencyCode With This Name \n";
			cout << " Please Enter CurrencyCode : ";
			getline(cin >> ws, CurrencyCode);
			Currency = Cls_Currencie::FindCod(CurrencyCode);
		}

		_Print_Currency_Card(Currency);
		char Chek = 'n';
		cout << "\n Are You Sure You Want To Update The Rete Of This Currency [Y/N] ? : ";
		cin >> Chek;

		if (Chek == 'Y' || Chek == 'y')
		{
			float NewRate = 0;
			cout << "\n\n Update Currency Rate : \n";
			cout << Tabs(23,"_") << Endl(2);

			cout << " Please Enter New Rate: ";
			cin >> NewRate;
			//Currency.SetRate(NewRate);
			Currency._Update(CurrencyCode,NewRate);
			cout << " Ceccessuflly :-) " << endl;
			Currency = Cls_Currencie::FindCod(CurrencyCode);
			_Print_Currency_Card(Currency);
		}





	}
};

