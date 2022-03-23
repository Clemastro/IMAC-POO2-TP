#include "menu.hpp"
#include <functional>
#include <list>
#include "../games/Guess_the_number/game-functions.hpp"
#include "../games/Hangman/Hangman.hpp"
#include "../games/Hangman/Player-functions.hpp"

void menu()
{
    //liste de commandes/fonctions
    std::list<Action> actionList{
        Action("play Guess_the_Number", '1', play_guess_the_number),
        Action("play Hangman", '2', play_hangman)};

    std::cout << "\nWhat do you want to play ?\n\n";
    showFunctions(actionList);

    bool stop = false;
    while (!stop) {
        char command = get_char_from_user();

        switch (command) {
        case 'q':
            quit(stop);
            break;

        case 'c':
            showFunctions(actionList);
            break;

        default:
            getPlayFunction(actionList, command);
            std::cout << "\nPlay again ? ('c' to see commands)\n\n";
            break;
        }
    }
}

void showFunctions(std::list<Action> actionList)
{
    std::cout << "Command list :\n";
    for (const auto& it : actionList) {
        std::cout << " - press '" << it.command << "' to " << it.name << std::endl;
    }
    std::cout << " - press 'c' to show commands" << std::endl;
    std::cout << " - press 'q' to quit" << std::endl;
    std::cout << std::endl;
}

void getPlayFunction(std::list<Action> actionList, char command)
{
    //selection de la fonction
    bool exist = false;
    for (const auto& it : actionList) {
        if (it.command == command) {
            exist = true;
            it.function();
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
    std::cin >> answer;
    if (answer == 'O' || answer == 'o') {
        std::cout << "bye\n";
        stop = true;
    }
}