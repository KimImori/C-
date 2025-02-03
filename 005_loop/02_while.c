#include <stdio.h>


int main()
{
    unsigned int i = 0;
    while(i<10) 
    {
        printf("%u,",i);
        i++; // i += 1
    }
    printf("\n i after loope %u\n", i);

    return 0;
}