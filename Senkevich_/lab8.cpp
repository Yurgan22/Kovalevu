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
	setlocale(LC_ALL, "Rus");
	double a = -0.3;
	double b = 0.4;
	double ee = 1e-4;
	double h = (double)(b - a) / 10;
	cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
	tabl(a, b, h, ee, y);
	cout << endl;
	cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
	tabl(a, b, h, ee, s);
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
	return 1 / (1 - x);
}

double s(double x, double eps, int& k)
{
	double a, c, sum;
	sum = 0;
	a = c = 1 / (1 + x);

	k = 1;
	while (fabs(c) > eps)
	{
		c = pow(2, k - 1) * pow(x, (pow(2, k - 1) - 1)) / (1 + pow(x, pow(2, k - 1)));
		//a *= -c;
		sum += c;
		k++;
	}
	return sum;
}