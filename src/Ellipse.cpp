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
	float x = m_center.x() + m_radius_x * std::cos(t);
	float y = m_center.y() + m_radius_y * std::sin(t);
    return Point(x, y);
}

Point Ellipse::dC(float t) const 	
{
	float dx = -  m_radius_x * std::sin(t);
	float dy =    m_radius_y * std::cos(t);
    return Point(dx, dy);
}

float Ellipse::getRadius() const { return 0; }
