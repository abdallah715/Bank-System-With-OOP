#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "C:\Users\juaitem computer\OneDrive - Al al-Bayt University\Documents\OOP Libraries\Input Validate\clsInputValidate.h"
#include <iomanip>
#include "clsMainMenue.h"
#include "clsDeposit.h"
#include "clsWithdrow.h"
#include "clsTotalBalances.h"

class clsTransactions : protected clsScreen 
{
private :
	enum enTransactionsOptions
	{
		eDeposit = 1 , eWithdraw = 2 , eTotalBlances = 3 , eMainMenue = 4
	};
    static  void _GoBackToTransitions()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowTransactions();
    }
    /*static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        clsMainMenue::ShowMainMenue();
    }*/
    static short _ReadTransitionsOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4 ? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDeposit::ShowDepositScreen();
    }

    static void _ShowWithdrowScreen()
    {
        clsWithdrow::ShowWithdrowScreen();
    }

    static void _ShowAllBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _PerfromTransactionsOption(enTransactionsOptions TransactionsOption)
    {
        switch (TransactionsOption)
        {
        case enTransactionsOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransitions();
            break;
        }
        case enTransactionsOptions::eWithdraw:
            system("cls");
            _ShowWithdrowScreen();
            _GoBackToTransitions();
            break;

        case enTransactionsOptions::eTotalBlances:
            system("cls");
            _ShowAllBalancesScreen();
            _GoBackToTransitions();
            break;

            case enTransactionsOptions::eMainMenue:
            break;

        }

    }

public :
	static void ShowTransactions()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }
		_DrawScreenHeader("\t\tTransactions menue");
        system("cls");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransitions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdrow.\n";
        cout << setw(37) << left << "" << "\t[3] Total balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTransactionsOption((enTransactionsOptions)_ReadTransitionsOption());

	}
};

