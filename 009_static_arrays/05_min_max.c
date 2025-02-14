#include <stdio.h>

#define ARR_LEN 10

int main()
{
    int arr[ARR_LEN] = {1, 2, 3, 4, -7, 6, 7, 8, 9, 0};
    int min = arr[0];
    int max = arr[0];
    for (size_t i = 1; i < ARR_LEN; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Min = %d\n", min);
    printf("Max = %d\n", max);
    return 0;
}