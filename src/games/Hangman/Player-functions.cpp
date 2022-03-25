#include "Player-functions.hpp"
#include <iostream>

void show_number_of_lives(int number_of_lives)
{
    std::cout << "You have " << number_of_lives << " lives left\n";
}

bool player_is_alive(int number_of_lives)
{
    return !(number_of_lives == 0);
}

bool player_has_won(const std::vector<bool>& letters_guessed)
{
    bool all_guessed = true;
    for (const auto it : letters_guessed) {
        if (!it) {
            all_guessed = false;
        }
    }
    return all_guessed;
}

void remove_one_life(int& lives_count)
{
    lives_count--;
}

void show_congrat_message(const std::string& word_to_guess)
{
    std::cout << "Well done ! you guess the word : " << word_to_guess << std::endl;
}

void show_defeat_message(const std::string& word_to_guess)
{
    std::cout << "Game over, you lose all your lifes. The word was : " << word_to_guess << std::endl;
}