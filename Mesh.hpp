#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

class Mesh_1D
{
  public:
    Mesh_1D(double start = 0.0, double end = 3000.0, int num = 20, double area = 1.0);
    void set_discretization(double start, double end, int num);

  private:
    double linspace(std::vector<double> &cells, double start, double end, int num);

  protected:
    const std::vector<double> &cells() const;
    double dx() const;
    double area() const;

  private:
    double m_dx;
    double m_area;
    std::vector<double> m_cells;
};

#endif // MESH_HPP
