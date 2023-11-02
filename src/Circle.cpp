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
	float x = m_center.x()  + m_radius * std::cos(t);
	float y = m_center.y() + m_radius * std::sin(t);
	return Point(x, y);
}

Point Circle::dC(float t) const {
	float dx = -  m_radius * std::sin(t);
	float dy =    m_radius * std::cos(t);
	return Point(dx, dy);
}

float Circle::getRadius() const { return m_radius; }

