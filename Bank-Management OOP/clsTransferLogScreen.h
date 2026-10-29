#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"

class clsTransferLogScreen : protected clsScreen
{
private:

	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLog)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << TransferLog.DateTime;
		cout << "| " << setw(8) << left << TransferLog.S_Acct;
		cout << "| " << setw(8) << left << TransferLog.D_Acct;
		cout << "| " << setw(10) << left << TransferLog.Amount;
		cout << "| " << setw(13) << left << TransferLog.S_Balance;
		cout << "| " << setw(13) << left << TransferLog.D_Balance;
		cout << "| " << setw(10) << left << TransferLog.UserName;
	}


public:

	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLogRecord> vTransferLog = clsBankClient::GetTransferLogList();

		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t    [" + to_string(vTransferLog.size()) + "] Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________"
			<< "______________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(25) << left << "Date/Time";
		cout << "| " << setw(8) << left << "S.Acct";
		cout << "| " << setw(8) << left << "D.Acct";
		cout << "| " << setw(10) << left << "Amount";
		cout << "| " << setw(13) << left << "S.Balance";
		cout << "| " << setw(13) << left << "D.Balance";
		cout << "| " << setw(10) << left << "User Name";

		cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________"
			<< "_______________\n" << endl;

		if (vTransferLog.size() == 0)
		{
			cout << "\n\t\t\tNo Transfer Logs In The System :(\n";
		}

		for (clsBankClient::stTransferLogRecord T : vTransferLog)
		{
			_PrintTransferLogRecordLine(T);

			cout << endl;
		}

		cout << setw(8) << left << "" << "______________________________________________________________________________________"
			<< "_______________\n" << endl;

	}

};

