#pragma once

#include <p6/p6.h>

enum class Value {
    empty,
    cross,
    nought,
};

//This class define a cell on the grid
class Cell {
private:
    //--attributs
    float     xposition;
    float     yposition;
    float     radius;
    p6::Color color;
    bool      mouse_over;
    Value     value;

public:
    //--constructors
    Cell() = default;
    Cell(float _xposition, float _yposition, float radius);

    //--methods
    void draw_a_cell(p6::Context& ctx);
    void activate_cell(p6::Context& ctx, Value shape);
    void draw_shape(p6::Context& ctx, Value shape);
    void save_value(p6::Context& ctx, Value shape);

    bool mouse_on_cell(p6::Context& ctx);

    //--getters/setters
    inline float get_xposition() const
    {
        return xposition;
    }

    inline float get_yposition() const
    {
        return yposition;
    }

    inline float get_radius() const
    {
        return radius;
    }

    inline p6::Color get_color() const
    {
        return color;
    }

    inline Value get_value() const
    {
        return value;
    }

    inline void set_color(p6::Color _color)
    {
        color = _color;
    }
};