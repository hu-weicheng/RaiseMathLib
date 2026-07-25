#pragma once
#include <cstring>
#include <cmath>
#include <vector>

#include <stdexcept>

namespace Rmath
{
    //复频率 //s=σ+jω
    class complexfreq
    {
    public:
        double mod();    //模
        double getreal();
        double getimag();


        // 构造函数
        //complexFreq(int resistance, int omega) : r(resistance), w(omega) {}
    protected:
        double sigma;   //实部
        double omega;   //虚部
    };


}