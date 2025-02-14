#include <stdio.h>


int main()
{
    int arr[3] = {1,2,3};
    // arr[0] = 1;
    // arr[1] = 2;
    // arr[3] = 3;

    for(int i=0; i < 3; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


    return 0;
}