#include "Hangman.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Player-functions.hpp"
#include "Random-functions.hpp"
#include "Word-functions.hpp"

void play_hangman()
{
    std::string       word_to_guess = pick_a_random_word();
    std::vector<bool> letters_guessed(word_to_guess.size(), false);
    int               player_lifes = 7;
    while (player_is_alive(player_lifes) && !player_has_won(letters_guessed)) {
        show_number_of_lives(player_lifes);
        show_the_word_with_missing_letters(word_to_guess, letters_guessed);
        const auto guess = get_char_from_user();
        if (word_contains(guess, word_to_guess)) {
            mark_as_guessed(guess, letters_guessed, word_to_guess);
        }
        else {
            remove_one_life(player_lifes);
        }
    }
    if (player_has_won(letters_guessed)) {
        show_congrat_message(word_to_guess);
    }
    else {
        show_defeat_message(word_to_guess);
    }
}