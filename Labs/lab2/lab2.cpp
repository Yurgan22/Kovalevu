#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x, y, f, a, b;
	int k;
	cout << "Vvedite x "; cin >> x;
	cout << "Vvedite y "; cin >> y;
	cout << "Viberite f: 1 - sh(x), 2 - x^2, 3 - exp(x) \n"; cin >> k;
	switch (k)
	{
	case 1: f = sinh(x); break;
	case 2: f = pow(x, 2); break;
	case 3: f = exp(x); break;
	default: cout << "Ne vuibrana funkciya "; return 1;
	}
	if (y == 0) {
		cout << "Net rezultata" << endl;
		return 1;
	}
	a = x/y;
	if (a > 0) b = pow(fabs(f), 1. / 3) + log(f);
	else
		if (a < 0) b = log(fabs(f / y)) * pow(x + y, 3);
		else b = pow(f * f + y, 3);
	cout << "RESULT = " << b << endl;
	return 0;
}