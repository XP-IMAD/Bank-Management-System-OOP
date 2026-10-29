#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card :";
		cout << "\n____________________________________\n";
		cout << "\nCountry   : " << Currency.Country();
		cout << "\nCode      : " << Currency.CurrencyCode();
		cout << "\nName      : " << Currency.CurrencyName();
		cout << "\nRate (1$) : " << Currency.Rate();
		cout << "\n____________________________________\n";
	}

	static void _UpdateCurrencyRate(clsCurrency Currency)
	{
		cout << "\nUpdate Currency Rate: ";
		cout << "\n____________________________________\n";

		cout << "\nEnter New Rate: ";
		float NewRate = clsInputValidate::ReadDblNumber();

		Currency.UpdateRate(NewRate);

		cout << "\nCurrency Rate Updated Successfully :)\n";
		_PrintCurrencyCard(Currency);

	}

public:

	static void ShowUpdateCurrencyListScreen()
	{
		_DrawScreenHeader("\t    Update Rate Screen");

		cout << "\nPLease Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Was Not Found! Choose Another One: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrencyCard(Currency);

		cout << "\n\nAre You Sure You Want To Update The Rate Of This Currency? [Y/N]: ";
		char Answer;
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			_UpdateCurrencyRate(Currency);
		}

	}

};

