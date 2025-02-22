#include <stdio.h>
#include <stdlib.h>

void print_array(const int* arr, size_t n)
{
    for(size_t i=0; i < n; i++)
    {
        if (i == 0)
        {
            printf("[");
        }
        printf("%d", arr[i]);
        if (i == n-1)
        {
            printf("]\n");
        }
        else
        {
            printf(", ");
        }
    }
}

void fill_array(int* arr, size_t n)
{
    for(size_t i=0; i < n; i++)
    {
        arr[i] = n-i;
    }
}


// valgrind ./a.out
int main()
{
    size_t array_size = 0;
    printf("Введите размер массива: ");
    if (scanf("%ld", &array_size) != 1)
    {
        return 1;
    }
    int* arr = malloc(array_size * sizeof(int));
    if (arr != NULL)
    {
        return 1;
    }
    fill_array(arr, array_size);
    print_array(arr, array_size);

    free(arr);
    return 0;
}