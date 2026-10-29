#pragma once

#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsers : protected clsScreen
{
private:

	enum enManageUsersMenueOption
	{
		enListUsers = 1, enAddNewUser = 2, enDeleteUser = 3,
		enUpdateUser = 4, enFindUser = 5, enMainM = 6
	};

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(38) << left << "" << "Choose What Do You Want To Do From [1 To 6]: ";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between [1-6]: ");

		return Choise;
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\n [>] Press Any Key To Go Back To Manage Users Menue...";

		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _ShowListUsersScreen()
	{
		//cout << "\nList Users Will Be Here...\n\n";

		clsUsersListScreen::ShowListUsersScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "\nAdd New User Screen Will Be Here...\n\n";

		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete User Screen Will Be Here...\n\n";

		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScree()
	{
		//cout << "\nUpdate User Screen Will Be Here...\n\n";

		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nFind User Screen Will Be Here...\n\n";

		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenue(enManageUsersMenueOption ManageUserOp)
	{
		switch (ManageUserOp)
		{
		case enListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;

		case enAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case enDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case enUpdateUser:
			system("cls");
			_ShowUpdateUserScree();
			_GoBackToManageUsersMenue();
			break;

		case enFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case enMainM:
			break;

		default:
			break;
		}
	}


public:

	static void ShowManageUsersScreen()
	{
		system("cls");

		if (!CheckAccessRight(clsUser::enPermissions::pManageUsers))
			return;

		_DrawScreenHeader("\t     Mange Users Screen");

		cout << setw(38) << left << "" << "=============================================\n";
		cout << setw(38) << left << "" << "\t\t     Manage Users Menue\n";
		cout << setw(38) << left << "" << "=============================================\n\n";

		cout << setw(38) << left << "" << "\t [1] List Users.\n";
		cout << setw(38) << left << "" << "\t [2] ADD New User.\n";
		cout << setw(38) << left << "" << "\t [3] Delete User.\n";
		cout << setw(38) << left << "" << "\t [4] Update User.\n";
		cout << setw(38) << left << "" << "\t [5] Find User.\n";
		cout << setw(38) << left << "" << "\t [6] Main Menue.\n";
		cout << setw(38) << left << "" << "=============================================\n\n";

		_PerformManageUsersMenue(enManageUsersMenueOption(_ReadManageUsersMenueOption()));

	}

};

