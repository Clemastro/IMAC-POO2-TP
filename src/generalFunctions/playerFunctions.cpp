#include "playerFunctions.hpp"

int get_int_from_user()
{
    int value;
    std::cout << ">: ";
    std::cin >> value;
    return value;
}

char get_char_from_user()
{
    char character;
    while (std::cout << ">: " && !(std::cin >> character)) {
        std::cin.clear(); //clear bad input flag
        std::cout << "Invalid input, please re-enter.\n";
    }
    return character;
}