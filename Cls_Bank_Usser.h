#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"CLs_String.h"
#include"Cls_Bank_Client.h"

using namespace std;

// Base Clase 
class Cls_Bank_Usser : public Cls_Bank_Client
{
private:

	enum enMode
	{
		EmptyMode  = 1,
		UpdateMode = 2,
		AddNewMode = 3,
	};

	enMode _Mode;

	string  _NameFile = "Usser.Txt";
	fstream _MYFILe;
	string _FrindtName = "";
	string _LastName = "";
	string _Email = "";
	string _Phone = "";
	string _PinCoude = "";
	string _UsserName  = "";
	short  _Permission = 0;

	static vector<string> _Read_data_To_File()
	{
		Cls_Bank_Usser Usser;
		vector<string>vRead;
		string Line = "";


		vector<string>vR;


		Usser._MYFILe.open(Usser._NameFile, ios::out | ios::app | ios::in);
		if (Usser._MYFILe.is_open())
		{
			while (getline(Usser._MYFILe, Line))
			{
				vRead = Split(Line,"#/#");

				Usser.SetUsserName(vRead[0]);
				vR.push_back(Usser.GetUsserName());
				Usser.SetFristName(vRead[1]);
				Usser.SetLastName(vRead[2]);
				vR.push_back(Usser.GetFristName() + " " + Usser.GetLastName());
				Usser.SetPhone(vRead[3]);
				vR.push_back(Usser.GetPhone());
				Usser.SetEmail(vRead[4]);
				vR.push_back(Usser.GetEmail());
				Usser.SetPinCoude(vRead[5]);
				vR.push_back(Usser.GetPinCoude());
				Usser.SetPermission(stof(vRead[6]));
				vR.push_back(to_string(Usser.GetPermission()));
			}

			Usser._MYFILe.close();
		}

		return vR;

	}

	static Cls_Bank_Usser _CheckUsserNameTOUsser(string& UserName)
	{
		Cls_Bank_Usser Usser;
		vector<string>vRead;
		string Line = "";

		short A = 0;
		fstream MYFILe;

		MYFILe.open("Usser.Txt", ios::out | ios::app | ios::in);
		if (MYFILe.is_open())
		{
			while (getline(MYFILe, Line))
			{
				vRead = vRead = Split(Line, "#/#");
				A++;
				if (vRead[0] == UserName)
				{
					MYFILe.close();
					return Cls_Bank_Usser(vRead[0], vRead[1], vRead[2], vRead[3], vRead[4],vRead[5], stod(vRead[6]), enMode::UpdateMode);
				}

				for (short i = vRead.size(); i < 0; i--)
				{
					vRead.pop_back();
				}
			}
			MYFILe.close();
		}

		return Cls_Bank_Usser("", "", "", "", "", "", 0, enMode::EmptyMode);
	}

	string UpdateLineToRicorde()
	{
		string Line = "";

		Line += GetUsserName();
		Line += "#/#";
		Line += GetFristName(); 
		Line += "#/#";
		Line += GetLastName();
		Line += "#/#";
		Line += GetPhone();
		Line += "#/#";
		Line += GetEmail();
		Line += "#/#";
		Line += GetPinCoude();
		Line += "#/#";
		Line += to_string(GetPermission());

		return Line;
	}

	static void _RecordUsserToFile(Cls_Bank_Usser& Usser)
	{
		Usser._MYFILe.open(Usser._NameFile, ios::out | ios::app | ios::in);
		if (Usser._MYFILe.is_open())
		{
			Usser._MYFILe << Usser.UpdateLineToRicorde() << endl;

			Usser._MYFILe.close();
		}
	}

	static vector<string> _DeleteUsserToFile(string& UserName)
	{
		Cls_Bank_Usser Usser;
		vector<string>vReadData;
		vector<string>vR;
		string Line = "";

		Usser._MYFILe.open(Usser._NameFile, ios::out | ios::app | ios::in);
		if (Usser._MYFILe.is_open())
		{
			while (getline(Usser._MYFILe,Line))
			{
				vReadData = Split(Line,"#/#");
				if (vReadData[0] == UserName)
				{
					// No Read...
				}
				else if (vReadData[0] != UserName)
				{
					vR.push_back(Line);
				}
			}

			Usser._MYFILe.close();
		}

		Usser._MYFILe.open(Usser._NameFile, ios::out);

		if (Usser._MYFILe.is_open())
		{
			for (string& Str : vR)
			{
				Usser._MYFILe << Str << endl;
			}

			Usser._MYFILe.close();
		}

		return vR;
	}

