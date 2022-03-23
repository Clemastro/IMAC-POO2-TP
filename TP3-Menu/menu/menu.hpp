#pragma once
#include <list>
#include "Action.hpp"

//Main function for the menu :
void menu();

//show fonctions
void showFunctions(std::list<Action>);

//get play function by a command
void getPlayFunction(std::list<Action> actionList, char command);

//replay function
void quit(bool& stop);
