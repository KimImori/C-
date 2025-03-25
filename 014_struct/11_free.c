#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *result = malloc(100);
    if(result == NULL)
    {
        return 1;
    }

    char *result_2 = malloc(200);
    if(result_2 == NULL)
    {
        free(result);
        return 1;
    }
    
    char *result_3 = malloc(300); 
    if(result_3 == NULL)
    {
        free(result);
        free(result_2);
        return 1;
    }

    char *result_4 = malloc(400); 
    if(result_4 == NULL)
    {
        free(result_3);
        free(result);
        free(result_2);
        return 1;
    }

    free(result_4);
    free(result_3);
    free(result_2);
    free(result);
    
    return 0;
}