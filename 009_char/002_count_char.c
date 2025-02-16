#include <stdio.h>
/*
используем ctrl + d для вывода значение EOF !
*/
int main()
{
    long nc;
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);

    return 0;
}