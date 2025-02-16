#include <stdio.h>
#include "array_utils.h"

int main()
{
    int arr[] = {1,2,3};
    size_t arr_len = 3;

    print_array(arr, 4); // out of bound


    return 0;
}