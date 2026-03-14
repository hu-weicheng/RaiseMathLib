#include "mathlimit.h"

// 使用梯形法则进行数值积分
//double a = 0.0; // 积分下限
//double b = 1.0; // 积分上限
//int n = 1000; // 分割区间的数量
double trapezoidalRule(double (*func)(double), double a, double b, int n) 
{
    double h = (b - a) / n; // 步长
    double sum = 0.5 * (func(a) + func(b)); // 首尾项各取一半
    for (int i = 1; i < n; ++i) 
    {
        sum += func(a + i * h);
    }
    return sum * h;
}
