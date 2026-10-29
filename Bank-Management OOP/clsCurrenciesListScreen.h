#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrenciesListScreen : protected clsScreen
{
private:

    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << left << setw(35) << Currency.Country();
        cout << "| " << left << setw(12) << Currency.CurrencyCode();
        cout << "| " << left << setw(38) << Currency.CurrencyName();
        cout << "| " << left << setw(10) << Currency.Rate();

    }


public:

	static void ShowCurrenciesListScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\t  Currencies List Screen";
		string SubTitle = "\t     [" + to_string(vCurrencies.size()) + "] Currency.";

		_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Country";
        cout << "| " << left << setw(12) << "Code";
        cout << "| " << left << setw(38) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
        {
            cout << "\n\t\t\tNo Currencies Available in The System :(\n";
        }
        else
        {
            for (const clsCurrency& C : vCurrencies)
            {
                _PrintCurrencyRecordLine(C);

                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "_______________________________________________________________";
        cout << "________________________________________________\n" << endl;

	}

};

