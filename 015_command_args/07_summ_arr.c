#include <stdio.h>

int summ_arr(int arr[],size_t n)
{
    int sum = 0;
    for(size_t i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int product_arr(int arr[],size_t n)
{
    int product = 1;
    for(size_t i = 0; i < n; i++)
    {
        product *= arr[i];
    }
    return product;
}


int main()
{
    int arr[3] = {1,2,3};
    int sum = product_arr(arr,3);
    printf("%d\n",sum);
    return 0;
}