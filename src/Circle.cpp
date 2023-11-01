#include "Circle.h"

Circle::Circle(Point center, float radius) : 
    m_center(center), 
    m_radius(radius) 
{
	if (radius <= 0.0) {
		throw std::invalid_argument("Radius must be positive!");
	}
}

Point Circle::C(float t) const {
	float x = std::get<0>(m_center)  + m_radius * std::cos(t);
	float y = std::get<1>(m_center) + m_radius * std::sin(t);
	return Point(x, y, 0);
}

Point Circle::dC(float t) const {
	float dx = -  m_radius * std::sin(t);
	float dy =    m_radius * std::cos(t);
	return Point(dx, dy, 0);
}