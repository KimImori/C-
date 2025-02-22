#include <stdio.h>
#include <stdlib.h>
#include "../library/array_utils.h"

int* create_array(size_t n, int default_value)
{
    int* arr = malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < n; i++)
    {
        //arr[i] = default_value;
        *(arr+i) = default_value;
    }
    return arr;
}

int* copy_array(const int* source_arr, size_t n)
{
    int* new_arr = malloc(n * sizeof(int));
    if (new_arr == NULL)
    {
        return NULL;
    }

    for(size_t i=0; i < n; i++)
    {
        new_arr[i] = source_arr[i];
    }

    return new_arr;
}


int main()
{
    int* arr = create_array(15, 10);
    if (arr == NULL)
    {
        return 1;
    }
    int* new_arr = copy_array(arr, 15);
    if (new_arr == NULL)
    {
        return 1;
    }
    new_arr[0] = 100;
    
    print_array(arr, 15);
    print_array(new_arr, 15);

    free(new_arr);
    free(arr);
    return 1;
}