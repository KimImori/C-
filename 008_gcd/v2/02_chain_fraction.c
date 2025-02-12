#include <stdio.h>
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

int gcd(int a, int b)
{
    assert(b != 0);
    printf("(");
    while(a%b)
    {
        int q = a%b;
        int p = a/b;
        printf("%d,",p);
        a = b;
        b = q;
    }
    printf("%d)\n", a);

    return dan_abs(b);
}


int main()
{
    gcd(9,4);
}