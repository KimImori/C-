#include <stdio.h>

int main()
{
    int a = 5;
    int* pa = &a;

    printf("a=%d\n", a);
    printf("&a = %p\n", &a);
    printf("pa = %p\n", pa);

    (*pa) = 15;

    printf("a=%d\n", a);

    return 0;
}