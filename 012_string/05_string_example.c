#include <stdio.h>
#include <string.h>

int main()
{
    char str_1[20]; // 19 chars + 1 NULL byte
    char str_2[20];

    char* str_3 = "Hello";

    size_t str_3_len = strlen(str_3);
    printf("%ld\n", str_3_len);

    strcpy(str_1, str_3);
    strcpy(str_2, str_3);

    printf("%s\n", str_1);

    strcat(str_2,str_1);

    printf("%s\n", str_2);




    return 0;
}