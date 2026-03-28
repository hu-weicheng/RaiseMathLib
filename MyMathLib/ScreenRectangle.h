#pragma once
#include"framework.h"


struct sPos	//screen position
{
	unsigned int s_x;
	unsigned int s_y;
};
class ScreenRectangle
{
public:
	ScreenRectangle();
	ScreenRectangle(ScreenRectangle& sRct);
	ScreenRectangle(const unsigned int& lefttop_x, const unsigned int& lefttop_y,
		const unsigned int& width, const unsigned int& height);

	sPos& GetMidPos();
	void SetLefttop(const int& lefttop_x, const int& lefttop_y);
	void SetCenter(const int& mid_x, const int& mid_y, const int& width, const int& height);
	void SetSRectWidHgt(const int& width, const int& height);
	void PrintSRectData();
	void CalcDataByLefttop();
	void CalcDataByMidPos();
	void CalcByLefttopRightbottom(const int& lefttop_x, const int& lefttop_y,
		const int& rightbottom_x, const int& rightbottom_y);
protected:
	struct sPos lefttop;
	struct sPos leftbottom;
	struct sPos righttop;
	struct sPos rightbottom;
	struct sPos center;
	unsigned int width;
	unsigned int height;
};

