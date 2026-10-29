#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"

class clsUsersListScreen : protected clsScreen
{

private:

    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << left << setw(15) << User.UserName;
        cout << "| " << left << setw(25) << User.FullName();
        cout << "| " << left << setw(23) << User.Email;
        cout << "| " << left << setw(15) << User.Phone;
        cout << "| " << left << setw(10) << User.Password;
        cout << "| " << left << setw(5) << User.Permissions;
    }


public:

	static void ShowListUsersScreen()
	{
		vector<clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\t\tUsers List";
		string SubTitle = "\t\t[" + to_string(vUsers.size()) + "] User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "_________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(23) << "Email";
        cout << "| " << left << setw(15) << "Phone";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(5) << "Permissions";

        cout << "\n\t_______________________________________________________________";
        cout << "_________________________________________________\n" << endl;

        if (vUsers.size() == 0)
        {
            cout << "\n\t\t\tNo Client Available in The System :(\n";
        }
        else
        {
            for (const clsUser& U : vUsers)
            {
                _PrintUserRecordLine(U);

                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "_______________________________________________________________";
        cout << "_________________________________________________\n" << endl;
	}

};