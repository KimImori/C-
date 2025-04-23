#include <stdio.h>
#include <math.h>
#include "../library/benchmark_time.h"

int main()
{
    struct timespec tstart={0,0}, tend={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    volatile double sink;
    for(size_t i=0; i<3141592; ++i)
      sink+=sin(i);
    clock_gettime(CLOCK_MONOTONIC, &tend);
    struct timespec diff = diff_timespec(&tstart, &tend);
    printf("Execution time: %.5f seconds", timespec_as_seconds(&diff));
    return 0;
}