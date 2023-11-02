#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>

using Element   = std::shared_ptr<ParametricCurve>;
using Container = std::vector<Element>;

class ElementFabric {
public:
    virtual Element MakeElement() = 0;
};

class HelixFabric : public ElementFabric 
{
protected:
    Element MakeElement() override final
    {
       return std::make_shared<Helix>(Point(rand() % 10, rand() % 10, rand() % 10), rand() % 5 + 1, 1);
    }
};

class CircleFabric : public ElementFabric 
{
protected:
    Element MakeElement() override final
    {
		return std::make_shared<Circle>(Point(rand() % 10, rand() % 10, 0), rand() % 5 + 1);
    }
};

class EllipseFabric : public ElementFabric 
{
protected:
    Element MakeElement() override final
    {
		return std::make_shared<Ellipse>(Point(rand() % 10, rand() % 10, 0), rand() % 5 + 1, rand() % 5 + 1);
    }
};

class RandomManner
{
private:
	void FillContainer(ElementFabric& fabric, Container& container)
	{
		for (int i = 0; i < 2; i++) container.emplace_back(fabric.MakeElement());
	}
public:
	Container CreateRandomContainer()
	{
		Container container;
		for (int i = 0; i < 10; ++i)
		{
			int RandomVal = rand() % 3;
	        if(RandomVal == 0)
	        {
				HelixFabric fabric;
				FillContainer(fabric,container);
	        }
	        if(RandomVal == 1)
	        {
				CircleFabric fabric; 
				FillContainer(fabric,container);
	        }
	        if(RandomVal == 2)
	        {
				EllipseFabric fabric; 
				FillContainer(fabric,container);
	        }
		}
		return container; 
	}	
};



void PrintContainer(const Container& container)
{
	std::cout << " ===== " << std::endl;
	std::cout << " container's size: " << container.size() << std::endl;
	for(auto& fig :container) 
	{
		std::cout << " \t x: " << std::get<0>(fig->C(M_PI/4.0)) << " dx: " << std::get<0>(fig->dC(M_PI/4.0)) << std::endl;
		std::cout << " \t y: " << std::get<1>(fig->C(M_PI/4.0)) << " dy: " << std::get<1>(fig->dC(M_PI/4.0)) << std::endl;
		std::cout << " \t z: " << std::get<2>(fig->C(M_PI/4.0)) << " dz: " << std::get<2>(fig->dC(M_PI/4.0)) << std::endl;
		std::cout << " \t radius: " << fig->getRadius() << std::endl;
	}
	std::cout << " ===== " << std::endl;
}

int main(int argc, char const *argv[])
{
	auto is_circle = [](const auto& element) 
	{
    	return (std::dynamic_pointer_cast<Circle>(element) != nullptr);
	};

	auto compareCircles = [](const Element& first, const Element& second) 
	{
    	float radius1 = first->getRadius();
   		float radius2 = second->getRadius();
    	return radius1 < radius2;
	};

	auto add = [](float accum, const Element& curve) 
	{ 
		return accum + curve->getRadius(); 
	};

	RandomManner fabric;
	for (int i = 0; i < 200; i++)
	{
		Container container;
		container = fabric.CreateRandomContainer();
		Container new_container;

		std::copy_if(std::begin(container), std::end(container), std::back_inserter(new_container), is_circle);

		std::sort(std::begin(new_container), std::end(new_container), compareCircles);
    
		PrintContainer(new_container);

		float totalSumOfRadii = std::accumulate(new_container.begin(), new_container.end(), 0.0, add);
  		std::cout << "Total Sum of Radii: " << totalSumOfRadii << std::endl;

	}
	return 0;
}