#include <stdio.h>

/*
напиши рекурсивный алгоритм для выяисления числа фибоначи

fib(n) = fib(n-1) + fib(n-2)



*/

unsigned int FIB_REC_COUNTER = 0;

unsigned int fibonacci(unsigned int n)
{
    FIB_REC_COUNTER++;
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

unsigned int fib_loop(unsigned int n) {
    unsigned int a, b, c;
    a = 0;
    b = 1;
    c = 0;
    for (int i = 0; i < n; i++) {
        a = b+c;
        b = c;
        c = a;
    }
    return a;
}

int main()
{
    unsigned int n;
    if (scanf("%u", &n) != 1)
    {
        return -1;
    }

    printf("Число фибоначи под номером %u = %u\n",n, fibonacci(n));
    printf("Количество вызовов рекурсии %u \n",FIB_REC_COUNTER);

    return 0;
}