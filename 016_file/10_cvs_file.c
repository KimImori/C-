#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dan_print_column(char *line, int column_num)
{
    int current_column = 0;
    char *end;

    while ((end = strchr(line, ',')))
    {
        if (current_column == column_num)
        {
            size_t len = end - line;
            char *result = malloc(len);
            if (result == NULL)
            {
                return NULL;
            }
            strncpy(result, line, len);
            return result;
        }
        line = end + 1;
        current_column++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("%s <файл>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    int column = atoi(argv[2]);

    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Не удалось открыть файл: %s\n", file_name);
        return 1;
    }

    char line[255];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *value = dan_print_column(line, column);
        if (value != NULL)
        {
            printf("%s\n", value);
            free(value);
        }
        else
        {
            printf("Столбец %d не найден\n", column);
        }
    }
    fclose(file);
    return 0;
}