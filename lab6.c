#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "rus");

	int n, m, * arr;
	printf("Введите размер матрицы NxM ");
	scanf_s("%d%d", &n, &m);

	arr = (int*)malloc(n * m * sizeof(int));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%d", arr + i * m + j);

	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n - 1; i++)
			for (int k = i + 1; k < n; k++)
				if (*(arr + i * m + j) > * (arr + k * m + j) && *(arr + i * m + j) < 0 && *(arr + k * m + j) < 0)
				{
					int buf = *(arr + i * m + j);
					*(arr + i * m + j) = *(arr + k * m + j);
					*(arr + k * m + j) = buf;
				}
	}
	printf("Матрица с отсортированными отрицательными элементами столбцов ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d  ", *(arr + i * m + j));
		printf("\n");
	}

	return 0;
}
