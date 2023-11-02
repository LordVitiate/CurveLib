#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include "Core.h"


void PrintContainer(const Container& container)
{
	std::cout << " ===== " << std::endl;
	std::cout << " container's size: " << container.size() << std::endl;
	for(auto& fig :container) 
	{
		std::cout << " \t x: " << fig->C(M_PI/4.0).x() << " dx: " << fig->dC(M_PI/4.0).x() << std::endl;
		std::cout << " \t y: " << fig->C(M_PI/4.0).y() << " dy: " << fig->dC(M_PI/4.0).y() << std::endl;
		std::cout << " \t z: " << fig->C(M_PI/4.0).z() << " dz: " << fig->dC(M_PI/4.0).z() << std::endl;
		std::cout << " \t radius: " << fig->getRadius() << std::endl;
	}
	std::cout << " ===== " << std::endl;
}

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


int main(int argc, char const *argv[])
{
	RandomManner fabric;
	for (int i = 0; i < 200; i++)
	{
		Container container;
		container = fabric.CreateRandomContainer();
		PrintContainer(container);

		Container new_container;
		std::copy_if(std::begin(container), std::end(container), std::back_inserter(new_container), is_circle);
		std::sort(std::begin(new_container), std::end(new_container), compareCircles);

		float totalSumOfRadii = std::accumulate(new_container.begin(), new_container.end(), 0.0, add);
  		std::cout << "Total Sum of Radii: " << totalSumOfRadii << std::endl;

	}
	return 0;
}