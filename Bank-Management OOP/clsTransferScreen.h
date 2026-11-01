#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTrnasferScreen : protected clsScreen
{
private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\nClient Card";
		cout << "\n________________________________________\n";
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nAcc.Number : " << Client.AccountNumber();
		cout << "\nBalance    : " << Client.AccountBalance;
		cout << "\n________________________________________\n";


	}

	static string _ReadAccountNumber(string message)
	{
		string AccountNumber = "";

		cout << message;
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Not Found! Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static bool _IsSameClient(clsBankClient SourceClient, clsBankClient DestinationClient)
	{
		return (SourceClient.AccountNumber() == DestinationClient.AccountNumber());
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount = 0;

		cout << "\nEnter Trasfer Amount: ";
		Amount = clsInputValidate::ReadPositiveNumber<double>();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds The Available Balance, Enter Another Amount: ";
			Amount = clsInputValidate::ReadPositiveNumber<double>();
		}

		return Amount;
	}

public:
	
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPLease Enter Account Number To Transfer From: "));
		_PrintClientCard(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPLease Enetr Account Number To Transfer To: "));
		
		while (_IsSameClient(SourceClient, DestinationClient))
		{
			cout << "\nSorry, You Can't Trasfer Money To Your Self!";
			DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPLease Enetr Account Number To Transfer To: "));
		}

		_PrintClientCard(DestinationClient);

		double Amount = _ReadAmount(SourceClient);

		char Answer = 'n';

		cout << "\nAre You Sure You Want To Perform This Operation? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer Done Successfully :)\n";
				_PrintClientCard(SourceClient);
				_PrintClientCard(DestinationClient);
				

			}
			else
			{
				cout << "\nError, Transfer Failed :(\n";
			}
		}

	}

};

