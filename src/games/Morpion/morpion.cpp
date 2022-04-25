#include "morpion.hpp"

//p6
#include <p6/p6.h>
#include <iostream>

//intern include
#include "grid.hpp"

void morpion()
{
    try {
        // Create some objects
        p6::Context ctx = p6::Context{{800, 800, "Morpion"}};
        //create a white background
        ctx.background({0.0f, 0.0f, 0.0f});

        Grid grid(3);
        //draw the grid
        grid.draw_grid(ctx);

        ctx.update = [&]() {
            //std::cout << "x : " << ctx.mouse().x << " | y : " << ctx.mouse().y << std::endl;
            //std::cout << "Cell over : " << grid.get_Cell(0).mouse_on_cell(ctx) << std::endl;
            //grid.get_Cell(0).activate_cell(ctx);
            grid.activate_cells(ctx);
        };

        // Start the program
        ctx.start();
    }
    // Log any error that might occur
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}