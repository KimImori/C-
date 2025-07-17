#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linear_congruential_generator(long seed, long a, long c, long m)
{
    long x = seed;
    for (long i = 0; i < 100; i++)
    {
        x = (a * x + c) % m;
        printf("%ld ", x);
    }
}

void my_rand()
{
    for(int i=0; i<100; i++)
    {
        printf("%d ", rand() % 100);
        
    }
}

int main()
{
    srand(time(NULL));
    my_rand();
    return 0;
}

