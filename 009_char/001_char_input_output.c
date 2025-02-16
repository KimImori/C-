/*
программа, копирующая по одному
символу с входного потока в выходной поток:
*/

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(c);

        int result = (c != EOF);
        printf("Сравнение (c != EOF): %d\n", result);
    }

    printf("Значение c: %d\n", c);
    printf("Значение EOF: %d\n", EOF);

    return 0;
}
