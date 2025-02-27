#include <stdio.h>


int main()
{
    char buf[255];
    char c;
    size_t i = 0;
    while((c = fgetc(stdin)) != EOF)
    {
        buf[i++] = c;
    }
    buf[i] = '\0';
    printf("%s", buf);
    return 0;
}