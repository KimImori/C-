/*
Есть 3 тарифных плана у оператора сотовой связи

1-тариф
  - 5 гигабайт бесплатно, далее 100 мб стоят 15 рублей
  - 50 смс бесплатно, далее каждая смс 10 рублей
  - все звонки 1 минут 2 рубля
  - цена тарифа: 500 рублей

  2-тариф
  - 1 гигабайт бесплатно, далее 100мб стоят 20 рублей
  - 20 смс бесплатно, далее каждая смс стоит 15 рублей
  - 2 часа беслпатных разговоров потом каждая минута стоит 3 рубля
  - цена тарифа 300 рублей

3-тариф
  - 100мб стоят 30 рублей
  - каждая смс стоит 20 рублей
  - каждая минута стоит 4 рубля
  - цена тарифа: 0 рублей



Задача:
с клавиатуры ты вводишь сколько пользователь планирует:
   - скачать мегабайт за месяц
   - сколько отрпавить смс
  - сколько поговорить минут


после нужно написать сколько это будет стоить на каждом тарифе и написать номер самого дешевого тарифа



З

*/

#include <stdio.h>

// --------------------------------------------------------
unsigned int PRICE_TARIF_1 = 500;
unsigned int FREE_MB_1 = 5000;
unsigned int PACKET_MB_1 = 100;
unsigned int PRICE_MB_PACKET_1 = 15;
unsigned int FREE_SMS_1 = 50;
unsigned int PRICE_SMS_1 = 10;
unsigned int FREE_MIN_1 = 0;
unsigned int PRICE_MIN_1 = 2;
// --------------------------------------------------------
unsigned int PRICE_TARIF_2 = 300;
unsigned int FREE_MB_2 = 1000;
unsigned int PACKET_MB_2 = 100;
unsigned int PRICE_MB_PACKET_2 = 20;
unsigned int FREE_SMS_2 = 20;
unsigned int PRICE_SMS_2 = 15;
unsigned int FREE_MIN_2 = 120;
unsigned int PRICE_MIN_2 = 3;
// --------------------------------------------------------
unsigned int PRICE_TARIF_3 = 0;
unsigned int FREE_MB_3 = 0;
unsigned int PACKET_MB_3 = 100;
unsigned int PRICE_MB_PACKET_3 = 30;
unsigned int FREE_SMS_3 = 0;
unsigned int PRICE_SMS_3 = 20;
unsigned int FREE_MIN_3 = 0;
unsigned int PRICE_MIN_3 = 4;
// --------------------------------------------------------

int main()
{

    unsigned int mb_1, sms_1, min_1, total_cost_1;
    printf("Введите количество скачанных мегабайт: \n");
    printf("Введите количество отправленных SMS: \n");
    printf("Введите количество минут разговора: \n");
    if (scanf("%u%u%u", &mb_1, &sms_1, &min_1) != 3)
    {
        printf("Вы ввели некорректные данные\n");
        return 1;
    }

    total_cost_1 = PRICE_TARIF_1;

    if (mb_1 > FREE_MB_1) // нужна тарификация
    {
        // ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!!
        unsigned int mb_for_tarif;
        mb_for_tarif = mb_1 - FREE_MB_1; // Убираем бесплатные мегабайты
        total_cost_1 += mb_for_tarif * PRICE_MB_PACKET_1 / PACKET_MB_1;
        if (mb_for_tarif % PACKET_MB_1 != 0)
        {
            total_cost_1 += PRICE_MB_PACKET_1;
        }
    }

    if (sms_1 > FREE_SMS_1) // нужна тарификация
    {
        // ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!!
        unsigned int sms_1_tarif = sms_1 - FREE_SMS_1; // Убираем бесплатные смс
        total_cost_1 += sms_1_tarif * PRICE_SMS_1;
    }
    if (min_1 > FREE_MIN_1) // нужна тарификация
    {
        // ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!!
        unsigned int min_1_tarif = min_1 - FREE_MIN_1; // Убираем бесплатные минуты
        total_cost_1 += min_1_tarif * PRICE_MIN_1;
    }

    // ЦЕНА 2 ТАРИФ

    unsigned int  total_cost_2;

    total_cost_2 = PRICE_TARIF_2;

    if (mb_1 > FREE_MB_2) // нужна тарификация
    {
        // ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!!
        unsigned int mb_for_tarif_2;
        mb_for_tarif_2 = mb_1 - FREE_MB_2; // Убираем бесплатные мегабайты
        total_cost_2 += mb_for_tarif_2 * PRICE_MB_PACKET_2 / PACKET_MB_2;
        if (mb_for_tarif_2 % PACKET_MB_2 != 0)
        {
            total_cost_2 += PRICE_MB_PACKET_2;
        }
    }

    if (sms_1> FREE_SMS_2) // нужна тарификация
    {
        // ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!!
        unsigned int sms_2_tarif = sms_1 - FREE_SMS_2; // Убираем бесплатные смс
        total_cost_2 += sms_2_tarif * PRICE_SMS_2;
    }
    if (min_1 > FREE_MIN_2) // нужна тарификация
    {
        // ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!!
        unsigned int min_2_tarif = min_1 - FREE_MIN_2; // Убираем бесплатные минуты
        total_cost_2 += min_2_tarif * PRICE_MIN_2;
    }

    // ЦЕНА 3 ТАРИФА
    unsigned int total_cost_3;

    total_cost_3 = PRICE_TARIF_3;

    if (mb_1 > FREE_MB_3) // нужна тарификация
    {
        // ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!!
        unsigned int mb_for_tarif_3;
        mb_for_tarif_3 = mb_1 - FREE_MB_3;
        total_cost_3 += mb_for_tarif_3 * PRICE_MB_PACKET_3 / PACKET_MB_3;
        if (mb_for_tarif_3 % PACKET_MB_3 != 0)
        {
            total_cost_3 += PRICE_MB_PACKET_3;
        }
    }

    if (sms_1 > FREE_SMS_3) // нужна тарификация
    {
        // ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!!
        unsigned int sms_3_tarif = sms_1 - FREE_SMS_3; // Убираем бесплатные смс
        total_cost_3 += sms_3_tarif * PRICE_SMS_3;
    }
    if (min_1> FREE_MIN_3) // нужна тарификация
    {
        // ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!!
        unsigned int min_3_tarif = min_1 - FREE_MIN_3; // Убираем бесплатные минуты
        total_cost_3 += min_3_tarif * PRICE_MIN_3;
    }

    printf("Стоимость тарифа 1: %u рублей\n", total_cost_1);
    printf("Стоимость тарифа 2: %u рублей\n", total_cost_2);
    printf("Стоимость тарифа 3: %u рублей\n", total_cost_3);

    // Самый дешевый тариф
    unsigned int cheap_tarif = 1;
    int cheapest_cost = total_cost_1;
    if (total_cost_2 < cheapest_cost)
    {
        cheap_tarif = 2;
        cheapest_cost = total_cost_2;
    }

    if (total_cost_3 < cheapest_cost)
    {
        cheap_tarif = 3;
        cheapest_cost = total_cost_3;
    }

    printf("Самый дешевый тариф %u\n", cheap_tarif);

    return 0;
}