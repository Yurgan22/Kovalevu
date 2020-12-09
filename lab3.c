#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define N 100

int main()
{
    setlocale(LC_ALL, "rus");
    int n, m[N], k, kol = 0;
    printf_s("Введите число N = ");
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) m[i] = 1;
    k = n - 1;

    do
    {
        printf("%d=", n);
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1 || m[i + 1] == 0) {
                printf("%d\n", m[i]);
                break;
            }
            else printf("%d+", m[i]);
        }

        if ((m[k] - 1) >= (m[k - 1] + 1) && (k >= 1))
        {
            m[k - 1]++; m[k]--;
        }
        else {
            m[k - 1] += m[k];
            m[k--] = 0;
        }
        kol++;
    } while (m[0] != 0 && k != 0);
    printf_s("%d=%d", n, n);
    printf_s("\nВсех - %d способов представления числа %d суммой ", ++kol, n);
    return 0;
}
