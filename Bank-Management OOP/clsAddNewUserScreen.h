#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsAddNewUserScreen : protected clsScreen
{

private:

    static void _ReadUserInfo(clsUser &User)
    {
        cout << "\nEnter First Name: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();;

        cout << "\nEnter Phone Number: ";
        User.Phone = clsInputValidate::ReadString();;

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();;

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissions();
    }

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

    static int _ReadPermissions()
    {
		short Permission = 0;
		char Answer = 'n';

		cout << "\nDo You Want To give Full access? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			return Permission = -1;
		}
		else
		{
			cout << "\nDo You Want To give access To :\n";

			cout << "\nShow Client List [Y/N]: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
				Permission += clsUser::enPermissions::pShowClientList;

			cout << "\nAdd New Client [Y/N]: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
				Permission += clsUser::enPermissions::pAddClient;

			cout << "\nDelete Client [Y/N]: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
				Permission += clsUser::enPermissions::pDeleteClient;

			cout << "\nUpdate Client [Y/N]: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
				Permission += clsUser::enPermissions::pUpdateClient;

			cout << "\nFind Client [Y/N]: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
				Permission += clsUser::enPermissions::pFindClient;

			cout << "\nTransactions [Y/N]: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
				Permission += clsUser::enPermissions::pTransactions;

			cout << "\nManage Users [Y/N]: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
				Permission += clsUser::enPermissions::pManageUsers;

			cout << "\nLogin Register [Y/N]: ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
				Permission += clsUser::enPermissions::pLoginRegister;
		}

		return (Permission == 255) ? -1 : Permission;
    }

public:

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t   Add New User Screen");

		string UserName = "";
		cout << "\nPLease Enter User Name: ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name [" << UserName << "] Is Already Exist, Choose Another One: ";
			UserName = clsInputValidate::ReadString();
		}

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;
        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:

            cout << "\nUser Added Successfully :)\n";
			_PrintUserCard(NewUser);
            break;

        case clsUser::enSaveResults::svFaildEmptyObject:

            cout << "\nError User Was Not Saved Becouse it's Empty :(\n";
            break;

        case clsUser::enSaveResults::svFaildUserExists:

            cout << "\nError User Was Not Saved Becouse UserName is Used !\n";
            break;

        }
	}

};

