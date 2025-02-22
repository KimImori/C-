#include <stdio.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 5;
    int b = 6;
    int c = 7;
    swap(&a, &b);
    swap(&b, &c);

    printf("%d %d %d\n", a, b, c);

    return 0;
}