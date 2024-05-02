#pragma once
#include<iostream>
#include"Cls_HeaderScreen.h"
#include"Cls_Show_Cleint_List.h"
#include"Cls_Add_New_Client.h"
#include"Cls_DeleteClient.h"
#include"CLs_UpdateClient.h"
#include"Cls_Find_Client.h"
#include"CLs_Transactions.h"
#include"Cls_ManageUsser.h"
#include"CLs_Utility.h"
#include"Cls_CurrencyExchange.h"

#include<fstream>
#include <ctime>
#include"Cls_Date.h"


using namespace std;

class Cls_MaineScreen : protected Cls_HeaderScreen
{
private:

	string _UsserName = "";
	string _Password = "";
	short  _BalanceUsser;

	enum _en_Switch_Project
	{
		Show_Cleint_List   = 1,
		Add_New_Client     = 2,
		Delet_Client       = 3,
		Update_Client_Info = 4,
		Find_Client        = 5,
		Transactions       = 6,
		Manage_Usser       = 7,
		CurrnceyEChange    = 8,
		Logout             = 9,
	};

	static short _Read_Number_MaineSecreen(short From, short TO)
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


	enum _enPermissions
	{
		All = -1,
		List = 1,
		Add = 2,
		Delet = 4,
		Update = 8,
		Finde = 16,
		Transaction = 32,
		Manage_User = 64,
	};

	bool _CheckPermission(_enPermissions Type)
	{
		if (this->_BalanceUsser == _enPermissions::All)
			return  true;

			if ((Type & this->_BalanceUsser) == Type)
			return  true;

			else
				return false;
	}

	void _Show_Cleint_List()
	{
		if (_CheckPermission(_enPermissions::List) == true)
			Cls_Show_Cleint_List::Show_Cleint_List();
		else
			HeaderSecreen("Access Denied! Contact Your Admine",1);
	}
	void _Add_New_Client()
	{
		if (_CheckPermission(_enPermissions::Add) == true)
			Cls_Add_New_Client::AddNewClient();
		else
			HeaderSecreen("Access Denied! Contact Your Admine", 1);
	}
	void _Delet_Client()
	{
		if (_CheckPermission(_enPermissions::Delet) == true)
			Cls_DeleteClient::DeleteClient();
		else
			HeaderSecreen("Access Denied! Contact Your Admine", 1);
		//Cls_DeleteClient::DeleteClient();
	}
	void _Update_Client_Info()
	{
		if (_CheckPermission(_enPermissions::Update) == true)
			CLs_UpdateClient::UpdateClien();
		else
			HeaderSecreen("Access Denied! Contact Your Admine", 1);
		//CLs_UpdateClient::UpdateClien();
	}
	void _Find_Client()
	{
		if (_CheckPermission(_enPermissions::Finde) == true)
			Cls_Find_Client::FindClient();
		else
			HeaderSecreen("Access Denied! Contact Your Admine", 1);
	}
	void _Transactions()
	{
		if (_CheckPermission(_enPermissions::Transaction) == true)
			CLs_Transactions::Transaction();
		else
			HeaderSecreen("Access Denied! Contact Your Admine", 1);
		//CLs_Transactions::Transaction();
	}
	void _Manage_Usser()
	{
		if (_CheckPermission(_enPermissions::Manage_User) == true)
			Cls_ManageUsser::MaineManageUsserSecreen();
		else
			HeaderSecreen("Access Denied! Contact Your Admine", 1);
		//Cls_ManageUsser::MaineManageUsserSecreen();
	}
	void _CurrencyExchange()
	{
		Cls_CurrencyExchange::Currency_Exchange();
	}
	void _Logout()
	{
		Cls_Bank_Client CLient = CLient.Find("", "", "");
		//LockerScreen();
	}

	void _Switch_Project(_en_Switch_Project Project)
	{
		switch (Project)   //Project
		{
		case Cls_MaineScreen::Show_Cleint_List:
			_Show_Cleint_List();
			GoBackToMainMenue();
			break;
		case Cls_MaineScreen::Add_New_Client:
			_Add_New_Client();
			GoBackToMainMenue();
			break;
		case Cls_MaineScreen::Delet_Client:
			_Delet_Client();
			GoBackToMainMenue();
			break;
		case Cls_MaineScreen::Update_Client_Info:
			_Update_Client_Info();
			GoBackToMainMenue();
			break;
		case Cls_MaineScreen::Find_Client:
			_Find_Client();
			GoBackToMainMenue();
			break;
		case Cls_MaineScreen::Transactions:
			_Transactions();
			//MaineSecreen();
			GoBackToMainMenue();
			break;
		case Cls_MaineScreen::Manage_Usser:
			_Manage_Usser();
			GoBackToMainMenue();
			break;
		case Cls_MaineScreen::CurrnceyEChange:
			_CurrencyExchange();
			GoBackToMainMenue();
			break;
		case Cls_MaineScreen::Logout:
			system("cls");
			_Logout();
			//GoBackToMainMenue();
			break;
		default:
			break;
		}
	}


