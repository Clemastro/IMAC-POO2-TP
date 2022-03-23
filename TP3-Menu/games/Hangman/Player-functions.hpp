#pragma once

#include <string>
#include <vector>

//ask the user to give a char
char get_char_from_user();

//show number of live you have
void show_number_of_lives(int number_of_lives);

//return true if the player still alive
bool player_is_alive(int number_of_lives);

//verify if the player guess all letters
bool player_has_won(const std::vector<bool>& letters_guessed);

//remove a life
void remove_one_life(int& lives_count);

//cout a congrat message
void show_congrat_message(const std::string& word_to_guess);

//cout a defeat message
void show_defeat_message(const std::string& word_to_guess);