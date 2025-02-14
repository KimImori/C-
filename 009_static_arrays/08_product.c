#include <stdio.h>

#define ARR_LEN 10

int main()
{
    int arr[ARR_LEN] = {1, 2, 3, 4, -7, 6, 7, 8, 9, 10};
    int product = 1;
    for (size_t i = 0; i < ARR_LEN; i++)
    {
        product *= arr[i];
    }
    printf("Sum = %d\n", product);
    return 0;
}