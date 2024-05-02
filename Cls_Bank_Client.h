#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"CLs_String.h"

using namespace std;

class Cls_Bank_Client : public Cls_String, public Cls_Utility
{

private:

	enum enMode
	{
		EmptyMode = 1,
		UpdateMode = 2,
	};

	enMode _Mode;

	string  _NameFile = "MyFile.Txt";
	fstream _MYFILE;

	string _FrindtName = "";
	string _LastName = "";
	string _Email = "";
	string _Phone = "";
	string _AccoutNumber = "";
	string _PinCoude = "";
	float  _AccoutBalance = 0;
	string _Operatour = "#/#";

	static vector<string> _ReadInformationFromTheFile()
	{
		Cls_Bank_Client Client;
		string Line = "";
		vector<string>vRead;
		vector<string>vR;

		Client._MYFILE.open(Client._NameFile, iostream::out | ios::app | ios::in);
		if (Client._MYFILE.is_open())
		{
			while (getline(Client._MYFILE, Line))
			{
				vRead = vRead = Split(Line, "#/#");
				vR.push_back(vRead[4]);
				vR.push_back(vRead[0] + Tabs(1, " ") + vRead[1]);
				vR.push_back(vRead[2]);
				vR.push_back(vRead[3]);
				vR.push_back(vRead[5]);
				vR.push_back(vRead[6]);
			}

			Client._MYFILE.close();
		}
		return vR;
	}

	//=================================================
	static Cls_Bank_Client _CheckAccountClient(string& AccountNumber, string Operatour) 
	{
		string Line = "";
		fstream MYFILE;
		vector<string>vRead;

		MYFILE.open("MyFile.Txt", ios::out | ios::app | ios::in);
		if (MYFILE.is_open())
		{
			while (getline(MYFILE, Line))
			{
				vRead = vRead = Cls_Bank_Client::Split(Line, Operatour);

				if (vRead[4] == AccountNumber)
				{
					return Cls_Bank_Client(vRead[0], vRead[1], vRead[2], vRead[3], vRead[4], vRead[5], stod(vRead[6]), enMode::UpdateMode);					////
				}

				for (short i = vRead.size(); i < 0; i--)
				{
					vRead.pop_back();
				}
			}

			MYFILE.close();
		}

		return Cls_Bank_Client("", "", "", "", "", "", 0, enMode::EmptyMode);
	}

	static Cls_Bank_Client _CheckAccountClient(string AccountNumber, string Password, string Operatour, string NameFile)   // Update...
	{
		string Line = "";
		fstream MYFILE;
		vector<string>vRead;
		bool Check;
	                                         // "MyFile.Txt"
		MYFILE.open(NameFile, ios::out | ios::app | ios::in);
		if (MYFILE.is_open())
		{
			while (getline(MYFILE, Line))
			{
				vRead = Cls_Bank_Client::Split(Line, Operatour);
				//4                              //5
				if (vRead[0] == AccountNumber && vRead[5] == Password)
				{
					return Cls_Bank_Client(vRead[0], vRead[1], vRead[2], vRead[3], vRead[4], vRead[5], stod(vRead[6]), enMode::UpdateMode);
				}

				for (short i = vRead.size(); i < 0; i--)
				{
					vRead.pop_back();
				}
			}

			MYFILE.close();
		}

		return Cls_Bank_Client("", "", "", "", "", "", 0, enMode::EmptyMode);
	}

