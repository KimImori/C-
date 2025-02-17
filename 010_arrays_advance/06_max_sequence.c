#include <stdio.h>
/*

Описание: В массиве найти самую длинную последовательность подряд идущих одинаковых чисел.
Вывести это число и длину последовательности.

Пример: [1, 1, 2, 2, 3, 3, 3, 3] → Число 3, длина 4.
Напиши функцую которая на вход примет массив а на выходе вернет два числа

*/

void max_sequence(const int arr[], size_t n, int *num, int *len)
{
    int current_num = arr[0];
    int current_len = 1;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] == current_num)
        {
            current_len++;
        }
        else
        {
            current_num = arr[i];
            current_len = 1;
    
        }
    }
    *num = current_num;
    *len = current_len;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 3, 3};

    size_t arr_len = sizeof(arr) / sizeof(arr[0]);
    int num, len;
    max_sequence(arr, arr_len, &num, &len);
    printf("Число %d Длина %d ", num, len);

    return 0;
}