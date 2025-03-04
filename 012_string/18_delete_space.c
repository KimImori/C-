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

void dan_remove_space(char *str)
{
    size_t len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            dan_delete_by_index(str, i);
        }
    }
}

int main()
{
    char str[LEN] = "Hello  World 1";
    dan_remove_space(str);
    printf("после удаления- %s\n", str);
    return 0;
}