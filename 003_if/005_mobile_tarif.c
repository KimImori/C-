#include <stdio.h>

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




*/

int main()
{

    unsigned int mb, sms, min, gb, cost_tarif, cost;
    printf("Введите мегабайты");
    scanf("%u", &mb);
    printf("Введите смс");
    scanf("%u", &sms);
    printf("Введите минуты");
    scanf("%u", &min);

    unsigned int MAX_SMS = 50;
    unsigned int MAX_MB = 5000;
    cost = mb / 100;

    if (mb % 100 != 0)
    {
        mb = mb - MAX_MB;
        cost = mb + 1;
        printf("Цена за мегабайты %u\n", cost);
    }

    return 0;
}