#include <stdlib.h>
#include <stdio.h>
#include "../library/random_utils.h"
#include "../library/array_utils.h"
#include "../library/benchmark_time.h"
#include <time.h>
#include <string.h>

int linear_search(const int *arr, size_t len, int target);
int linear_search_2(const char **arr, size_t len, char* target);
int linear_search_3(const void* arr, size_t element_size, size_t len, const void* target, int (*compare_func)(const void *, const void *))
{
    if (arr == NULL)
    {
        return -1;
    }
    const char *casted_arr = (const char *)arr;
    for (size_t i = 0; i < len; i++)
    {
        if (compare_func(casted_arr + (i * element_size), target) == 0)
        {
            return i;
        }
    }
    return -1;
}

int compare_int(const void *value1, const void *value2)
{
    int *int_value1 = (int *)value1;
    int *int_value2 = (int *)value2;
    return *int_value1 == *int_value2 ? 0 : 1;
}

int compare_str(const void *value1, const void *value2)
{
    char **str_value1 = (char **)value1;
    char **str_value2 = (char **)value2;
    return strcmp(*str_value1, *str_value2) == 0 ? 0 : 1;
}
int main()
{
    int arr[] = {0,1,2};
    const char* arr_1[] = {"noi","dan","tuy"};
    int target = 2;
    char *target_str = "dan";
    int result = linear_search_3(arr, sizeof(int), 3, &target, compare_int);
    int result_2 = linear_search_3(arr_1, sizeof(char*), 3, &target_str, compare_str);
    printf("%d\n",result);
    printf("%d\n",result_2);
    return 0;
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
int linear_search_2(const char **arr, size_t len, char* target)
{
    if (arr == NULL)
    {
        return -1;
    }
    for (size_t i = 0; i < len; i++)
    {
        if (strcmp(arr[i],target) == 0)
        {
            return i;
        }
    }
    return -1;
}