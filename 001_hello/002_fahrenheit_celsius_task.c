#include <stdio.h>

/* печать таблицы температур по Фаренгейту
и Цельсию для fahr = 0, 20, ..., 300 */

int main()

{

    int lower, upper, step;
    float fahr, celsius;

    lower = 0;
    upper = 300;
    step = 20;
    printf("+-----------------+-----------------+\n");
    printf("|      °F         |      °C         |\n");
    printf("+-----------------+-----------------+\n");
    celsius = lower;
    while (celsius <= upper)
    {

        celsius = (5.0 / 9.0) * (fahr - 32.0);

        printf("%3.0f\t\t\t %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}