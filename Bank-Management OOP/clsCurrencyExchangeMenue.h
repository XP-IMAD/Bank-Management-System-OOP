#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMenue : protected clsScreen
{
private:

	enum enCurrencyExchangeMenue
	{
		enListCurrencies = 1, enFindCurrency = 2, enUpdateRate = 3,
		enCurrencyCalculator = 4, enMainMenue = 5
	};

	static short _ReadCurrencyMenueOption()
	{
		cout << setw(38) << left << "" << "Choose What Do You Want To Do From [1 To 5]: ";
		short Choise = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number Between [1-5]: ");

		return Choise;
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nCurrensies List Screen Will Be Here...\n\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen Will Be Here...\n\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nUpdate Rate Screen Will Be Here...\n\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyListScreen();
	}

	static void _ShowCarruncyCalculatorScreen()
	{
		//cout << "\nCurrency Calculator Screen Will Be Here...\n\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << "\n\n [>] Press Any Key To Go Back To Carrency Exchange Menue...";

		system("pause>0");
		ShowCurrencyExchangeMeneu();
	}

	static void _PerformCurrencyExchangeMenue(enCurrencyExchangeMenue CurrencyOP)
	{
		switch(CurrencyOP)
		{

		case enListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenue();
			break;


		case enFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;


		case enUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		
		case enCurrencyCalculator:
			system("cls");
			_ShowCarruncyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
			break;


		case enMainMenue:
			break;

		}
	}



public:

	static void ShowCurrencyExchangeMeneu()
	{
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Main Screen");

		cout << setw(38) << left << "" << "=============================================\n";
		cout << setw(38) << left << "" << "\t\t Currency Exchange Menue\n";
		cout << setw(38) << left << "" << "=============================================\n";

		cout << setw(38) << left << "" << "\t   [1] List Currencies.\n";
		cout << setw(38) << left << "" << "\t   [2] Find Currency.\n";
		cout << setw(38) << left << "" << "\t   [3] Update Rate.\n";
		cout << setw(38) << left << "" << "\t   [4] Currency Calculator.\n";
		cout << setw(38) << left << "" << "\t   [5] Main Menue.\n";
		cout << setw(38) << left << "" << "=============================================\n\n";


		_PerformCurrencyExchangeMenue(enCurrencyExchangeMenue(_ReadCurrencyMenueOption()));

	}

};

