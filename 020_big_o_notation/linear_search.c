#include <stdio.h>
#include "../library/benchmark_time.h"
#include "../library/random_utils.h"
#include <stdlib.h>

int linear_search(int arr[], int size, int target)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int* generate_random_array(int size, int from, int to)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for(int i=0; i<size; i++)
    {
        arr[i] = rand_range_exclusive(from, to);
    }
    return arr;
}

void benchmark_linear_search(int size)
{
    struct timespec start, end;
    int* arr = generate_random_array(size, 0, size/2);
    clock_gettime(CLOCK_REALTIME, &start);
    int result = linear_search(arr, size, size);
    printf("Result: %d\n", result);
    clock_gettime(CLOCK_REALTIME, &end);
    free(arr);
    struct timespec diff = diff_timespec(&start, &end);
    printf("Time taken: %lf seconds for size %d\n", timespec_as_seconds(&diff), size);
}

int main()
{
    benchmark_linear_search(100);
    benchmark_linear_search(1000);
    benchmark_linear_search(10000);
    benchmark_linear_search(100000);
    benchmark_linear_search(1000000);
    benchmark_linear_search(10000000);
    benchmark_linear_search(100000000);
    benchmark_linear_search(1000000000);
    return 0;
}