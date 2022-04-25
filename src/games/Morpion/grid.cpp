#include "grid.hpp"

Grid::Grid(int _nb_case)
    : nb_case(_nb_case)
{
    for (int i = 0; i < nb_case; i++) {
        float xcenter = (1.0f / (nb_case * 0.5f)) * (i % nb_case) - (((nb_case - 1) * 1.0f) / nb_case);
        for (int j = 0; j < nb_case; j++) {
            float ycenter = (1.0f / (nb_case * 0.5f)) * (j % nb_case) - (((nb_case - 1) * 1.0f) / nb_case);
            cells.push_back(Cell(xcenter, ycenter, 1.0f / nb_case));
        }
    }
}

void Grid::draw_grid(p6::Context& ctx)
{
    for (auto& cell : cells) {
        cell.draw_a_cell(ctx);
    }
}

void Grid::activate_cells(p6::Context& ctx)
{
    for (auto& cell : cells) {
        cell.activate_cell(ctx);
    }
}