#include "Coordinates.h"

Coordinates::Coordinates(double& lat, double& lng)
{
	this->lat = lat;
	this->lng = lng;
}

double& Coordinates::GetLat()
{
	// TODO: 在此处插入 return 语句
	return this->lat;
}

double& Coordinates::GetLng()
{
	// TODO: 在此处插入 return 语句
	return this->lng;
}

void Coordinates::SetCoordinates(double& lat, double& lng)
{
	this->lat = lat;
	this->lng = lng;
}

char Coordinates::EastOrWestLng()
{
	// TODO: 在此处插入 return 语句
	if (lng >= 0)
		return 'E';
	else
		return 'W';
	return 0;
}

char Coordinates::NorthOrSouthLat()
{
	if (lat >= 0)
		return 'N';
	else
		return 'S';
	return 0;
}

char Coordinates::NorthernOrSourthHemisphere()
{
	if (lat < 0)
		return 'S';
	else
		return 'N';
	return 0;
}

char Coordinates::EasternOrWesternHemisohere()
{
	if (lng > -20 && lng <= 160)
		return 'E';
	else
		return 'W';
	return 0;
}

int Coordinates::TimeZone()
{
	if ((int)lng % 15 > 0)
		return lng / 15 + 1;
	else
		return lng / 15;
	return 0;
}

int Coordinates::TimeZone(double lng)
{
	if ((int)lng % 15 > 0)
		return lng / 15 + 1;
	else
		return lng / 15;
	return 0;
}

double Coordinates::TimeZoneCenterline()
{
	// TODO: 在此处插入 return 语句
	int n = 0;
	if ((int)lng % 15 > 0)
		n= lng / 15 + 1;
	else
		n= lng / 15;
	return static_cast<double>(n*15);
}

double Coordinates::TimeZoneCenterline(int n)
{
	// TODO: 在此处插入 return 语句
	return static_cast<double>(n * 15);
}

double Coordinates::LeftLngOfTimeZone()
{
	int n = 0;
	if ((int)lng % 15 > 0)
		n = lng / 15 + 1;
	else
		n = lng / 15;
	return n * 15 - 7.5;
}

double Coordinates::RightLngOfTimeZone()
{
	int n = 0;
	if ((int)lng % 15 > 0)
		n = lng / 15 + 1;
	else
		n = lng / 15;
	return n * 15 + 7.5;
}


double Coordinates::LeftLngOfTimeZone(double lng)
{
	int n = 0;
	if ((int)lng % 15 > 0)
		n = lng / 15 + 1;
	else
		n = lng / 15;
	return n * 15 - 7.5;
}

double Coordinates::RightLngOfTimeZone(double lng)
{
	int n = 0;
	if ((int)lng % 15 > 0)
		n = lng / 15 + 1;
	else
		n = lng / 15;
	return n * 15 + 7.5;
}
