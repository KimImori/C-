#include <stdio.h>

void print_even_array(const int arr[], size_t len)
{
    for (size_t i = 0; i < len; i += 2)
    {
        printf("Arr[%ld] = %d \n ", i, arr[i]);
    }
}

void print_arr_reverse(const int arr[], size_t len)
{
    for (size_t i = len; i > 0; i--)
    {
        printf("Arr[%ld] = %d \n ", i - 1, arr[i - 1]);
    }
}

void print_array(const int arr[], size_t len)
{
    for (size_t i = 0; i < len; i++)
    {

        printf("Arr[%ld] = %d \n ", i, arr[i]);
    }
    printf("\n");
}

void print_start_end_array(const int arr[], size_t len)
{
    size_t i = 0;
    size_t j = len - 1;

    for (; i < len; i++, j--)
    {
        printf("Arr[%ld] = %d and Arr[%ld] = %d\n", i, arr[i], j, arr[j]);
    }
}

void find_min_array(const int arr[], size_t len, int *min_index, int *min_element)
{
    *min_element = arr[0];
    *min_index = 0;
    for (size_t i = 1; i < len; i++)
    {
        if (arr[i] <= *min_element)
        {
            *min_element = arr[i];
            *min_index = i;
        }
    }
}

int find_element_array(const int arr[], size_t len, int element)
{
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void remove_element_by_index(int arr[], size_t *len, size_t index)
{
    if (index >= *len)
    {
        return;
    }
    for (size_t i = index; i < *len - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*len)--;
}

void remove_by_element(int arr[], size_t *len, int element)
{      
    int found_index;
    while (1)
    {
        found_index = find_element_array(arr, *len, element);
        if (found_index == -1)
        {
            return;
        }
        remove_element_by_index(arr, len, found_index);
    }
}

int main()
{
    int min_index;
    int min_element;
    int arr[] = {3, 3, 3, 3, 3, 1};
    size_t len_arr = sizeof(arr) / sizeof(arr[0]);
    remove_by_element(arr, &len_arr, 3);
    print_array(arr, len_arr);

    return 0;
}