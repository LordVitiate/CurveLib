#include "Ellipse.h"

Ellipse::Ellipse(Point center, float radius_x, float radius_y) : 
	m_center(center), 
    m_radius_x(radius_x), 
	m_radius_y(radius_y)
{
	if (radius_x < 0.0 || radius_y < 0.0) {
	throw std::invalid_argument("Radii must be positive.");
	}
}

Point Ellipse::C(float t) const 	
{
	float x = std::get<0>(m_center) + m_radius_x * std::cos(t);
	float y = std::get<1>(m_center) + m_radius_y * std::sin(t);
    return Point(x, y, 0);
}
