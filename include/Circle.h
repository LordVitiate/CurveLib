#pragma once

#include "core_headers.h"

#include "Curve.h"

/**
 * @class Circle
 * @brief      The planar circle
 */

struct Circle : ParametricCurve {

    /**
     * @brief      Constructs a new instance.
     *
     * @param[in]  center  The center
     * @param[in]  radius  The radius
     */
    Circle(Point center, float radius);

    /**
     * @brief      Calculates the point. C(t)-function
     *
     * @param[in]  t     natural parameter
     *
     * @return     The point.
     */
    Point C(float t) const override;

    /**
     * @brief      Calculates the point. C(t)-function
     *
     * @param[in]  t     natural parameter
     *
     * @return     The point.
     */
    Point dC(float t) const override;
private:
    Point m_center;
    float m_radius;
};