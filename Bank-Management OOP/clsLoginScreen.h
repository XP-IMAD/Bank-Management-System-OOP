#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFail = false;
		string UserName, Password;
		short Trials = 3;

		do
		{
			if (LoginFail)
			{
				Trials--;
				system("cls");
				_DrawScreenHeader("\t\tLogin Screen");
				cout << "\nInvalid UserName/Password!\n";
				cout << "\nYou Have [" << Trials << "] Trials To Login\n";
			}

			if (Trials == 0)
			{
				cout << "\n\nYou Are Locked After 3 Faild Trials :(\n";
				return false;
			}

			cout << "\nEnter UserName: ";
			cin >> UserName;

			cout << "Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFail = CurrentUser.IsEmpty();

		} while (LoginFail);

		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tLogin Screen");

		return _Login();
	}

};

