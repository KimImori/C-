#include <stdio.h>


int main()
{
    int arr[3];

    for(int i=0; i < 3; i++)
    {
        //scanf("%d", &(arr[i]));
        // arr[i] = 10-i;
        arr[2-i] = 10-i;
        // i = 0 arr[2] = 10;
        // i = 1 arr[1] = 9;
        // i = 2 arr[0] = 8;
    }

    for(int i=0; i < 3; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


    return 0;
}