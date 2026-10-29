#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "clsScreen.h"
#include "clsUser.h"

class clsLoginRegisterScreen : protected clsScreen
{
private:

	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord Record)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << Record.DateTime;
		cout << "| " << setw(25) << left << Record.UserName;
		cout << "| " << setw(15) << left << Record.Password;
		cout << "| " << setw(10) << left << Record.Permissions;
	} 

public:

	static void ShowLoginRegisterScreen()
	{
		if(!CheckAccessRight(clsUser::enPermissions::pLoginRegister))
			return;


		vector<clsUser::stLoginRegisterRecord> vLoginRegister = clsUser::GetLoginRegisterList();

		string Title = "\t  Login Register List Screen";
		string SubTitle = "\t      [" + to_string(vLoginRegister.size()) + "] Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________"
			<< "______________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(35) << left << "Date/Time";
		cout << "| " << setw(25) << left << "User Name";
		cout << "| " << setw(15) << left << "Password";
		cout << "| " << setw(10) << left << "Permissions";

		cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________"
			<< "_______________\n" << endl;

		if (vLoginRegister.size() == 0)
		{
			cout << "\n\t\t\tNo Logins in The System :(\n";
		}
		else

			for (clsUser::stLoginRegisterRecord Record : vLoginRegister)
			{
				_PrintLoginRegisterRecordLine(Record);

				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________"
			<< "_______________\n" << endl;
	}

};

