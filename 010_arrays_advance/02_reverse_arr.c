#include <stdio.h>

void print_array(const int arr[], size_t n)
{
    for(size_t i=0; i < n; i++)
    {
        if (i == 0)
        {
            printf("[");
        }
        printf("%d", arr[i]);
        if (i == n-1)
        {
            printf("]\n");
        }
        else
        {
            printf(", ");
        }
    }
}

void reverse_array(int arr[], size_t n)
{
    int start = 0;
    int end = n - 1;
    int tmp;
    while (start < end)
    {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    size_t arr_length = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, arr_length);
    reverse_array(arr, arr_length);
    print_array(arr, arr_length);

    return 0;
}