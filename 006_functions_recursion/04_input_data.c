#include <stdio.h>
#include <stdlib.h>

void input_data(int* a, int *b)
{
    if (scanf("%d%d", a, b) != 2)
    {
        abort();
    }
    return;
}

int main()
{
    int a,b;
    input_data(&a, &b);
    printf("%d %d\n", a,b);
    return 0;
}