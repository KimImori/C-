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
    Now,
    Dec
};

int main()
{
    // переменная месяц
    // это просто число!!!
    enum Month month = May;
    printf("%d\n", month);

    return 0;
}