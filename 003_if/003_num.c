#include <stdio.h>

/*
С клавиатур вводится 5 чисел

Напиши самое большое среди них
*/

int main()
{
    printf("Введите пять чисел:\n");

    unsigned char num1, num2, num3, num4, num5;

    if (scanf("%hhu %hhu %hhu %hhu %hhu", &num1, &num2, &num3, &num4, &num5) != 5)
    {

        printf("Вы ввели некорректное число\n");
        return 1;
    }
    if (num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5)
    {

        printf("Самое большое число - %hhu\n", num1);
    }
    else if (num2 > num3 && num2 > num4 && num2 > num5)
    {

        printf("Самое большое число - %hhu\n", num2);
    }
    else if (num3 > num4 && num3 > num5)
    {

        printf("Самое большое число - %hhu\n", num3);
    }
    else if (num4 > num5)
    {

        printf("Самое большое число - %hhu\n", num4);
    }
    else if (num5>= num5)
    {

        printf("Самое большое число - %hhu\n", num5);
    }
    else
    {

        printf("Иначе\n");
    }

    return 0;
}