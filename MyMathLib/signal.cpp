#include "signal.h"



namespace Rmath
{
    int complexFreq::mod()
    {
        return sqrt(pow(r, 2) * pow(w, 2));
    }

    void complexFreq::print()
    {
        cout << "Z=" << r << " + j" << w << endl;
    }

    void complexFreq::print(const string format)
    {
        if (format == string("all"))
        {
            cout << "Z=" << r << " + j" << w << endl;
            cout << "|Z|=" << mod() << endl;
        }
    }

    int test_complexFrq()
    {
        complexFreq z1 = complexFreq();
        //complexFreq z2(3, 2);
        //z2.print();
        z1.print();
    }
}

