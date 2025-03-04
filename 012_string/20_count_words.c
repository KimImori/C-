#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int dan_count_words(char *str)
{
    int word_count = 0;
    size_t len = strlen(str);
    bool i_am_in_word = false;

    for (size_t i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            if (!i_am_in_word)
            {
                i_am_in_word = true;
                word_count++;
            }
        }
        else
        {
            i_am_in_word = false;
        }
    }
    return word_count;
}

int main()  
{
    char str[50] = "Привет, мир";
    int words = dan_count_words(str);
    printf("Количество слов в строке %d\n", words);

    return 0;
}