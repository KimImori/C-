#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_lowercase_str(char* str)
{
    while(*str)
    {
        *str = tolower(*str);
        str++;
    }
}

int main()
{
    char str[20];
    strcpy(str, "HeLLo, WoRlD");
    to_lowercase_str(str);
    printf("%s\n", str);

    return 0;
}