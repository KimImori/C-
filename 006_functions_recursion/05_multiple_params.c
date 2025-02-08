#include <stdio.h>


void diopant_eq(int a, int b, int c, int* x, int* y)
{
    *x = a+b;
    *y = c;
}

int main()
{
    int a=5;
    int b=6;
    int c=7;
    int x,y;

    diopant_eq(a,b,c,&x,&y);
    printf("%d %d\n", x, y);
}