#pragma once
#include <cstring>
#include <cmath>

#include <iostream>
using namespace std;

namespace Rmath
{
    int test_complexFrq();

    //复频率
    struct complexFreq
    {
        int r;  //电阻
        int w;  //角频率
        // 构造函数
        //complexFreq(int resistance, int omega) : r(resistance), w(omega) {}
    private:
        int inline mod();    //模
    public:
        void print();
        void print(const string format);
    };
}