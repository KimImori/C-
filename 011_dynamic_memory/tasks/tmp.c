#include <stdio.h>
#include <stdbool.h>
#include "../../library/array_utils.h"


bool contains(int arr[], size_t len, int element)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == element)
        {
            return true;
        }
    }
    return false;
}

void del_dupl(int arr[], size_t len, int arr_result[])
{
    int result_len = 0;
    for (int i = 0; i < len; i++)
    {
        if (contains(arr_result, result_len, arr[i]))
        {
       
        }
    }
}

int main()
{
    int arr_1[] = {1, 2, 3, 2, 3, 3, 5, 6, 5};
    int len_arr = sizeof(arr_1) / sizeof(arr_1[0]);
    int result[len_arr];
    del_dupl(arr_1, len_arr, result);
    print_array(result, len_arr);

    return 0;
}