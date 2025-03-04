#include <stdio.h>
#include <string.h>
// сделай так что в момент когда одна строка добавляется в конец другой строки
//должен поставиться запятая и пробел
//"Hello", "Dan" -> "Hello, Dan"

char *dan_strcat(char *destination, char *str)
{
    size_t destination_len = strlen(destination);
    char *end_of_destination = destination + destination_len;

    *end_of_destination = ',';
    end_of_destination++;
    *end_of_destination= ' ';
    end_of_destination++;
    while ((*end_of_destination = *str) != '\0')
    {
        end_of_destination++;
        str++;
    }

    return end_of_destination;
}

int main()
{
    char destination[40] = "Hello";
    char *str = "Dan";

    dan_strcat(destination, str);
    printf("%s\n", destination);

    return 0;
}

