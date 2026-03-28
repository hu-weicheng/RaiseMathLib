#pragma once

#include"framework.h"

template<class T>
class Square
{
public:
	Square();
	Square(T& side);
	T& GetSquare();
	T& SidesLeghth();
	T& Area();

private:
	T side;
};
