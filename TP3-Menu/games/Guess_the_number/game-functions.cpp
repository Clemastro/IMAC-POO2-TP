#include "game-functions.hpp"

int randomInt(int min, int max)
{
    static std::default_random_engine  generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}

int get_int_from_user()
{
    int number;
    std::cout << "Give a number (int) : ";
    std::cin >> number;
    return number;
}

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
    int  int_guess;
    int  score    = 0;
    bool finished = false;
    while (!finished) {
        score++;

        std::cin >> int_guess;

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