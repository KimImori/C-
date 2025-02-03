#include <stdio.h>


int main()
{
    unsigned int i = 100;
    while(1) 
    {
        printf("%u,",i);
        if (i == 0)
        {
            break;
        }
        i -= 5;
    }
    printf("\n i after loope %u\n", i);

    return 0;
}