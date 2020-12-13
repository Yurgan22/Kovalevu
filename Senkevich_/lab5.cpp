#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, m, check;
	int** matr, * sum;
	cout << "Введите размер матрицы NxM: " << endl;
	cin >> n >> m;

	matr = new int* [n];
	sum = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(matr + i) = new int[m];
		*(sum + i) = 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> *(*(matr + i) + j);
			*(sum + i) += *(*(matr + i) + j);
		}
	int buf;
	for (int i = 0; i < n-1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (*(sum + i) > * (sum + j))
			{
				buf = *(sum + i);
				*(sum + i) = *(sum + j);
				*(sum + j) = buf;
				for (int k = 0; k < m; k++)
				{
					buf = *(*(matr + i) + k);
					*(*(matr + i) + k) = *(*(matr + j) + k);
					*(*(matr + j) + k) = buf;
				}
			}
		}

	cout << "Отсортированный массив :\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << *(*(matr + i) + j) << " ";
		cout << endl;
	}
	for (int i = 0; i < n; i++)
		delete[] * (matr + i);
	delete[]matr;
	matr = NULL;
	delete[]sum;
	sum = NULL;
	return 0;
}