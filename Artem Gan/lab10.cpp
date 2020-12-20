#pragma warning(disable:4996)
#include<iostream>  
#include<stdio.h>  
#include<conio.h>

#include<string.h>
#include<Windows.h>
#define uint unsigned int

using namespace std;
FILE* fl, * ft;
char name[20];
char namet[30];
char abonent[15];
typedef struct
{
	char nomer[15];
	int time;
	int price;
	int summa;
} razgovori;
razgovori zvonki[100];
void sorti(razgovori[], int);

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
	cout << "Введите количество разговоров" << endl;
	cin >> n;
	getchar();

	for (int i = 0; i < n; i++)
	{
		cout << "Введите номер абонента:\n";
		cin >> zvonki[i].nomer;
		cout << "Введите время разговора в минутах:\n";
		cin >> zvonki[i].time;
		cout << "Введите тариф (руб/мин):\n";
		cin >> zvonki[i].price;

		zvonki[i].summa = zvonki[i].time * zvonki[i].price;
		fwrite(&zvonki[i], sizeof(razgovori), 1, fl);
	}
	fclose(fl);
	cout << "Информацию о каком абоненте вы хотите узнать?:\n";
	getchar();
	cin >> abonent;
}
void opf()      // Открыть файл 
{
	if ((fl = fopen(name, "rb")) == NULL)
	{
		cout << "Oshibka pri otkritii" << endl;
		exit(1);
	}
	char s[80];
	int i = 0; razgovori std;
	while (true)
	{
		int nwrt = fread(&std, sizeof(razgovori), 1, fl);
		if (nwrt != 1) break;
		zvonki[i] = std;
		cout << zvonki[i].nomer << " Тариф - " << zvonki[i].price
			<< " руб/мин. Время разговора - " << zvonki[i].time << " минут." << endl;
		i++;
	}
	fclose(fl);
}

void resc()      // Вывести результат на экран 
{
	for (int i = 0; i < n; i++)
		if (strcmp(zvonki[i].nomer, abonent) == 0)
			cout << zvonki[i].nomer << " Тариф - " << zvonki[i].price << " руб/мин."
			<< " Время разговора - " << zvonki[i].time << " минут." << endl << "Нужно заплатить : " << zvonki[i].summa << " рублей" << endl;
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
		if (strcmp(zvonki[i].nomer, abonent) == 0)
		{
			kol++;
			strcpy(s, zvonki[i].nomer);
			strcat(s, " Тариф - ");
			sprintf(str, "%d", zvonki[i].price);
			strcat(s, str);
			strcat(s, " Время разговора - ");
			sprintf(str, "%d", zvonki[i].time);
			strcat(s, str);
			strcat(s, " минут.");
			strcat(s, "\n");
			strcat(s, "Нужно заплатить : ");
			sprintf(str, "%d", zvonki[i].summa);
			strcat(s, str);
			strcat(s, " рублей.");
			strcat(s, "\n");
			fputs(s, ft);
		}
	fclose(ft);
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
	while (i < kol*2)
	{
		fgets(std, 110, ft);
		cout << std << endl;
		i++;
	}
	fclose(ft);
}