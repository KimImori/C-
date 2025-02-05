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


unsigned int calculate_tarrif(
    unsigned int user_mb,
    unsigned int user_sms,
    unsigned int user_min,
    unsigned int tarrif_price,
    unsigned int tarif_free_mb,
    unsigned int tarif_price_packet,
    unsigned int tarif_packet_mb,
    unsigned int tarif_free_sms,
    unsigned int tarif_sms_price,
    unsigned int tarif_free_min,
    unsigned int tarif_min_price
)
{
    unsigned int total_cost = tarrif_price;

    if (user_mb > tarif_free_mb) // нужна тарификация
    {
        unsigned int mb_for_tarif;
        mb_for_tarif = user_mb - tarif_free_mb; // Убираем бесплатные мегабайты
        total_cost += mb_for_tarif * tarif_price_packet / tarif_packet_mb;
        if (mb_for_tarif % tarif_packet_mb != 0)
        {
            total_cost += tarif_price_packet;
        }
    }

    if (user_sms > tarif_free_sms) // нужна тарификация
    {
        unsigned int sms_1_tarif = user_sms - tarif_free_sms; // Убираем бесплатные смс
        total_cost += sms_1_tarif * tarif_sms_price;
    }
    if (user_min > tarif_free_min) // нужна тарификация
    {
        unsigned int min_1_tarif = user_min - tarif_free_min; // Убираем бесплатные минуты
        total_cost += min_1_tarif * tarif_min_price;
    }

    return total_cost;
}

unsigned int min_3(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int min = a;
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }
    return min;
}


int main()
{

    unsigned int mb, sms, min;
    printf("Введите количество скачанных мегабайт: \n");
    printf("Введите количество отправленных SMS: \n");
    printf("Введите количество минут разговора: \n");
    if (scanf("%u%u%u", &mb, &sms, &min) != 3)
    {
        printf("Вы ввели некорректные данные\n");
        return 1;
    }

    unsigned int total_cost_1 = calculate_tarrif(
        mb,
        sms,
        min,
        PRICE_TARIF_1,
        FREE_MB_1,
        PRICE_MB_PACKET_1,
        PACKET_MB_1,
        FREE_SMS_1,
        PRICE_SMS_1,
        FREE_MIN_1,
        PRICE_MIN_1
    );

    unsigned int total_cost_2 = calculate_tarrif(
        mb,
        sms,
        min,
        PRICE_TARIF_2,
        FREE_MB_2,
        PRICE_MB_PACKET_2,
        PACKET_MB_2,
        FREE_SMS_2,
        PRICE_SMS_2,
        FREE_MIN_2,
        PRICE_MIN_2
    );

    unsigned int total_cost_3 = calculate_tarrif(
        mb,
        sms,
        min,
        PRICE_TARIF_3,
        FREE_MB_3,
        PRICE_MB_PACKET_3,
        PACKET_MB_3,
        FREE_SMS_3,
        PRICE_SMS_3,
        FREE_MIN_3,
        PRICE_MIN_3
    );


    printf("Стоимость тарифа 1: %u рублей\n", total_cost_1);
    printf("Стоимость тарифа 2: %u рублей\n", total_cost_2);
    printf("Стоимость тарифа 3: %u рублей\n", total_cost_3);

    printf("Самый дешевый тариф %u\n", min_3(total_cost_1, total_cost_2, total_cost_3));

    return 0;
}