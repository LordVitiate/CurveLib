#include "Circle.h"
#include <iostream>


int main(int argc, char const *argv[])
{
	Circle a({0.0,0.0,0.0}, 1);
	std::cout << std::get<0>(a.C(11));
	return 0;
}