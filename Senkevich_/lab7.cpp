#include<iostream>
#include<clocale>
#include<Windows.h>
using namespace std;

struct book
{
	char name[100];
	char number[100];
	char author[100];
	int year;
	char publisher[100];
	int kol;
} books[100];

void sorti(book a[], int m)
{
	for (int i = 0; i < m - 1; i++)
		for (int j = i + 1; j < m; j++)
			if (strcmp(a[i].name, a[j].name) > 0)
			{
				book temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	

	int n;
	cout << "Введите количество книг:\n";
	cin >> n;
	getchar();

	for (int i = 0; i < n; i++)
	{
		cout << "Введите регистрационный номер:\n";
		cin >> books[i].number; getchar();
		cout << "Введите автора книги:\n";
		cin >> books[i].author; getchar();
		cout << "Введите название книги:\n";
		cin >> books[i].name; getchar();
		cout << "Введите год издания:\n";
		cin >> books[i].year; getchar();
		cout << "Введите издательство:\n";
		cin >> books[i].publisher; getchar();
		cout << "Введите количество страниц:\n";
		cin >> books[i].kol; getchar();
	}
	
	int year;
	cout << "Книги после какого года вы хотите увидеть?\n";
	cin >> year;
	getchar();

	sorti(books, n);

	for (int i = 0; i < n; i++)
		if (books->year>year)
			cout << "Название : " << books[i].name << ". Автор : " << books[i].author << ". Год издания : " << books[i].year << "." << endl;

	return 0;
}