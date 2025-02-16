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