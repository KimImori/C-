#include <stdio.h>

void min_max(const int arr[], size_t n, int *min, int *max)
{
    for (size_t i = 1; i < n; i++)
    {
        *min = arr[0];
        *max = arr[0];
        if (*min > arr[i])
        {
            *min = arr[i];
        }
        if (*max < arr[i])
        {
            *max = arr[i];
        }

        return;
    }
}

int main()
{

    return 0;
}