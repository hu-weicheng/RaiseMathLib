#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}


int& Point::GetX()
{
	// TODO: 在此处插入 return 语句
	return x;
}

int& Point::GetY()
{
	// TODO: 在此处插入 return 语句
	return y;
}

void Point::Zero()
{
	x = 0;
	y = 0;
}

void Point::SetPos(const int& xa, const int& ya)
{
	x = xa;
	y = ya;
}

Point::Point(Point& po)
{
	this->x = po.x;
	this->y = po.y;
}

Point::Point(const int& xp, const int& yp)
{
	x = xp;
	y = yp;
}

void Point::SetPointValue(int& x_t, int& y_t)
{
	x_t = x;
	y_t = y;
}

void Point::PrintPos()
{
	cout << "X:" << x << endl;
	cout << "Y:" << y << endl;
}

Point& Point::GetPointPos()
{
	return *this;
}