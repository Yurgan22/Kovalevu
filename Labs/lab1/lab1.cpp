#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double chislitel, znamenatel, vichitaemoe, x, y, z;
    cout << "Vvedite x, y, z: " << endl;
    cin >> x >> y >> z;
    chislitel = pow(9 + pow(x - y, 2), 1 / 3.);
    znamenatel = x * x + y * y + 2;
    vichitaemoe = exp(fabs(x - y)) * pow(tan(z), 3);
    cout << "S = " << chislitel / znamenatel - vichitaemoe << endl;
}

