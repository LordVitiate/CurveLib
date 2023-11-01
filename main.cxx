#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

#include <iostream>
#include <memory>
#include <vector>


using Container = std::vector<std::unique_ptr<ParametricCurve>>;

class ContainerFabric {
protected:
    virtual void FillContainer(Container& container) = 0;
public:
    Container CreateContainer()
    {
        Container container;

        FillContainer(container);

        return container;
    }
};

class HelixFabric : public ContainerFabric 
{
protected:
    void FillContainer(Container& container) override final
    {
        for (int i = 0; i < 10; i++) container.push_back(std::make_unique<Helix>(Point(rand() % 10, rand() % 10, rand() % 10), rand() % 5 + 1, 1));
    }
};

class CircleFabric : public ContainerFabric 
{
protected:
    void FillContainer(Container& container) override final
    {
		for (int i = 0; i < 10; i++) container.push_back(std::make_unique<Circle>(Point(rand() % 10, rand() % 10, 0), rand() % 5 + 1));
    }
};

class EllipseFabric : public ContainerFabric 
{
protected:
    void FillContainer(Container& container) override final
    {
		for (int i = 0; i < 10; i++) container.push_back(std::make_unique<Ellipse>(Point(rand() % 10, rand() % 10, 0), rand() % 5 + 1, rand() % 5 + 1));
    }
};

class RandomManner
{
public:
	Container CreateRandomContainer()
	{
		Container container;

		int RandomVal = rand() % 3;
        if(RandomVal == 0)
        {
			HelixFabric fabric; 
			return fabric.CreateContainer();
        }
        if(RandomVal == 1)
        {
			CircleFabric fabric; 
			return fabric.CreateContainer();
        }
        if(RandomVal == 2)
        {
			EllipseFabric fabric; 
			return fabric.CreateContainer();
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
	}
	std::cout << " ===== " << std::endl;

}

int main(int argc, char const *argv[])
{
	Container container;
	RandomManner fabric;
	for (int i = 0; i < 10; i++)
	{
		container = fabric.CreateRandomContainer();
		PrintContainer(container);
	}
	return 0;
}