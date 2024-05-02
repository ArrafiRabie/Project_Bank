#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Usser.h"

using namespace std;

class Cls_DeletUsser : protected Cls_HeaderScreen
{
private:

	static void _print(Cls_Bank_Usser& Usser)
	{
		cout << "\n Usser Card:";
		cout << "\n___________________";
		cout << "\nFirstName      : " << Usser.FristName;
		cout << "\nLastName       : " << Usser.LastName;
		cout << "\nFull Name      : " << Usser.GetFullName();
		cout << "\nEmail          : " << Usser.Email;
		cout << "\nPhone          : " << Usser.Phone;
		cout << "\nUsserName      : " << Usser.UsserName;
		cout << "\nPassword       : " << Usser.PinCoude;
		cout << "\nPermission     : " << Usser.Permission;
		cout << "\n___________________\n";
	}

protected:

public:

	static void DeletUsser()
	{
		system("cls");
		HeaderSecreen("Delet Usser Screen",8);
		Cls_Bank_Usser Usser;
		string ReadUsserName = "";
		printf(" Please Enter UsserName : "); getline(cin >> ws, ReadUsserName);
		while (!Usser.IsUsserExit(ReadUsserName))
		{
			cout << " Usser Is Not Found, Choose Another One : ";
			getline(cin >> ws, ReadUsserName);
		}
		_print(Usser);

		char CheckDelete = 'n';
		printf("Are You Sure You Want To Delete This Client ?  : ");
		cin >> CheckDelete;

		if (CheckDelete == 'Y' || CheckDelete == 'y')
		{
			Cls_Bank_Usser::DeleteUsserToFile(ReadUsserName);
			printf("Usser Delete Successfully :-) \n");
			Usser.IsUsserExit(ReadUsserName);
			_print(Usser);
		}
	}
};