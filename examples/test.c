#include <stdio.h>
#include <stdlib.h>

void print_array(const int *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_array_of_pointers(int **arr_ptr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *arr_ptr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int *arr_ptr[5] = {arr, arr + 1, arr + 2, arr + 3, arr + 4};

    print_array(arr, 5);
    print_array_of_pointers(arr_ptr, 5);
    

    return 0;
}