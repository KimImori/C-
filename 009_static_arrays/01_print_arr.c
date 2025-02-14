#include <stdio.h>


int main()
{
    int arr[3]; // мусорный массив, потомучто не проинициализирован

    printf("My arr %ld bytes\n", sizeof(arr));

    for(int i=0; i < 3; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


    return 0;
}