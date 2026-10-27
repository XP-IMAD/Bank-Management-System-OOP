#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen : protected clsScreen
{
private:

    static void _PrintClientCard(clsBankClient Client)
    {
        cout << "\nClient Card :";
        cout << "\n_______________________________\n";
        cout << "\nFirst Name : " << Client.FirstName;
        cout << "\nLast Name  : " << Client.LastName;
        cout << "\nFull Name  : " << Client.FullName();
        cout << "\nEmail      : " << Client.Email;
        cout << "\nPhone      : " << Client.Phone;
        cout << "\nAcc.Number : " << Client.AccountNumber();
        cout << "\nPinCode    : " << Client.PinCode;
        cout << "\nBalance    : " << Client.AccountBalance;
        cout << "\n_______________________________\n";

    }


public:


    static void ShowFindClientScreen()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pFindClient))
            return;


        _DrawScreenHeader("\t   Find Client Screen");

        string AccountNumber = "";

        cout << "\nPLease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAcocunt Number is Not Found, Choose Another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.IsEmpty())
        {
            cout << "\nClient Found :-)\n";

            _PrintClientCard(Client);
        }
        else
        {
            cout << "\nClient Was Not Found :(\n";
        }

    }


};

