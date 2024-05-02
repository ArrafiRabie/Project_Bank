#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include"Cls_Bank_Client.h"

using namespace std;


class Cls_Bank_Rogister : public Cls_Bank_Client
{
private:

	string _NameFile = "UserSystem.txt";
	string _Operatour = "#/#";

	vector<string> _Read_Data_To_File()
	{
		fstream MYFILE;
		string Line = "";
		vector<string> vRead;
		vector<string> vR;

		MYFILE.open(_NameFile,ios::out | ios::app | ios::in);
		if (MYFILE.is_open())
		{
			while (getline(MYFILE, Line))
			{
				vRead = Split(Line, _Operatour);
				vR.push_back(vRead[0]);
				vR.push_back(vRead[1]);
				vR.push_back(vRead[2]);
				vR.push_back(vRead[3]);
			}
			MYFILE.close();
		}

		return vR;
	}

	//protected:

public:

	vector<string> Read_Data_To_File()
	{
		return _Read_Data_To_File();
	}


};

