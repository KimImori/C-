#include <stdio.h>

int GLOBAL_A = 12;

int main()
{
    char* str = "Hello, world";
    int local_a = 13;
    printf("GLobal - %p, local - %p\n", &GLOBAL_A, &local_a);
    printf("str = %p\n", str);
    printf("%s\n", str);


    return 0;
}