#include <stdlib.h>
#include <stdio.h>
#include "../library/random_utils.h"
#include "../library/array_utils.h"
#include "../library/benchmark_time.h"
#include <time.h>

int *create_arr_random(size_t len, int start, int end);
int linear_search(const int *arr, size_t len, int target);
double benchmark_1(size_t len);
double benchmark_2(size_t len);

int main()
{
    FILE* f = fopen("not_found.csv", "w");
    srand(time(NULL));
    for(size_t i = 10;i <= 1000000000;i += 1000000)
    {
        double time = benchmark_2(i);
        fprintf(f,"%ld, %lf\n",i,time);
        fflush(f);
    }
    fclose(f);
    return 0;
}
int *create_arr_random(size_t len, int start, int end)
{
    int *arr = malloc(sizeof(int) * len);
    if (arr == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        arr[i] = rand_range_inclusive(start, end);
    }
    return arr;
}

int linear_search(const int *arr, size_t len, int target)
{
    if (arr == NULL)
    {
        return -1;
    }
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
double benchmark_1(size_t len)
{
   int *arr = create_arr_random(len,0,len);
   int random_target = rand_range_inclusive(0,len);
   struct timespec start, end;
   clock_gettime(CLOCK_REALTIME, &start);

   int r = linear_search(arr,len,random_target);

   clock_gettime(CLOCK_REALTIME, &end);
   struct timespec diff = diff_timespec(&start,&end);
   double time = timespec_as_seconds(&diff);
   free(arr);
   return time;
}

double benchmark_2(size_t len)
{
   int *arr = create_arr_random(len,0,len);
   struct timespec start, end;
   clock_gettime(CLOCK_REALTIME, &start);

   int r = linear_search(arr,len,len + 1);

   clock_gettime(CLOCK_REALTIME, &end);
   struct timespec diff = diff_timespec(&start,&end);
   double time = timespec_as_seconds(&diff);
   free(arr);
   return time;
}