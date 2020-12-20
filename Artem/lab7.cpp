#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

struct strc
{
    char fio[100];
    int otm[4];
    double sb;
}mstud[100];

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int stud, i, j, n = 0;
    cout << "Ввелите кол-во студентов:" << endl;
    cin >> stud;
    getchar();
    for (i = 0; i < stud; i++)
    {
        cout << "Введите ФИО:" << endl;
        fgets(mstud[i].fio, 100, stdin);

        cout << "Введите 4 отметки:" << endl;
        mstud[i].sb = 0;
        for (j = 0; j < 4; j++)
        {
            cin >> mstud[i].otm[j];
            mstud[i].sb += mstud[i].otm[j];
        }
        getchar();
        mstud[i].sb /= 4;
        cout << endl;
    }

    mstud[stud].sb = 0;
    for (i = 0; i < stud; i++)
        mstud[stud].sb += mstud[i].sb;
    mstud[stud].sb /= stud;
    strc stemp;

    for (i = 0; i < stud - 1; i++)
        for (j = i + 1; j < stud; j++)
            if (mstud[i].sb < mstud[j].sb)
            {
                stemp = mstud[i];
                mstud[i] = mstud[j];
                mstud[j] = stemp;
            }

    cout << "Средний балл по ВУЗу : " << mstud[stud].sb << endl;

    for (i = 0; i < stud; i++)
        if (mstud[i].sb > mstud[stud].sb)
            cout << mstud[i].sb << ":" << mstud[i].fio << endl;

    return 0;
}
