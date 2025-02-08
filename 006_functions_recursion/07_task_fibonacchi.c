#include <stdio.h>

/*
напиши рекурсивный алгоритм для выяисления числа фибоначи

fib(n) = fib(n-1) + fib(n-2)



*/

unsigned int fibonacci(unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    unsigned int n;
    if (scanf("%u", &n) != 1)
    {
        return -1;
    }

    printf("Число фибоначи под номером %u = %u\n",n, fibonacci(n));

    return 0;
}