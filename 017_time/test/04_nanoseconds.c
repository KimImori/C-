#include <stdio.h>
#include <time.h>
#include <math.h>

double diff_timespec(struct timespec start, struct timespec end)
{

    struct timespec diff;
    if (end.tv_nsec < start.tv_nsec)
    {
        diff.tv_sec = end.tv_sec - start.tv_sec - 1;
        diff.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec ;
    }
    else
    {
        diff.tv_sec = end.tv_sec - start.tv_sec;
        diff.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    double micro_sec = diff.tv_sec * 1000000 + diff.tv_nsec / 1000;
    return micro_sec / 1000000;
}

int main()
{

    struct timespec start;
    timespec_get(&start, TIME_UTC);
    printf("%ld %ld \n", start.tv_sec, start.tv_nsec);

    volatile double sink;
    for (size_t i = 0; i < 31415920; ++i)
        sink += sin(i);

    struct timespec end;
    timespec_get(&end, TIME_UTC);
    printf("%ld %ld \n", end.tv_sec, end.tv_nsec);

    double diff = diff_timespec(start, end);
    printf("sec: %lf\n", diff);

    return 0;
}