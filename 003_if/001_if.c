#include <stdio.h>

int main()
{
    printf("Введите номер месяца:\n");
    unsigned char month;
    if (scanf("%hhu", &month) != 1)
    {
        printf("Вы ввели некоректное число.\n");
        return 1;
    }
    if (month == 1)
    {

        printf("Январь\n");
    }
    else if (month == 2)
    {

        printf("Февраль\n");
    }
    else if (month == 3)
    {

        printf("Март\n");
    }
    else if (month == 4)
    {

        printf("Апрель\n");
    }
    else if (month == 5)
    {

        printf("Май\n");
    }
    else if (month == 6)
    {

        printf("Июнь\n");
    }
    else if (month == 7)
    {

        printf("Июль\n");
    }
    else if (month == 8)
    {

        printf("Август\n");
    }
    else if (month == 9)
    {

        printf("Сентябрь\n");
    }
    else if (month == 10)
    {

        printf("Октябрь\n");
    }
    else if (month == 11)
    {

        printf("Ноябрь\n");
    }
    else if (month == 12)
    {

        printf("Декабрь\n");
    }
    
    else
    {
        printf("Иначе\n");
    }

    return 0;
}