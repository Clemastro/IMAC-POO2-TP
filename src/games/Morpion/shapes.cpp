#include "shapes.hpp"

void draw_cross(p6::Context& ctx, float xposition, float yposition, float radius)
{
    ctx.stroke_weight = 0.05f;
    ctx.line(glm::vec2(xposition - radius, yposition - radius), glm::vec2(xposition + radius, yposition + radius));
    ctx.line(glm::vec2(xposition - radius, yposition + radius), glm::vec2(xposition + radius, yposition - radius));
}

void draw_nought(p6::Context& ctx, float xposition, float yposition, float radius)
{
    ctx.stroke_weight = 0.1f;
    ctx.circle(p6::Center(xposition, yposition), p6::Radius(radius + 0.05));
}