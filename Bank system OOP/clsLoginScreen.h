#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainMenue.h"
#include "Global.h"
#include <fstream>
#include "C:\Users\juaitem computer\OneDrive - Al al-Bayt University\Documents\OOP Libraries\OOP Dates\clsDate.h"

class clsLoginScreen : protected clsScreen
{

private:
    static string _ConvertRigesterRecordToLine(clsUser user)
    {
        clsDate Date;
        
        string DataLine = Date.DateToString() + " - ";
        DataLine += user.UserName + "#//#";
        DataLine += user.Password + "#//#";
        DataLine += to_string(user.Permissions);
        return DataLine;
    }
    static void _LogRegister(string DataLine)
    {
        fstream MyFile;
        MyFile.open("Register.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile <<DataLine << endl;
            MyFile.close();
        }

    }
    static  bool _Login()
    {
        bool LoginFaild = false;
        short Triales = 3;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                Triales--;
                if (Triales < 1)
                {
                    cout << "You are blocked from the system .\n";
                    return false;
                }
                    
                
                cout << "\nInvlaid Username/Password!";
                printf("\nYou have %d triles more to log in \n.", Triales);

            }
            
            cout << "Enter Username? ";
            Username = clsInputValidate::ReadString();

            cout << "Enter Password? ";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        _LogRegister(_ConvertRigesterRecordToLine(CurrentUser));
        clsMainMenue::ShowMainMenue();

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }

};

