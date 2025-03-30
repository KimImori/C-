#include <stdio.h>
#include <string.h>

int find_longest_str(char **str, size_t num)
{
    if (num == 0 || str == NULL)
    {
        return -1;
    }
    int index_max = -1;
    int len_max = -1;
    for (int i = 0; i < num; i++)
    {
        if(str[i] == NULL)
        {
            continue;
        }
        int current_len = strlen(str[i]);
        if (current_len > len_max)
        {
            len_max = current_len;
            index_max = i;
        }
    }
    return index_max;
}

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        fprintf(stderr, "Use - %s [arg1, arg2, arg3 ...]\n", argv[0]);
        return -1;
    }
    char **arguments_strings = argv + 1;
    int argument_len = argc - 1;
    int longest = find_longest_str(arguments_strings, argument_len);
    if (longest == -1)
     {
        fprintf(stderr, "Error\n");
        return 1; 
    }
    printf("Result: %s\n", arguments_strings[longest]);
    return 0;
}