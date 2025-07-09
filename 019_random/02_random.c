#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// [from; to]
int my_rand(int from, int to)
{
    int c = to-from+1;
    return (rand() % c) + from;
}

// [from; to)
int my_rand_2(int from, int to)
{
    int c = to-from;
    return (rand() % c) + from;
}


void print_random(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", my_rand(5, 10));
    }
}


int main()
{
    srand(time(NULL));
    print_random(1000);

    return 0;
}