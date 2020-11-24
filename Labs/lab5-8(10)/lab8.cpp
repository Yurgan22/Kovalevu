#include <iostream> 
#include <math.h> 
#include <iomanip>
using namespace std;
typedef double (*uf)(double, double, int&);

void tabl(double, double, double, double, uf);
double y(double, double, int&);
double s(double, double, int&);

int main()
{
	double a = 0.1;
	double b = 0.9;
	double ee = 1e-5;
	cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
	tabl(a, b, 0.1, ee, y);
	cout << endl;
	cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
	tabl(a, b, 0.1, ee, s);
	return 0;
}

void tabl(double a, double b, double h, double eps, uf fun)
{
	int k = 0;
	double sum;
	for (double x = a; x <= b; x += h)
	{
		sum = fun(x, eps, k);
		cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
	}
}

double y(double x, double eps, int& k)
{
	return sin(x) / x;
}

double s(double x, double eps, int& k)
{
	double a, c, sum;
	sum = a = c = 1;

	k = 1;
	while (fabs(c) > eps)
	{
		c = pow(x, 2) / (2 * k * (2 * k + 1));
		a *= -c;
		sum += a;
		k++;
	}
	return sum;
}