
#include <stdio.h>
int main()
{
    unsigned int mb, total_cost = 0;
    unsigned int COST_PER_PACKET = 13;
    unsigned int PACKET_MB = 100;
    unsigned int FREE_MB = 4500;

    printf("Ввведите количество мб: \n");
    if (scanf("%u", &mb) != 1)
    {
        printf("Вы ввели некорректное количество мегабайт\n");
        return 1;
    }
    if (mb > FREE_MB) // нужна тарификация
    {
        mb = mb - FREE_MB; // Убираем бесплатные мегабайты
        total_cost = mb * COST_PER_PACKET / PACKET_MB;
        if (mb % PACKET_MB != 0)
        {
            total_cost = total_cost + COST_PER_PACKET;
        }
    }

    printf("Цена: %u\n", total_cost);
    return 0;
}
