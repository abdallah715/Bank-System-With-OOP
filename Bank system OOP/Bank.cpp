#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "C:\Users\juaitem computer\OneDrive - Al al-Bayt University\Documents\OOP Libraries\Input Validate\clsInputValidate.h"
#include "C:\Users\juaitem computer\source\repos\Bank system OOP\Bank system OOP\clsUtil.h"
#include "clsMainMenue.h"
#include "clsScreen.h"
#include "clsLoginScreen.h"
#include "Global.h"
int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        break;
    }
    return 0;
}