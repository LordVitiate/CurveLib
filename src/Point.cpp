#include "Point.h"

PlanarPoint::PlanarPoint(float x, float y): m_x(x), m_y(y) {}
float PlanarPoint::x() const {return m_x;}
float PlanarPoint::y() const {return m_y;}
float PlanarPoint::z() const {return 0.0;}

SpacePoint::SpacePoint(float x, float y, float z) : PlanarPoint(x, y), m_z(z) {}
float SpacePoint::z() const {return m_z;}

Point::Point(float x, float y) : point(std::make_shared<PlanarPoint>(x,y)) {}
Point::Point (float x, float y, float z) : point(std::make_shared<SpacePoint>(x,y,z)) {}
float Point::x() const {return point->x();}
float Point::y() const {return point->y();}
float Point::z() const {return point->z();}
