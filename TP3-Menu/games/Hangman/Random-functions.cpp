#include "Random-functions.hpp"
#include <array>                                  //create an array of word with std::array
#include "../Guess_the_number/game-functions.hpp" //RandomInt()

const char* pick_a_random_word()
{
    static constexpr std::array words = {
        "code",
        "crous",
        "imac",
        "opengl",
        "jules",
    };

    int random_index = randomInt(0, words.size() - 1);

    return words[random_index];
}