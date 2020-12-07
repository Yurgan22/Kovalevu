#pragma warning(disable:4996)
#include<iostream>  
#include<stdio.h>  
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define uint unsigned int

using namespace std;
int count_day_in_months[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
FILE* fl, * ft;
char name[20];
char namet[30];
typedef struct
{
	char name[20];
	int kol;
	int price;
	char date[11];
	int days;
} tovari;
tovari tov[100];
void sorti(tovari[], int);
uint date_days(uint, uint, uint);
int dd = 7, mm = 12, yy = 2020, n;
int kol = 0;
int i = 0;       // Число введенных структур 
int menu();        // Меню 
void nnf();        // Ввести имя файла 
void newf();       // Создать новый файл
void spisok();     // Ввести список 
void opf();        // Открыть файл 
void opf1();
void resc();       // Вывести результат на экран 
void resf();       // Вывести результат в файл 

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		switch (menu())
		{
		case 1: nnf();    break;
		case 2: newf();   break;
		case 3: spisok(); break;
		case 4: opf();    break;
		case 5: resc();   break;
		case 6: resf();   break;
		case 7: opf1();   break;
		case 8: return 0;
		default: "Выберете правильный вариант!";
		}
		puts("Нажмите любую клавишу, чтобы продолжить...");
		getch();      system("cls");
	}
}

int menu() // Меню 
{
	cout << "Выберете действие:" << endl;
	cout << "1. Ввод название файла" << endl;
	cout << "2. Создание нового файла" << endl;
	cout << "3. Ввод списка товаров" << endl;
	cout << "4. Открыть файл ввода" << endl;
	cout << "5. Вывести результат на экран" << endl;
	cout << "6. Вывести результат в файл" << endl;
	cout << "7. Открыть файл вывода" << endl;
	cout << "8. Выход" << endl;
	int i;
	cin >> i;
	return i;
}

void nnf()      // Ввести имя файла 
{
	cout << "Vvedite file name" << endl;
	cin >> name;
}

void newf()     // Создать новый файл 
{
	if ((fl = fopen(name, "wb")) == NULL)
	{
		cout << "Oshibka pri sozdanii" << endl;
		exit(1);
	}
	cout << "OK" << endl;
	fclose(fl);
}

void spisok()   // Ввести список 
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Oshibka pri sozdanii" << endl;
		exit(1);
	}
	cout << "Vvedite chislo tovarov" << endl;
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
		fwrite(&tov[i], sizeof(tovari), 1, fl);
	}
	fclose(fl);
}
void opf()      // Открыть файл 
{
	if ((fl = fopen(name, "rb")) == NULL)
	{
		cout << "Oshibka pri otkritii" << endl;
		exit(1);
	}
	char s[80];
	int i = 0; tovari std;
	while (true)
	{
		int nwrt = fread(&std, sizeof(tovari), 1, fl);
		if (nwrt != 1) break;
		tov[i] = std;
		cout << tov[i].name << " Цена - " << tov[i].price
			<< " Количество - " << tov[i].kol << " Дата - "
			<< tov[i].date << " Дней - "
			<< tov[i].days << endl;
		i++;
	}
	sorti(tov, n);
	fclose(fl);
}

void resc()      // Вывести результат на экран 
{
	for (int i = 0; i < n; i++)
		if (tov[i].days > 30 && tov[i].price > 100000)
			cout << tov[i].name << " Цена - " << tov[i].price
			<< " Количество - " << tov[i].kol << " Дата - "
			<< tov[i].date << " Дней на складе - "
			<< tov[i].days << endl;
}

void resf()      // Вывести результат в файл 
{
	cout << "Введите имя файла " << endl;
	cin >> namet;
	if ((ft = fopen(namet, "w")) == NULL)
	{
		cout << "Ошибка при создании " << endl;
		exit(1);
	}
	char s[110], str[9];
	for (int i = 0; i < n; i++)
		if (tov[i].days > 30 && tov[i].price > 100000)
		{
			kol++;
			strcpy(s, tov[i].name);
			strcat(s, " Цена - ");
			sprintf(str, "%d", tov[i].price);
			strcat(s, str);
			strcat(s, " Количество - ");
			sprintf(str, "%d", tov[i].kol);
			strcat(s, str);
			strcat(s, " Дата - ");
			strcat(s, tov[i].date);
			strcat(s, " Дней на складе - ");
			sprintf(str, "%d", tov[i].days);
			strcat(s, str);
			strcat(s, "\n");
			fputs(s, ft);
		}
	fclose(ft);
}

uint date_days(uint day, uint month, uint year) // Вычесление кол-во дней хранения на складе
{
	uint days_in_months = count_day_in_months[month - 1];
	if (!(year % 4) && month > 2)
		days_in_months++;
	return (year - 1) * 365 + days_in_months + day - 1;
}

void sorti(tovari a[], int m) // Сортировка в алфавитном порядке
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

void opf1()      // Открыть файл Вывода
{
	if ((ft = fopen(namet, "rb")) == NULL)
	{
		cout << "Oshibka pri otkritii" << endl;
		exit(1);
	}
	char std[111];
	int i = 0;
	while (i<kol)
	{
		fgets(std, 110, ft);
		cout << std << endl;
		i++;
	}
	fclose(ft);
}
