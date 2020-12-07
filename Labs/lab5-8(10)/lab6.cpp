#include <iostream>
#include <clocale>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");

	char str[100];
	int length_and_index[100][2];
	cout << "Введите строку : " << endl;
	gets_s<100>(str);

	bool check = 0;
	int n = strlen(str) - 1, i = 0, len = strlen(str), len_gr;
	int m = 0;
	while (str[i] != '\0')
	{
		len_gr = 0;
		while (str[i] == str[i + 1] && i < n) { len_gr++; i++; }
		len_gr++;
		length_and_index[m][0] = len_gr;
		length_and_index[m][1] = i;
		if (len_gr < len) len = len_gr;
		m++;
		i++;
	}
	cout << "Наименьшие по длине группы : " << endl;
	for (int j = 0; j < m; j++)
		if (length_and_index[j][0] == len)
		{
			for (int i = length_and_index[j][1] - len + 1; i <= length_and_index[j][1]; i++)
				cout << str[i];
			cout << endl;
		}
	return 0;
}
