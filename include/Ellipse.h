#pragma once

#include "core_headers.h"

#include "Curve.h"

/**
 * @class Ellipse
 * 
 * @brief The planar Ellipse
 */
struct Ellipse : public ParametricCurve {
    /**
     * @brief      Constructs a new ellipse.
     *
     * @param[in]  center    The center
     * @param[in]  radius_x  The radius x
     * @param[in]  radius_y  The radius y
     */
    Ellipse(Point center, float radius_x, float radius_y);

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
    float m_radius_x, m_radius_y;
};