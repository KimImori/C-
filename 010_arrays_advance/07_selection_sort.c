#include <stdio.h>
#include "array_utils.h"
/*
selection sort простая вещь
сначала ищешь максимальный элемент и добавляешь его в конец
потом ищешь следующий максимальный не учитывая последний и добавляешь его на предпоследнее место
итд
*/

void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void set_max_element_in_end(int arr[], size_t len)
{
    int min = arr[0];
    int min_index = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            min_index = i;
        }
    }

    if (min_index != (len - 1))
    {
        swap(&arr[min_index], &arr[len - 1]);
    }
}

int main()
{
    int arr[] = {5,-1,4,1,0};
    size_t len_arr = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < len_arr; i++)
    {
        set_max_element_in_end(arr, len_arr - i);
    }
    print_array(arr, len_arr);
    reverse_array(arr, len_arr);
    print_array(arr, len_arr);

    return 0;
}