#include <stdio.h>
#include "array_utils.h"

#define GLOBAl_ARRAY_LENGTH 1000000
int GLOBAL_ARRAY[GLOBAl_ARRAY_LENGTH] = {1,2,3};

int main()
{
    print_array(GLOBAL_ARRAY, 100);

    return 0;
}