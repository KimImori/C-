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

    unsigned long sec;
    scanf("%lu", &sec);
    unsigned long SEC_IN_MIN = 60;
    unsigned long SEC_IN_HOUR = SEC_IN_MIN * 60;
    unsigned long SEC_IN_DAY = SEC_IN_HOUR * 24;
    unsigned long SEC_IN_YEAR = SEC_IN_DAY * 365;

    unsigned long years = sec / SEC_IN_YEAR;
    sec %= SEC_IN_YEAR;
    unsigned long days = sec / SEC_IN_DAY;
    sec %= SEC_IN_DAY;
    unsigned long hours = sec / SEC_IN_HOUR;
    sec %= SEC_IN_HOUR;
    unsigned long mins = sec / SEC_IN_MIN;
    sec %= SEC_IN_MIN;
    unsigned long remaining_seconds = sec;
    printf("Y=%lu\n", years);
    printf("D=%lu\n", days);
    printf("H=%lu\n", hours);
    printf("M=%lu\n", mins);
    printf("Remainged Sec=%lu\n", sec);


    return 0;
}