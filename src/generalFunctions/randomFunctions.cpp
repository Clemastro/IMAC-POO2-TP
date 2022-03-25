#include "randomFunctions.hpp"

// extern includes
#include <array>
#include <random>

int randomInt(int min, int max)
{
    static std::default_random_engine  generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}

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