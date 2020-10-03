#include <iostream>
#include <math.h>
using namespace std;
const double x = -4.5, y = 0.75e-4, z = -84.5;
int main()
{
    double chislitel, znamenatel, vichitaemoe;
    chislitel = pow(9 + pow(x - y, 2), 1 / 3.);
    znamenatel = x * x + y * y + 2;
    vichitaemoe = exp(fabs(x - y)) * pow(tan(z), 3);
    cout << "S = " << chislitel / znamenatel - vichitaemoe << endl;
}

