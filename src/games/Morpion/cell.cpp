#include "cell.hpp"

//p6
#include <p6/p6.h>

//std
#include <iostream>

//intern include
#include "player.hpp"
#include "shapes.hpp"

Cell::Cell(float _xposition, float _yposition, float _radius)
    : xposition(_xposition), yposition(_yposition), radius(_radius)
{
    color = p6::Color(0.5f, 0.5f, 0.5f);
    value = Value::empty;
}

void Cell::draw_a_cell(p6::Context& ctx)
{
    ctx.stroke_weight = 0.01f;
    ctx.fill          = color;
    ctx.square(p6::Center{xposition, yposition}, // Center on the middle of the window
               p6::Radius{radius},               // A radius of 1 would fit the entire window so this is quite a big square
               p6::Rotation{0.0_turn});          // Slightly tilt the square
    if (value != Value::empty) {
        draw_shape(ctx, value);
    }
}

void Cell::activate_cell(p6::Context& ctx, Value shape)
{
    if (mouse_on_cell(ctx)) {
        color = p6::Color(0.8f, 0.8f, 0.8f);
        if (value != Value::empty) {
            color = p6::Color(0.8f, 0.3f, 0.3f);
        }
        draw_a_cell(ctx);
        draw_shape(ctx, shape);
    }
    else {
        color = p6::Color(0.5f, 0.5f, 0.5f);
        draw_a_cell(ctx);
    }
}

void Cell::draw_shape(p6::Context& ctx, Value shape)
{
    switch (shape) {
    case Value::cross:
        draw_cross(ctx, xposition, yposition, radius - 0.1);
        break;

    case Value::nought:
        draw_nought(ctx, xposition, yposition, radius - 0.1);
        break;

    default:
        break;
    }
}

void Cell::save_value(p6::Context& ctx, Value& shape)
{
    if (mouse_on_cell(ctx) && value == Value::empty) {
        value = shape;
        change_player(shape);
    }
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