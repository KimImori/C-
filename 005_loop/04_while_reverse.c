#include <stdio.h>


int main()
{
    int i = 100;
    while(i>=0) 
    {
        printf("%u,",i);
        i -= 5;
    }
    printf("\n i after loope %d\n", i);

    return 0;
}