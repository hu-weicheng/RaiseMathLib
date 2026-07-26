#include "signal.h"




namespace Rmath
{
    //复频率
    double complexfreq::mod() const
    {
        return sqrt(sigma * sigma + omega * omega);
    }
    double complexfreq::getreal() const
    {
        return this->sigma;
    }
    double complexfreq::getimag() const
    {
        return this->omega;
    }

    /*****复频率*********************************************/


    int sequence_real::n_to_index(int n) const noexcept
    {
        return static_cast<int>(zeroindex) + n;
    }
    double sequence_real::at_n(int n) const
    {
        int idx = n_to_index(n);
        if (idx < 0 || idx >= static_cast<int>(data.size()))
            return 0.0; // 或 throw
        return data[idx];
    }
    size_t sequence_real::get_zero_index() const noexcept
    {
        return zeroindex;
    }
    void sequence_real::set_zero_index(size_t idx)
    {
        if (idx >= data.size())
            return;
        zeroindex = idx;
    }
    std::vector<double> sequence_real::add(std::vector<double>& y) const
    {
        std::vector<double> z(this->data.size());
        for (size_t n = 0;n < z.size();n++)
        {
            z[n] = this->data[n] + y[n];
        }
    }
    sequence_real sequence_real::add(sequence_real& y) const
    {
        size_t N = std::min(this->data.size(), y.data.size());
        sequence_real z(N);
        for (size_t i = 0; i < N; ++i)
            z.data[i] = data[i] + y.data[i];
        return z;
    }
    // 逐元素乘法（Hadamard 积）
    sequence_real sequence_real::multi(const sequence_real& y) const
    {
        sequence_real z(data.size());
        if (data.size() != y.data.size())
            return z;

        
        for (size_t i = 0; i < data.size(); ++i)
            z.data[i] = data[i] * y.data[i];
        return z;
    }
    std::vector<double> sequence_real::multi(std::vector<double>& y) const
    {
        size_t n = this->data.size();
        std::vector<double> z(n);
        if (n != y.size())
            return z;
        
        for (size_t i = 0; i < n; ++i)
            z[i] = this->data[i] + y[i];
        return z;
    }
    std::vector<double> sequence_real::multi_scalar(double& c) const
    {
        std::vector<double> z(this->data.size());
        for (size_t n=0;n<this->data.size();++n)
        {
           z[n] = this->data[n] * c;
        }
    }
    std::vector<double> sequence_real::cumsum() const
    {
        std::vector<double> csum(this->data);
        if (csum.size() < 2)
            return csum;
        for (size_t i = 1;i < csum.size();i++)
        {
            csum[i] += csum[i - 1];
        }
    }
    double sequence_real::sum() const
    {
        double s = 0.0;
        for (size_t i = 0;i < this->data.size();i++)
        {
            s += this->data[i];
        }
        return s;
    }
    double sequence_real::energe() const
    {
        double e = 0.0;
        for (size_t i = 0;i < this->data.size();i++)
        {
            e += this->data[i] * this->data[i];
        }
        return e;
    }
    double sequence_real::averagepower() const
    {
        return energe() / this->data.size();
    }
    std::vector<double> sequence_real::getdata() const
    {
        return this->data;
    }
    sequence_real sequence_real::timeshift(int m) const
    {
        // 新序列：长度不变，zeroindex 偏移 m
        sequence_real result(*this);

        // 新的时间原点 = 原时间原点 + m
        int new_zero = static_cast<int>(zeroindex) + m;

        // 合法性检查
        if (new_zero < 0 || new_zero >= static_cast<int>(data.size()))
            throw std::out_of_range("timeshift causes zeroindex out of range");

        result.zeroindex = static_cast<size_t>(new_zero);
        return result;
    }
    std::vector<double> sequence_real::convolve(const std::vector<double>& h) const
    {
        size_t Nx = this->data.size();
        size_t Nh = h.size();
        size_t Ny = Nx + Nh - 1;

        std::vector<double> y(Ny, 0.0);

        for (size_t n = 0; n < Ny; ++n)
        {
            for (size_t k = 0; k < Nh; ++k)
            {
                if (n >= k && n - k < Nx)
                    y[n] += this->data[n - k] * h[k];
            }
        }
        return y;
    }
    sequence_real sequence_real::fold() const
    {
        sequence_real result(data.size(), zeroindex);

        // 遍历新序列的时间轴
        for (int n = -static_cast<int>(zeroindex);
            n < static_cast<int>(data.size()) - static_cast<int>(zeroindex);
            ++n)
        {
            // y[n] = x[-n]
            result.data[result.n_to_index(n)] =
                this->at_n(-n);
        }
        return result;
    }
    sequence_real sequence_real::decimate(size_t M) const
    {
        size_t new_size = (data.size() + M - 1) / M;
        sequence_real result(new_size);

        for (size_t i = 0; i < new_size; ++i)
            result.data[i] = data[i * M];

        // zeroindex 需要重新计算
        result.zeroindex = static_cast<size_t>(
            static_cast<int>(zeroindex) / M
            );

        return result;
    }
    sequence_real sequence_real::interpolate(size_t M) const    //放大
    {
        size_t new_size = data.size() * M;
        sequence_real result(new_size);

        for (size_t i = 0; i < data.size(); ++i)
            result.data[i * M] = data[i];

        // 其余位置保持 0（已在构造函数中初始化）

        result.zeroindex = static_cast<size_t>(
            static_cast<int>(zeroindex) * M
            );

        return result;
    }
    sequence_real sequence_real::operator+(const sequence_real& rhs) const
    {
        if (data.size() != rhs.data.size())
            throw std::invalid_argument("operator+: sequence length mismatch");

        sequence_real result(data.size(), zeroindex);

        for (size_t i = 0; i < data.size(); ++i)
            result.data[i] = data[i] + rhs.data[i];

        return result;
    }
    sequence_real sequence_real::operator-(const sequence_real& rhs) const
    {
        if (data.size() != rhs.data.size())
            throw std::invalid_argument("operator-: sequence length mismatch");

        sequence_real result(data.size(), zeroindex);

        for (size_t i = 0; i < data.size(); ++i)
            result.data[i] = data[i] - rhs.data[i];

        return result;
    }
}

