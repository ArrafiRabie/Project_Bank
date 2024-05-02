#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"CLs_String.h"
#include"Cls_Currencie.h"
#include"CLs_Utility.h"

using namespace std;


class Cls_FindCurrencey : public Cls_HeaderScreen
{
private:

	static void _Print_Currency_Card(Cls_Currencie Currency)
	{
		cout << "\n\n Currncey Card ;-) : " << endl;
		cout << Tabs(25,"_")  << Endl(1);
		cout << " Country : " << Currency.GetCountry() << endl;
		cout << " Code    : " << Currency.GetCurrencyCoud()<< endl;
		cout << " Name    : " << Currency.GetCurrencyName()<< endl;
		cout << " Rate($) : " << Currency.GetRate() << endl;
		cout << Tabs(25, "_") << Endl(1);
	}
	

//protected:

public:

	static void Find_Currencey()
	{
		system("cls");
		HeaderSecreen("Find Currency Screen",9);
		short Number = 0;
		cout << " Find By : [1] -> Code / [2] -> Country ? : "; cin >> Number;
		
		if (Number == 1)
		{
			string CurrencyCode = "";
			cout << " Please Enter CurrencyCode : ";
			getline(cin>> ws,CurrencyCode);

			Cls_Currencie Currency = Cls_Currencie::FindCod(CurrencyCode);

			while (Currency.IsEmpty())
			{
				cout << " There Is Not CurrencyCode With This Name \n";
				cout << " Please Enter CurrencyCode : ";
				getline(cin >> ws, CurrencyCode);
				Currency = Cls_Currencie::FindCod(CurrencyCode);
			}

			_Print_Currency_Card(Currency);
		}

		else if (Number == 2)
		{
			string  Country = "";
			cout << " Please Enter Country : ";
			getline(cin >> ws, Country);

			Cls_Currencie COUNTRY = Cls_Currencie::FindCountry(Country);


			while (COUNTRY.IsEmpty())
			{
				cout << " There Is Not Country With This Name \n";
				cout << " Please Enter Country : ";
				getline(cin >> ws, Country);
				COUNTRY = Cls_Currencie::FindCountry(Country);
			}

			_Print_Currency_Card(COUNTRY);
		}
	}

};

