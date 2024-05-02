#pragma once
#include<iostream>
#include"Cls_HeaderScreen.h"
#include"Cls_Currencie.h"

using namespace std;

class Cls_List_Currencies : protected Cls_HeaderScreen
{
private:

	static void _PrintCurency(Cls_Currencie Currency)
	{
		cout << setw(30) << left << Currency.GetCountry(); //update...
		cout << left << setw(21) << Currency.GetCurrencyCoud(); //update...
		cout << left << setw(49) << Currency.GetCurrencyName(); //update...
		cout << left << setw(13) << Currency.GetRate(); //update...
		cout << Endl(1) << Tabs(121, "~") << Endl(1);
	}

//protected:

public:


	void static HeaderTabel()
	{
		cout << Endl(1) << Tabs(121, "=") << Endl(1);
		cout << left << setw(30) << "Country";
		cout << left << setw(21) << "Code";
		cout << left << setw(49) << "Name";
		cout << left << setw(13) << "Rate/(1$)";
		cout << Endl(1) << Tabs(121, "=") << Endl(1);
	}


	static void ListCurrencies()
	{
		system("cls");
		vector <Cls_Currencie> vR;
		vR = Cls_Currencie::Read_Data_To_Frome_File();

		string Message = "";
		Message = "Currencies List Screen (" + to_string(vR.size()) + ") Currency";
		HeaderSecreen(Message,1);

		HeaderTabel();

		for (Cls_Currencie& Str : vR)
		{
			_PrintCurency(Str);
		}
	}
};

