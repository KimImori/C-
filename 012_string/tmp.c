#include <stdio.h>
#include <ctype.h>
#include <string.h>

void dan_longest_word(char *str, int *max_word_start_index, int *max_len)
{
    int current_len = 0;
    int word_start_index = 0;
    *max_len = 0;
    *max_word_start_index = -1;

    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            if (current_len == 0)
            {
                word_start_index = i;
            }
            current_len++;
        }
        else
        {
            if (current_len > *max_len)
            {
                *max_len = current_len;
                *max_word_start_index = word_start_index;
            }
            current_len = 0;
        }
    }

    if (current_len > *max_len)
    {
        *max_len = current_len;
        *max_word_start_index = word_start_index;
    }
}

int main()
{
    char str[50] = "Hello Worldd";
    int max_word_start_index, max_len;

    dan_longest_word(str, &max_word_start_index, &max_len);

    printf("Самое длинное слово начинается с индекса %d и  длина %d\n", max_word_start_index, max_len);

    return 0;
}