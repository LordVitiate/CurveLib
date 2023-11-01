#pragma once

using Point = std::tuple<float, float, float>;

/**
 * @brief      Pure abstract interface
 */
struct ParametricCurve {
    virtual Point C(float t) const = 0;
    virtual Point dC(float t) const = 0;
};

