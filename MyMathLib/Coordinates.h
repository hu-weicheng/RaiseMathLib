#pragma once
#include"framework.h"

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
	Coordinates(double& lat,double& lng);
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

