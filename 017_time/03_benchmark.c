#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
    clock_t start = clock();
    volatile double sink;
    for(size_t i=0; i<3141592; ++i)
      sink+=sin(i);
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("for loop took %lf seconds to execute \n", cpu_time_used);
}