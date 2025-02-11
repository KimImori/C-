#include <stdio.h>


int abs_1(int num)
{

    if (num < 0)
    {
        return -num;
    }
    return num;
}

int main()
{
    int a, b;
    if (scanf("%d%d", &a, &b) != 2)
    {
        return 1;
    }

    a = abs_1(a);
    b = abs_1(b);

    while (b != 0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    printf("НОД = %d\n", a);

    return 0;
}