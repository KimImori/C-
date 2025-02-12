#include <stdio.h>
#include <limits.h>
#include <assert.h>

int dan_abs(int n)
{
    if (n < 0)
    {
        return -n;
    }

    return n;
}

// gcd(a,b) = gcd(b,q)
int COUNTER = 0;
int gcd(int a, int b)
{
    assert(b != 0);
    while(a%b)
    {
        COUNTER++;
        int q = a%b;
        a = b;
        b = q;
    }

    return dan_abs(b);
}

int main()
{
    printf("INT_MIN = %d\n", INT_MIN);
    printf("INT_MAX = %d\n", INT_MAX);
    printf("abs(INT_MINT) = %d\n", dan_abs(INT_MIN));

    for(int a=1; a<=1000; a++)
    {
        for(int b=1; b<=1000; b++)
        {
            COUNTER = 0;
            int g = gcd(a,b);
            printf("%d,%d,%d,%d\n",a,b,g,COUNTER);
        }
    }
    return 0;
}