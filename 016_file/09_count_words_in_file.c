#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int dan_count_words(char *str)
{
    int word_count = 0;
    size_t len = strlen(str);
    bool i_am_in_word = false;

    for (size_t i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            if (!i_am_in_word)
            {
                i_am_in_word = true;
                word_count++;
            }
        }
        else
        {
            i_am_in_word = false;
        }
    }
    return word_count;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "%s <имя файла>\n", argv[0]);
        return 1;
    }

    char *name_file = argv[1];
    printf("FileName: %s\n", name_file);

    FILE *file = fopen(name_file, "r");
    if (file == NULL)
    {
        perror("Error");
        return 1;
    }

    char str[255];
    int word_counter = 0;

    while (fgets(str, sizeof(str), file) != NULL)
    {
        word_counter += dan_count_words(str);
    }

    if (feof(file))
    {
        printf("Success\n");
        printf("Words - %d\n", word_counter); 
    }
    else
    {
        perror("Error Reading");
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}