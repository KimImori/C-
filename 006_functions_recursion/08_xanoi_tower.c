#include <stdio.h>

void hanoi(unsigned int n, unsigned int src, unsigned int dst, unsigned int tmp)
{
    if (n == 1)
    {
        printf("Перемести диск со стержня %u на стержень %u\n", src, dst);
    }
    else
    {
        hanoi(n - 1, src, tmp, dst);
        hanoi(1, src, dst, tmp);
        hanoi(n - 1, tmp, dst, src);
    }
}

int main()
{
    hanoi(4, 1, 2, 3);

    return 0;
}