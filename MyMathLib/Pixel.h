#pragma once

#include"framework.h"

class Pixel
{
public:
	Pixel(Pixel& p);
	Pixel(const unsigned int& x, const unsigned int& y,
		const unsigned int& red, const unsigned int& green, const unsigned int& blue);
	~Pixel();
	unsigned int& GetSX();
	unsigned int& GetSY();
	RGBQUAD& GetRGB();
	void PrintScreenPos();
	void PrintRGB();

protected:
	unsigned int s_x;
	unsigned int s_y;
	RGBQUAD rgb;
};

