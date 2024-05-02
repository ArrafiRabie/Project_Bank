#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Usser.h"


using namespace std;

class cLs_UpdateUsser : protected Cls_HeaderScreen
{
private:

	enum _enPermissions
	{
		All = -1,
		List = 1,
		Add = 2,
		Delet = 4,
		Update = 8,
		Find = 16,
		Transaction = 32,
		Manage_User = 64,
	};

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

protected:

public:


	static void ReadUpdateData(Cls_Bank_Usser& Client)
	{
		string Read;
		cout << Endl(2) << Tabs(27, "~") << Endl(1);
		cout << " Plaes Enter Update To Data " << Endl(1);
		cout << Tabs(27, "~") << Endl(2);
		cout << "Please Enter UsserName        : ";
		getline(cin >> ws, Read); Client.SetUsserName(Read);
		cout << "Please Enter Email            : ";
		getline(cin >> ws, Read); Client.SetEmail(Read);
		cout << " Do You Want To Give Full Access [Y/N] ? : ";
		char Access = 'n'; cin >> Access;
		short Permission = 0;
		if (Access == 'Y' || Access == 'y')
		{
			Permission += _enPermissions::All;
			Client.SetPermission(Permission);
		}
		else
		{
			cout << " Do You Want To Give Access To : " << endl << "\n";
			cout << " Shoe Client List [Y/N] ? : "; cin >> Access;
			if (Access == 'Y' || Access == 'y')
			{
				Permission += _enPermissions::List;
			}
			cout << " Add New Client [Y/N] ?   : "; cin >> Access;
			if (Access == 'Y' || Access == 'y')
			{
				Permission += _enPermissions::Add;
			}
			cout << " Delet Client [Y/N] ?     : "; cin >> Access;
			if (Access == 'Y' || Access == 'y')
			{
				Permission += _enPermissions::Delet;
			}
			cout << " UpdateClient [Y/N] ?     : "; cin >> Access;
			if (Access == 'Y' || Access == 'y')
			{
				Permission += _enPermissions::Update;
			}
			cout << " Find Client [Y/N] ?      : "; cin >> Access;
			if (Access == 'Y' || Access == 'y')
			{
				Permission += _enPermissions::Find;
			}
			cout << " Transaction [Y/N] ?      : "; cin >> Access;
			if (Access == 'Y' || Access == 'y')
			{
				Permission += _enPermissions::Transaction;
			}
			cout << " Manage Usser [Y/N] ?     : "; cin >> Access;
			if (Access == 'Y' || Access == 'y')
			{
				Permission += _enPermissions::Manage_User;
			}
			if (Permission == 127)
			{
				Permission = _enPermissions::All;
			}

			Client.SetPermission(Permission);
		}
	}

	static  void UpdateUsser()
	{
		system("cls");
		Cls_Bank_Usser Usser;

		HeaderSecreen("Update Usser Screen", 8);
		string ReadData = "";
		cout << " Please Enter UsserName "; getline(cin >> ws, ReadData);
		while (!Usser.IsUsserExit(ReadData))
		{
			cout << " Usser Is Not Found, Choose Another One : "; getline(cin >> ws, ReadData);
		}

		//Usser.IsUsserExit(ReadData);
		_Print(Usser);

		ReadUpdateData(Usser);
		_Print(Usser);

		//====================
		// Update...

		char CheckDelete = 'n';
		printf("Are You Sure You Want To Delete This Client ?  : ");
		cin >> CheckDelete;

		if (CheckDelete == 'Y' || CheckDelete == 'y')
		{
			Usser.UPdateUsserTOFile(ReadData);
			printf("Usser Delete Successfully :-) \n");
		}
	}
};

