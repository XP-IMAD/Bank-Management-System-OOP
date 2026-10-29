#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsUpdateClientScreen : protected clsScreen
{

private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadDblNumber();
    }

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

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pUpdateClient))
            return;


        _DrawScreenHeader("\t   Update Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is Not Found, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientCard(Client1);

        char Answer = 'n';

        cout << "\nAre You Sure You Want To Update This Client? [Y/N]: ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            cout << "\nUpdate Client Info :";
            cout << "\n__________________________________\n";
            _ReadClientInfo(Client1);

            clsBankClient::enSaveResult SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResult::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintClientCard(Client1);
                break;
            }
            case clsBankClient::enSaveResult::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }
            }
        }
    }

};

