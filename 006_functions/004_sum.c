#include <stdio.h>

int sum(int a, int b)
{
    a = 10;
    return a+b;
}


int main()
{
    int a=5;
    int b=6;
    printf("%d\n", sum(a,b));
    printf("a=%d, b=%d\n",a,b);


    return 0;
}