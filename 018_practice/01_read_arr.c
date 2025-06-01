#include <stdio.h>
#include <stdlib.h>
#include "../library/array_utils.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "%s <file.name>", argv[0]);
        return 1;
    }
    char *file_name = argv[1];
    IntArr arr = create_arr(file_name);
    if (arr.arr == NULL)
    {
        return 1;
    }
    print_array(arr.arr, arr.n);
    free_arr(&arr);

    return 0;
}


