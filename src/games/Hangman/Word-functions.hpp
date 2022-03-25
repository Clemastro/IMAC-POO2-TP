#pragma once

#include <string> //string
#include <vector> //stock all letters guessed

//show the word with missing letters
void show_the_word_with_missing_letters(const std::string& word, const std::vector<bool>& letters_guessed);

//verify if the word contain the letter
bool word_contains(char letter, std::string word);

//add the letter guessed into a list
void mark_as_guessed(char guessed_letter, std::vector<bool>& letters_guessed, std::string word_to_guess);