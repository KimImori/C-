#include <stdlib.h>
#include <stdio.h>
#include "../library/random_utils.h"
#include "../library/array_utils.h"
#include "../library/benchmark_time.h"
#include <time.h>
#include <string.h>

int linear_search(const int *arr, size_t len, int target);
int linear_search_2(const char **arr, size_t len, char* target);
int linear_search_3(const int *arr, size_t len, int target)
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

int main()
{
    int arr[] = {0,1,2};
    const char* arr_1[] = {"noi","dan","tuy"};
    int target_1 = linear_search_2(arr_1,3,"dan");
    printf("%d",target_1);
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