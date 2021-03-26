#include "Mesh.hpp"

Mesh_1D::Mesh_1D(double start, double end, int num, double area)
    : m_area(area)
{
    this->set_discretization(start, end, num);
}

void Mesh_1D::set_discretization(double start, double end, int num)
{
    m_dx = this->linspace(m_cells, start, end, num);
}

double Mesh_1D::linspace(std::vector<double> &cells, double start, double end, int num)
{
    cells.clear();
    cells.resize(num);
    auto delta = num > 1 ? (end - start) / (num - 1) : end;

    if (num != 0)
    {
        if (num == 1)
        {
            cells[0] = start;
        }
        else
        {
            for (auto i = 0; i < (num - 1); ++i)
            {
                cells[i] = start + delta * i;
            }
            *cells.rbegin() = end;
        }
    }
    return delta;
}

const std::vector<double> &Mesh_1D::cells() const
{
    return m_cells;
}

double Mesh_1D::dx() const
{
    return m_dx;
}

double Mesh_1D::area() const
{
    return m_area;
}
