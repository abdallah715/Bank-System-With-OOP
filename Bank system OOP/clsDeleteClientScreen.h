#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "C:\Users\juaitem computer\OneDrive - Al al-Bayt University\Documents\OOP Libraries\Input Validate\clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
{
    static void _ReadClientInfo(clsBankClient& Client)
        {
            cout << "\nEnter FirstName: ";
            Client.SetFirstName(clsInputValidate::ReadString());

            cout << "\nEnter LastName: ";
            Client.SetLastName(clsInputValidate::ReadString());

            cout << "\nEnter Email: ";
            Client.SetEmail(clsInputValidate::ReadString());

            cout << "\nEnter Phone: ";
            Client.SetPhone(clsInputValidate::ReadString());

            cout << "\nEnter PinCode: ";
            Client.SetPinCode(clsInputValidate::ReadString());

            cout << "\nEnter Account Balance: ";
            Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
        }
    public:

    static void DeleteClient() 
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\tDelete client screen");
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        Client1.Print();

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            Client1.Delete();

            cout << "\nClient Deleted Successfully :-)\n";

            Client1.Print();
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }

    }

};

