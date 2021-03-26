#include "Transporter.hpp"

Transporter::Transporter(
    const Mesh_1D &mesh, const Phases &saturation, const Phases &injector_concentration, const Phases &flow_rate)
    : Mesh_1D(mesh)
    , m_saturation(saturation)
    , m_injector_concentration(injector_concentration)
    , m_flow_rate(flow_rate)
{
}
