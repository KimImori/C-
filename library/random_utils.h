#include <stdlib.h>


// [from; to]
int rand_range_inclusive(int from, int to)
{
    int c = to - from + 1;
    return (rand() % c) + from;
}

// [from; to)
int rand_range_exclusive(int from, int to)
{
    int c = to - from;
    return (rand() % c) + from;
}