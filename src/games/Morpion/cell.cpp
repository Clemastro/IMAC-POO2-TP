#include "cell.hpp"
#include <p6/p6.h>

Cell::Cell(float _xposition, float _yposition, float _radius)
    : xposition(_xposition), yposition(_yposition), radius(_radius)
{
    color = p6::Color(0.5f, 0.5f, 0.5f);
}

void Cell::draw_a_cell(p6::Context& ctx)
{
    ctx.square(p6::Center{xposition, yposition}, // Center on the middle of the window
               p6::Radius{radius},               // A radius of 1 would fit the entire window so this is quite a big square
               p6::Rotation{0.0_turn});          // Slightly tilt the square
}
