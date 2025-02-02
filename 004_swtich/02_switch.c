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
        case Jan:
            printf("Январь\n"); break;
        case Feb:
            printf("Февраль\n"); break;
        case Mar:
            printf("Март\n"); break;
        case Apr:
            printf("Апрель\n"); break;
        case May:
            printf("Май\n"); break;
        case Jun:
            printf("Июнь\n"); break;
        case Jul:
            printf("Июль\n"); break;
        case Aug:
            printf("Август\n"); break;
        case Sep:
            printf("Сентябрь\n"); break;
        case Oct:
            printf("Октябрь\n"); break;
        case Now:
            printf("Ноябрь\n"); break;
        case Dec:
            printf("Декабрь\n"); break;
        default:
            printf("Некорректный месяц\n");
    }

    return 0;
}