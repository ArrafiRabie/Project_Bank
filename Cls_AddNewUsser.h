#pragma once
#include<iostream>
#include<string>
#include"Cls_HeaderScreen.h"
#include"Cls_Bank_Usser.h"
#include"CLs_Utility.h"

using namespace std;

class Cls_AddNewUsser : protected Cls_HeaderScreen
{
private:

	enum _enPermissions
	{
		All         = -1,
		List        = 1,
		Add         = 2,
		Delet       = 4,
		Update      = 8,
		Find        = 16,
		Transaction = 32,
		Manage_User = 64,
	};

	static void _printE(Cls_Bank_Usser& USSER)
	{
		cout << "\n Usser Card:";
		cout << "\n___________________";
		cout << "\nFirstName      : " << USSER.FristName;
		cout << "\nLastName       : " << USSER.LastName;
		cout << "\nFull Name      : " << USSER.GetFullName();
		cout << "\nEmail          : " << USSER.Email;
		cout << "\nPhone          : " << USSER.Phone;
		cout << "\nUsserName      : " << USSER.UsserName;
		cout << "\nPassword       : " << USSER.PinCoude;
		cout << "\nPermission     : " << USSER.Permission;
		cout << "\n___________________\n";
	}

	static void _AddNewUsser(Cls_Bank_Usser& Usser)
	{
		string ReasDataInUsser = "";
		cout << " Please Enter UsserName : "; getline(cin >> ws, ReasDataInUsser);
		while (Usser.IsUsserExit(ReasDataInUsser))
		{
			cout << " Usser Is Not Found, Choose Another One : " ; getline(cin >> ws, ReasDataInUsser);
		}
		Usser.SetUsserName(ReasDataInUsser);
		cout << " Please Enter FristName : "; getline(cin >> ws, ReasDataInUsser);
		Usser.SetFristName(ReasDataInUsser);
		cout << " Please Enter LastName : "; getline(cin >> ws, ReasDataInUsser);
		Usser.SetLastName(ReasDataInUsser);
		cout << " Please Enter Email : "; getline(cin >> ws, ReasDataInUsser);
		Usser.SetEmail(ReasDataInUsser); 
		cout << " Please Enter Phone : "; getline(cin >> ws, ReasDataInUsser);
		Usser.SetPhone(ReasDataInUsser);
		// Start Update Coud...
		cout << " Please Enter Password : "; getline(cin >> ws, ReasDataInUsser);
		//short  _EncrayptionKey = 7;
		string _Encrayption    = "";
		_Encrayption = Cls_Utility::Encrayption(ReasDataInUsser);
		Usser.SetPinCoude(_Encrayption);
		// End Update Coud...
		cout << " Do You Want To Give Full Access [Y/N] ? : ";
		char Access = 'n'; cin >> Access;
		short Permission = 0;
		if (Access == 'Y' || Access == 'y')
		{
			Permission += _enPermissions::All;
			Usser.SetPermission(Permission);
			_printE(Usser);
		}
		else
		{
			cout << " Do You Want To Give Access To : " << endl<<"\n";
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

			Usser.SetPermission(Permission);

			_printE(Usser);
		}
	}

//protected:

public:

	/*_enPermissions Per;*/

	static void AddNewUsser()
	{
		Cls_Bank_Usser Usser;
		system("cls");
        HeaderSecreen("Add New Usser Screen", 5);
		_AddNewUsser(Usser);
		Cls_Bank_Usser::RecordUsserToFile(Usser);
	}

};