	void Record_The_Name_Of_The_User_Who_Logged_Into_The_System(string Message)
	{
		Cls_Date Date;
		string NameFileToRecorde = "UserSystem.txt";
		fstream MYFILE;
		MYFILE.open(NameFileToRecorde, ios::out | ios::app | ios::in);
		if (MYFILE.is_open())
		{
			MYFILE << Cls_Date::GetSystemDateTimeString();
			MYFILE << Message << endl;
			MYFILE.close();
		}
	}

	string Test(string UsserName, string Password, short Permission)
	{
		string RecordLine = "";
		Cls_Date Date;

		//// Start Update Coud...
		////short  _EncrayptionKey = 7;
		//string _Encrayption = "";
		//_Encrayption = Cls_Utility::Encrayption(Password);
		//// End Update Coud...

		RecordLine += "#/#";
		RecordLine += UsserName;
		RecordLine += "#/#";
		RecordLine += Password;
		//RecordLine += _Encrayption;
		RecordLine += "#/#";
		RecordLine += to_string(Permission);

		return RecordLine;
	}

	string _UpdatePasswordeUsser(string Passworde)
	{
		string DncrayptionKey = "";
		DncrayptionKey = Cls_Utility::Encrayption(Passworde);
		return DncrayptionKey;
	}

	//static short Counter;

	void _ShowLogenSecreen()
	{
		Cls_MaineScreen Pas;
		Cls_Bank_Client CLient;

		HeaderSecreen("LoginScreen", 12);
		string User_Pas = "";
		cout << " Please Enter UsserName : "; getline(cin >> ws, Pas._UsserName);
		cout << " Please Enter Password  : "; getline(cin >> ws, Pas._Password);

		string DncrayptionKey = "";
		DncrayptionKey = _UpdatePasswordeUsser(Pas._Password);
		CLient = CLient.Find(Pas._UsserName, DncrayptionKey, "Usser.Txt");

		while (CLient.GetPinCoude() == "" && Counter != 1) 
		{
			system("Cls");
			HeaderSecreen("LoginScreen", 12);
			printf("Invalide UsserName/Password\n");

			//==================
			Counter--;
			cout << " You Have " << Counter << "Trials To Login " << Endl(2);
			//==================

			cout << " Please Enter UsserName : "; getline(cin >> ws, Pas._UsserName);
			cout << " Please Enter Password  : "; getline(cin >> ws, Pas._Password);
			DncrayptionKey = _UpdatePasswordeUsser(Pas._Password);
			CLient = CLient.Find(Pas._UsserName, DncrayptionKey, "Usser.Txt");
		}

		if (Counter == 1)
		{
			cout << Endl(2); printf("Invalide UsserName/Password\n");
			Counter--;
			cout << " You Have " << Counter << "Trials To Login " << Endl(2);
			cout << " Your Are Locked After " << 3 << " Failde Trails " << endl;
			return;
		}

		Cls_HeaderScreen::SetUsserName(CLient.FristName);

		_BalanceUsser = CLient.AccountBalance;

		//Test(CLient.FristName, CLient.PinCoude, CLient.AccountBalance);
		Record_The_Name_Of_The_User_Who_Logged_Into_The_System(Test(CLient.FristName, CLient.PinCoude, CLient.AccountBalance));

		MaineSecreen();
	}





//protected:
public:

	static short Counter ;

	void ShowLogenSecreen()
	{
		_ShowLogenSecreen();
	}

	//====================================

	void MaineSecreen()
	{
		Cls_MaineScreen T;


		string Message = "Main Screen";
		Cls_MaineScreen::HeaderSecreen(Message,12);
		system("Color 7");;
		cout << Cls_MaineScreen::Tabs(36, "=") << endl;
		printf("\tMain Menue Screen\t\n");
		cout << Cls_MaineScreen::Tabs(36, "=") << endl;
		cout << " [1] : Show Cleint List.\n";
		cout << " [2] : Add New Client.\n";
		cout << " [3] : Delet Client.\n";
		cout << " [4] : Update Client Info.\n";
		cout << " [5] : Find Client.\n";
		cout << " [6] : Transactions.\n";
		cout << " [7] : Manage Usser.\n";
		// Update...
		cout << " [8] : Currency Exchange.\n";

		cout << " [9] : Logout.\n";
		cout << Cls_MaineScreen::Tabs(36, "=") << endl;
		_Switch_Project(_en_Switch_Project(Cls_MaineScreen::_Read_Number_MaineSecreen(1, 9)));
	}
	void GoBackToMainMenue()
	{
		system("pause");
		MaineSecreen();
	}
};

short Cls_MaineScreen::Counter = 3;