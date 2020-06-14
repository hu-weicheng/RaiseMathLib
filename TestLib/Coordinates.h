#pragma once
#include"framework.h"

/*****************************************************************
*��γ�����Ե���Ϊģ�ͳ������������ϵ.
*��������Ӣ��������������̨�ı���������Ϊ���.������Ϊ��,��GPS����һ��.
*γ���Գ��Ϊ0,��Ϊ��,����Ϊ��,��GPS����һ��.
*��������������ת�����߱������ȿ���̫�������ߵ�ʱ��Ҳ�����ߵ��硣
*����ʱ��������ʱ�̵Ĳ�ֵ����Ҫ��ʱ�ƣ����һ�Ҫ�Էֺ��������㣬������Ǵ������㡣
*ȫ�򻮷�Ϊ24��ʱ������������12��ʱ����
*�涨Ӣ����������������̨��ַ��Ϊ��ʱ������ʱ��������1��12������1��12����
*ÿ��ʱ����羭��15�ȣ�ʱ��������1Сʱ�����Ķ�������12�����羭��7.5�ȣ��Զ�������180��Ϊ��.
*ÿ��ʱ�������뾭���ϵ�ʱ��������ʱ����ͳһ���õ�ʱ�䣬��Ϊ��ʱ����������ʱ����ʱ�����1Сʱ��
******************************************************************/

class Coordinates
{
public:
	Coordinates(double& lat,double& lng);
	double& GetLat();
	double& GetLng();
	void SetCoordinates(double& lat, double& lng);
	//�涨�˷����Ϳ����жϷ�����
	char EastOrWestLng();
	char NorthOrSouthLat();
	char NorthernOrSourthHemisphere();
	char EasternOrWesternHemisohere();
	//����ʱ��
	//��Ϊ��,��Ϊ��.
	int TimeZone();
	int TimeZone(double lng);
	double TimeZoneCenterline();
	double TimeZoneCenterline(int n);
	double LeftLngOfTimeZone();
	double RightLngOfTimeZone();
	double LeftLngOfTimeZone(double lng);
	double RightLngOfTimeZone(double lng);

private:
	double lat;		//latitudeγ��
	double lng;		//longitude����
};

