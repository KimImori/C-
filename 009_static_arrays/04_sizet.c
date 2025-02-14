#include <stdio.h>

#define ARR_LEN 3

int main()
{
    int arr[ARR_LEN] = {1,2,3};

    for(size_t i=0; i < ARR_LEN; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


    return 0;
}