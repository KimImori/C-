#include <stdio.h>
#include <stdlib.h>

// ./print_file filename
int main(int argc, char **argv) 
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        char str[255];
        sprintf(str, "Error opening file: %s.\nReason", filename);
        perror(str);
        return 1;
    }

    char buffer[255];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }

    if (feof(fp))
    {
        printf("End of file\n");
    }
    else if (ferror(fp))
    {
        perror("Error reading file");
        return 1;
    }

    fclose(fp);
    return 0;
}