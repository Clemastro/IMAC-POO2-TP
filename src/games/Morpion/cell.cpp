#include "cell.hpp"
#include <p6/p6.h>
#include <iostream>

Cell::Cell(float _xposition, float _yposition, float _radius)
    : xposition(_xposition), yposition(_yposition), radius(_radius)
{
    color = p6::Color(0.5f, 0.5f, 0.5f);
}

void Cell::draw_a_cell(p6::Context& ctx)
{
    ctx.fill = color;
    ctx.square(p6::Center{xposition, yposition}, // Center on the middle of the window
               p6::Radius{radius},               // A radius of 1 would fit the entire window so this is quite a big square
               p6::Rotation{0.0_turn});          // Slightly tilt the square
}

void Cell::activate_cell(p6::Context& ctx)
{
    if (mouse_on_cell(ctx)) {
        color = p6::Color(0.8f, 0.8f, 0.8f);
    }
    else {
        color = p6::Color(0.5f, 0.5f, 0.5f);
    }
    draw_a_cell(ctx);
}

bool Cell::mouse_on_cell(p6::Context& ctx)
{
    bool xalign     = false;
    bool yalign     = false;
    bool mouse_over = false;
    if (ctx.mouse().x < xposition + radius && ctx.mouse().x > xposition - radius) {
        xalign = true;
    }
    if (ctx.mouse().y < yposition + radius && ctx.mouse().y > yposition - radius) {
        yalign = true;
    }
    if (xalign && yalign) {
        mouse_over = true;
    }
    return mouse_over;
}