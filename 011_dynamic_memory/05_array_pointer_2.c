#include <stdio.h>


int main()
{
    int arr[5] = {1,2,3,4,5};
    char* parr = arr;

    // int = {FF} {12} {00} {FF}

    printf("&arr[0] = %p. arr[0] = %d\n", parr, *parr);
    printf("&arr[1] = %p. arr[1] = %d\n", parr+1, *(parr+1));
    printf("&arr[2] = %p. arr[2] = %d\n", parr+2, *(parr+2));
    printf("&arr[3] = %p. arr[3] = %d\n", parr+3, *(parr+3));
    printf("&arr[4] = %p. arr[4] = %d\n", parr+4, *(parr+4));
    printf("&arr[5] = %p. arr[5] = %d\n", parr+5, *(parr+5)); // ub

    int i=0;
    while(i<5)
    {
        printf("*parr= %d\n", *parr);
        parr += 1;
        i++;
    }

    
    return 0;
}