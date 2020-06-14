#include "Pixel.h"

Pixel::Pixel(Pixel& p)
{
	this->s_x = p.s_x;
	this->s_y = p.s_y;
	this->rgb = p.rgb;
}

Pixel::Pixel(const unsigned int& x, const unsigned int& y,
	const unsigned int& red, const unsigned int& green, const unsigned int& blue)
{
	this->s_x = x;
	this->s_y = y;
	this->rgb.rgbRed = red;
	this->rgb.rgbGreen = green;
	this->rgb.rgbBlue = blue;
}

Pixel::~Pixel()
{
}

unsigned int& Pixel::GetSX()
{
	// TODO: 在此处插入 return 语句
	return this->s_x;
}

unsigned int& Pixel::GetSY()
{
	// TODO: 在此处插入 return 语句
	return s_y;
}

RGBQUAD& Pixel::GetRGB()
{
	// TODO: 在此处插入 return 语句
	return rgb;
}

void Pixel::PrintScreenPos()
{
	cout << "s_x:" << s_x << "  s_y:" << s_y << endl;
}

void Pixel::PrintRGB()
{
	cout << "Red:" << rgb.rgbRed << " Green:" << rgb.rgbGreen << " Blue:" << rgb.rgbBlue << endl;
}
