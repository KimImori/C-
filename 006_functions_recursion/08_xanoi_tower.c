#include <stdio.h>

void hanoi(unsigned int n, unsigned int i, unsigned int k)
{
    if (n == 1)
    {
        printf("Перемести диск 1 со стержня %u на стержень %u\n", i, k);
    }
    else
    {
        int tmp = 6 - i - k;
        hanoi(n - 1, i, tmp);
        printf("Перемести диск %u со стержня %u на стержен %u\n", n, i, k);
        hanoi(n - 1, tmp, k);
    }
}

int main()
{
    hanoi(3, 1, 2);

    return 0;
}