	//======================================
	void _UpdateUsserToFile(string UsserName)
	{
		Cls_Bank_Usser Usser;
		vector<string>vReadData;
		vector<string>vR;
		string Line = "";

		Usser._MYFILe.open(Usser._NameFile, ios::out | ios::app | ios::in);
		if (Usser._MYFILe.is_open())
		{
			while (getline(Usser._MYFILe, Line))
			{
				vReadData = Split(Line, "#/#");

				if (vReadData[0] == UsserName)
				{
					UpdateLineToRicorde();
					vR.push_back(UpdateLineToRicorde());

					/*vR.push_back(_UsserName);
					vR.push_back(_FrindtName);
					vR.push_back(_LastName);
					vR.push_back(_Email);
					vR.push_back(_Phone);
					vR.push_back(_PinCoude);
					vR.push_back(to_string(_Permission));*/
				}
				else if (vReadData[0] != UsserName)
				{
					vR.push_back(Line);
				}
			}

			Usser._MYFILe.close();
		}

		Usser._MYFILe.open(Usser._NameFile, ios::out);
		if (Usser._MYFILe.is_open())
		{

			for (string& Str : vR)
			{
				Usser._MYFILe << Str << endl;
			}

			Usser._MYFILe.close();
		}


	}
	//======================================


//protected:

public:

	Cls_Bank_Usser()
	{

	}

	Cls_Bank_Usser(string UsserName, string FrinstName, string LastName, string Phone,
		string Email, string Password, short Permission, enMode Mod)
	: Cls_Bank_Client(FrinstName, LastName, Phone,
			Email, UsserName, Password, Permission, Mode)
	{
		_FrindtName = FrinstName;
		_LastName   = LastName;
		_Phone      = Phone;
		_Email      = Email;
		_UsserName  = UsserName;
		_PinCoude   = Password;
		_Permission = Permission;
		_Mode       = Mod;
	}

	// Property Set
	void SetUsserName(string UsserName)
	{
		_UsserName = UsserName;
	}
	// Property Get
	string GetUsserName()
	{
		return _UsserName;
	}
	__declspec(property(get = GetUsserName, put = SetUsserName))string UsserName;

	// Property Set
	void SetPermission(float Permission)
	{
		_Permission = Permission;
	}
	// Property Get
	short GetPermission()
	{
		return _Permission;
	}
	__declspec(property(get = GetPermission, put = SetPermission))short Permission;

	static vector<string> Read_data_To_File()
	{
		return _Read_data_To_File();
	}
	
	bool IsUsserExit(string& UserName)
	{
		*this = _CheckUsserNameTOUsser(UserName);

		if (this->_Mode == enMode::UpdateMode)
		{
			return true;
		}
		else if (this->_Mode == enMode::EmptyMode)
		{
			return false;
		}
		
	}

	static void RecordUsserToFile(Cls_Bank_Usser& Usser)
	{
		_RecordUsserToFile(Usser);
		printf(" Add Usser Seccssuflly :-) \n");
	}

	static void DeleteUsserToFile(string& UserName)
	{
		_DeleteUsserToFile(UserName);
	}

	void UPdateUsserTOFile(string& UserName)
	{
		_UpdateUsserToFile(UserName);
	}

	////=========================
	////=========================

	//enum _enPermissions
	//{
	//	All = -1,
	//	List = 1,
	//	Add = 2,
	//	Delet = 4,
	//	Update = 8,
	//	Find = 16,
	//	Transaction = 32,
	//	Manage_User = 64,
	//};

	////short PermissionType
	//bool CheckPermissionUsser(_enPermissions Type)
	//{
	//	//_enPermissions Type;
	//	cout << "\t\t\t\t" << this->AccountBalance << endl;
	//	if (this->AccountBalance == Type)
	//		return true;

	//	/*if ((Type & this->UsserName) == true)
	//	{

	//	}*/

	//	return false;
 //                                                                                      		return false;
	//}
};