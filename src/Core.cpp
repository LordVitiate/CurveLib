#include "Core.h"

Element HelixFabric::MakeElement() 
{
	return std::make_shared<Helix>(Point(rand() % 10, rand() % 10, rand() % 10), rand() % 5 + 1, 1);
}

Element CircleFabric::MakeElement() 
{
	return std::make_shared<Circle>(Point(rand() % 10, rand() % 10), rand() % 5 + 1);
}

Element EllipseFabric::MakeElement() 
{
	return std::make_shared<Ellipse>(Point(rand() % 10, rand() % 10), rand() % 5 + 1, rand() % 5 + 1);
}

void RandomManner::FillContainerByElement(ElementFabric& fabric, Container& container)
{
	container.emplace_back(fabric.MakeElement());
}

Container RandomManner::CreateRandomContainer()
{
	Container container;
	for (int i = 0; i < 10; ++i)
	{
		int RandomVal = rand() % 3;
        if(RandomVal == 0)
        {
			HelixFabric fabric;
			FillContainerByElement(fabric,container);
        }
        if(RandomVal == 1)
        {
			CircleFabric fabric; 
			FillContainerByElement(fabric,container);
        }
        if(RandomVal == 2)
        {
			EllipseFabric fabric; 
			FillContainerByElement(fabric,container);
        }
	}
	return container; 
}