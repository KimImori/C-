#include <stdio.h>
#include "../library/benchmark_time.h"
#include "../library/random_utils.h"
#include <stdlib.h>

int is_primary_number(int number)
{
    if(number <= 1)
    {
        return 0;
    }
    for(int i=2; i<=number/2; i++)
    {
        if(number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}


void benchmark_primary_number()
{
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    int is_primary = is_primary_number(2147483647);
    printf("Result: %d\n", is_primary);
    clock_gettime(CLOCK_REALTIME, &end);
    struct timespec diff = diff_timespec(&start, &end);
    printf("Time taken: %lf seconds for size %d\n", timespec_as_seconds(&diff), 2147483647);
}

int main()
{
    benchmark_primary_number();
    return 0;
}