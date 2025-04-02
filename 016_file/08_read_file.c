/*напиши программу которая с аргументов командной строки читает имя файла и
пишет сколько букв в этом файле
./a.out my_super_file.txt
5522 alphas in file*/

#include <stdio.h>
#include <ctype.h>

int alpha_counts(const char *str)
{
    int counter = 0;
    if(str == NULL)
    {
        return 0;
    }
    while(*str != '\0')
    {
         if (isalpha(*str))
         {
            counter++;
         }
        str++;
    }
    return counter;
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
    int counter = 0;
    while (fgets(str, sizeof(str), file) != NULL)
    {
        counter += alpha_counts(str);
        printf("%s", str);
    }

    if (feof(file))
    {
        printf("Success\n");
        printf("Alphas - %d\n",counter);
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
