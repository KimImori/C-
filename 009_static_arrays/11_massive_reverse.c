#include <stdio.h>

#define ARR_LEN 10

int main()
{
    int arr[ARR_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (size_t i = ARR_LEN; i > 0; i--)
    {
        printf("%d ", arr[i-1]);
    }
    return 0;
}