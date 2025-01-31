/*
    Пользователь с клавы вводит номер месяца
    если ввод некорректный, то завершить программу
    иначе написать какой у нас сезон

 || или
 && и
*/

#include <stdio.h>

int main()
{

    printf("Введите номер месяца:\n");
    unsigned char month;

    if (scanf("%hhu", &month) != 1)
    {

        printf("Вы ввели некорректное число\n");
        return 1;
    }
    if (month == 12 || month == 1 || month == 2)
    {

        printf("Зима\n");
    }
    else if (month >= 3 && month <= 5)
    {

        printf("Весна\n");
    }
    else if (month >= 6 && month <= 8)
    {

        printf("Лето\n");
    }

    else if (month >= 9 && month <= 11)
    {

        printf("Осень\n");
    }

    else
    {

        printf("Иначе\n");
    }

    return 0;
}