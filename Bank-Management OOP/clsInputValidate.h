#pragma once

#include <iostream>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{

public:

	template <typename T> static bool IsNumberBetween(T Number, T from, T to)
	{
		return (Number >= from && Number <= to);

	}

	static bool IsDateBetwen(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		//Date >= from && Date <= To
		if (clsDate::IsDate1AfterDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom)
			&& clsDate::IsDate1BeforeDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateTo))
		{
			return true;
		}

		//Date >= to && Date <= from 
		if (clsDate::IsDate1AfterDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateTo)
			&& clsDate::IsDate1BeforeDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom))
		{
			return true;
		}

		return false;
	}

	template <typename T> static T ReadNumber(string message = "Invalide Number, Enter Again: ")
	{
		T Number;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << message;
			cin >> Number;
		}

		return Number;
	}

	template <typename T> static T ReadNumberBetween(T From, T To, string message)
	{
		T Number = ReadNumber<T>();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << message;
			Number = ReadNumber<T>();
		}

		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S1 = "";

		getline(cin >> ws, S1);
		return S1;
	}

	template <typename T> static T ReadPositiveNumber()
	{
		T Number = ReadNumber<T>();

		while (Number <= 0)
		{
			cout << "\nPLease Enter a Positive Number: ";
			Number = ReadNumber<T>();
		}

		return Number;
	}

};

