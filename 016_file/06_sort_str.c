#include <stdio.h>
#include <string.h>
#include <assert.h>

int find_max_index(const int *arr, size_t n);

void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void sort_arr(int *arr, size_t n);

int main()
{
    int arr[8] = {3, 1, 4, 1, 5, 9, 2, 6};
    sort_arr(arr, 8);
    for (size_t i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

int find_max_index(const int *arr, size_t n)
{
    if (arr == NULL)
    {
        return -1;
    }
    int max_index = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (arr[i] > arr[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}

void sort_arr(int *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        size_t current_size = n - i;
        int max_index = find_max_index(arr, current_size);
        if (max_index != current_size - 1)
        {
            swap(arr + (current_size - 1), arr + max_index);
        }
    }
}