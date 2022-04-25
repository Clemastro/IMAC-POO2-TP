#pragma once

//std
#include <vector>

//p6
#include <p6/p6.h>

//intern include
#include "cell.hpp"

//This class define the grid of the game
class Grid {
private:
    //--attributs
    int               nb_case;
    std::vector<Cell> cells;

public:
    //--constructor
    Grid() = default;
    Grid(int _nb_case);

    //--methode
    void draw_grid(p6::Context& ctx);
};