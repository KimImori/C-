#include <stdio.h>

typedef char* t_string;

void foo(char **arr, size_t n);

int main()
{
    sss a;
    char str[255];
    t_string p = str;

    fgets(str, 255, stdin);
    printf("%s\n", str);
    return 0;
}