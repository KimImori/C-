#include <stdio.h>
#include <string.h>
// на вход принимает строку и разварачивает ее задом наперед

void dan_reverse(char *str)
{
    size_t str_len = strlen(str);
    for (size_t i = 0; i < str_len / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[str_len - i - 1];
        str[str_len - i - 1] = tmp;
    }
}

int main()
{
    char str[40] = "Hello";
    dan_reverse(str);
    printf("Развернутая: %s\n", str);

    return 0;
}