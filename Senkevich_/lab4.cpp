#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    int a[100], buf, f_el, left = 0, k;

    setlocale(LC_ALL, "Rus");

    cout << "Введите размерность массива k = " << endl;
    cin >> k;


    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        if (a[i] < 0) left++;
    }


    int i = k - 1;
    while (i > 0)
        if (a[i] < 0 && left != 0)
        {
            buf = a[i];
            for (int j = i; j > 0; j--)
                a[j] = a[j - 1];
            a[0] = buf;
            left--;
        }
        else i--;

    cout << "Массив после перестановок:" << endl;
    for (int i = 0; i < k; i++)
        cout << a[i] << " ";

    return 0;
}