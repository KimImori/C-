#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 10;
    char **arr_str = malloc(sizeof(char*)*n);
    for(size_t i = 0; i < n; i++) {
        char *str = malloc(255);
        str[0] = 'H';
        str[1] = 'e';
        str[2] = 'l';
        str[3] = 'l';
        str[4] = 'o';
        str[5] = '\0';
        arr_str[i] = str;
    }
    for(size_t i = 0; i < n; i++) {
        printf("%s\n", arr_str[i]);
    }

    for(size_t i = 0; i < n; i++) {
        free(arr_str[i]);
    }
    free(arr_str);
    
    return 0;
}