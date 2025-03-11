#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    int a = 55;
    sprintf(str, "a= %d\n", a);
    strcat(str, "world");
    printf("%s",str);
    return 0;
}