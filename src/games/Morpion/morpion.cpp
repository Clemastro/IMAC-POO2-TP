#include "morpion.hpp"

//p6
#include <p6/p6.h>
#include <iostream>

//intern include
#include "cell.hpp"
#include "grid.hpp"

void morpion()
{
    try {
        // Create the canvas
        p6::Context ctx = p6::Context{{800, 800, "Morpion"}};
        //create a white background
        ctx.background({1.0f, 1.0f, 1.0f});

        //draw the grid
        Grid grid(3);
        grid.draw_grid(ctx);

        Value player = Value::cross;

        ctx.update = [&]() {
            grid.activate_cells(ctx, player);
        };

        ctx.mouse_pressed = [&](p6::MouseButton) {
            grid.save_value(ctx, player);
        };

        // Start the program
        ctx.start();
    }
    // Log any error that might occur
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}