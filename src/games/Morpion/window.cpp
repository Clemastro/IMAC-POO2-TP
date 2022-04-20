#include "window.hpp"

//p6
#include <p6/p6.h>
#include <iostream>

void create_grid(p6::Context& ctx, int n)
{
    ctx.fill = p6::Color(0.5f, 0.5f, 0.5f);
    for (int i = 0; i < n; i++) {
        float xcenter = (1.0f / (n * 0.5)) * (i % n) - (((n - 1) * 1.0f) / n);
        std::cout << xcenter << std::endl;
        for (int j = 0; j < n; j++) {
            float ycenter = (1.0f / (n * 0.5)) * (j % n) - (((n - 1) * 1.0f) / n);
            ctx.square(p6::Center{xcenter, ycenter}, // Center on the middle of the window
                       p6::Radius{1.0f / n},         // A radius of 1 would fit the entire window so this is quite a big square
                       p6::Rotation{0.0_turn});      // Slightly tilt the square
        }
    }
}