#include <stdio.h>


int abs_1(int num)
{
    if (num < 0)
    {
        return -num;
    }
    return num;
}

void coeff(int numerator, int denominator)
{

    if (denominator == 0)
    {
        printf("Знаменатель не может быть равен 0\n");
        return;
    }

    while (numerator != 0)
    {

        int whole_part = numerator / denominator;
        printf("Целая часть - %d", whole_part);
    }
} 

int main()
{

    return 0;
}