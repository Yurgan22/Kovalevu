#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	long double a, b, h, x, y, s, p;
	int n, i;
	cout << "Vvedite a,b,n" << endl;
	cin >> a >> b >> n;
	x = a;
	h = (b - a) / 10;
	cout << setw(15) << "X" << setw(15) << "Y" << setw(15) << "S" << endl;
	while (x <= b + h / 2)
	{
		p = s = 1;
		for (i = 1; i <= n; i++)
		{
			p *= x * x / 2 * i;
			s += p;
		}
		y = (exp(x) + exp(-x)) / 2;
		cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
		cout << "          ---------------------------------------" << endl;
		x += h;
	}
	cout << endl;
	return 0;
}
