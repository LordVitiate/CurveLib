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
    PlanarPoint(float x, float y);
    float x() const override;
    float y() const override;
    float z() const override;

};


class SpacePoint : public PlanarPoint {
protected:
    float m_z;
public:
    SpacePoint(float x, float y, float z);
    float z() const override;

};


struct Point
{
	Point(float x, float y);
	Point (float x, float y, float z);
	float x() const;
    float y() const;
    float z() const;
private:
	std::shared_ptr<SpatialPoint> point;
};