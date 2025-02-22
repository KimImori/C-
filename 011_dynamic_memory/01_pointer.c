#include <stdio.h>


int main()
{
    int a = 5;

    printf("a = %d. sizeof(a) = %ld bytes \n", a, sizeof(a));

    int* pa = &a;
    printf("pa = %p. sizeof(pa) = %ld bytes\n", pa, sizeof(pa)); 
    *pa = 6; // разименование / dereference

    int* pa2 = &a;

    printf("a = %d. sizeof(a) = %ld bytes \n", a, sizeof(a));
    *pa2 = 12;
    printf("a = %d. sizeof(a) = %ld bytes \n", a, sizeof(a));
    return 0;
}