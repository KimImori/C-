#include <stdio.h>

int main()
{
    unsigned int x, y, power;
    unsigned int x_line = 0;
    unsigned int in_square = 0;

    printf("Введите x y \n");
    if (scanf("%u%u", &x, &y) != 2)
    {

        printf("Вы ввели некорректные координаты\n");
        return 1;
    }
    // проверка - в какой части плоскости находится x
    if (x < 20)
    {
        x_line = 1;
    }
    else if (x <= 50)
    {

        x_line = 2;
    }
    else
    {
        x_line = 3;
    }

    // проверка - в квадрате или нет.
    int is_x_in_square = 40 <= x && x < 80;
    int is_y_in_square = 40 <= y && y < 80;

    if (is_x_in_square && is_y_in_square)
    {
        in_square = 1;
    }

    switch (x_line)
    {
    case 1: // Первый участок
        power = 30;
        printf("Мощность бура должна составлять %u\n", power);
        break;

    case 2: // Второй участок
        if (in_square == 1)
        {
            power = 50;
            printf("Мощность бура должна составлять %u\n", power);
        }
        else
        {
            power = 0;
            printf("Мощность бура должна составлять %u\n", power);
        }
        break;

    case 3: // Третий участок
        if (in_square == 1)
        {
            power = 80;
            printf("Мощность бура должна составлять %u\n", power);
        }
        else
        {
            power = 30;
            printf("Мощность бура должна составлять %u\n", power);
        }
        break;

    default:
        printf("Сюда не должны попасть\n");
        break;
    }

    return 0;
}