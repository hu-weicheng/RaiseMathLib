#include "ScreenRectangle.h"

ScreenRectangle::ScreenRectangle()
{
	this->width = 0;
	this->height = 0;
	this->lefttop.s_x = 0;
	this->lefttop.s_y = 0;
	this->center.s_x = 0;
	this->center.s_y = 0;
	this->rightbottom.s_x = 0;
	this->rightbottom.s_y = 0;
	this->leftbottom.s_x = 0;
	this->leftbottom.s_y = 0;
	this->righttop.s_x = 0;
	this->righttop.s_y = 0;
}

ScreenRectangle::ScreenRectangle(ScreenRectangle& sRct)
{
	this->width = sRct.width;
	this->height = sRct.height;
	this->lefttop = sRct.lefttop;
	this->leftbottom = sRct.leftbottom;
	this->righttop = sRct.righttop;
	this->rightbottom = sRct.rightbottom;
	this->center = sRct.center;
}

ScreenRectangle::ScreenRectangle(const unsigned int& s_x, const unsigned int& s_y, const unsigned int& width, const unsigned int& height)
{
	this->lefttop.s_x = s_x;
	this->lefttop.s_y = s_y;
	this->width = width;
	this->height = height;
	this->leftbottom.s_x = s_x;
	this->leftbottom.s_y = s_y + height;
	this->righttop.s_x = s_x + width;
	this->righttop.s_y = s_y;
	this->rightbottom.s_x = s_x + width;
	this->rightbottom.s_y = s_y + height;
	this->center.s_x = s_x + width / 2;
	this->center.s_y = s_y + height / 2;
}


sPos& ScreenRectangle::GetMidPos()
{
	// TODO: 在此处插入 return 语句
	return this->center;
}

void ScreenRectangle::SetLefttop(const int& lefttop_x, const int& lefttop_y)
{
	this->lefttop.s_x = lefttop_x;
	this->lefttop.s_y = lefttop_y;
}

void ScreenRectangle::SetCenter(const int& mid_x, const int& mid_y, const int& width, const int& height)
{
	this->center.s_x = mid_x;
	this->center.s_y = mid_y;
	this->height = height;
	this->width = width;
	this->lefttop.s_x = mid_x - width / 2;
	this->lefttop.s_y = mid_y - height / 2;
	this->righttop.s_x = mid_x + width / 2;
	this->righttop.s_y = mid_y - height / 2;
	this->leftbottom.s_x = mid_x - width / 2;
	this->leftbottom.s_y = mid_y + height / 2;
	this->rightbottom.s_x = mid_x + width / 2;
	this->rightbottom.s_y = mid_y + height / 2;
}

void ScreenRectangle::SetSRectWidHgt(const int& width, const int& height)
{
	this->width = width;
	this->height = height;
}

void ScreenRectangle::PrintSRectData()
{
	cout << "lefttop_x:" << lefttop.s_x << " lefttop_y:" << lefttop.s_y << endl;
	cout << "leftbottom_x:" << leftbottom.s_x << " leftbottom_y:" << leftbottom.s_y << endl;
	cout << "righttop_x:" << righttop.s_x << " righttop_y:" << righttop.s_y << endl;
	cout << "rightbottom_x:" << rightbottom.s_x << " rightbottom_y:" << rightbottom.s_y << endl;
	cout << "center_x:" << center.s_x << " center.s_y:" << center.s_y << endl;
	cout << "sRct_width:" << width << " sRct_height:" << height << endl;
}

void ScreenRectangle::CalcDataByLefttop()
{
	if (this->width == 0 || this->height == 0)
		return;
	this->center.s_x = this->lefttop.s_x + width / 2;
	this->center.s_y = this->lefttop.s_y + height / 2;
	this->righttop.s_x = this->lefttop.s_x + width;
	this->righttop.s_y = this->lefttop.s_y;
	this->leftbottom.s_x = this->lefttop.s_x;
	this->leftbottom.s_y = this->lefttop.s_y + height;
	this->rightbottom.s_x = this->lefttop.s_x + width;
	this->rightbottom.s_y = this->lefttop.s_y + height;
}

void ScreenRectangle::CalcDataByMidPos()
{
	this->lefttop.s_x = center.s_x - width / 2;
	this->lefttop.s_y = center.s_y - height / 2;
	this->rightbottom.s_x = center.s_x + width / 2;
	this->rightbottom.s_y = center.s_y + height / 2;
	this->leftbottom.s_x = center.s_x - width / 2;
	this->leftbottom.s_y = center.s_y + height / 2;
	this->righttop.s_x = center.s_x + width / 2;
	this->righttop.s_y = center.s_y - height / 2;
}

void ScreenRectangle::CalcByLefttopRightbottom(const int& lefttop_x, const int& lefttop_y, const int& rightbottom_x, const int& rightbottom_y)
{
	this->lefttop.s_x = lefttop_x;
	this->lefttop.s_y = lefttop_y;
	this->rightbottom.s_x = rightbottom_x;
	this->rightbottom.s_y = rightbottom_y;
	this->width = rightbottom_x - lefttop_x;
	this->height = rightbottom_y - lefttop_y;
	this->righttop.s_x = lefttop_x + this->width;
	this->righttop.s_y = lefttop_y;
	this->leftbottom.s_x = lefttop_x;
	this->leftbottom.s_y = rightbottom_y;
	this->center.s_x = lefttop_x + this->width / 2;
	this->center.s_y = lefttop_x + this->height / 2;
}
