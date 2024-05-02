#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

#include"CLs_Utility.h"
#include"CLs_String.h"
#include"Cls_Interface_ReadOnly.h"

using namespace std;

class Cls_Currencie : public Cls_Interface_ReadOnly , public Cls_String
{
private:

	enum enMode
	{
		EmptyMode  = 0,
		UpdateMode = 1,
	};

	enMode _Mode;
	string _Country = "";
	string _CurrencyCoud = "";
	string _CurrencyName = "";
	float  _Rate = 0;

	string _NameToFile;

	static Cls_Currencie _Convert_Line_TO_Object(string& Line, string Seperator = "#//#")
	{
		vector<string>vData;
		vData = Split(Line, Seperator);
		return Cls_Currencie(enMode::UpdateMode, vData[0], vData[1], vData[2], stof(vData[3]));
	}

	static string _UpdateLine(Cls_Currencie Currencie, string Seperator = "#//#")
	{
		string Line = "";

		Line += Currencie.GetCountry();
		Line += Seperator;
		Line += Currencie.GetCurrencyCoud();
		Line += Seperator;
		Line += Currencie.GetCurrencyName();
		Line += Seperator;
		Line += to_string(Currencie.GetRate());

		return Line;
	}



	static Cls_Currencie _GetEmptyCurrencyObject()
	{
		return Cls_Currencie(enMode::EmptyMode, "", "", "",0);
	}

	static Cls_Currencie _CheckCurrencyCode(string CurrencyCode)
	{
		CurrencyCode = Cls_String::InvertLettersCase(CurrencyCode);
		fstream MYFILE;
		string Line = "";
		MYFILE.open("Currencies.txt", ios::in);
		if (MYFILE.is_open())
		{
			while (getline(MYFILE,Line))
			{
				Cls_Currencie Currencie = _Convert_Line_TO_Object(Line);
				if (Currencie.GetCurrencyCoud() == CurrencyCode)
				{
					MYFILE.close();
					return Currencie;
				}
			}

			MYFILE.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static Cls_Currencie _CheckCountry(string Country)
	{
		Country = Cls_String::TheFristLitterIsCapitalized(Country);

		fstream MYFILE;
		string Line = "";
		MYFILE.open("Currencies.txt", ios::in);
		if (MYFILE.is_open())
		{
			while (getline(MYFILE, Line))
			{
				Cls_Currencie Currencie = _Convert_Line_TO_Object(Line);
				if (Currencie.GetCountry() == Country)
				{
					MYFILE.close();
					return Currencie;
				}
			}

			MYFILE.close();
		}

		return _GetEmptyCurrencyObject();
	}


	static vector<Cls_Currencie> _Read_Data_To_Frome_File()
	{
		fstream MYFILE;
		string Line = "";
		vector<Cls_Currencie>vCurrencie;

		MYFILE.open("Currencies.txt", ios::in);
		if (MYFILE.is_open())
		{
			while (getline(MYFILE,Line))
			{
				Cls_Currencie Currencie = _Convert_Line_TO_Object(Line);
				vCurrencie.push_back(Currencie);
			}

			MYFILE.close();
		}

		return vCurrencie;
	}

	static void _ReadDataFomeFile(string CurrencyCode, float NewRate)
	{

		CurrencyCode = Cls_String::InvertLettersCase(CurrencyCode);

		vector<Cls_Currencie> vCurrencie;

		fstream MYFILE;
		string Line = "";
		MYFILE.open("Currencies.txt", ios::in);
		if (MYFILE.is_open())
		{
			while (getline(MYFILE,Line))
			{
				Cls_Currencie Currency = _Convert_Line_TO_Object(Line);

				if (Currency.GetCurrencyCoud() == CurrencyCode)
				{
					Currency.SetRate(NewRate);
				}

				vCurrencie.push_back(Currency);
			}

			MYFILE.close();
		}

		NewFile(vCurrencie);

		//return vCurrencie;
	}


	static void NewFile(vector<Cls_Currencie> vCurrencie)
	{
		fstream MYFILE;
		string Line;
		MYFILE.open("Currencies.txt", ios::out);


		if (MYFILE.is_open())
		{
			for (Cls_Currencie REC : vCurrencie)
			{
				Line = _UpdateLine(REC);

				MYFILE << Line << endl;
			}

			MYFILE.close();
		}
	}

	


//protected:


public:

	Cls_Currencie(enMode Mode, string Country, string CurrencyCoud, string CurrencyName,
		float  Rate)
	{
		_Mode         = Mode;
		_Country      = Country;
		_CurrencyCoud = CurrencyCoud;
		_CurrencyName = CurrencyName;
		_Rate         = Rate;
	}



	string GetCountry()
	{
		return _Country;
	}
	string GetCurrencyCoud()
	{
		return _CurrencyCoud;
	}
	string GetCurrencyName()
	{
		return _CurrencyName;
	}
	void SetRate(float Rate)
	{
		_Rate = Rate;
	}
	float GetRate()
	{
		return _Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static vector<Cls_Currencie> Read_Data_To_Frome_File()
	{
		return _Read_Data_To_Frome_File();
	}

	static Cls_Currencie FindCod(string Line)
	{
		return Cls_Currencie::_CheckCurrencyCode(Line);
	}

	static Cls_Currencie FindCountry(string Line)
	{
		return Cls_Currencie::_CheckCountry(Line);
	}


	static void _Update(string CurrencyCode, float NewRate)
	{
		_ReadDataFomeFile(CurrencyCode, NewRate);
	}


	        
	static float Convert_Currency(float Amount, Cls_Currencie Currency1, Cls_Currencie Currency2)
	{
		float Total = 0;

		Total = (Amount / Currency1.GetRate());
		Total *= Currency2.GetRate();///

		return Total;
	}



	~Cls_Currencie(){

	}



};
//static string _NameToFile = "Currencies.txt";