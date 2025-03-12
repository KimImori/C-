#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <wctype.h>
#include <ctype.h>

int dan_count_words(wchar_t *str)
{
    int word_count = 0;
    size_t len = wcslen(str);
    bool i_am_in_word = false;

    for (size_t i = 0; i < len; i++)
    {
        if (iswalpha(str[i]))
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
    setlocale(LC_ALL, "C.utf8");
    const int BYTES_IN_KB = 1024;
    const int BYTES_IN_MB = BYTES_IN_KB * 1024;

    wchar_t *book = malloc(10 * BYTES_IN_MB);
    if (book == NULL)
    {
        return -1;
    }
    wint_t symbol;
    size_t i = 0;
    while ((symbol = getwc(stdin)) != WEOF)
    {
        book[i] = symbol;
        i++;
    }
    book[i] = L'\0';

    int count_words = dan_count_words(book);
    printf("Количество слов: %d", count_words);
    free(book);
    return 0;
}