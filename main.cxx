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

int main(int argc, char const *argv[])
{
	Container a;
	RandomManner fabric;
for (int i = 0; i < 10; i++)
{
	a = fabric.CreateRandomContainer();
	std::cout << "size: " << a.size() << std::endl;
	for(auto& fig : a) 
	{
		std::cout << "\t x: " << std::get<0>(fig->C(2.5)) << std::endl;
	}
}
	return 0;
}