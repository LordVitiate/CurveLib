#include "Helix.h"

Helix::Helix(Point center, float radius, float step) : 
	m_center(center), 
    m_radius(radius), 
    m_step(step)
{
	if (radius < 0) {
	throw std::invalid_argument("Radius must be positive.");
    }
}

Point Helix::C(float t) const {
	float x = std::get<0>(m_center) + m_radius * std::cos(t);
    float y = std::get<1>(m_center) + m_radius * std::sin(t);
    float z = std::get<2>(m_center) + m_step * t / (2 * M_PI);
    return Point(x, y, z);
}