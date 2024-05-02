#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Usser.h"

using namespace std;


class Cls_FindUsser : protected Cls_HeaderScreen
{
private:

	static void _Print(Cls_Bank_Usser& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName     : " << Client.FristName;
		cout << "\nLastName      : " << Client.LastName;
		cout << "\nFull Name     : " << Client.GetFullName();
		cout << "\nEmail         : " << Client.Email;
		cout << "\nPhone         : " << Client.Phone;
		cout << "\nUsserName     : " << Client.UsserName;
		cout << "\nPassword      : " << Client.PinCoude;
		cout << "\nPermission    : " << Client.Permission;
		cout << "\n___________________\n";
	}

//protected:


public:

	static void FindUsser()
	{
		system("cls");
		Cls_Bank_Usser Usser, TT;

		string ReadUsserName = "";
		HeaderSecreen("Find Usser Screen", 8);
		printf("Please Enter A UsserName : "); getline(cin >> ws, ReadUsserName);
		while (!Usser.IsUsserExit(ReadUsserName))
		{
			cout << " Usser Is Not Found, Choose Another One : "; getline(cin >> ws, ReadUsserName);
		}
		_Print(Usser);
	}
};

