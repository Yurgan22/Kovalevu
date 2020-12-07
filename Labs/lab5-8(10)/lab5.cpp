#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, m, check;
	int** matr, * b;
	cout << "Введите размер матрицы NxM: " << endl;
	cin >> n >> m;

	matr = new int* [n];
	for (int i = 0; i < n; i++)
		*(matr+i) = new int[m];
	b = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> *(*(matr + i) + j);

	for (int i = 0; i < n; i++)
	{
		check = 1;
		for (int j = 0; j < m - 1; j++)
			if (*(*(matr + i) + j) <= *(*(matr + i) + j + 1)) check = 0;
		*(b + i) = check;
	}

	cout << "Массив В:\n";
	for (int i = 0; i < n; i++)
		cout << i + 1 << ") " << *(b + i) << endl;
	for (int i = 0; i < n; i++)
		delete []*(matr + i);
	delete[]matr;
	matr = NULL;
	delete[]b;
	b = NULL;
	return 0;
}
