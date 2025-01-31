#include <stdio.h>

int main()
{
    unsigned int mb1 = 1;
    unsigned int mb, cost;

    scanf("%u", &mb);
    cost = mb / 100;
    if (mb % 100 != 0)
    {

        cost = cost + 1;
    }
        int total_cost = cost * mb1;
         printf("Цена: %u\n", total_cost);
    return 0;
}