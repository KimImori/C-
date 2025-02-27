#include <stdio.h>
#include <stdlib.h>
int main()
{
    size_t length;
    if(scanf("%ld", &length) != 1)
    {
        return 1;
    }
    char* str = malloc(length+1);
    if (str == NULL)
    {
        return 1;
    }
    //scanf("%s", str);
    while ((getchar()) != '\n');
    while (fgets(str, length, stdin))
    {
        printf("my str = \"%s\"\n", str);
    }

    free(str);
    return 0;
}