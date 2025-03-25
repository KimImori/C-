#include <stdio.h>

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("%s [n]...\n",argv[0]);
        return 1;
    }
    int sum = 0;
    for(size_t i = 1; i < argc; i++)
    {
        char *str = argv[i];
        int a;
        if(sscanf(str, "%d",&a)!= 1)
        {
            return 1;
        }
        sum += a;
    }
    printf("%d\n", sum);

    return 0;
}