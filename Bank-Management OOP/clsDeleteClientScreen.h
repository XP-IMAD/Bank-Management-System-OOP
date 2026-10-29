#pragma once

#include <iostream>
#include <iomanip>
#include <cctype>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
{
private:

    static void _PrintClientCard(clsBankClient Client)
    {
        cout << "\nClient Card :";
        cout << "\n_______________________________________\n";
        cout << "\nFirst Name : " << Client.FirstName;
        cout << "\nLast Name  : " << Client.LastName;
        cout << "\nFull Name  : " << Client.FullName();
        cout << "\nEmail      : " << Client.Email;
        cout << "\nPhone      : " << Client.Phone;
        cout << "\nAcc.Number : " << Client.AccountNumber();
        cout << "\nPinCode    : " << Client.PinCode;
        cout << "\nBalance    : " << Client.AccountBalance;
        cout << "\n_______________________________________\n";


    }


public:

    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient))
            return;


        _DrawScreenHeader("\t   Delete Client Screen");

        cout << "\nPLease Enter Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not Found, Choose Another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientCard(Client1);

        char Answer = 'n';

        cout << "\nAre You Sure You Want To Delete This Client? [Y/N]: ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintClientCard(Client1);
            }
            else
            {
                cout << "\nError Client Was Not Deleted :(\n";
            }

        }

    }

};

