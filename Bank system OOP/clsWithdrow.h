#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "C:\Users\juaitem computer\OneDrive - Al al-Bayt University\Documents\OOP Libraries\Input Validate\clsInputValidate.h"
#include <iomanip>
#include "clsMainMenue.h"

class clsWithdrow : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
public:
	static void ShowWithdrowScreen()
	{
		_DrawScreenHeader("  Withdrow screen");
		cout << "Enter a valid account number : ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient client = clsBankClient::Find(AccountNumber);
		_PrintClient(client);
		cout << "\nHow much do you want to withdrow : ";
		int x = clsInputValidate::ReadIntNumber();
		client.AccountBalance -= x;
		clsBankClient::enSaveResults SaveResult;
		SaveResult = client.Save();
		cout << "\nAccount balance after withdrow is : " << client.AccountBalance << endl;
	}
};

