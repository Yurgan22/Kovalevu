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

	int length = 0, num = 0, pos;
	int max = 0, numm, posm;
	int i = 0,m=0;
	while (str[i] != '\0')
	{
		length = 0;
		length_and_index[m][1] = i;
		while (str[i] != ' ' && str[i] != '\0') { length++; i++; }
		while (str[i] == ' ') i++;
		length_and_index[m][0] = length;
		m++;
		if (max < length)
			max = length;
	}
	cout << "Наибольшие по длине слова : " << endl;
	cout << "Порядковый номер	Индеккс, с которого начинается слово " << endl;
	for (int j = 0; j < m; j++)
		if (length_and_index[j][0] == max)
			cout << j + 1 << "\t\t\t\t" << length_and_index[j][1] << endl;
	cout << endl;

	return 0;
}