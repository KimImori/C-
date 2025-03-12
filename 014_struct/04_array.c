#include <stdio.h>
#include <stdlib.h>

typedef struct __Dummy{
    int a;
    int b;
} Dummy;

int main()
{
    Dummy arr[20];

    Dummy *d = malloc(sizeof(Dummy) * 20);
    if (d == NULL)
    {
        return 1;
    }
    for(size_t i = 0; i < 20; i++)
    {
        d[i].a = 5;
        d[i].b = 7;
    }

    free(d);
    return 0;
}