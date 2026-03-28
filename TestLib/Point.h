#pragma once
#include"framework.h"

//Point类是所有图形类的基类
class Point
{
public:
	Point();
	Point(Point& p);
	Point(const int& xp, const int& yp);

	int& GetX();
	int& GetY();
	void PrintPos();
	Point& GetPointPos();
	void SetPointValue(int& x, int& y);
	void Zero();
	void SetPos(const int& xa, const int& ya);
protected:
	int x;
	int y;
};

