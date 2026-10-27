#pragma once

#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "clsLoginRegisterScreen.h"
#include "Global.h"
using namespace std;

class clsMainScreen : protected clsScreen
{

private:

	enum enMainMenueOption {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionMenue = 6,
		eManageUsers = 7, eLoginRegister = 8, eExit = 9 
	};

	static short _ReadMainMenuOption()
	{
		cout << setw(38) << left << "" << "Choose What Do You Want To Do [1 TO 9]: ";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number Between 1 and 9: ");

		return Choise;
	}

	static void _GoBackToMainMenue()
	{

		cout << "\n [>] Press Any Key To Go Back To Main Menue...";

		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClientsScreen()
	{
		// cout << "\nClient List Screen Will Be Here...\n";

		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
		//cout << "\nAdd New Client Screen Will Be Here...\n";

		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen Will Be Here...\n";

		clsDeleteClientScreen::ShowDeleteClientScreen();

	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen Will Be Here...\n";

		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen Will Be Here...\n";

		clsFindClientScreen::ShowFindClientScreen();

	}

	static void _ShowTransactionMenue()
	{
		//cout << "\nTransaction Menue Will Be Here...\n";

		clsTransactionScreen::ShowTransactionMenue();
	}

	static void _ShowManageUsersMeneu()
	{
		//cout << "\nManage Users Will Be Hare...\n";

		clsManageUsers::ShowManageUsersScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _Logout()
	{
		CurrentUser.ClearObject();
	}

	static void _PerformMainMenueOption(enMainMenueOption MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case eListClients:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;

		case eAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;

		case eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;

		case eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;

		case eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;

		case eShowTransactionMenue:
			system("cls");
			_ShowTransactionMenue();
			_GoBackToMainMenue();
			break;

		case eManageUsers:
			system("cls");
			_ShowManageUsersMeneu();
			_GoBackToMainMenue();
			break;

		case eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;

		case eExit:
			system("cls");
			_Logout();
			break;

		default:
			break;
		}
	}

public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t     Main Menue Screen");

		cout << setw(38) << left << "" << "=============================================\n";
		cout << setw(38) << left << "" << "\t\t        Main Menue\n";
		cout << setw(38) << left << "" << "=============================================\n\n";

		cout << setw(38) << left << "" << "\t [1] Show Client List\n";
		cout << setw(38) << left << "" << "\t [2] ADD New Client\n";
		cout << setw(38) << left << "" << "\t [3] Delete Client\n";
		cout << setw(38) << left << "" << "\t [4] Update Client Info\n";
		cout << setw(38) << left << "" << "\t [5] Find Client\n";
		cout << setw(38) << left << "" << "\t [6] Transactions\n";
		cout << setw(38) << left << "" << "\t [7] Manage Users\n";
		cout << setw(38) << left << "" << "\t [8] Login Register\n";
		cout << setw(38) << left << "" << "\t [9] Logout\n";
		cout << setw(38) << left << "" << "=============================================\n\n";

		_PerformMainMenueOption(enMainMenueOption(_ReadMainMenuOption()));

	}

};

