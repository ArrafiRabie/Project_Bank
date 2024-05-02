#pragma warning(disable : 4996)
#pragma once

#include<iostream>
#include<ctime>
#include<string>
#include<vector>


using namespace std;

class Cls_Date
{

private:

    short Days = 0;
    short Month = 0;
    short Year = 0;

    vector<string> Date_To_String(string Date, char Operatour)
    {
        vector<char>vRead;
        string Record = "";
        vector<string>vDate;


        for (short i = 0; i < Date.length(); i++)
        {
            if (Date[i] != Operatour)
            {
                vRead.push_back(Date[i]);
            }

            if (Date[i] == Operatour)
            {
                for (short i = 0; i < vRead.size(); i++)
                {
                    Record += vRead[i];
                }

                vDate.push_back(Record);
                Record = "";

                for (short i = vRead.size(); i > 0; i--)
                {
                    vRead.pop_back();
                }
            }
        }

        if (vDate.size() != 3)
        {
            for (short i = 0; i < vRead.size(); i++)
            {
                Record += vRead[i];
            }

            vDate.push_back(Record);
            Record = "";

            for (short i = vRead.size(); i > 0; i--)
            {
                vRead.pop_back();
            }
        }

        return vDate;
    }

    short Date_To_Total_Days(short Total_Days, short Year)
    {
        bool Check_Years = false;
        short MonthTow = 0;
        short Counter = 1;

        if (((this->Year % 4 == 0) && (this->Year % 100 != 0)) || (this->Year % 400 == 0))
            Check_Years = true;
        else
            return Check_Years = false;

        if (Check_Years == true)
        {
            MonthTow = 29;
        }

        else if (Check_Years == false)
        {
            MonthTow = 28;
        }

        short Month_Year[12] = { 31,MonthTow,31,30,31,30,31,31,30,31,30,31 };

        for (short i = 0; i < 12; i++)
        {
            if (Total_Days > 31)
            {
                Total_Days -= Month_Year[i];
                Counter++;
            }
        }

        this->Days = Total_Days;
        this->Month = Counter;
        this->Year = Year;

        return 0;
    }


public:

    Cls_Date()
    {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        this->Days = ltm->tm_mday;
        this->Month = ltm->tm_mon + 1;
        this->Year = ltm->tm_year + 1900;
    }

    Cls_Date(string Date)
    {
        vector<string>vDate;
        vDate = Date_To_String(Date, '/');

        this->Days = stoi(vDate[0]);
        this->Month = stoi(vDate[1]);
        this->Year = stoi(vDate[2]);
    }

    Cls_Date(short Days, short Month, short Year)
    {
        this->Days = Days;
        this->Month = Month;
        this->Year = Year;
    }

    Cls_Date(short Total_Days, short Year)
    {
        Date_To_Total_Days(Total_Days, Year);
    }



    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    void Read_Year()
    {
        cout << " Please Enter Year : ";
        cin >> this->Year;
    }

    void Set_Year(short Year)
    {
        this->Year = Year;
    }
    short Get_Year()
    {
        return this->Year;
    }
    __declspec(property(get = Get_Year, put = Set_Year)) short Year;

    void Set_Month(short Year)
    {
        this->Month = Month;
    }
    short Get_Month()
    {
        return this->Month;
    }
    __declspec(property(get = Get_Month, put = Set_Month)) short Month;

    void Set_Days(short Year)
    {
        this->Days = Days;
    }
    short Get_Days()
    {
        return this->Days;
    }
    __declspec(property(get = Get_Days, put = Set_Days)) short Days;



    void Date()
    {
        //string Line;
        cout /* << "Date :  "*/ << this->Days << "/" << this->Month << "/" << this->Year << endl;
        
        //Line += this->Days + "/" + this->Month + "/" + this->Year;

        //return Line;
    }


    static string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        short Day, Month, Year, Hour, Minut, Second;

        Month  = now->tm_mon + 1;
        Year   = now->tm_year + 1900;
        Day    = now->tm_mday;
        Hour   = now->tm_hour;
        Minut  = now->tm_min;
        Second = now->tm_sec;

        return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) +
            "   " + to_string(Hour) + ":" + to_string(Minut) + ":" + to_string(Second);
    } 

};