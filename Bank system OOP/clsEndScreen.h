#pragma once
#include <iostream>
#include "clsMainMenue.h"
#include "clsLoginScreen.h"
#include "Global.h"
class clsEndScreen : protected clsScreen
{
private :

public :
	static void ShowLogOutScreen()
	{
		system("cls");
		CurrentUser = clsUser::Find("", "");
		clsLoginScreen::ShowLoginScreen();
	}
};

