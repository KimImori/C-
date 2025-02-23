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
    print_array(arr, len_arr);
    
    free(arr);
    return 0;
}