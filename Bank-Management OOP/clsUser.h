#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"

class clsUser : public clsPerson
{

private:

	enum enMode {EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;

	string _UserName;
	string _Password;
	int _Permissions = 0;
	bool _MarkForDelete = false;

	struct stLoginRegisterRecord;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUser;
		vUser = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3],
			vUser[4], clsUtil::DecryptName(vUser[5]), stoi(vUser[6]));

	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string UserRecord = "";

		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += clsUtil::EncryptName(User.Password) + Seperator;
		UserRecord += to_string(User.Permissions);

		return UserRecord;
	}

	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string DataLine;

			while (getline(MyFile, DataLine))
			{
				clsUser User = _ConvertLineToUserObject(DataLine);
				vUsers.push_back(User);
			}

			MyFile.close();
		}

		return vUsers;

	}

	static void _SaveUserDataToFile(const vector<clsUser> &vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine;

			for (clsUser U : vUsers)
			{

				if (U.MarkForDeleted() == false)
				{
					DataLine = _ConvertUserObjectToLine(U);

					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}
		}

		_SaveUserDataToFile(vUsers);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

public:

	enum enPermissions
	{
		pAll = -1, pShowClientList = 1, pAddClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransactions = 32,
		pManageUsers = 64, pLoginRegister = 128
	};

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions = 0;
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string UserName, string Password, int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	bool MarkForDeleted()
	{
		return _MarkForDelete;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(short Permisssions)
	{
		_Permissions = Permisssions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}
		return _GetEmptyUserObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}

		case enMode::UpdateMode:
		{

			_Update();

			return enSaveResults::svSucceeded;
			break;
		}

		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNew();
				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}

	}

	static bool IsUserExist(string UserName)
	{

		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	bool Delete()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == _UserName)
			{
				if (U.Permissions != enPermissions::pAll)
				{
					U._MarkForDelete = true;
					break;
				}
				else
					return false;
			}

		}

		_SaveUserDataToFile(_vUsers);

		*this = _GetEmptyUserObject();

		return true;

	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	void ClearObject()
	{
		*this = _GetEmptyUserObject();
	}

	bool CheckAccessPermissions(enPermissions Permissions)
	{
		if (this->Permissions == enPermissions::pAll)
			return true;

		if ((this->Permissions & Permissions) == Permissions)
			return true;
		else
			return false;
	}


};

