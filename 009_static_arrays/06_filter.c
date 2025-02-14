#include <stdio.h>

#define ARR_LEN 10

int main()
{
    int arr[ARR_LEN] = {1, 2, 3, 4, -7, 6, 7, 8, 9, 0};
   
    for(size_t i = 0; i < ARR_LEN ;i++)
    {
        if(arr[i] % 2 == 0)
        {
            printf("%d ", arr[i]);

        }

    }
    printf("\n");
    return 0;
}