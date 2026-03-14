#include "periodicity.h"

//f(t)==f(t+nT)


bool isPeriodic(singnalfunc f, double t, double T,size_t n)
{
    //std::cout << f(t) << std::endl;
    //std::cout << f(t + n * T) << std::endl;
    //return bool(f(t) == f(t + n * T));//0 true  ; 1 false
    return f(t) == f(t + n * T);
}