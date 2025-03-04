#include <stdio.h>
#include <string.h>
size_t LEN = 50;
// Найди символ в строке и верни его позицию если не найден верни -1
char dan_find_element(char *str, char element)
{
    size_t str_len = strlen(str);
    for (size_t i = 0; i < str_len; i++)
    {
        if (str[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char str[LEN];
    char element = 'H';
    fgets(str, LEN, stdin);
    char find_element = dan_find_element(str, element);

    if (find_element != -1)
    {
        printf("позиция -  %d.\n", find_element);
    }
    else
    {
        printf("Символ '%c' не найден \n", element);
    }
    return 0;
}