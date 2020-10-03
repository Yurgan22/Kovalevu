#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	int n, k, buf;
	char c[1000];
	cout << "Vvedite k" << endl;
	cin >> k;
	for (int i = 0; i < k; i++) cin >> c[i];
	for (int i = 0; i < k / 2; i++)
	{
		buf = c[i];
		c[i] = c[k - i - 1];
		c[k - i - 1] = buf;
	}
	for (int i = 0; i < k; i++) cout << c[i] << " ";
	return 0;
}