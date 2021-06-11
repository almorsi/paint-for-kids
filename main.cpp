/*
* This project is created by:
    ___                                      _   __
   /   |  ____ ___  ____ ___  ____ ______   / | / /___ ______________  _____
  / /| | / __ `__ \/ __ `__ \/ __ `/ ___/  /  |/ / __ `/ ___/ ___/ _ \/ ___/
 / ___ |/ / / / / / / / / / / /_/ / /     / /|  / /_/ (__  |__  )  __/ /
/_/  |_/_/ /_/ /_/_/ /_/ /_/\__,_/_/     /_/ |_/\__,_/____/____/\___/_/

___  ___      _                              _  __   __    _     _
|  \/  |     | |                            | | \ \ / /   | |   (_)
| .  . | ___ | |__   __ _ _ __ ___   ___  __| |  \ V /__ _| |__  _  __ _
| |\/| |/ _ \| '_ \ / _` | '_ ` _ \ / _ \/ _` |   \ // _` | '_ \| |/ _` |
| |  | | (_) | | | | (_| | | | | | |  __/ (_| |   | | (_| | | | | | (_| |
\_|  |_/\___/|_| |_|\__,_|_| |_| |_|\___|\__,_|   \_/\__,_|_| |_|_|\__,_|
	on 06/11/21
 */

#include "ApplicationManager.h"


int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	}while(ActType != EXIT);
	

	
	return 0;
}

