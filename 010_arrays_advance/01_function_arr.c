#include <stdio.h>

void print_array(int arr[], size_t n)
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

int main()
{
    int arr[] = {1,2,3,4,5};
    size_t arr_length = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, arr_length);

    int arr2[] = {1,534534,4324,123423,4,234,234,23432,4,234};
    size_t arr2_length = sizeof(arr2) / sizeof(arr2[0]);

    print_array(arr2, arr2_length);



    return 0;
}