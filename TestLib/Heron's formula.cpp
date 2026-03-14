#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	double a, b, c, s, p;

	cin >> a >> b >> c;

	p = (a + b + c) / 2;

	s = sqrt(p * (p - a) * (p - b) * (p - c));

	cout.setf(ios::fixed);

	cout.precision(3);

	cout << s << endl;

	return 0;
}

