#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <stdlib.h>
#include <string.h>


int find_index_char(const char *str, char symbol)
{
    if (str == NULL)
    {
        return -1;
    }

    int index = 0;
    while (str[index] != '\0')
    {
        if (str[index] == symbol)
        {
            return index;
        }
        index++;
    }
    return -1;
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

char *find_substr(const char *str, size_t start, size_t end)
{
    if (str == NULL)
    {
        return NULL;
    }
    if (end <= start)
    {
        return NULL;
    }
    size_t len_str = strlen(str);
    if (start >= len_str || end > len_str)
    {
        return NULL;
    }

    size_t len = end - start;
    char *result = malloc(len + 1);
    if (result == NULL)
    {
        return NULL;
    }
    size_t j = 0;
    for (size_t i = start; i < end; i++)
    {
        result[j] = str[i];
        j++;
    }
    result[j] = '\0';
    return result;
}

#endif 