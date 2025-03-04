#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
// напиши функцию которая найдет самое длинное слово в строке

void dan_longest_word(char *str, int *start_index, int *len_longest)
{
    int max_len = 0;
    int current_len = 0;
    int long_start = 0;
    int word_start_index = 0;
    bool in_word = false;
    size_t len = strlen(str);
    for (size_t i = 0; i <= len; i++)
    {
        if (isalpha(str[i]))
        {
            if (!in_word)
            {
                in_word = true;
                word_start_index = i;
            }
            current_len++;
        }
        else
        {
            if (in_word)
            {
                if (current_len > max_len)
                {
                    max_len = current_len;
                    long_start = word_start_index;
                }
                current_len = 0;
                in_word = false;
            }
        }
    }

    *start_index = long_start;
    *len_longest = max_len;
}

int main()
{
    char str[50] = "Hello Worldd";
    int start_index;
    int len;
    dan_longest_word(str, &start_index, &len);
    for (size_t i = 0; i < len; i++)
    {
        printf("%c", str[start_index + i]);
    }
    return 0;
}