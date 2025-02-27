#include <stdio.h>
#include <string.h>

int main()
{
    char* str = "Hello, world";
    //size_t str_len = strlen(str);
    
    // 1 вариант
    // for(size_t i = 0; i < str_len; i++)
    // {
    //     printf("%ld %c\n", i, str[i]);
    // }

    // 2 вариант
    // while(*str != '\0')
    // {
    //     printf("%c", *str);
    //     str++;
    // }

    // 3 вариант
    while(*str)
    {
        printf("%c", *str);
        str++;
    }


    return 0;
}