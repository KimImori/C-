#include <stdio.h>
#include <stdlib.h>
#include "../library/array_utils.h"

int sum_arr(IntArr arr);

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
    print_array(arr.arr, arr.n);
    int result = sum_arr(arr);
    printf("Summ - %d\n", result);
    free_arr(&arr);

    return 0;
}

int sum_arr(IntArr arr)
{
    int result = 0;
    for(size_t i = 0; i < arr.n;i++)
    {
        result += arr.arr[i];
    }
    return result;
}
