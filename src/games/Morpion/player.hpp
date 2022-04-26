#pragma once

#include "cell.hpp"
#include "grid.hpp"

void change_player(Value& player);

bool player_have_win(Grid& grid, Value& player);

bool grid_full(Grid& grid);