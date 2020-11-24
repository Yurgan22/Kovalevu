#include <iostream>
#include <clocale>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");

	char str[100];
	cout << "Введите строку : " << endl;
	gets_s<100>(str);

	bool check = 0;
	int n = strlen(str) - 1, i = 0, index = 0, len = strlen(str), len_gr;

	while (str[i] != '\0')
	{
		len_gr = 0;
		while (str[i] == str[i + 1] && i < n) { len_gr++; i++; }
		len_gr++;
		if (len_gr < len) { len = len_gr; index = i; }
		i++;
	}
	cout << "Наименьшая по длине группа : " << endl;
	for (int i = index - len + 1; i <= index; i++)
		cout << str[i];

	return 0;
}