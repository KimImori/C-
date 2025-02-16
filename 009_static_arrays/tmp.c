#include <stdio.h>

#define ARR_LEN 10

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int arr[ARR_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tmp;
    int start = 0;
    int end = ARR_LEN - 1;
    while (start < end)
    {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
    for(size_t i = 0; i <ARR_LEN; i++)
    {

        printf("%d\n",arr[i]);

    }
    return 0;
}