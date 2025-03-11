#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <wctype.h>

void dan_longest_word(wchar_t *str, int *start_index, int *len_longest)
{
    int max_len = 0;
    int current_len = 0;
    int long_start = 0;
    int word_start_index = 0;
    bool in_word = false;
    size_t len = wcslen(str);
    for (size_t i = 0; i <= len; i++)
    {
        if (iswalpha(str[i]))
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
    setlocale(LC_ALL, "C.utf8");
    const int BYTES_IN_KB = 1024;
    const int BYTES_IN_MB =BYTES_IN_KB*1024;

    wchar_t* book = malloc(10*BYTES_IN_MB);
    if (book == NULL)
    {
        return -1;
    }
    wint_t  symbol;
    size_t i =0;
    while( (symbol = getwc(stdin)) != WEOF)
    {
        book[i] = symbol;
        i++;
    }
    book[i] = L'\0';


    //printf("Book: %ls\n", book);

    int start_index;
    int length_of_longest_word;
    dan_longest_word(book, &start_index, &length_of_longest_word);

    for (size_t i = start_index; i < start_index+length_of_longest_word; i++)
    {
        printf("%lc", book[i]);
    }
    

    free(book);
    return 0;
}