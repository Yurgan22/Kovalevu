#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x, y, f, a, b;
	char k;
	cout << "Vvedite x "; cin >> x;
	cout << "Vvedite y "; cin >> y;
	cout << "Viberite f: a - sh(x), b - x^2, c - exp(x) \n";
	cin >> k;
	switch (k)
	{
	case 'a': f = sinh(x); break;
	case 'b': f = pow(x, 2); break;
	case 'c': f = exp(x); break;
	default: cout << "Ne vuibrana funkciya "; return 1;
	}
	if (y == 0) {
		cout << "Net rezultata" << endl;
		return 1;
	}
	a = x / y;
	if (a > 0 && a!=5 ) b = pow(fabs(f), 1. / 3) + log(f);
	else
		if (a < 0) b = log(fabs(f / y)) * pow(x + y, 3);
		else b = pow(f * f + y, 3);
	cout << "RESULT = " << b << endl;
	return 0;
}
