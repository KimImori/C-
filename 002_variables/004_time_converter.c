#include <stdio.h>
/*
Конвертер времени
пользователь с клавиатуры вводит кол-во секунд
это целое число(unsigned int)
написать сколько в секундах полных лет
сколько в оставшихся  секундах дней
сколько в оставшихся секундах часов
сколько в оставшихся секундах минут
сколько всего осталось секунд, которых не хватило на минут





*/

int main() {

    unsigned int sec;
    scanf("%u", &sec);
    unsigned int SEC_IN_MIN = 60;
    unsigned int SEC_IN_HOUR = SEC_IN_MIN * 60;
    unsigned int SEC_IN_DAY = SEC_IN_HOUR * 24;
    unsigned int SEC_IN_YEAR = SEC_IN_DAY * 365;

    unsigned int years = sec / SEC_IN_YEAR;
    sec %= SEC_IN_YEAR;
    unsigned int days = sec / SEC_IN_DAY;
    sec %= SEC_IN_DAY;
    unsigned int hours = sec / SEC_IN_HOUR;
    sec %= SEC_IN_HOUR;
    unsigned int mins = sec / SEC_IN_MIN;
    sec %= SEC_IN_MIN;
    unsigned int remaining_seconds = sec;
    printf("Y=%u\n", years);
    printf("D=%u\n", days);
    printf("H=%u\n", hours);
    printf("M=%u\n", mins);
    printf("Remainged Sec=%u\n", sec);


    return 0;
}