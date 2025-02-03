#include <stdio.h>


int main()
{
    unsigned int x, y, power;
    unsigned int x_line = 0;
    unsigned int in_square = 0;

    printf("Введите x y \n");
    if(scanf("%u%u", &x, &y) !=2 )
    {

        printf("Вы ввели некорректные координаты\n");
        return 1;

    }
    // проверка - в какой части плоскости находится x 
    if (x <20){
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

    if(is_x_in_square && is_y_in_square)
    {
        in_square = 1;

    }


// Первый участок 30
    if(x_line == 1){

        power = 30;
        printf("Мощность бура должна составлять %u\n", power);

    }

// Второй участок 0 для y< 40

else if (x_line == 2 && in_square == 1)
{

    power = 50;
    printf("Мощность бура должна составлять %u\n", power);

}
// Второй участок 0 для y< 80
if(x_line == 2 && in_square == 0)
{

    power = 0;
    printf("Мощность бура должна составлять %u\n", power);
}

if(x_line == 3 && in_square == 1)
{

    power = 80;
    printf("Мощность бура должна составлять %u\n", power);
}
else if (x_line == 3 && in_square == 0)
{
    power = 30;
    printf("Мощность бура должна составлять %u\n", power);
}


    
    
    
    return 0;

}