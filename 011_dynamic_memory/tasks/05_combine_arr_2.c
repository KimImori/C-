#include <stdio.h>
#include "../../library/array_utils.h"
#include <stdlib.h>

int* arr_combine(
    const int* arr_1, size_t len_1,
    const int* arr_2, size_t len_2)
{
    int *arr_result = malloc((len_1 + len_2) * sizeof(int));
    if (arr_result == NULL)
    {
        return NULL;
    }
    size_t i = 0;
    for (; i < len_1; i++)
    {
        arr_result[i] = arr_1[i];
    }
    for (size_t j = 0; j < len_2; j++)
    {
        arr_result[i++] = arr_2[j];
    }
    // for( size_t i = len_1, j = 0; i < len_1 + len_2;i++,j++)
    // {
    //     arr_result[i] = arr_2[j];
    // }
    return arr_result;
}

int* arr_combine_3_arr(const int* arr_1, size_t len_1,
                       const int* arr_2, size_t len_2,
                       const int* arr_3, size_t len_3)
{
    int* arr_two_combine = arr_combine(arr_1, len_1, arr_2, len_2);
    if(arr_two_combine == NULL)
    {
        return NULL;
    }
    int* result = arr_combine(arr_two_combine,len_1+len_2,arr_3, len_3);
    free(arr_two_combine);
    return result;
}

int main()
{
    int arr_1[] = {4, 8, 4};
    size_t len_arr_1 = sizeof(arr_1) / sizeof(arr_1[0]);
    int arr_2[] = {6, 2, 1};
    size_t len_arr_2 = sizeof(arr_2) / sizeof(arr_2[0]);
    int arr_3[] = {4, 2};
    size_t len_arr_3 = sizeof(arr_3) / sizeof(arr_3[0]);

    int *arr_result = arr_combine_3_arr(arr_1, len_arr_1, arr_2, len_arr_2, arr_3, len_arr_3);
    if (arr_result == NULL)
    {
        return -1;
    }
    print_array(arr_result, len_arr_1 + len_arr_2+len_arr_3);
    free(arr_result);
    return 0;
}