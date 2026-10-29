#pragma once

#include <iostream>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{

public:

	static bool IsNumberBetween(short Number, short from, short to)
	{
		return (Number >= from && Number <= to);
	}

	static bool IsNumberBetween(int Number, int from, int to)
	{
		return (Number >= from && Number <= to);
	}

	static bool IsNumberBetween(float Number, float from, float to)
	{
		return (Number >= from && Number <= to);
	}

	static bool IsNumberBetween(double Number, double from, double to)
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

	static int ReadIntNumber(string message = "Invalid Number, Enter Again: ")
	{
		int Number;
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

	static short ReadShortNumber(string message = "Invalid Number, Enter Again: ")
	{
		short Number;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << message << endl;
			cin >> Number;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string message)
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << message;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string message)
	{
		short Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << message;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static double ReadDblNumber(string message = "Invalid Number, Enter Again:")
	{
		double Number;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << message << endl;
			cin >> Number;
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string message)
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << message;
			Number = ReadDblNumber();
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

	static double ReadPositiveDblNumber()
	{
		double Number = ReadDblNumber();

		while (Number <= 0)
		{
			cout << "\nPLease Enter a Positive Number: ";
			Number = ReadDblNumber();
		}

		return Number;
	}

};

