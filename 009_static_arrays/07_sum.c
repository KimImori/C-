#include <stdio.h>

#define ARR_LEN 10

int main()
{
    int arr[ARR_LEN] = {1, 2, 3, 4, -7, 6, 7, 8, 9, 0};
    int sum = 0;
    for (size_t i = 0; i < ARR_LEN; i++)
    {
        sum += arr[i];
    }
    printf("Sum = %d\n", sum);
    return 0;
}