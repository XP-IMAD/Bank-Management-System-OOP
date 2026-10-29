#pragma once

#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete = false;

	struct stTransferLogRecord;

	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TransferLogRecord;

		vector<string> vTransferLog = clsString::Split(Line, Seperator);

		TransferLogRecord.DateTime = vTransferLog[0];
		TransferLogRecord.S_Acct = vTransferLog[1];
		TransferLogRecord.D_Acct = vTransferLog[2];
		TransferLogRecord.Amount = stod(vTransferLog[3]);
		TransferLogRecord.S_Balance = stod(vTransferLog[4]);
		TransferLogRecord.D_Balance = stod(vTransferLog[5]);
		TransferLogRecord.UserName = vTransferLog[6];

		return TransferLogRecord;
	}

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClient;
		vClient = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3],
			vClient[4], vClient[5], stod(vClient[6]));

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string ClientLine = "";

		ClientLine += Client.FirstName + Seperator;
		ClientLine += Client.LastName + Seperator;
		ClientLine += Client.Email + Seperator;
		ClientLine += Client.Phone + Seperator;
		ClientLine += Client.AccountNumber() + Seperator;
		ClientLine += Client.PinCode + Seperator;
		ClientLine += to_string(Client.AccountBalance);

		return ClientLine;
	}

	static vector<clsBankClient> _LoadClientDataFromFile()
	{
		vector<clsBankClient> vClients;
		
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string DataLine;

			while (getline(MyFile, DataLine))
			{
				clsBankClient Client = _ConvertLineToClientObject(DataLine);
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;

	}

	static void _SaveClientDataToFile(const vector<clsBankClient> &vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine;

			for (clsBankClient C : vClients)
			{
				
				if(C.MarkForDeleted() == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsBankClient> vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientDataToFile(vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

	string _PrepareTransferLogLine(clsBankClient DestinationClient, double Amount, string UserName, string Seperator = "#//#")
	{
		string TransferLogLine = "";

		TransferLogLine += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogLine += AccountNumber() + Seperator;
		TransferLogLine += DestinationClient.AccountNumber() + Seperator;
		TransferLogLine += to_string(Amount) + Seperator;
		TransferLogLine += to_string(AccountBalance) + Seperator;
		TransferLogLine += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogLine += UserName;
	
		return TransferLogLine;
	}

	void _RegisterTransferLog(clsBankClient DestinationClient, double Amount, string UserName)
	{
		string DataLine = _PrepareTransferLogLine(DestinationClient, Amount, UserName);
		
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;

			MyFile.close();
		}

	}

	

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, 
		string AccountNumber, string PinCode, double AccountBalance) : 
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	struct stTransferLogRecord
	{
		string DateTime;
		string S_Acct;
		string D_Acct;
		double Amount = 0;
		double S_Balance;
		double D_Balance;
		string UserName;

	};

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkForDeleted()
	{
		return _MarkForDelete;
	}

	string AccountNumber()
	{
		return  _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	enum enSaveResult {svFaildEmptyObject = 0 , svSucceeded = 1, svFaildAccountNumberExists};

	enSaveResult Save()
	{
		
		switch (_Mode)
		{

		case enMode::EmptyMode:
		{

			return enSaveResult::svFaildEmptyObject;
			break;

		}
		case enMode::UpdateMode:
		{

			_Update();

			return enSaveResult::svSucceeded;
			break;

		}
		case enMode::AddNewMode:
		{
			if (IsClientExist(_AccountNumber))
			{
				return enSaveResult::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;

			}

			break;
		}

		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient> vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}

		_SaveClientDataToFile(vClients);

		*this = _GetEmptyClientObject();

		return true;

	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalance = 0;

		for (clsBankClient Client : vClients)
		{
			TotalBalance += Client.AccountBalance;
		}

		return TotalBalance;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(double Amount, clsBankClient& DestinationClient, string UserName)
	{
		if (Amount > AccountBalance)
			return false;

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(DestinationClient, Amount, UserName);
		return true;
	}

	static vector<stTransferLogRecord> GetTransferLogList()
	{
		vector<stTransferLogRecord> vTransferLogs;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in); //Red Mode


		if (MyFile.is_open())
		{
			string DataLine;

			stTransferLogRecord TransferLogRecord;

			while (getline(MyFile, DataLine))
			{
				TransferLogRecord = _ConvertTransferLogLineToRecord(DataLine);

				vTransferLogs.push_back(TransferLogRecord);
			}

			MyFile.close();
		}

		return vTransferLogs;
	}
	
};

