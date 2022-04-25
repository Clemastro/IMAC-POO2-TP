#include "player.hpp"

void change_player(Value& player)
{
    switch (player) {
    case Value::cross:
        player = Value::nought;
        break;

    case Value::nought:
        player = Value::cross;
        break;

    default:
        break;
    }
}