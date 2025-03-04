#include <stdio.h>
#include <string.h>

void dan_remove_last_char(char *str)
{
    size_t len = strlen(str);
    str[len - 1] = '\0';
}

int main()
{
    char str[50] = "Hello";
    dan_remove_last_char(str);
    printf("после удаления: %s\n", str);
    return 0;
}