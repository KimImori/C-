#include <stdio.h>
#include <ctype.h>

size_t dan_count_let(const char *str)
{
    int count = 0;

    while (*str != '\0')
    {
        if (isalpha(*str))
        {
            count++;
        }
        str++;
    }

    return count;
}

int main()
{
    char *str = "Hello, World! 12345";
    size_t let_count = dan_count_let(str);
    printf("Количество букв в строке: %lu\n", let_count);
    return 0;
}