	void _RecordeUpdateInfo(string AccountNumber, string NameFile)
	{
		string Line = "";
		fstream MYFILE;
		vector<string>vRead;
		vector<string>vR;

		//"MyFile.Txt"

		MYFILE.open(NameFile, ios::out | ios::app | ios::in);
		if (MYFILE.is_open())
		{
			while (getline(MYFILE, Line))
			{
				vRead = Cls_Bank_Client::Split(Line, _Operatour);

				if (vRead[4] == AccountNumber)
				{
					vRead.push_back(_FrindtName);
					vRead.push_back(_LastName);
					vRead.push_back(_Phone);
					vRead.push_back(_Email);
					vRead.push_back(_AccoutNumber);
					vRead.push_back(_PinCoude);
					vRead.push_back(to_string(_AccoutBalance));


					//if (_FrindtName != "")
					//{
					//	//vRead[0] = _FrindtName;
					//	vRead.push_back(_FrindtName);
					//}
					//else if(_LastName != "")
					//{
					//	//vRead[1] = _LastName;
					//	vRead.push_back(_LastName);
					//}
					//else if (_Phone != "")
					//{
					//	//vRead[2] = _Phone;
					//	vRead.push_back(_Phone); 
					//}
					//else if (_Email != "")
					//{
					//	vRead[3] = _Email;
					//	vRead.push_back(_Email);
					//}
					//else if (_AccoutNumber != "")
					//{
					//	//vRead[4] = _AccoutNumber;
					//	vRead.push_back(_AccoutNumber);
					//}
					//else if (_PinCoude != "")
					//{
					//	//vRead[5] = _PinCoude;
					//	vRead.push_back(_PinCoude);
					//}
					//else if (_AccoutBalance != 0)
					//{
					//	//vRead[6] = _AccoutBalance;
					//	vRead.push_back(to_string(_AccoutBalance));
					//}

					UpdateLine();
					vR.push_back(UpdateLine());
				}

				if (vRead[4] != AccountNumber)
				{
					vR.push_back(Line);
				}

			}

			MYFILE.close();
		}

		//=================================

		MYFILE.open(NameFile, ios::out);
		if (MYFILE.is_open())
		{
			for (string Str : vR)
			{
				MYFILE << Str << endl;
			}

			for (short i = vR.size(); i < 0; i--)
			{
				vR.pop_back();
			}

			MYFILE.close();
		}
	}

	void _AddingNewClient() ///////
	{
		Cls_Bank_Client CL;
		fstream MYFILE;
		MYFILE.open("MyFile.Txt", ios::out | ios::app | ios::in);

		if (MYFILE.is_open())
		{
			MYFILE << UpdateLine() << endl;
			MYFILE.close();
		}
	}

	static enMode _Delete(string AccountNumber)
	{
		Cls_Bank_Client Clinet;
		string Line = "";
		fstream MYFILE;
		vector<string>vRead;
		vector<string>vR;

		MYFILE.open("MyFile.Txt", ios::out | ios::app | ios::in);
		if (MYFILE.is_open())
		{
			while (getline(MYFILE, Line))
			{
				vRead = Cls_Bank_Client::Split(Line, Clinet._Operatour);

				if (vRead[4] == AccountNumber)
				{
					//vR.push_back(Clinet.UpdateLine());
				}
				else if (vRead[4] != AccountNumber)
				{
					vR.push_back(Line);
				}

				for (short i = vRead.size(); i < 0; i--)
				{
					vRead.pop_back();
				}
			}

			MYFILE.close();
		}

		MYFILE.open("MyFile.Txt", ios::out);
		if (MYFILE.is_open())
		{
			for (string Str : vR)
			{
				MYFILE << Str << endl;
			}

			MYFILE.close();

			for (short i = vR.size(); i < 0; i--)
			{
				vR.pop_back();
			}

			MYFILE.close();
			//Clear();
			return enMode::UpdateMode;
		}

		return enMode::EmptyMode;
	}

	static vector<string> _ReadBalancClient()
	{
		Cls_Bank_Client Cleint;

		string Line = "";
		fstream MYFILE;
		vector<string>vRead;
		vector<string>vRecord;

		MYFILE.open("MyFile.Txt", ios::out | ios::app | ios::in);

		if (MYFILE.is_open())
		{
			while (getline(MYFILE, Line))
			{
				vRead = Cls_Bank_Client::Split(Line, Cleint._Operatour);

				vRecord.push_back(vRead[4]);
				vRecord.push_back(vRead[0] + " " + vRead[1]);
				vRecord.push_back(vRead[6]);
			}

			MYFILE.close();
		}

		return vRecord;
	}
	//=================================================


public:

	Cls_Bank_Client()
	{

	}
	Cls_Bank_Client(string FrinstName, string LastName, string Phone, 
		string Email, string AccoutNumber, string PinCoud, float  
		AccoutBalance, enMode Mode)
	{
		_FrindtName = FrinstName;
		_LastName = LastName;
		_Phone = Phone;
		_Email = Email;
		_AccoutNumber = AccoutNumber;
		_AccoutBalance = AccoutBalance;
		_PinCoude = PinCoud;
		_Mode = Mode;
	}

	// Property Set 
	void SetFristName(string FristName)
	{
		_FrindtName = FristName;
	}
	// Property Get
	string GetFristName()
	{
		return _FrindtName;
	}
	__declspec(property(get = GetFristName, put = SetFristName)) string FristName;

	// Property Set 
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	// Property Get
	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	// Property Set 
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	// Property Get
	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	// Property Set 
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	// Property Get
	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	// Property Get
	string GetFullName()
	{
		return _FrindtName + " " + _LastName;
	}


