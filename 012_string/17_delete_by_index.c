#include <stdio.h>
#include <string.h>
#define LEN 50

int dan_delete_by_index(char *str, int index)
{
    size_t len = strlen(str);
    if (index >= len)
    {
        return -1;
    }
    for (size_t i = index; i < len - 1; i++)
    {
        str[i] = str[i + 1];
    }
    str[len - 1] = '\0';
    return 0;
}

int main()
{
    char str[LEN] = "Hello";
    int index = 1;
    int result = dan_delete_by_index(str, index);
    if (result == 0)
    {
        printf("после удаления - %s\n", str);
    }
    else
    {
        printf("Ошибка\n");
    }

    return 0;
}