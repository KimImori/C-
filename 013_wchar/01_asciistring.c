#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 255

int main()
{
    char str[BUFF_SIZE];

    fgets(str, BUFF_SIZE, stdin);

    size_t length = strlen(str);
    printf("My string = %s", str);
    printf("Length %ld\n", length);

    return 0;
}