#include "Circle.h"



Circle::Circle(const Circle& c)
{
	this->x = c.x;
	this->y = c.y;
	this->radius = c.radius;
}




Circle& Circle::Copy()
{
	return *this;
}







void Circle::print()
{
	this->print();
	cout << "Radius:" << radius << endl;
}

bool Circle::IsOnCircle(const int& x_t, const int& y_t)
{
	if (x == x_t && y == y_t)
		return true;
	return false;
}

bool  Circle::operator==(Circle& c)
{
	// TODO: 在此处插入 return 语句
	if (c.x == this->x && c.y == this->y && c.radius == this->radius)
		return true;
	return false;
}

void Circle::SetRadius(unsigned int r)
{
	radius = r;
}

unsigned int& Circle::GetRadius()
{
	return this->radius;
}

unsigned int Circle::SidesLeghth()
{
	// TODO: 在此处插入 return 语句
	return static_cast<unsigned int>(radius* 2 * Pi_0);
}

unsigned int Circle::Area()
{
	// TODO: 在此处插入 return 语句
	return static_cast<unsigned int>(Pi_14 * radius * radius);
}

unsigned int Circle::Diameter()
{
	return (radius * 2);
}
