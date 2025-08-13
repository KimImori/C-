#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../library/random_utils.h"

typedef struct _BinomParams
{
    int n;
    double p;

} Binom;

int outcome(Binom b);

int main()
{
    Binom b;
    b.n = 30;
    b.p = 0.5;
    for(size_t i = 0; i < 100;i++)
    {
        printf("%d\n",outcome(b));
    }

    return 0;
}

int outcome(Binom b)
{
    int counter = 0;
    for(size_t i = 0; i < b.n ;i++)
    {
       int r = rand_range_exclusive(0,100);
       if(r < b.p * 100)
       {
        counter++;
       }   

    }


    return counter;
}