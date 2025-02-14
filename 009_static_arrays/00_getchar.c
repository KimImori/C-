#include <stdio.h>


int main()
{
    int i=0;
    char c;
    while(c = getchar())
    {
        if (c == EOF)
        {
            break;
        }
        printf("%c", c);
    }


    return 0;
}