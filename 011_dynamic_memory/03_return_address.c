#include <stdio.h>

int* foo()
{
    int a = 7;
    return &a;
}

int main()
{
    int* pa = foo(); // dead parrot
    printf("%p %d\n", pa, *pa);

    return 0;
}