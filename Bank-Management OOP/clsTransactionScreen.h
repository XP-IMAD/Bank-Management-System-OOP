#pragma once

#include <iostream>
#include <iomanip>
#include "clsString.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferLogScreen.h"
#include "clsTransferScreen.h"

class clsTransactionScreen : protected clsScreen
{
private:
	
	enum enTransactionMenueOption {
		enDeposit = 1, enWithdraw = 2, enTotalBalances = 3,
		enTransfer = 4, enTrasferLog = 5, enMainMenue = 6
	};
	
	static short _ReadTransactionMenueOption()
	{
		cout << setw(38) << left << "" << "Choose What Do You Want To Do From [1 To 6]: ";
		short Choise = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number Between [1-6]: ");

		return Choise;
	}

	static void _ShowDepositScreen()
	{
		//cout << "\nDeposit Screen Will Be Here...\n";

		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\nWithdraw Screen Will Be Here...\n";

		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "\nTotal Balances Screen Will Be Here...\n";

		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		//cout << "\nTransfer Screen Will Be Here...\n";

		clsTrnasferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "\nTransfer Log Screen Will Be Here...\n";

		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _GoBackToTransactionMenue()
	{
		cout << "\n\n [>] Press Any Key To Go Back To Transaction Menue...";

		system("pause>0");
		ShowTransactionMenue();
	}

	static void _PerformTransactionMenue(enTransactionMenueOption TransactionOption)
	{
		switch (TransactionOption)
		{
		case enDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;


		case enWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;


		case enTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenue();
			break;


		case enTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenue();
			break;
			

		case enTrasferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenue();
			break;


		case enMainMenue:
			break;

		}
	}

public:

	static void ShowTransactionMenue()
	{
		system("cls");

		if (!CheckAccessRight(clsUser::enPermissions::pTransactions))
			return;

		_DrawScreenHeader("\t     Transaction Screen");

		cout << setw(38) << left << "" << "=============================================\n";
		cout << setw(38) << left << "" << "\t\t     Transaction Menue\n";
		cout << setw(38) << left << "" << "=============================================\n";

		cout << setw(38) << left << "" << "\t   [1] Deposit.\n";
		cout << setw(38) << left << "" << "\t   [2] Withdraw.\n";
		cout << setw(38) << left << "" << "\t   [3] Total Balances.\n";
		cout << setw(38) << left << "" << "\t   [4] Transfer.\n";
		cout << setw(38) << left << "" << "\t   [5] Transfer Log.\n";
		cout << setw(38) << left << "" << "\t   [6] Main Menue.\n";
		cout << setw(38) << left << "" << "=============================================\n\n";

		_PerformTransactionMenue(enTransactionMenueOption(_ReadTransactionMenueOption()));
	}


};

