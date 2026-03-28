#pragma once
#include <functional>
#include <iostream>

typedef std::function<double(double)> singnalfunc;


bool isPeriodic(singnalfunc f, double t, double T, size_t n);
