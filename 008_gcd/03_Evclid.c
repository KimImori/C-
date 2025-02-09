#include <stdio.h>

int main()
{
    int a, b;
    if (scanf("%d%d", &a, &b) != 2)
    {
        return 1;
    }

    while (b != 0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    printf("НОД = %d\n", a);

    return 0;
}