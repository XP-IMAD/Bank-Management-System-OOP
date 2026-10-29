#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsDepositScreen : protected clsScreen
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

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";

        cout << "\nPLease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
    
        return AccountNumber;
    }

public:

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t\tDeposit Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number[" << AccountNumber << "] Not Found!";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClientCard(Client);

        double Amount = 0;
        cout << "\nPLease Enter Deposit Amount: ";
        Amount = clsInputValidate::ReadPositiveDblNumber();


        cout << "\nAre You Sure You Want To Perform This Trasaction? [Y/N]: ";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Client.Deposit(Amount);
            cout << "\nDeposit Done Successfully, New Balance = "
                << Client.AccountBalance << endl;

        }
        else
        {
            cout << "\nOperation Was Cancelled :(\n";
        }

    }

};
