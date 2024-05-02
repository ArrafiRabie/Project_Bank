#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Cls_String
{

private:

	string _VAlue = "";

public:

	Cls_String()
	{
		_VAlue = "";
	}
	Cls_String(string VAlue)
	{
		_VAlue = VAlue;
	}

	void Read_Value()
	{
		cout << " Please Enter Value : "; getline(cin, _VAlue);
	}

	void Set_Value(string VAlue)
	{
		_VAlue = VAlue;
	}
	string Value()
	{
		return _VAlue;
	}

	/*1*/  static void CountWords(string VAlue)
	{
		short Counter1 = 0, Counter2 = 0;
		string  Record = "";

		for (short i = 0; i < VAlue.length(); i++)
		{

			if (VAlue[i] != ' ')
			{
				Record += VAlue[i];
				Counter1++;
			}

			if (VAlue[i] == ' ')
			{
				if (Counter1 > 0)
				{
					Counter2++;
					Record = "";
				}
				Counter1 = 0;
			}
		}

		if (Record.size() != 0)
		{
			Counter2++;
		}

		cout << Counter2 << endl;
	}
	/*2*/  static void Size(string VAlue)
	{
		short Counter1 = 0;

		for (short i = 0; i < VAlue.length(); i++)
		{
			Counter1++;
		}

		cout << Counter1 << endl;
	}
	/*3*/  static void CountCapitalletters(string VAlue)
	{
		short Counter = 0;
		for (short i = 0; i < VAlue.length(); i++)
		{
			if (VAlue[i] == toupper(VAlue[i]))
			{
				Counter++;
			}
		}

		cout << Counter << endl;
	}
	/*4*/  static void CountSmullletters(string VAlue)
	{
		short Counter = 0;
		for (short i = 0; i < VAlue.length(); i++)
		{
			if (VAlue[i] != toupper(VAlue[i]))
			{
				Counter++;
			}
		}

		cout << Counter << endl;
	}
	/*5*/  static void CountVowels(string VAlue)
	{
		short Counter = 0;

		for (short i = 0; i < VAlue.length(); i++)
		{
			if ('A' == toupper(VAlue[i]) || 'E' == toupper(VAlue[i]) || 'N' == toupper(VAlue[i])
				|| 'I' == toupper(VAlue[i]) || 'O' == toupper(VAlue[i]) || 'U' == toupper(VAlue[i]))
			{
				Counter++;
			}
		}

		cout << Counter << endl;
	}
	/*6*/  static string InvertLettersCase(string VAlue)
	{
		short Counter = 0;
		string A = "";
		string Record = "";

		/*for (short i = 0; i < VAlue.length(); i++)
		{
			A = tolower(VAlue[i]);
			A = toupper(VAlue[i]);

			if (VAlue[i] == toupper(VAlue[i]))
			{
				A = tolower(VAlue[i]);
			}

			if (VAlue[i] == tolower(VAlue[i]))
			{
				A = toupper(VAlue[i]);
			}

			Record += A;

		}*/

		for (short i = 0; i < VAlue.length(); i++)
		{

			A = toupper(VAlue[i]);

           /* if (i != 0)
			{
				A = toupper(VAlue[i]);
			}*/

			Record += A;

		}


		return Record;
	}
	/*7*/  static void IsVowels(string VAlue)
	{
		bool Check = false;

		for (short i = 0; i < VAlue.length(); i++)
		{
			if ('A' == toupper(VAlue[i]) || 'E' == toupper(VAlue[i]) || 'N' == toupper(VAlue[i])
				|| 'I' == toupper(VAlue[i]) || 'O' == toupper(VAlue[i]) || 'U' == toupper(VAlue[i]))
			{
				Check = true;
			}
		}

		//(Check == true) ? " Yeas" : " NO ";

		if (Check == true)
		{
			cout << " Yeas " << endl;
		}
		else if (Check != true)
		{
			cout << " NO " << endl;
		}
	}
	/*8*/  static short length(string VAlue)
	{
		return VAlue.length();
	}
	/*9*/  static void LowerAllString(string VAlue)
	{
		string Record = "";

		for (short i = 0; i < VAlue.length(); i++)
		{
			VAlue[i] = tolower(VAlue[i]);
			Record += VAlue[i];
		}

		cout << Record << endl;
	}
	/*10*/ static string LowerFristLatterOFEachWord(string VAlue)
	{
		short Counter = 0;
		string Record = "";


		for (short i = 0; i < VAlue.length(); i++)
		{
			if (VAlue[i] != ' ')
			{
				Counter++;
			}

			if (Counter == 1)
			{
				VAlue[i] = toupper(VAlue[i]);//tolower(VAlue[i]
				//Record += VAlue[i];
			}

			if (VAlue[i] == ' ')
			{
				Counter = 0;
			}

			Record += VAlue[i];
		}

		//cout << Record << endl;
		return Record;
	}
	/*11*/ static void RemovePunctuations(string VAlue)
	{
		string Record = "";

		for (short i = 0; i < VAlue.length(); i++)
		{
			if (!ispunct(VAlue[i]))
			{
				Record += VAlue[i];
			}
		}

		cout << Record << endl;
	}
	/*12*/ static void ReverseWordesinString(string VAlue)
	{
		vector<string> Read;
		string Record = "";
		short Counter = 0;
		short Counter2 = 0;

		for (short i = 0; i < VAlue.length(); i++)
		{

			if (VAlue[i] != ' ')
			{
				Record += VAlue[i];
				Counter++;
			}

			if (VAlue[i] == ' ')
			{
				if (Counter > 0)
				{
					Read.push_back(Record);
					Counter2++;
					Record = "";
				}
				Counter = 0;
			}
		}

		if (Record.size() != 0)
		{
			Counter2++;
			Read.push_back(Record);
			Record = "";
		}

		for (auto it = Read.rbegin(); it != Read.rend(); ++it)
		{
			Record += *it + " ";
		}

		cout << Record << endl;

		for (short i = Read.size(); i > 0; i--)
		{
			Read.pop_back();
		}
	}
	/*13*/ static vector<string> Split(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			// if (sWord != "")
			// {
			vString.push_back(sWord);
			//}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	/*1*/  void CountWords()
	{

		CountWords(_VAlue);

	}
	/*2*/  void Size()
	{
		Size(_VAlue);
	}
	/*3*/  void CountCapitalletters()
	{
		CountCapitalletters(_VAlue);
	}
	/*4*/  void CountSmullletters()
	{
		CountSmullletters(_VAlue);
	}
	/*5*/  void CountVowels()
	{
		CountVowels(_VAlue);
	}
	/*6*/  void InvertLettersCase()
	{
		InvertLettersCase(_VAlue);
	}
	/*7*/  void IsVowels()
	{
		IsVowels(_VAlue);
	}
	/*8*/  void length()
	{
		cout << length(_VAlue);
	}
	/*9*/  void LowerAllString()
	{
		LowerAllString(_VAlue);
	}
	/*10*/ void LowerFristLatterOFEachWord()
	{
		LowerFristLatterOFEachWord(_VAlue);
	}
	/*11*/ void RemovePunctuations()
	{
		RemovePunctuations(_VAlue);
	}
	/*12*/ void ReverseWordesinString()
	{
		ReverseWordesinString(_VAlue);
	}
	/*13*/ vector<string> Split(string Delim)
	{
		return Split(_VAlue, Delim); 
	}


	void CountSpecificletters(char Specific)
	{
		short Counter = 0;

		for (short i = 0; i < _VAlue.length(); i++)
		{
			if (Specific == toupper(_VAlue[i]))
			{
				Counter++;
			}
		}

		cout << Counter << endl;
	}
	void Clear()
	{
		_VAlue = "";
	}

	static string TheFristLitterIsCapitalized(string String)
	{
		string A = "";
		string Record = "";

		for (short i = 0; i < String.length(); i++)
		{

			A = toupper(String[i]);

			if (i != 0)
			{
				A = tolower(String[i]);
			}

			Record += A;

		}


		return Record;
	}


};