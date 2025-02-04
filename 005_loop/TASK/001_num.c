#include <stdio.h>

int main()
{
    unsigned int num, sum = 0;

    if (scanf("%u", &num) != 1)
    {
        printf("Вы ввели неположительное число\n");
        return 1;
    }

    for (unsigned int i = 1; i <= num; i++)
    {
        sum += i;
        if (i == 1)
        {
            printf("%u", i);
        }
        else
        {
            printf("+%u", i);
        }
    }
    printf("=%u", sum);
    return 0;
}