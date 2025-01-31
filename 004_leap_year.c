#include <stdio.h>

int main()
{
    int year;
    printf("Введите год\n");
    if (scanf("%d", &year) != 1)
    {
        printf("Некорректный год\n");
        return 1;
    }

    if (year % 400 == 0)
    {
        printf("Високосный год\n");
    }
    else if (year % 100 == 0)
    {
        printf("Не високосный\n");
    }
    else if (year % 4 == 0)
    {
        printf("Високосный год\n");
    }
    else
    {
        printf("Не високосный\n");
    }

    return 0;
}