#include <stdio.h>
#include <stdlib.h>
#include "../library/array_utils.h"

int mining_max(IntArr arr);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "%s [file.name]\n", argv[0]);
        return 1;
    }

    IntArr arr = create_arr(argv[1]);
    if (arr.arr == NULL)
    {
        fprintf(stderr, "can't create arr\n");
        return 1;
    }
    int result = mining_max(arr);
    print_array(arr.arr, arr.n);
    printf("%d\n", result);
    free_arr(&arr);

    return 0;
}

int my_max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int mining_max(IntArr arr)
{
    if(arr.n == 1)
    {
       return arr.arr[0];
    }
    int *answer = calloc(arr.n, sizeof(int));
    if (answer == NULL)
    {
        return -1;
    }

    answer[0] = arr.arr[0];
    answer[1] = my_max(arr.arr[0], arr.arr[1]);

    for(size_t i = 2; i < arr.n; i++)
    {
    answer[i] =  my_max(answer[i - 1], answer[i - 2] + arr.arr[i]);

    }
    int result = answer[arr.n - 1];
    free(answer);
    return result;
}