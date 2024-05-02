#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Cls_HeaderScreen.h"
#include"Cls_ListUsser.h"
#include"Cls_AddNewUsser.h"
#include"Cls_DeletUsser.h"
#include"cLs_UpdateUsser.h"
#include"Cls_FindUsser.h"
#include"Cls_LoginRogister.h"

using namespace std;


class Cls_ManageUsser : protected Cls_HeaderScreen
{
private:

	enum _enNameMethodScreen
	{
		List_Usser    = 1,
		Add_New_Usser = 2,
		Delet_sser    = 3,
		Update_Usser  = 4,
		Find_Usser    = 5,
		LognRogister  = 6,
		Main_Menue    = 7,
	};

	static short ReadNumberInScreen(short Frome, short TO)
	{
		short NumberScreen = 0;
		cout << " Choose What Do You Want To Do [" << Frome << " To " << TO << "] ? : ";
		cin >> NumberScreen;
		//<><><> Validete <><><>//
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			cout << "\t\t Invalid Number, Enter A Valid One: " << endl;
			printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			cout << "\t\t"; cin >> NumberScreen;
			cin.ignore(1, '\n');
		}
		//<><><><><><><><><><><>//
		while (NumberScreen > TO || NumberScreen < Frome)
		{
			printf("\n\t\t<><><><><><><><><><><><><><><><>\n");
			printf("\t\t Please Enter The Required Number \n");
			printf("\t\t<><><><><><><><><><><><><><><><>\n");
			printf("\t\tChoose What Do You Want To Do ? [1 To 8] ? : ");
			cin >> NumberScreen;
			//=== Validete ===//
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				cout << "\t\t Invalid Number, Enter A Valid One: " << endl;
				printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				cout << "\t\t"; cin >> NumberScreen;
				cin.ignore(1, '\n');
			}
			//===============//
		}
		return NumberScreen;
	}


	static void _ListUsser()
	{
		Cls_ListUsser::ListUsser();
	}
	static void _AddNewUsser()
	{
		Cls_AddNewUsser::AddNewUsser();
	}
	static void _DeletUsser()
	{
		Cls_DeletUsser::DeletUsser();
	}
	static void _UpdateUsser()
	{
		cLs_UpdateUsser::UpdateUsser();
	}
	static void _FindUsser()
	{
		Cls_FindUsser::FindUsser();
	}
	static void _LoginRogister()
	{
		Cls_LoginRogister::LoginRogiister();
	}
	static void _MainMenue()
	{

	}


	static void _SwitchMaineManageUsserSecreen(_enNameMethodScreen NameMethod)
	{
		switch (NameMethod)
		{
		case Cls_ManageUsser::List_Usser:
			_ListUsser();
			GoBackToMaineManageUsserSecreen();
			break;
		case Cls_ManageUsser::Add_New_Usser:
			_AddNewUsser();
			GoBackToMaineManageUsserSecreen();
			break;
		case Cls_ManageUsser::Delet_sser:
			_DeletUsser();
			GoBackToMaineManageUsserSecreen();
			break;
		case Cls_ManageUsser::Update_Usser:
			_UpdateUsser();
			GoBackToMaineManageUsserSecreen();
			break;
		case Cls_ManageUsser::Find_Usser:
			_FindUsser();
			GoBackToMaineManageUsserSecreen();
			break;
		case Cls_ManageUsser::LognRogister: // Update Check Errour...
			_LoginRogister();
			GoBackToMaineManageUsserSecreen();
			break;
		case Cls_ManageUsser::Main_Menue:
			_MainMenue(); 
			break;
		default:
			break;
		}
	}


protected:

public:

	static void MaineManageUsserSecreen()
	{
		string Message = "Manage Usser Screen";
		HeaderSecreen(Message, 8);
		system("Color 7");
		cout << Tabs(36, "=") << endl;
		printf("\tManage Usser Menue \t\n");
		cout << Tabs(36, "=") << endl;
		cout << " [1] : List Usser.\n";
		cout << " [2] : Add New Usser.\n";
		cout << " [3] : Delet Usser.\n";
		cout << " [4] : Update Usser.\n";
		cout << " [5] : Find Usser.\n";
		cout << " [6] : Login Rogister.\n";
		cout << " [7] : Main Menue.\n"; //Update..... Number TO 6

		cout << Tabs(36, "=") << endl;
		_SwitchMaineManageUsserSecreen(_enNameMethodScreen(ReadNumberInScreen(1,7)));
	}

	static void GoBackToMaineManageUsserSecreen()
	{
		system("pause");
		MaineManageUsserSecreen();
	}

};

