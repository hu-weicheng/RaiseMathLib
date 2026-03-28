#pragma once

#include"framework.h"
#include"Point.h"

//typedef unsigned int Radius_t;
#define Pi_0	3
#define Pi_1	3.1
#define Pi_2	3.14
#define Pi_3	3.141
#define Pi_4	3.1415
#define Pi_5	3.14159
#define Pi_6	3.141592
#define Pi_7	3.1415926
#define Pi_8	3.14159265
#define Pi_9	3.141592653
#define Pi_10	3.1415926535
#define Pi_11	3.14159265358
#define Pi_12	3.141592653589
#define Pi_13	3.1415926535897
#define Pi_14	3.14159265358979

class Circle:Point
{
public:
	Circle();
	Circle(const int& x, const int& y, const unsigned int radius);
	Circle(const Circle& c);
	Circle(int& x_t, int& y_t, unsigned int r);

	Circle& Copy();

	void print();
	bool IsOnCircle(const int& x, const int& y);
	bool operator==(Circle& c);
	void SetRadius(unsigned int r);
	unsigned int& GetRadius();
	unsigned int SidesLeghth();
	unsigned int Area();
	unsigned int Diameter();

protected:
	unsigned int radius;
};

