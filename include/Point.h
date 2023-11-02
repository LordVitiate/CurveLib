#pragma once

#include "core_headers.h"

class SpatialPoint 
{
public:
    virtual float x() const = 0;
    virtual float y() const = 0;
    virtual float z() const = 0;

};


class PlanarPoint : public SpatialPoint {
protected:
    float m_x;
    float m_y;
public:
    PlanarPoint(float x, float y): m_x(x), m_y(y) {}
    float x() const override {return m_x;}
    float y() const override {return m_y;}
    float z() const override {return 0.0;}

};


class SpacePoint : public PlanarPoint {
protected:
    float m_z;
public:
    SpacePoint(float x, float y, float z) : PlanarPoint(x, y), m_z(z) {}
    float z() const override {return m_z;}

};


struct Point
{
	Point(float x, float y) : point(std::make_shared<PlanarPoint>(x,y)) {}
	Point (float x, float y, float z) : point(std::make_shared<SpacePoint>(x,y,z)) {}
	float x() const {return point->x();}
    float y() const {return point->y();}
    float z() const {return point->z();}
private:
	std::shared_ptr<SpatialPoint> point;
};