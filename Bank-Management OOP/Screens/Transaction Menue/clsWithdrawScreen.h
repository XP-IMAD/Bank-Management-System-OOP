#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsWithdrawScreen : protected clsScreen
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

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t\tWithdraw Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number[" << AccountNumber << "] Not Found!";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClientCard(Client);

        double Amount = 0;
        cout << "\nPLease Enter Withdraw Amount: ";
        Amount = clsInputValidate::ReadPositiveDblNumber();

        while (Amount > Client.AccountBalance)
        {
            cout << "\nAmount Exeeds The Balance, You Can't Withdraw Up To : "
                << Client.AccountBalance << endl;
            cout << "\nPLease Enter Another Amount: ";
            Amount = clsInputValidate::ReadPositiveDblNumber();

        }

        cout << "\nAre You Sure You Want To Perform This Trasaction? [Y/N]: ";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client.Withdraw(Amount))
            {
                cout << "\nWithdraw Done Successfully, New Balance = "
                    << Client.AccountBalance << endl;
            }
            else
            {
                cout << "\nCannot Withdraw, Insuffecient Balance!";
                cout << "\nAmount To Withdraw is : " << Amount;
                cout << "\nYour Balance is : " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\nOperaton was Cancelled :(\n";
        }
        
    }

};

