#include <stdio.h>
#include "../../library/array_utils.h"
#include <stdlib.h>

void fill_array(int arr[], size_t len)
{
    for(size_t i = 0; i < len;i++)
    {
        arr[i] = i+1;
    }
}

int* arr_copy(const int arr_source[], size_t len)
{
    int* arr_dest = malloc(len * sizeof(int));
    if(arr_dest == NULL)
    {
        return NULL;
    }
    for(size_t i = 0; i < len;i++)
    {
        arr_dest[i] = arr_source[i];
    }
    return arr_dest;
}
int main()
{
    size_t len_arr; 
    if(scanf("%ld", &len_arr) != 1)
    {
        return 1;
    }
    int* arr = malloc(len_arr * sizeof(int));
    if(arr == NULL)
    {
        return 1;
    }
    fill_array(arr, len_arr);
    int* new_arr  = arr_copy(arr, len_arr);
    if(new_arr == NULL)
    {
        return -1;
    }
    new_arr[0] = 3;
    print_array(arr, len_arr);
    print_array(new_arr, len_arr);

    free(arr);
    free(new_arr);
    return 0;
}