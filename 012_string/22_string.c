#include <stdio.h>

void dan_print_string(char* str, int start, size_t len)
{
    int end = start + len;
    for (size_t i = start; i < end; i++)
    {
        printf("%c", str[i]);
    }
}

int main()
{
    char* str = "Hello, World";
    int start = 1;
    size_t len = 5;
    dan_print_string(str, start, len);

    return 0;
}