	// Property Set
	void SetAccountNumber(string AccountNumber)
	{
		_AccoutNumber = AccountNumber;
	}
	// Property Get
	string GetAccouNumber()
	{
		return _AccoutNumber;
	}
	__declspec(property(get = GetAccouNumber, put = SetAccountNumber)) string AccountNumber;

	// Property Set
	void SetPinCoude(string PinCoude)
	{
		_PinCoude = PinCoude;
	}
	// Property Get
	string GetPinCoude()
	{
		return _PinCoude;
	}
	__declspec(property(get = GetPinCoude, put = SetPinCoude)) string PinCoude;

	// Property Set
	void SetAccountBalance(float AccountBalance)
	{
		_AccoutBalance = AccountBalance;
	}
	// Property Get
	float GetAccountBalance()
	{
		return _AccoutBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance; //////

	static Cls_Bank_Client Find(string& AccountNumber)
	{
		return _CheckAccountClient(AccountNumber, "#/#");
	}

	static Cls_Bank_Client Find(string AccountNumber, string Password, string NameFile)
	{
		return _CheckAccountClient(AccountNumber, Password, "#/#", NameFile);
	}

	static bool IsClientExit(string AccountNumber)
	{
		Cls_Bank_Client Client = Find(AccountNumber);
		if (Client.GetPinCoude() == "") //GetPinCoude()//
		{
			return false;
		}
		else if (Client.GetPinCoude() != "")
		{
			return true;
		}
	}

	// NO UI ReLated Code Isisde Object  //
	/*void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FristName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << GetFullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCoude;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";
	}*/

	void Clear()
	{
		_FrindtName = "";
		_LastName = "";
		_Email = "";
		_Phone = "";
		_AccoutNumber = "";
		_PinCoude = "";
		_AccoutBalance = 0;
	}


	string UpdateLine()   // Update 
	{
		string Line = "";

		Line += _FrindtName;
		Line += _Operatour;
		Line += _LastName;
		Line += _Operatour;
		Line += _Phone;
		Line += _Operatour;
		Line += _Email;
		Line += _Operatour;
		Line += _AccoutNumber;
		Line += _Operatour;
		Line += _PinCoude;
		Line += _Operatour;
		Line += to_string(_AccoutBalance);

		return Line;
	}

	void UpdateClient(string AccountNumber, string NameFile)
	{
		Cls_Bank_Client::_RecordeUpdateInfo(AccountNumber, NameFile);
	}

	void AddingNewClient()
	{
		Cls_Bank_Client::_AddingNewClient();
	}

	static string Delete(string AccountNumber)
	{
		//_Delete(AccountNumber);

		string script1 = "", script2 = "";
		script1 = " Client Deleted Succssefully ";
		script2 = " T'dont Client Deleted Succssefully ";


		/*if (_Delete(AccountNumber) == enMode::UpdateMode)
		{
			_Delete(AccountNumber);
			return script1;
		}

		else if (_Delete(AccountNumber) == enMode::EmptyMode)
		{
			_Delete(AccountNumber);
			return script2;
		}*/


		if (_CheckAccountClient(AccountNumber, "#/#")._Mode == enMode::UpdateMode)
		{
			_Delete(AccountNumber);
			return script1;
		}
	}

	static vector<string>  ReadBalancClient()
	{
		return _ReadBalancClient();
	}

	static void Recoerde__Update()
	{

		Cls_Bank_Client CLT;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		if (CLT.GetAccouNumber() != "")
		{
			CLT.SetAccountNumber("ERT");
		}
		else if (CLT.GetFristName() != "")
		{
			CLT.SetFristName("ERT");
		}
		else if (CLT.GetLastName() != "")
		{
			CLT.SetLastName("ERT");
		}
		else if (CLT.GetLastName() != "")
		{
			CLT.SetEmail("ERT");
		}
		else if (CLT.GetPhone() != "")                                   // Open Update//
		{
			CLT.SetPhone("ERT");
		}
		else if (CLT.GetPinCoude() != "")
		{
			CLT.SetPinCoude("ERT");
		}
		else if (CLT.GetAccountBalance() != 0)
		{
			CLT.SetAccountBalance(111);
		}
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	}

	static vector<string> ReadInformationFromTheFile()
	{
		return _ReadInformationFromTheFile();
	}

	//====================
	enMode GetMode()
	{
		return _Mode;
	}
	__declspec(property(get = GetMode))enMode Mode;
};