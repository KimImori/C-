#include <stdio.h>
#include <time.h>

int main()
{
    time_t n = time(NULL);
    printf("%ld %ld\n", sizeof(time_t), n);
    return 0;
}