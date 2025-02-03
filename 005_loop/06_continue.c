#include <stdio.h>


int main()
{
    int i = 0;
    while(i <= 100)
    {
        i++;
        if ((i % 10) == 0)
        {
            continue;
        }
        printf("%d\n",i);
    }

    return 0;
}