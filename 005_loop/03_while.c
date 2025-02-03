#include <stdio.h>


int main()
{
    unsigned int i = 0;
    while(i<=100) 
    {
        printf("%u,",i);
        i += 5;
    }
    printf("\n i after loope %u\n", i);

    return 0;
}