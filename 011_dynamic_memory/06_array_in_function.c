#include <stdio.h>


int max_arr(const int* arr, size_t n)
{
    int max = arr[0];
    for (size_t i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}


int main()
{


    return 0;
}