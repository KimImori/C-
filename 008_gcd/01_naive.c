#include <stdio.h>

int min(int a, int b)
{

    if (a < b)
    {
        return a;
    }
    return b;
}

int gcd(int a, int b)
{

    int counter = 0;

    for (int i = min(a, b); i >= 1; i--)
    {
        counter++;
        if ((a % i == 0) && (b % i == 0))
        {
            printf("Счетчик - %d\n", counter);
            return i;
        
        }
    }
    return 0;
}

int main()
{
    int a, b;
    if (scanf("%d%d", &a, &b) != 2)
    {
        return 1;
    }

    printf("%d\n", gcd(a, b));
    return 0;
}