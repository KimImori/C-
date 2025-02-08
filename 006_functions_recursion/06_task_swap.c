#include <stdio.h>

/*
Напиши функцию swap(меняеет переменные местами)

Условно я вызываю
swap(&a, &b)

И после вызова в a лежит b
А в b лежит a

*/

void swap_num(unsigned int *a, unsigned int *b)
{
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    unsigned int a, b;
    if (scanf("%u %u", &a, &b) != 2)
    {

        return 1;
    }

    printf("Число a = %u Число b = %u до замены местами\n", a, b);

    swap_num(&a, &b);
    
    printf("Число а = %u Число b = %u после заменты местами\n", a, b);
    return 0;
}
