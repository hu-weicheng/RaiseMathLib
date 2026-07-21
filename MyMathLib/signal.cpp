#include "signal.h"




namespace Rmath
{
    double complexfreq::mod()
    {
        return sqrt(sigma * sigma + omega * omega);
    }
    double complexfreq::getreal()
    {
        return this->sigma;
    }
    double complexfreq::getimag()
    {
        return this->omega;
    }

    /*****复频率*********************************************/

    //离散时间信号---序列,实序列
    class sequence_real
    {
    public:
        //构造函数
        // 1. 默认构造：空序列
        sequence_real() = default;

        // 2. 指定长度 + 初始值    //explicit静止隐式转换
        explicit sequence_real(size_t n, double init = 0.0)
            : data(n, init) 
        {
            this->zeroindex = 0;
        }

        // 3. 从 vector 构造（非常重要）//explicit静止隐式转换
        explicit sequence_real(const std::vector<double>& v)
            : data(v)
        {
            this->zeroindex = 0;
        }

        // 4. 从 initializer_list 构造（写代码最舒服）
        sequence_real(std::initializer_list<double> lst)
            : data(lst)
        {
            this->zeroindex = 0;
        }



        //加法
        std::vector<double> add(std::vector<double>& y);
        sequence_real add(sequence_real& y);
        //乘法 对应相乘
        std::vector<double> multi(std::vector<double>& y);
        sequence_real multi(const sequence_real& y);
        //标度乘法
        std::vector<double> multi_scalar(double& c);
        //累加 与前一个点相加
        std::vector<double> cumsum();
        double sum();
        double energe();
        double averagepower();

        std::vector<double> getdata();
    protected:
        std::vector<double> data;
        size_t zeroindex;//零点位置，n=0时在vector中的位置。
    };

    std::vector<double> sequence_real::add(std::vector<double>& y)
    {
        std::vector<double> z(this->data.size());
        for (size_t n = 0;n < z.size();n++)
        {
            z[n] = this->data[n] + y[n];
        }
    }
    sequence_real sequence_real::add(sequence_real& y)
    {
        size_t N = std::min(this->data.size(), y.data.size());
        sequence_real z(N);
        for (size_t i = 0; i < N; ++i)
            z.data[i] = data[i] + y.data[i];
        return z;
    }
    // 逐元素乘法（Hadamard 积）
    sequence_real sequence_real::multi(const sequence_real& y)
    {
        sequence_real z(data.size());
        if (data.size() != y.data.size())
            return z;

        
        for (size_t i = 0; i < data.size(); ++i)
            z.data[i] = data[i] * y.data[i];
        return z;
    }
    std::vector<double> sequence_real::multi(std::vector<double>& y)
    {
        size_t n = this->data.size();
        std::vector<double> z(n);
        if (n != y.size())
            return z;
        
        for (size_t i = 0; i < n; ++i)
            z[i] = this->data[i] + y[i];
        return z;
    }
    std::vector<double> sequence_real::multi_scalar(double& c)
    {
        for (size_t n=0;n<this->data.size();++n)
        {
            this->data[n] *= c;
        }
    }
    std::vector<double> sequence_real::cumsum()
    {
        if (this->data.size() < 2)
            return this->data;
        for (size_t i = 1;i < this->data.size();i++)
        {
            this->data[i] += this->data[i - 1];
        }
    }
    double sequence_real::sum()
    {
        double s = 0.0;
        for (size_t i = 0;i < this->data.size();i++)
        {
            s += this->data[i];
        }
        return s;
    }
    double sequence_real::energe()
    {
        double e = 0.0;
        for (size_t i = 0;i < this->data.size();i++)
        {
            e += this->data[i] * this->data[i];
        }
        return e;
    }
    double sequence_real::averagepower()
    {
        return energe() / this->data.size();
    }
    std::vector<double> sequence_real::getdata()
    {
        return this->data;
    }
}

