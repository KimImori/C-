#include <stdio.h>
#include <stdbool.h>
#define ARR_LEN 10
/*Пользоваетль с клавиатуры вводит число
Если число в массиве есть пишется индекс элемента в массиве
Если числа в массиве нет, пишется что числа нет
Если в массиве несколько таких чисел пишется индекс первого найденного элемента*/

int main()
{
    int arr[ARR_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n;
    int index = -1;
    printf("Введите число:\n");
    if (scanf("%d", &n) != 1)
    {
        printf("Некорректное число\n");
        return 1;
    }
    for (size_t i = 0; i < ARR_LEN; i++)
    {
        if (arr[i] == n)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        printf("Ваше число под индексом - %d\n", index);
    }
    else
    {
        printf("В массиве числа нет\n");
    }
    return 0;
}