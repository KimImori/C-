#include <stdio.h>


size_t count_char(const char *str, char symbol);
int main()
{
    char str[] = "Hello, Dan!";
    char symbol = 'a';
    size_t result = count_char(str,symbol);
    printf("%d ",result);
    return 0;
}

size_t count_char(const char *str, char symbol)
{
    if (str == NULL)
    {
        return 0;
    }
    size_t counter = 0;
    while (*str != '\0')
    {
        if (*str == symbol)
        {
            counter++;
        }
        str++;
    }
    return counter;
}