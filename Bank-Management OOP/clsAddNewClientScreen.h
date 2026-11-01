#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsAddNewClientScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient &Client)
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
        Client.AccountBalance = clsInputValidate::ReadNumber<double>();
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

    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pAddClient))
            return;

        _DrawScreenHeader("\t   Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResult::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClientCard(NewClient);
            break;
        }
        case clsBankClient::enSaveResult::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResult::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }

};

