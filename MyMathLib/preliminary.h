#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cstring>
#include <array>
#include <algorithm>

#include <cstdio>
#include <iostream>	//以后逐渐剥离IO逻辑
#include <iomanip>
using namespace std;

/**************************************************************************************
*	2026年重新整理2015年的代码。
* Author：Raise, Ryse
***************************************************************************************/

namespace Rmath
{
	//TestBench
	void test_mMatrix();//test mMatrix
	void test_sPos();//sPos	//screen position
	int test_MD5();
	//接口函数
	int heronformula();//海伦公式
	string md5(const void* input, size_t nBytes);
	/*******Point******************************************************************/
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
	/*******Point******************************************************************/

	/*******Circle******************************************************************/
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

	class Circle :Point
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

	/*******Circle******************************************************************/

	/*******Pixel******************************************************************/
#define BYTE unsigned char
	//GDI中的定义
	typedef struct tagRGBQUAD {
		BYTE rgbBlue;      // 蓝色的强度 (0–255)
		BYTE rgbGreen;     // 绿色的强度 (0–255)
		BYTE rgbRed;       // 红色的强度 (0–255)
		BYTE rgbReserved;  // 保留字节，必须为 0（有时用作 Alpha 通道）
	} RGBQUAD;

	class Pixel
	{
	public:
		Pixel(Pixel& p);
		Pixel(const unsigned int& x, const unsigned int& y,
			const unsigned int& red, const unsigned int& green, const unsigned int& blue);
		~Pixel();
		unsigned int& GetSX();
		unsigned int& GetSY();
		RGBQUAD& GetRGB();	//RGBQUAD&
		void PrintScreenPos();
		void PrintRGB();

	protected:
		unsigned int s_x;
		unsigned int s_y;
		RGBQUAD rgb;
	};

	/*******Pixel******************************************************************/

	/*******Square******************************************************************/
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
	/*******Square******************************************************************/


	/*******Coordinates******************************************************************/
	/*****************************************************************
	*经纬度是以地球为模型抽象出来的坐标系.
	*经度是以英国格林尼治天文台的本初子午线为起点.这里向东为正,与GPS保持一致.
	*纬度以赤道为0,向北为正,向南为负,与GPS保持一致.
	*地球是自西向东自转，东边比西边先看到太阳，东边的时间也比西边的早。
	*东边时刻与西边时刻的差值不仅要以时计，而且还要以分和秒来计算，这给人们带来不便。
	*全球划分为24个时区（东、西各12个时区）
	*规定英国（格林尼治天文台旧址）为中时区（零时区）、东1—12区，西1—12区。
	*每个时区横跨经度15度，时间正好是1小时。最后的东、西第12区各跨经度7.5度，以东、西经180度为界.
	*每个时区的中央经线上的时间就是这个时区内统一采用的时间，称为区时，相邻两个时区的时间相差1小时。
	******************************************************************/

	class Coordinates
	{
	public:
		Coordinates(double& lat, double& lng);
		double& GetLat();
		double& GetLng();
		void SetCoordinates(double& lat, double& lng);
		//规定了方向后就可以判断方向了
		char EastOrWestLng();
		char NorthOrSouthLat();
		char NorthernOrSourthHemisphere();
		char EasternOrWesternHemisohere();
		//计算时区
		//正为东,负为西.
		int TimeZone();
		int TimeZone(double lng);
		double TimeZoneCenterline();
		double TimeZoneCenterline(int n);
		double LeftLngOfTimeZone();
		double RightLngOfTimeZone();
		double LeftLngOfTimeZone(double lng);
		double RightLngOfTimeZone(double lng);

	private:
		double lat;		//latitude纬度
		double lng;		//longitude经度
	};
	/*******Coordinates******************************************************************/

	/*******mMatrix******************************************************************/
	class mMatrix
	{
	public:
		mMatrix();
		mMatrix(unsigned char rows, unsigned char column);
		void SetData(unsigned char rows, unsigned char column);
		void Generate();
		void Print();
		vector<unsigned char> Find1();
		int Find1_RowNo();
		~mMatrix();
	private:
		inline void initBuffer(unsigned char rows, unsigned char column);

	private:
		uint16_t rows;
		uint16_t column;
		unsigned char* pBuf;
	};
	/*******mMatrix******************************************************************/


	/*******sPos//screen position******************************************************************/
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

	/*******sPos//screen position******************************************************************/

	/******triangle*******************************************************************/
	class triangle
	{
	public:
		triangle();
		triangle(double a, double b, double c);
		triangle(triangle& tria);
		bool isTriangle();
		bool equalSide();
		bool isosceles();
		bool isSimilar(triangle& other);//相似三角形
		double area(double base, double height);//底边乘高除二
		double perimeter();//周长
		double area_heron();//海伦公式求面积
		double angleA();
		double angleB();
		double angleC();

	protected:
		double a, b, c;//三角形三条边
	};
	/******triangle*******************************************************************/
}/*****namapspace Rmath;**************/




