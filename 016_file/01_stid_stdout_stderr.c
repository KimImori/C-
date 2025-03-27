#include <stdio.h>

// stdout
// stdin
// stderr

int main() 
{
    int a = 10;
    char str[255] = "123";

    scanf("%d", &a); // stdin
    fscanf(stdin, "%d", &a);
    sscanf(str, "%d", &a);

    printf("Hello, World! %d\n", a); // stdout
    fprintf(stdout, "Hello, World! %d\n", a);
    sprintf(str, "Hello, World! %d\n", a);

    return 0;
}