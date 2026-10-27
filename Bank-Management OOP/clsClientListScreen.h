#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
using namespace std;

class clsClientListScreen : protected clsScreen
{

private:

    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(22) << Client.FullName();
        cout << "| " << left << setw(20) << Client.Email;
        cout << "| " << left << setw(15) << Client.Phone;
        cout << "| " << left << setw(10) << Client.PinCode;
        cout << "| " << left << setw(12) << Client.AccountBalance;
    }

public:

    static void ShowClientsList()
    {

        if (!CheckAccessRight(clsUser::enPermissions::pShowClientList))
            return;


        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t    Client List Screen";
        string SubTitle = "\t    [" + to_string(vClients.size()) + "] Client(s).\n";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(22) << "Client Name";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(15) << "Phone";
        cout << "| " << left << setw(10) << "PinCode";
        cout << "| " << left << setw(12) << "Balance";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "________________________________________________\n" << endl;

        if (vClients.size() == 0)
        {
            cout << "\n\t\t\tNo Client Available in The System :(\n";
        }
        else
        {
            for (const clsBankClient &C : vClients)
            {
                _PrintClientRecordLine(C);

                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "_______________________________________________________________";
        cout << "________________________________________________\n" << endl;

    }

};

