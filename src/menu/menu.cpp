#include "menu.hpp"

//extern include
#include <functional>
#include <iostream>
#include <list>

//intern include
#include "../games/Guess_the_number/game-functions.hpp"
#include "../games/Hangman/Hangman.hpp"
#include "../games/Morpion/morpion.hpp"
#include "../generalFunctions/playerFunctions.hpp"
#include "Game.hpp"

void menu()
{
    //liste de commandes/fonctions
    std::list<Game> gamesList{
        Game("play Guess_the_Number", '1', play_guess_the_number),
        Game("play Hangman", '2', play_hangman),
        Game("play Crosses and Noughts", '3', morpion)};

    std::cout << "\nWhat do you want to play ?\n\n";
    showFunctions(gamesList);

    bool stop = false;
    while (!stop) {
        char command = get_char_from_user();

        switch (command) {
        case 'q':
            quit(stop);
            break;

        case 'c':
            showFunctions(gamesList);
            break;

        default:
            getPlayFunction(gamesList, command);
            break;
        }
    }
}

void showFunctions(std::list<Game> gamesList)
{
    std::cout << "Command list :\n";
    for (const auto& it : gamesList) {
        std::cout << " - press '" << it.command << "' to " << it.name << std::endl;
    }
    std::cout << " - press 'c' to show commands" << std::endl;
    std::cout << " - press 'q' to quit" << std::endl;
    std::cout << std::endl;
}

void getPlayFunction(std::list<Game> gamesList, char command)
{
    //selection de la fonction
    bool exist = false;
    for (const auto& it : gamesList) {
        if (it.command == command) {
            exist = true;
            it.function();
            std::cout << "\nPlay again ? ('c' to see commands)\n\n";
        }
    }

    //si aucune correspondance
    if (exist == false) {
        std::cout << "Command unknown, please give a right command\n";
    }
}

void quit(bool& stop)
{
    char answer;
    std::cout << "Do you really want to quit ? (O/n)\n";
    answer = get_char_from_user();
    if (answer == 'O' || answer == 'o') {
        std::cout << "bye\n";
        stop = true;
    }
}