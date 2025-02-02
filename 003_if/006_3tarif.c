/*
Есть 3 тарифных плана у оператора сотовой связи

1-тариф
  - 5 гигабайт бесплатно, далее 100 мб стоят 15 рублей
  - 50 смс бесплатно, далее каждая смс 10 рублей
  - все звонки 1 минут 2 рубля
  - цена тарифа: 500 рублей


Задача:
 с клавиатуры ты вводишь сколько пользователь планирует:
   - скачать мегабайт за месяц
   - сколько отрпавить смас
  - сколько поговорить минут


после нужно написать сколько это будет стоить на каждом тарифе и написать номер самого дешевого тарифа

*/

#include <stdio.h>

unsigned int PRICE_TARIF_1 = 500;
unsigned int FREE_MB_1 = 5000;
unsigned int PACKET_MB_1 = 100;
unsigned int PRICE_MB_PACKET_1 = 15;
unsigned int FREE_SMS_1 = 50;
unsigned int PRICE_SMS_1 = 10;
unsigned int FREE_MIN_1 = 0;
unsigned int PRICE_MIN_1 = 2;


int main(){

    unsigned int mb_1, sms_1, min_1, total_cost_1;
    if (scanf("%u%u%u", &mb_1, &sms_1, &min_1) != 3){
        printf("Вы ввели некорректные данные\n");
        return 1;
    }

    total_cost_1 = PRICE_TARIF_1;

    if (mb_1 > FREE_MB_1) // нужна тарификация
    { 
        //ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!!
        unsigned int mb_for_tarif;
        mb_for_tarif = mb_1 - FREE_MB_1; // Убираем бесплатные мегабайты
        total_cost_1 += mb_for_tarif * PRICE_MB_PACKET_1 / PACKET_MB_1;
        if (mb_for_tarif % PACKET_MB_1 != 0)
        {
            total_cost_1 +=  PRICE_MB_PACKET_1;
        }
    }

    if (sms_1 > FREE_SMS_1) // нужна тарификация
    {
        //ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!! 
        sms_1 -= FREE_SMS_1; // Убираем бесплатные смс
        total_cost_1 += sms_1 * PRICE_SMS_1;
        
    }
    if (min_1 > FREE_MIN_1) // нужна тарификация
    {
        //ИЗМЕНЯЕМ ПЕРЕМЕННУЮ !!! 
        min_1 -= FREE_MIN_1; // Убираем бесплатные минуты
        total_cost_1 += min_1 * PRICE_MIN_1;
        
    }

    printf("Цена тарифа %u\n",total_cost_1);



    return 0;
}