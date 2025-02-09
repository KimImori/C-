#include <stdio.h>

int GLOBAL_COUNTER = 0;
int gcd(int a, int b)
{
    GLOBAL_COUNTER++;
    int r = a % b;
    if (r == 0)
    {
        return b;
    }
    return gcd(b, r);
}

int main()
{
    int a, b;
    if (scanf("%d%d", &a, &b) != 2)
    {
        return 1;
    }

    printf("%d\n", gcd(a, b));
    printf("Счетчик %d\n", GLOBAL_COUNTER);
    return 0;
}