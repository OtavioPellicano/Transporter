#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

struct Point
{
    double x, y, z;
};

class Cell
{
  public:
    Cell(const Point &position, const Point &variation)
        : m_p(position)
        , m_d(variation)
    {
    }

    const Point &current() const
    {
        return m_p;
    }

    Point West() const
    {
        return {m_p.x, m_p.y - m_d.y, m_p.z};
    }

    Point East() const
    {
        return {m_p.x, m_p.y + m_d.y, m_p.z};
    }

    Point Noth() const
    {
        return {m_p.x, m_p.y, m_p.z + m_d.z};
    }

    Point South() const
    {
        return {m_p.x, m_p.y, m_p.z - m_d.z};
    }

    Point Front() const
    {
        return {m_p.x + m_d.x, m_p.y, m_p.z};
    }

    Point Back() const
    {
        return {m_p.x - m_d.x, m_p.y, m_p.z};
    }

  private:
    Point m_p; // Position
    Point m_d; // Variation
};

struct Range
{
    Range(double start = 0.0, double end = 0.0, int num = 1)
        : start(start)
        , end(end)
        , num(num)
    {
    }
    double start;
    double end;
    int num;
};

class Grid
{
  public:
    Grid(const Range &x = Range(), const Range &y = Range(), const Range &z = Range());

    void set_discretization(const Range &x, const Range &y, const Range &z);

  private:
    std::vector<Cell> m_cells;
    double linspace(std::vector<double> &cells, const Range &x);
};

#endif // GRID_HPP
