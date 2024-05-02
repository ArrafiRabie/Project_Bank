#pragma once

#include <iostream>
#include<ctime>
#include<string>
#include<vector>
#include"Cls_Date.h"

using namespace std;


class Cls_Utility : public Cls_Date
{

private:

    string _Word = "";


public:

    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5,
    };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static short RandomeNumber(short Frome, short To)
    {
        short Rand = rand() % (To - Frome + 1) + Frome;

        return Rand;
    }

    static char GetRandomeNumber(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SamallLetter:
            return char(RandomeNumber(97, 122));
            break;
        case enCharType::CapitalLetter:
            return char(RandomeNumber(65, 90));
            break;
        case enCharType::Digit:
            return char(RandomeNumber(48, 57));
            break;
        case enCharType::MixChars:
            return char(RandomeNumber(65, 90));
            break;
        case enCharType::SpecialCharacter:
            return char(RandomeNumber(33, 47));
            break;
        default:
            break;
        }
    }

    static string GenerateWorde(enCharType CharType, short Lenght)
    {
        string Word;

        for (short i = 0; i < Lenght; i++)
        {
            Word = Word + GetRandomeNumber(CharType);
        }

        return Word;
    }

    static string GenerateKey(enCharType CharType)
    {
        string Word;

        for (short i = 0; i < 4; i++)
        {
            Word += GenerateWorde(CharType, 4) + "-";
        }

        Word = Word.substr(0, Word.length() - 1);

        return Word;
    }

    static void GenerateKey(enCharType CharType, short NumberKey)
    {
        for (short i = 1; i <= NumberKey; i++)
        {
            cout << " Key [" << i << "] : " << GenerateKey(CharType) << endl;
        }
    }

    static void Swap(short& Number1, short& Number2)
    {
        short Swap = 0;

        Swap = Number1;
        Number1 = Number2;
        Number2 = Swap;
    }

    static void Swap(float& Number1, float& Number2)
    {
        float Swap = 0;

        Swap = Number1;
        Number1 = Number2;
        Number2 = Swap;
    }

    static void Swap(string& Nume1, string& Nume2)
    {
        string Swap = "";

        Swap = Nume1;
        Nume1 = Nume2;
        Nume2 = Swap;
    }

    static void Swap(Cls_Utility& Nume1, Cls_Utility& Nume2)
    {
        Cls_Utility Swap;

        Swap  = Nume1;
        Nume1 = Nume2;
        Nume2 = Swap;
    }

    static void ChuffleArry(short Arry[100], short NumberArry)
    {
        for (short i = 0; i < NumberArry; i++)
        {
            Swap(Arry[RandomeNumber(1, NumberArry) - 1], Arry[RandomeNumber(1, NumberArry) - 1]);
        }
    }

    static void ChuffleArry(string Arry[100], short NumberArry)
    {
        for (short i = 0; i < NumberArry; i++)
        {
            Swap(Arry[RandomeNumber(1, NumberArry) - 1], Arry[RandomeNumber(1, NumberArry) - 1]);
        }
    }

    static void FillArryWithRandomNumber(short Arr[100], short NumberArry, short Frome, short To)
    {
        for (short i = 0; i < NumberArry; i++)
        {
            Arr[i] = RandomeNumber(Frome, To);
        }
    }

    static void FillArryWithRandomWords(string Arr[100], short NumberArry, enCharType CharType, short Lenght)
    {
        for (short i = 0; i < NumberArry; i++)
        {
            Arr[i] = GenerateWorde(CharType, Lenght);
        }
    }

    static void FillArryWithRandomKey(string Arr[100], short NumberArry, enCharType CharType)
    {
        for (short i = 0; i < NumberArry; i++)
        {
            Arr[i] = GenerateKey(CharType);
        }
    }

    static string Tabs(short NumberTaps, string Character)
    {
        string Record = "";
        for (short i = 0; i < NumberTaps; i++)
        {
            Record += Character;
        }

        return Record;
    }

    static string Encrayption(string Text, short EncrayptionKey=7)
    {
        for (short i = 0; i <= Text.length(); i++)
        {
            Text[i] = char(short(Text[i]) + EncrayptionKey);
        }

        return Text;
    }

    static string Dencrayption(string Text, short EncrayptionKey=7)
    {
        for (short i = 0; i <= Text.length(); i++)
        {
            Text[i] = char(short(Text[i]) - EncrayptionKey);
        }

        return Text;
    }

    static string Endl(short NumberTaps)
    {
        string Record = "";
        for (short i = 0; i < NumberTaps; i++)
        {
            Record += "\n";
        }

        return Record;
    }

};

