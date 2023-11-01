#pragma once

#include "core_headers.h"

#include "Curve.h"


/**
 * @class Helix
 * 
 * @brief The spatial Helix
 */
class Helix : public ParametricCurve {
public:
    
    /**
     * @brief      Constructs a new helix.
     *
     * @param[in]  center  The center
     * @param[in]  radius  The radius
     * @param[in]  step    The step
     */
    Helix(Point center, float radius, float step);

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
    float m_radius, m_step;
};