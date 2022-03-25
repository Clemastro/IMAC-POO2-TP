#include "game-functions.hpp"

//external includes
#include <iostream> //cin-cout

//intern includes
#include "../../generalFunctions/playerFunctions.hpp" //get_value_from_user
#include "../../generalFunctions/randomFunctions.hpp" //randomInt

void play_guess_the_number()
{
    std::cout << "Welcome, you will have to guess a number. Choose a min and a max\n";

    //the player choose the min and the max
    int min;
    std::cout << "min : ";
    std::cin >> min;

    int max;
    std::cout << "max : ";
    std::cin >> max;

    //generate a random number
    int random_int = randomInt(min, max);
    std::cout << "I have generate a number can you guess it ?\n";

    //let's play
    int  score    = 0;
    bool finished = false;
    while (!finished) {
        score++;
        int int_guess = get_int_from_user();
        if (int_guess == random_int) {
            std::cout << "Correct !\n";
            std::cout << "Your score is " << score << std::endl;
            finished = true;
        }

        else {
            std::cout << "Wrong, try ";

            if (int_guess > random_int) {
                std::cout << "smaller\n";
            }

            else {
                std::cout << "greater\n";
            }
        }
    }
}