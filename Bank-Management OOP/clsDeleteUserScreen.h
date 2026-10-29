#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{

private:

	static void _PrintUserCard(clsUser User)
	{
		cout << "\nUser Card :";
		cout << "\n_______________________________________\n";
		cout << "\nFirst Name  : " << User.FirstName;
		cout << "\nLast Name   : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n_______________________________________\n";

	}


public:

	static void ShowDeleteUserScreen()
	{
		
		_DrawScreenHeader("\t   Delete User Screen");

		string UserName = "";
		cout << "\nPLease Enter User Name: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name [" << UserName << "] is Not Found, Choose Another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUserCard(User);

		char Answer = 'n';

		cout << "\nAre You Sure You Want To Delete This User? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if(User.Delete())
			{
				cout << "\nUser Was Deleted Successfully :)\n";
				_PrintUserCard(User);
			}
			else
			{
				cout << "\nError User Was Not Deleted :(\n";
			}

		}

	}

};