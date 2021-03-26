#include "Grid.hpp"

Grid::Grid(const Range &x, const Range &y, const Range &z)
{
    this->set_discretization(x, y, z);
}

void Grid::set_discretization(const Range &x, const Range &y, const Range &z)
{
    m_cells.clear();
    m_cells.reserve(x.num * y.num * z.num);

    auto xcells = std::vector<double>(x.num);
    auto ycells = std::vector<double>(y.num);
    auto zcells = std::vector<double>(z.num);

    auto dx = this->linspace(xcells, x);
    auto dy = this->linspace(ycells, y);
    auto dz = this->linspace(zcells, z);

    for (const auto &z_item : zcells)
    {
        for (const auto &y_item : ycells)
        {
            for (const auto &x_item : xcells)
            {
                m_cells.push_back(Cell({x_item, y_item, z_item}, {dx, dy, dz}));
            }
        }
    }
}

double Grid::linspace(std::vector<double> &cells, const Range &proj)
{
    auto delta = proj.num > 1 ? (proj.end - proj.start) / (proj.num - 1) : proj.end;

    if (proj.num != 0)
    {
        if (proj.num == 1)
        {
            cells[0] = proj.start;
        }
        else
        {
            for (auto i = 0; i < (proj.num - 1); ++i)
            {
                cells[i] = proj.start + delta * i;
            }
            *cells.rbegin() = proj.end;
        }
    }
    return delta;
}
