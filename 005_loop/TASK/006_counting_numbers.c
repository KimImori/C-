#include <stdio.h>

/*

вводишь число x

печатаешь сколько в нем цифр.

те если я введу: 1400
печатаешь что в нем 4 цифры

*/

int main()
{

    unsigned int x;

    if (scanf("%u", &x) != 1)
    {
        printf("Вы ввели некорректное число");

        return 1;
    }
    unsigned int counter = 0;

    while (x > 0)
    {
        x /= 10;
        counter++;
    }

    printf("В числе цифр %u\n", counter);

    return 0;
}