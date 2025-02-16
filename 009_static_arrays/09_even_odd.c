#include <stdio.h>

#define ARR_LEN 10

int main()
{

    int arr[ARR_LEN] = {1,2,3,4,5,6,7,8,9,10};
    int odd = 0;
    int even = 0;
    
    for(size_t i = 0; i < ARR_LEN; i++)
    {
       if(arr[i] % 2 == 0 )
       {
        even ++;

       } 
       if(arr[i] % 2 > 0)
       {
        odd++;
       }
    }
    printf("Even - %d Odd - %d\n", even, odd);
    return 0;
}