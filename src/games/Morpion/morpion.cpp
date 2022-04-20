#include "morpion.hpp"

//p6
#include <p6/p6.h>
#include <iostream>

//intern include
#include "window.hpp"

void morpion()
{
    try {
        // Create some objects
        p6::Context ctx = p6::Context{{800, 800, "Morpion"}};
        //create a white background
        ctx.background({0.5f, 0.5f, 0.5f});

        create_grid(ctx, 5);

        // Start the program
        ctx.start();
    }
    // Log any error that might occur
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}