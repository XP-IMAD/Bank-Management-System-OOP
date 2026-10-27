#pragma once

#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t  _______________________________________";
		cout << "\n\n\t\t\t\t\t    " << Title;

		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t    " << SubTitle;
		}
		
		cout << "\n\t\t\t\t\t  _______________________________________\n\n";

		
		cout << "\t\t\t\t\t  User: " << CurrentUser.UserName << endl;
		cout << "\t\t\t\t\t  Date: " << clsDate::DateToString(clsDate()) << "\n\n";
		
	}

	static bool CheckAccessRight(clsUser::enPermissions Permissions)
	{
		if (!CurrentUser.CheckAccessPermissions(Permissions))
		{
			cout << "\t\t\t\t\t______________________________________________";
			cout << "\n\n\t\t\t\t\t      Access Denied! Contact Your Admin\n";
			cout << "\t\t\t\t\t______________________________________________\n\n";
			return false;
		}
		else
			return true;
	}

};

