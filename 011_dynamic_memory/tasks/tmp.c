#include <stdio.h>
int del_dupl(int arr[], int n)
{
    int j = 0;
    for (int i = 1; i < n - 1; i++)
    {

        if (arr[i] != arr[j])
        {
            arr[j++] = arr[i];
        }
    }

    return j;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 3, 3, 5, 6, 5};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);
    arr_len = del_dupl(arr, arr_len);
    for (int i = 0; i < arr_len; i++)
        printf("%d ", arr[i]);
    return 0;
}