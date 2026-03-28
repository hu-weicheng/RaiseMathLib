#define SIGNALANDSYSTEM_H
#include "periodicity.h"
#include "mathlimit.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <ATLComTime.h>
//#include <math.h>
//#include <ranges>
//#include <algorithm>
#include <functional>

using namespace std;



//double singnalfunc(double t) 
//{
//    // 示例函数，你可以替换为你想要验证的函数
//    return sin(t); // 正弦函数作为示例
//}
//double cosfunc(double t)
//{
//    // 示例函数，你可以替换为你想要验证的函数
//    return cos(t);
//}
//double linerfun(double t)
//{
//    return t * t + 2.0;
//}
//
//int main()
//{
//    size_t n = 2; // 周期性条件中的 n
//    double range_start = 0; // 定义域的起始
//    double range_end = 20 * M_PI; // 定义域的结束
//    size_t sample_points = 100; // 在定义域内采样的点的数量
//
//    if (IsCycleSignal(&singnalfunc, n, range_start, range_end, sample_points))
//    {
//        cout << "The function is not cycle signal with the given condition." << std::endl;
//    }
//    else 
//    {
//        std::cout << "The function does not appear to be periodic with the given condition." << std::endl;
//    }
//
//    if (IsCycleSignal(&cosfunc, n, range_start, range_end, sample_points))
//    {
//        std::cout << "The function appears to be periodic with the given condition." << std::endl;
//    }
//    else
//    {
//        std::cout << "The function does not appear to be periodic with the given condition." << std::endl;
//    }
//
//    if (IsCycleSignal(&linerfun, n, range_start, range_end, sample_points))
//    {
//        std::cout << "The function appears to be periodic with the given condition." << std::endl;
//    }
//    else
//    {
//        std::cout << "The function does not appear to be periodic with the given condition." << std::endl;
//    }
//	return 0;
//}

// 定义一个函数类型
//typedef std::function<double(double)> Function;
//
//// 检查函数是否具有周期性
//bool isPeriodic(Function f, double start, double end, double step, double tolerance) 
//{
//    bool foundPeriod = false;
//    double period = 0.0;
//
//    for (double t = start; t <= end; t += step) 
//    {
//        for (double n = 1.0; n * step <= end - start; n++) 
//        {
//            if (std::abs(f(t) - f(t + n * step)) < tolerance) 
//            {
//                period = n * step;
//                foundPeriod = true;
//                break;
//            }
//        }
//        if (foundPeriod) break;
//    }
//
//    if (foundPeriod) 
//    {
//        std::cout << "The function is periodic with a period of " << period << std::endl;
//    }
//    else 
//    {
//        std::cout << "The function is not periodic." << std::endl;
//    }
//
//    return foundPeriod;
//}

// 示例函数
double exampleFunction(double t) 
{
    return sin(t); // 这是一个周期为2π的函数
}

int main() {

    cout << isPeriodic(exampleFunction, 0.1 * M_PI, 2 * M_PI, (size_t)2) << endl;

    cout << trapezoidalRule(exampleFunction, 0, 1, 1000) << endl;
    double a = -1e-6; // 积分下限，接近0但不为0
    double b = 1e-6; // 积分上限，接近0但不为0
    int n = 1000; // 分割区间的数量
    cout<<"Left Limit:"<< trapezoidalRule(exampleFunction, a, b, n) << endl;
    a = 0;
    b = 1e6;
    n = 1000;
    cout << "Right Limit:" << trapezoidalRule(exampleFunction, a, b, n) << endl;
    cout << exampleFunction(0) << endl;
    return 0;
}