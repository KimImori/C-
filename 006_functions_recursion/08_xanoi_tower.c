#include <stdio.h>

void hanoi(unsigned int n, unsigned int b1, unsigned int b2, unsigned int b3)
{
    if (n == 1)
    {
        printf("Перемести диск со стержня %u на стержень %u\n", b1, b3);
    }
    else
    {
        hanoi(n - 1, b1, b3, b2);
        hanoi(1, b1, b2, b3);
        hanoi(n - 1, b2, b1, b3);
    }
}

int main()
{
    hanoi(3, 1, 2, 3);

    return 0;
}