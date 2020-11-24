#include<iostream>
#include<cstring>
#include<clocale>
#include<cstdio>
#include<cstdlib>
#include<clocale>
#include<Windows.h>
#define uint unsigned int
using namespace std;

int count_day_in_months[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };

uint date_days(uint day, uint month, uint year)
{
	uint days_in_months = count_day_in_months[month - 1];
	if (!(year % 4) && month > 2)
		days_in_months++;
	return (year - 1) * 365 + days_in_months + day - 1;
}

struct tovari
{
	char name[100];
	int kol;
	int price;
	char date[11];
	int days;
} tov[100];

void sorti(tovari a[], int m)
{
	for (int i = 0; i < m - 1; i++)
		for (int j = i + 1; j < m; j++)
			if (strcmp(a[i].name, a[j].name) > 0)
			{
				tovari temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char date_now[11];
	int dd, mm, yy;
	cout << "Введите текущую дату:\n";
	cin >> date_now;

	dd = ((int)date_now[0] - 48) * 10 + (int)date_now[1] - 48;
	mm = ((int)date_now[3] - 48) * 10 + (int)date_now[4] - 48;
	yy = ((int)date_now[6] - 48) * 1000 + ((int)date_now[7] - 48) * 100 + ((int)date_now[8] - 48) * 10 + (int)date_now[9] - 48;

	int n;
	cout << "Введите количество товаров:\n";
	cin >> n;
	getchar();
	int d, m, y;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите наименование товара:\n";
		cin >> tov[i].name;

		cout << "Введите количество едениц товара:\n";
		cin >> tov[i].kol;
		getchar();
		cout << "Введите цену товара:\n";
		cin >> tov[i].price;
		getchar();
		cout << "Введите дату поступления товара на склад в формате ДД.ММ.ГГГГ :\n";
		cin >> tov[i].date;

		d = ((int)tov[i].date[0] - 48) * 10 + (int)tov[i].date[1] - 48;
		m = ((int)tov[i].date[3] - 48) * 10 + (int)tov[i].date[4] - 48;
		y = ((int)tov[i].date[6] - 48) * 1000 + ((int)tov[i].date[7] - 48) * 100 + ((int)tov[i].date[8] - 48) * 10 + (int)tov[i].date[9] - 48;
		tov[i].days = date_days(dd, mm, yy) - date_days(d, m, y);
	}
	sorti(tov, n);
	for (int i = 0; i < n; i++)
		if (tov[i].days > 30 && tov[i].price > 100000)
			cout << tov[i].name << " Цена - " << tov[i].price << " Количество - " << tov[i].kol << " Дата - " << tov[i].date << " Дней - " << tov[i].days << endl;

	return 0;
}