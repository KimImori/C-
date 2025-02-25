#include <stdio.h>

int main()
{
    unsigned char month;
    if (scanf("%hhu", &month) != 1)
    {
        printf("Вы ввели некорректный месяц\n");
        return 1;
    }

    if (month == 12 || month == 1 || month == 2)
    {
        printf("Зима\n");
    }
    else if (month == 3 || month == 4 || month == 5)
    {Ц
        printf("Весна\n");
    }
    else if (month == 6 || month == 7 || month == 8)
    {
        printf("Лето\n");
    }
    else if (month == 9 || month == 10 || month == 11)
    {
        printf("Осень\n");
    }
    else
    {
        printf("Что-то другое?\n");
    }

    return 0;
}