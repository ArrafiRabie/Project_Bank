#pragma once
#include<iostream>
#include"CLs_Utility.h"
#include"Cls_Date.h"


#include"Cls_Bank_Client.h"
#include"Cls_MaineScreen.h"



using namespace std;

class Cls_HeaderScreen : public Cls_Utility
{
private:

	
	static string _UsserName;

protected:
public:

	void SetUsserName(string UsserName)
	{

		_UsserName = UsserName;
	}

	string GetUsserName()
	{
		return _UsserName;
	}

	static void HeaderSecreen(string Message, short Number_Character)
	{
		system("cls"); 
		cout << Tabs(40, "=") << endl;
		cout << Tabs(Number_Character, " ") << Message << endl;
		cout << Tabs(40, "=") << endl;
		//=======================
		Cls_Date Date;
		cout << Tabs(18, " ") << "Usser : " << _UsserName << endl;
		cout << Tabs(18, " ") << "Datae : " << Date.Get_Days() << "/" << Date.Get_Month() << "/" << Date.Get_Year() << Endl(3);
		//=======================
	}
};

string  Cls_HeaderScreen::_UsserName = "";