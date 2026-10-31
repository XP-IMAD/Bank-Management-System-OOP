#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "clsString.h"

class clsCurrency
{
private:

	enum enMode {EmptyMode = 0, UpdateMode = 1};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertCurrencyLineToObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrency = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2],
			stof(vCurrency[3]));
	}

	static vector<clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector<clsCurrency> vCurrency;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in); //Read Mode 

		
		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertCurrencyLineToObject(Line);

				vCurrency.push_back(Currency);

			}

			MyFile.close();

		}

		return vCurrency;

	}

	static string _ConvertCurrencyRecordToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string CurrencyLine = "";

		CurrencyLine += Currency.Country() + Seperator;
		CurrencyLine += Currency.CurrencyCode() + Seperator;
		CurrencyLine += Currency.CurrencyName() + Seperator;
		CurrencyLine += to_string(Currency.Rate());

		return CurrencyLine;

	}

	static void _SaveCurrencyDataToFile(const vector<clsCurrency> &vCurrency)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		string Line;

		if (MyFile.is_open())
		{
			for (const clsCurrency &C : vCurrency)
			{
				Line = _ConvertCurrencyRecordToLine(C);

				MyFile << Line << endl;

			}

			MyFile.close();

		}
	}

	void _Update()
	{
		vector<clsCurrency> vCurrency = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(vCurrency);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}


public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertCurrencyLineToObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in); //Read Mode

		string Line;

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertCurrencyLineToObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());
	}

	static bool IsCurrencyExistByCountry(string Country)
	{
		clsCurrency C1 = clsCurrency::FindByCountry(Country);
		return (!C1.IsEmpty());
	}

	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return float(AmountInUSD * Currency2.Rate());
	}

};

