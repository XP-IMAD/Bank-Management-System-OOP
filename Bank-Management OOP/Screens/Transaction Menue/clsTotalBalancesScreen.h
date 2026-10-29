#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"

class clsTotalBalancesScreen : protected clsScreen
{

private:


    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(11) << left << "" << "| " << left << setw(25) << Client.AccountNumber();
        cout << "| " << left << setw(40) << Client.FullName();
        cout << "| " << left << setw(15) << Client.AccountBalance;
    }

public:

    static void ShowTotalBalancesScreen()
    {
        
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        
        string Title = "\t   Total Balances Screen";
        string SubTitle = "\t   [" + to_string(vClients.size()) + "] Client(s).";
       
        _DrawScreenHeader(Title, SubTitle);
        
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________"
            << "______________\n" << endl;

        cout << setw(11) << left << "" << "| " << setw(25) << left << "Account Number";
        cout << "| " << setw(40) << left << "Client Name";
        cout << "| " << setw(15) << left << "Balance";

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________"
            << "_______________\n" << endl;


        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\tNo Client Available In The System :(\n";
        else
        {
            for (clsBankClient C : vClients)
            {
                _PrintClientRecordBalanceLine(C);

                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "______________________________________________________________________________________"
            << "______________\n" << endl;

        cout << "\t\t\t\t\t\t Total Balances = " << TotalBalances << endl;

        cout << "\n\t\t\t\t\t[ " << clsUtil::NumberToText(TotalBalances) << "]\n";

    }



};

