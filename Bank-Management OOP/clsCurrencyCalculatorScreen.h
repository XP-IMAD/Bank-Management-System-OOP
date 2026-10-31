#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency, string Title)
	{
		cout << "\n" << Title << "\n";
		cout << "\n____________________________________\n";
		cout << "\nCountry   : " << Currency.Country();
		cout << "\nCode      : " << Currency.CurrencyCode();
		cout << "\nName      : " << Currency.CurrencyName();
		cout << "\nRate (1$) : " << Currency.Rate();
		cout << "\n____________________________________\n\n";
	}

	static float _ReadAmount()
	{
		float Amount = 0;

		cout << "\nEnter Amount To Exchange: ";
		Amount = clsInputValidate::ReadDblNumber();

		return Amount;
	}

	static clsCurrency _GetCurrency(string message)
	{
		string CurrencyCode = "";

		cout << message;
		cin >> CurrencyCode;

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Was Not Found! Choose Another One: ";
			CurrencyCode = clsInputValidate::ReadDblNumber();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

	static void _PrintCalculationResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		_PrintCurrencyCard(CurrencyFrom, "Convert From: ");

		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		cout << Amount << " " << CurrencyFrom.CurrencyCode()
			<< " = " << AmountInUSD << " USD \n";

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		_PrintCurrencyCard(CurrencyTo, "Convert From USD To: ");

		float AmountInCurrency2 = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);


		cout << Amount << " " << CurrencyFrom.CurrencyCode()
			<< " = " << AmountInCurrency2 << " " << CurrencyTo.CurrencyCode();

	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\t Currency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPLease Enetr Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPLease Enter Currency2 Code: ");

			float Amount = _ReadAmount();

			_PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo You Want To Perform Another Calculation? [Y/N]: ";
			cin >> Continue;

		}

	}


};

