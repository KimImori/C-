#include <stdio.h>

void print_array(const int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("[");
        }
        printf("%d", arr[i]);
        if (i == n - 1)
        {
            printf("]\n");
        }
        else
        {
            printf(", ");
        }
    }
}
void reverse_array(int arr[], size_t n)
{
    int start = 0;
    int end = n - 1;
    int tmp;
    while (start < end)
    {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
}

typedef struct _IntArr
{
    size_t n;
    int *arr;
} IntArr;

IntArr empty_arr()
{
    IntArr empty;
    empty.arr = NULL;
    empty.n = 0;
    return empty;
}
void free_arr(IntArr *arr)
{
    free(arr->arr);
    arr->n = 0;
}

IntArr create_arr(const char *file_name)
{
    IntArr result = empty_arr();
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("cannot open file");
        goto error;
    }

    if (fscanf(file, "%ld", &result.n) != 1)
    {
        goto error;
    }
    result.arr = malloc(sizeof(int) * result.n);
    if (result.arr == NULL)
    {
        goto error;
    }
    for (size_t i = 0; i < result.n; i++)
    {
        if (fscanf(file, "%d", result.arr + i) != 1)
        {
            fprintf(stderr, "%ld not number\n", i);
            goto error;
        }
    }

success:
    fclose(file);
    return result;
error:
    fclose(file);
    free_arr(&result);
    return empty_arr();
}
