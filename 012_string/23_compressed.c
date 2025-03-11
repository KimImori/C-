#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Функция принимает строку "aaabbc" и функция сжимает в строку "3a2bc"
и вторая функция, которая разжимает строку "3a2bc" и возвращает "aaabbc"
*/
char *dan_compress(const char *str)
{
    int len = strlen(str);
    int index = 0;

    char *result = malloc(len);
    if (result == NULL)
    {
        return NULL;
    }
    *result = '\0';
    for (int i = 0; i < len;)
    {
        int counter = 1;
        for (int j = i + 1; j < len; j++)
        {
            if (str[i] == str[j])
            {
                counter++;
            }
            else
            {
                break;
            }
        }

        if (counter > 1)
        {
            char num_str[20];
            sprintf(num_str, "%d", counter);
            strcat(result, num_str);
        }
        char tmp[2];
        tmp[0] = str[i];
        tmp[1] = '\0';
        strcat(result, tmp);
        i += counter;
    }

    return result;
}

int main()
{
    const char *str = "aaabbc";
    char *compressed = dan_compress(str);
    printf("После сжатия: %s\n", compressed);
    free(compressed);

    return 0;
}