#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_str_greater(const char *str_1, const char *str_2)
{
    if (str_1 == NULL || str_2 == NULL)
    {
        return false;
    }

    while (*str_1 != '\0' || *str_2 != '\0')
    {
        char symbol_one = *str_1;
        char symbol_two = *str_2;
        if (symbol_one > symbol_two)
        {
            return true;
        }
        if (symbol_one < symbol_two)
        {
            return false;
        }
        str_1++;
        str_2++;
    }
    return false;
}

void swap(char **a, char **b)
{
    char *tmp = *b;
    *b = *a;
    *a = tmp;
}

int find_max_index(char **arr, size_t n)
{
    if (arr == NULL)
    {
        return -1;
    }
    int max_index = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (is_str_greater(arr[i], arr[max_index]))
        {
            max_index = i;
        }
    }
    return max_index;
}

void sort_arr(char **arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        size_t current_size = n - i;
        int max_index = find_max_index(arr, current_size);
        if (max_index != current_size - 1)
        {
            swap(arr + (current_size - 1), arr + max_index);
        }
    }
}

int main(int argc,char **argv)
{
    if(argc == 1)
    {
        fprintf(stderr, "Use - %s [arg1, arg2, arg3 ...]\n", argv[0]);
        return -1;
    }
    char **arguments_strings = argv + 1;
    int argument_len = argc - 1;
    sort_arr(arguments_strings,argument_len);
    for(size_t i = 0; i < argument_len; i++)
    {
        printf("%s ",arguments_strings[i]);
    }

    return 0;
}