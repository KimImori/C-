#include <time.h>
#include <stdio.h>

int main()
{
    time_t t = time(NULL);
    printf("Epoch time:%ld\n", t);
    return 0;
}