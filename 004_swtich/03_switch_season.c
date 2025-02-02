#include <stdio.h>

// тип данных
enum Month {
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Now,
    Dec
};

int main()
{
    // переменная месяц
    // это просто число!!!
    enum Month month;
    scanf("%d", &month);

    switch (month)
    {
        case Dec:
        case Jan:
        case Feb:
            printf("Зима\n"); break;
        case Mar:
        case Apr:
        case May:
            printf("Весна\n"); break;
        case Jun:
        case Jul:
        case Aug:
            printf("Лето\n"); break;
        case Sep:
        case Oct:
        case Now:
            printf("Осень\n"); break;
        default:
            printf("Некорректный месяц\n");
    }

    return 0;
}