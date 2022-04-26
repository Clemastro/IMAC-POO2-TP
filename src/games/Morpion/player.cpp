#include "player.hpp"

//std
#include <iostream>
#include <vector>

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

bool player_have_win(Grid& grid, Value& player)
{
    bool             ans = false;
    std::vector<int> cells_of_player;
    for (size_t i = 0; i < grid.get_Cells().size(); i++) {
        if (grid.get_Cells()[i].get_value() == player) {
            cells_of_player.push_back(i);
        }
    }
    for (int index : cells_of_player) {
        switch (index) {
        case 0:
            if (grid.get_Cell(1).get_value() == player && grid.get_Cell(2).get_value() == player) {
                ans = true;
            }
            if (grid.get_Cell(3).get_value() == player && grid.get_Cell(6).get_value() == player) {
                ans = true;
            }
            if (grid.get_Cell(4).get_value() == player && grid.get_Cell(8).get_value() == player) {
                ans = true;
            }
            break;

        case 1:
            if (grid.get_Cell(4).get_value() == player && grid.get_Cell(7).get_value() == player) {
                ans = true;
            }
            break;

        case 2:
            if (grid.get_Cell(4).get_value() == player && grid.get_Cell(6).get_value() == player) {
                ans = true;
            }
            if (grid.get_Cell(5).get_value() == player && grid.get_Cell(8).get_value() == player) {
                ans = true;
            }
            break;

        case 3:
            if (grid.get_Cell(4).get_value() == player && grid.get_Cell(5).get_value() == player) {
                ans = true;
            }
            break;

        case 6:
            if (grid.get_Cell(7).get_value() == player && grid.get_Cell(8).get_value() == player) {
                ans = true;
            }
            break;

        default:
            break;
        }
        if (ans == true) {
            break;
        }
    }
    if (ans == true) {
        switch (player) {
        case Value::cross:
            std::cout << "Crosses WIN !!\n";
            break;

        case Value::nought:
            std::cout << "Noughts WIN !!\n";
            break;

        default:
            break;
        }
    }
    return ans;
}

bool grid_full(Grid& grid)
{
    for (const auto& cell : grid.get_Cells()) {
        if (cell.get_value() == Value::empty) {
            return false;
        }
    }
    return true;
}