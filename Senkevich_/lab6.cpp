#include <iostream>
#include <clocale>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");

	char str[1000];
	char* k;
	cout << "Введите строку : " << endl;
	gets_s<1000>(str);
	while (strstr(str, ".") != NULL)
	{
		k = strstr(str, ".");
		if ((*(k + 1) >= '0' && *(k + 1) <= '9') && (*(k - 1) >= '0' && *(k - 1) <= '9'))
			while (*(k - 1) >= '0' && *(k - 1) <= '9') k--;
		if (*k != '.')
		{
			int kol = 0;
			while ((*k >= '0' && *k <= '9') || *k == '.')
			{
				if (*k == '.')kol++;
				if (kol > 1)break;
				cout << *k;
				k++;
			}
			cout << endl;
		}
		k = strchr(str, '.');
		*k = '|';
	}
	return 0;
}