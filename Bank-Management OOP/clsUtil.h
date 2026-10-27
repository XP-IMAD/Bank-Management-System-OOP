#pragma once

#include <iostream>
#include <ctime>
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:

    enum enCharType {
        SmallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChar = 4, SepicialCharacter = 5
    };

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int from, int to)
    {
        return rand() % (to - from + 1) + from;

    }

    static char GetRandomChar(enCharType CharType)
    {
        if (CharType == MixChar)
            CharType = enCharType(RandomNumber(1, 3));

        switch (CharType)
        {

        case enCharType::SmallLetter:
            return (char)RandomNumber(97, 122);
            break;

        case enCharType::CapitalLetter:
            return (char)RandomNumber(65, 90);
            break;


        case enCharType::SepicialCharacter:
            return (char)RandomNumber(33, 47);
            break;


        case enCharType::Digit:
            return (char)RandomNumber(48, 57);
            break;

        default:
            return (char)RandomNumber(65, 90);
            break;

        }
    }

    static string GenerateWord(enCharType CharType, int Length)
    {
        string word;

        for (int i = 1; i <= Length; i++)
        {
            word += GetRandomChar(CharType);

        }

        return word;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter)
    {
        string Key = "";

        Key = GenerateWord(CharType, 4) + '-';
        Key += GenerateWord(CharType, 4) + '-';
        Key += GenerateWord(CharType, 4) + '-';
        Key += GenerateWord(CharType, 4);

        return Key;

    }

    static void GenerateKeys(short NumberofKeys, enCharType CharType)
    {
        for (int i = 1; i <= NumberofKeys; i++)
        {
            cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl;
        }
    }

    static void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;

    }

    static void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;

    }

    static void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;

    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);
    }

    static void ShuffelArray(int arr[], int arrLingth)
    {
        for (int i = 0; i < arrLingth; i++)
        {
            Swap(arr[RandomNumber(0, arrLingth - 1)], arr[RandomNumber(0, arrLingth - 1)]);
        }

    }

    static void ShuffelArray(string arr[], int arrLingth)
    {
        for (int i = 0; i < arrLingth; i++)
        {
            Swap(arr[RandomNumber(0, arrLingth - 1)], arr[RandomNumber(0, arrLingth - 1)]);
        }

    }

    static void FillArrayWithRandomNumbers(int arr[], int arrLingth, short From, short To)
    {

        for (int i = 0; i < arrLingth; i++)
        {
            arr[i] = RandomNumber(From, To);

        }

    }

    static void FillArrayWithRandomWords(string arr[], int arrLingth, enCharType CharType, short CharNumber)
    {

        for (int i = 0; i < arrLingth; i++)
        {
            arr[i] = GenerateWord(CharType, CharNumber);

        }

    }

    static void FillArrayWithRandomKeys(string arr[], int arrLingth, enCharType CharType)
    {

        for (int i = 0; i < arrLingth; i++)
        {
            arr[i] = GenerateKey(CharType);

        }

    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i <= NumberOfTabs; i++)
        {
            t += "\t";
        }

        return t;
    }

    static string EncryptName(string Name, short EncryptKey = 2)
    {
        for (int i = 0; i <= Name.length(); i++)
        {
            Name[i] = char((int)Name[i] + EncryptKey);
        }

        return Name;
    }

    static string DecryptName(string& Name, short EncryptKey = 2)
    {

        for (int i = 0; i <= Name.length(); i++)
        {
            Name[i] = char((int)Name[i] - EncryptKey);
        }

        return Name;
    }

    static string NumberToText(int Number)
    {
        if (Number == 0)
            return "";

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "" , "One" , "Two" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" ,
            "Nine" , "Ten" , "Eleven" , "Twelve" , "Thirteen" , "Fourteen" , "Fifteen" , "Sixteen" ,
            "Seventeen" , "Eighteen" , "Ninteen" };

            return arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "" , "" , "Twenty" , "Thirty" , "Fourty" , "Fifty" , "Sixty" , "Seventy" ,
            "Eighty" , "Ninty" };

            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 999)
        {
            return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + "Milion " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 999999999999)
        {
            return NumberToText(Number / 1000000000) + "Bilion " + NumberToText(Number % 1000000000);
        }

    }


};

