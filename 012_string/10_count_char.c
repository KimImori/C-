#include <stdio.h>

size_t dan_strlen(const char* str)
{
    size_t len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

int main()
{
    char* str = "Hello";
    size_t str_len = dan_strlen(str);       
    printf("Длина строки: %lu\n", str_len); 
    return 0;
}