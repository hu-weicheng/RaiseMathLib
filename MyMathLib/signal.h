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
        double mod() const;    //模
        double getreal() const;
        double getimag() const;


        // 构造函数
        //complexFreq(int resistance, int omega) : r(resistance), w(omega) {}
    protected:
        double sigma;   //实部
        double omega;   //虚部
    };


    //离散时间信号---序列,实序列
    class sequence_real
    {
    public:
        //构造函数
        // 1. 默认构造：空序列
        sequence_real() = default;

        // 2. 指定长度 + 初始值    //explicit静止隐式转换
        explicit sequence_real(size_t n, double init = 0.0)
            : data(n, init), zeroindex(0) {
        }


        // 3. 从 vector 构造（非常重要）//explicit静止隐式转换
        explicit sequence_real(const std::vector<double>& v)
            : data(v), zeroindex(0) {
        }

        // 4. 从 initializer_list 构造（写代码最舒服）
        sequence_real(std::initializer_list<double> lst)
            : data(lst), zeroindex(0) {
        }


        // ===== zeroindex 访问接口 =====
        void set_zero_index(size_t idx);

        size_t get_zero_index() const noexcept;

        // ===== 时间轴映射（非常关键）=====
        int n_to_index(int n) const noexcept;

        double at_n(int n) const;
        std::vector<double> getdata() const;

        //加法
        std::vector<double> add(std::vector<double>& y) const;
        sequence_real add(sequence_real& y) const;
        //乘法 对应相乘
        std::vector<double> multi(std::vector<double>& y) const;
        sequence_real multi(const sequence_real& y) const;
        //标度乘法
        std::vector<double> multi_scalar(double& c) const;
        //累加 与前一个点相加
        std::vector<double> cumsum() const;
        double sum() const;
        double energe() const;//const承诺不修改成员变量
        double averagepower() const;
        std::vector<double> convolve(const std::vector<double>& h) const;
        sequence_real timeshift(int m) const;
        sequence_real fold() const;
        sequence_real decimate(size_t M) const;    //放大
        sequence_real interpolate(size_t M) const;  //缩小

    protected:
        std::vector<double> data;
        size_t zeroindex;//零点位置,数组下标，n=0时在vector中的位置。
    };
}