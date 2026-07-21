// generateSine.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>
#include <cmath>
#include <numbers>//C++20

#include <conio.h>
#include <graphics.h>
#include <easyx.h>

std::vector<double> generateSine(
    double amplitude,
    double frequencyHz,
    double sampleRate,
    size_t numSamples)
{
    std::vector<double> x(numSamples);
    double pi = std::numbers::pi;
    const double omega = 2.0 * pi * frequencyHz / sampleRate;

    for (size_t n = 0; n < numSamples; ++n)
    {
        x[n] = amplitude * std::sin(omega * n);
    }
    return x;
}
std::vector<double> generateCosine(
    double amplitude,
    double frequencyHz,
    double sampleRate,
    size_t numSamples)
{
    std::vector<double> x(numSamples);
    constexpr double pi = std::numbers::pi;
    const double omega = 2.0 * pi * frequencyHz / sampleRate;

    for (size_t n = 0; n < numSamples; ++n)
    {
        x[n] = amplitude * std::cos(omega * n);
    }
    return x;
}
std::vector<double> generateImpulse(size_t N, size_t pos = 0)
{
    std::vector<double> x(N, 0.0);
    if (pos < N) x[pos] = 1.0;
    return x;
}
std::vector<double> convolve(
    const std::vector<double>& x,
    const std::vector<double>& h)
{
    size_t Nx = x.size();
    size_t Nh = h.size();
    size_t Ny = Nx + Nh - 1;

    std::vector<double> y(Ny, 0.0);

    for (size_t n = 0; n < Ny; ++n)
    {
        for (size_t k = 0; k < Nh; ++k)
        {
            if (n >= k && n - k < Nx)
                y[n] += x[n - k] * h[k];
        }
    }
    return y;
}

// 通用画信号函数
void drawSignal(
    const std::vector<double>& s,
    COLORREF color,
    int yOffset = 0)
{
    for (size_t n = 0; n < s.size() && n < 1000; ++n)
    {
        int x = static_cast<int>(n);
        int y = 200 - static_cast<int>(s[n] * 150) + yOffset;
        putpixel(x, y, color);
    }
}
int main()
{
    constexpr size_t N = 1024;
    constexpr double fs = 8000.0;

    // 单位冲击
    //auto impulse = generateImpulse(N);

    // 正弦波
    //auto sine = generateSine(1.0, 99.6094, fs, N);

    auto cosi = generateCosine(1.0, 101, fs, N);

    //卷积
    //// y[n] = sum_{k=-inf}^{inf} x[k] * h[n - k]
    //y[n] = ∑_{ k = -∞ }^ {∞} x[k]·h[n - k]
    //auto y = convolve(sine, impulse);

    //std::cout << "打印正弦型号离散序列" << std::endl;
    //for (const double& v : sine)
    //{
    //    std::cout << v << std::endl;
    //}
    //std::cout << "_________________" << std::endl;
    //for (const double& v : impulse)
    //{
    //    std::cout << v << std::endl;
    //}
    //std::cout << "打印卷积结果" << std::endl;
    //for (const double& v : y)
    //{
    //    std::cout << v << std::endl;
    //}
    //std::cout << "---------------------------" << std::endl;

    // 初始化窗口（加宽，因为卷积结果更长）
    initgraph(1200, 600);
    SetWindowText(GetHWnd(), L"DSP 信号可视化");  // 设置窗口标题
    setbkcolor(BLACK);
    cleardevice();

    // ===== 坐标轴 =====
    setcolor(WHITE);
    line(0, 200, 1200, 200);

    //// ===== 画正弦波 =====
    //setcolor(YELLOW);
    //drawSignal(sine, YELLOW, 0);

    setcolor(YELLOW);
    drawSignal(cosi, YELLOW, 0);

    //// ===== 画单位冲击 =====
    //setcolor(RED);
    //drawSignal(impulse, RED, 0);

    //// ===== 画卷积结果 =====
    //setcolor(GREEN);
    //drawSignal(y, GREEN, 0);



    _getch();
    closegraph();
}

