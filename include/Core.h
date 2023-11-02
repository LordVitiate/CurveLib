#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

using Element   = std::shared_ptr<ParametricCurve>;
using Container = std::vector<Element>;

/**
 * @class      ElementFabric
 *
 * @brief      This class describes an abstract element fabric.
 */
class ElementFabric {
public:
    /**
     * @brief      Makes an element.
     *
     * @return     The element
     */
    virtual Element MakeElement() = 0;
};

/**
 * @class      HelixFabric
 * @brief      This class describes a helix fabric.
 */
class HelixFabric : public ElementFabric 
{
protected:
    /**
     * @brief      Makes an helix
     *
     * @return     The helix
     */
    Element MakeElement() override final;
};

/**
 * @class      CircleFabric
 * @brief      This class describes a circle fabric.
 */
class CircleFabric : public ElementFabric 
{
protected:
    /**
     * @brief      Makes an circle.
     *
     * @return     the circle
     */
    Element MakeElement() override final;
};

/**
 * @class      EllipseFabric
 * @brief      This class describes an ellipse fabric.
 */
class EllipseFabric : public ElementFabric 
{
protected:
    /**
     * @brief      Makes an ellipse.
     *
     * @return     The ellipse
     */
    Element MakeElement() override final;
};

/**
 * @brief      This class describes a random container fabric
 */
class RandomManner
{
private:
	/**
	 * @brief      Fills container by random type elements
	 *
	 * @param      fabric     The concrete fabric
	 * @param      container  The container
	 */
	void FillContainer(ElementFabric& fabric, Container& container);
public:
	/**
	 * @brief      Creates a random container.
	 *
	 * @return     the full container
	 */
	Container CreateRandomContainer();
};


