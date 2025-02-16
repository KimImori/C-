#include <stdio.h>

int max_arr(const int arr[], size_t n)
{
    int max = arr[0];
    for (size_t i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int min_arr(const int arr[], size_t n)
{
    int min = arr[0];
    for (size_t i = 1; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

void min_max(const int arr[], size_t n, int *min, int *max)
{
    *min = arr[0];
    *max = arr[0];
    for (size_t i = 1; i < n; i++)
    {
        if (*min > arr[i])
        {
            *min = arr[i];
        }
        if (*max < arr[i])
        {
            *max = arr[i];
        }
    }
    return;
}

int main()
{

    int arr[] = {1, 2, 3, 6, 3, 7, 5, 3};

    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    int min, max;
    min_max(arr, arr_len, &min, &max);
    printf("%d %d ", min, max);

    int arr_1[] = {2, 5, 8, 2, 4, 6, 7};
    size_t arr_len_1 = sizeof(arr_1) / sizeof(arr_1[0]);
    int min_1, max_1;
    min_max(arr_1, arr_len_1, &min_1, &max_1);
    printf("Минимальное %d Макисмальное %d ", min_1, max_1);

    return 0;
}