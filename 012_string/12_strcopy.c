#include <stdio.h>

char *dan_strcpty(char *destination, char *str)
{
    while ((*destination = *str) != '\0')
    {
        destination++;
        str++;
    }
    return destination;
}

int main()
{
    char destination[40];
    char *str = "Hello, World!";
    dan_strcpty(destination, str);
    printf("Строка -  %s\n", destination);

    return 0;
}