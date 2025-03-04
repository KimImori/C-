#include <stdio.h>
#include <string.h>
#include <ctype.h>

// полиндром - это строка которая одинаковая справа налево
// Madam
// Peep
// Level
void dan_to_lowercase(char *str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

int dan_is_polindrom(const char *str)
{
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[50] = "gobnatg";
    dan_to_lowercase(str);
    int result = dan_is_polindrom(str);
    if (result == 1)
    {
        printf("Да\n");
    }
    else
    {
        printf("Нет\n");
    }
    return 0;
}