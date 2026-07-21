#pragma once

//库所需要的公共头文件
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
#include<Windows.h>



#include <cstdio>
#include <iostream>	//计算与IO分离
#include <iomanip>

#include "RaiseMathLib.h"
using namespace std;
using namespace Rmath;

int heronformula();//海伦公式


//IO逻辑
void PrintPos();//Point
void print_Circle(Circle& c);	//Circle
void PrintSRectData(ScreenRectangle& sR);//ScreenRectangle
void Print_Matrix(mMatrix& mat);
void PrintScreenPos(Pixel& pix);//Pixel
void PrintRGB(Rmath::RGBQUAD& rgb);
void SetData(mMatrix& mat,vector<unsigned char> data);//mMatrix
int test_MD5();
void test_sPos();//sPos	//screen position
void test_mMatrix();//test mMatrix