#include <stdio.h>


int baz(int a)
{
    return a;
}

int bar(int a)
{
    a += 100;
    return baz(a+1);
}

int foo(int a)
{
    int x = bar(a+1);
    return x;
}

int main()
{
    printf("%d", foo(5));

    return 0;
}