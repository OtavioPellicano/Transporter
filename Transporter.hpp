#ifndef TRANSPORTER_HPP
#define TRANSPORTER_HPP

#include "Mesh.hpp"

struct Phases
{
    Phases(double water, double oil, double gas)
        : water(water)
        , oil(oil)
        , gas(gas)
    {
    }

    Phases &operator-()
    {
        this->water = -this->water;
        this->oil = -this->oil;
        this->gas = -this->gas;
        return *this;
    }

    double water;
    double oil;
    double gas;
};

class Transporter : public Mesh_1D
{
  public:
    Transporter(
        const Mesh_1D &mesh = {}, const Phases &saturation = {1., 0., 0.},
        const Phases &injector_concentration = {.1, 0., 0.}, const Phases &flow_rate = {20., 0., 0.});

  private:
    const int m_number_of_time_steps = 100;
    Phases m_saturation;
    Phases m_injector_concentration;
    Phases m_flow_rate;

    const double m_total_volume = this->area() * (*this->cells().rbegin());
    const double m_bulk_volume = m_total_volume / this->cells().size();
    const double m_porosity = .3;
    const double m_pore_volume = m_porosity * m_bulk_volume;
    Phases m_density{1000., 800., 200.};
    const int m_injector_cell_index = 0;
    const int m_producer_cell_index = this->cells().size() - 1;
    Phases m_injector_rate = -m_flow_rate;
    Phases m_producer_rate = m_flow_rate;
};

#endif // TRANSPORTER_HPP
