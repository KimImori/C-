/*
именить массив так чтобы он шел задом наперед, не просто напечатать а именно изменить исходный массив

Те если у тебя есть массив {1,2,3,}
То он доожен превратиться а {3,2,1}

*/

#include <stdio.h>

#define ARR_LEN 10

int main()
{
    int arr[ARR_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tmp;
    int start = 0;
    int end = ARR_LEN - 1;
    while (start < end)
    {
        tmp = arr[start];      
        arr[start] = arr[end]; 
        arr[end] = tmp;
        start++;
        end --;
    }
    for (size_t i = 0; i < ARR_LEN; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}