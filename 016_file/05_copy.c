#include <stdio.h>

// ./copy source_file destination_file
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }
    char *source_file = argv[1];
    char *destination_file = argv[2];

    FILE *source = fopen(source_file, "r");
    if (source == NULL)
    {
        perror("Error opening source file");
        return 1;
    }

    FILE *destination = fopen(destination_file, "w");
    if (destination == NULL)
    {
        perror("Error opening destination file");
        return 1;
    }

    char buffer[255];
    while (fgets(buffer, sizeof(buffer), source) != NULL)
    {
        fputs(buffer, destination);
    }
    
    if (ferror(source) || ferror(destination))
    {
        perror("Error coping source file");
        return 1;
    }
    

    fclose(source);
    fclose(destination);
    return 0;
}