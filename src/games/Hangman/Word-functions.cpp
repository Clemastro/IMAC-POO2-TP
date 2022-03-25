#include "Word-functions.hpp"
#include <iostream>
#include <string>

void show_the_word_with_missing_letters(const std::string& word, const std::vector<bool>& letters_guessed)
{
    for (size_t i = 0; i < word.size(); i++) {
        if (letters_guessed[i]) {
            std::cout << word[i] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

bool word_contains(char letter, std::string word)
{
    return word.find(letter) < word.size();
}

void mark_as_guessed(char guessed_letter, std::vector<bool>& letters_guessed, std::string word_to_guess)
{
    size_t position = word_to_guess.find(guessed_letter, 0);
    size_t index    = 0;
    while (position != std::string::npos && index <= word_to_guess.size()) {
        letters_guessed[position] = true;
        position                  = word_to_guess.find(guessed_letter, position++);
        index++;
    }
}