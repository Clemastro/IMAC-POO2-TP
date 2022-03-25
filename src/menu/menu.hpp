#pragma once
#include <list>
#include "Game.hpp"

//Main function for the menu :
void menu();

//show fonctions
void showFunctions(std::list<Game>);

//get play function by a command
void getPlayFunction(std::list<Game> actionList, char command);

//replay function
void quit(bool& stop);
