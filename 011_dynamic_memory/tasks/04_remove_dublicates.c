// Дан массив {1,2,3,2,3,3,5,6,5}
// нужно удалить дубликаты и оставить в единственном числе
// результат должен быть {1,2,3,5,6}
// нужна функция,  которая проверит есть ли элемент в массиве
// и вернуть T or F(contains) функция  Find
// 1) Резервируем  массив у которого кол-во элементов
// столько сколько в оригинальном
// 2) Бежим по нащему ориг массиву и проверяем на каждой иттерации,
// если элемент есть в новом массиве через функцию contains,
// то пропускаем, иначе  добавляем

#include <stdio.h>
#include "../../library/array_utils.h"
#include <stdlib.h>
#include <stdbool.h>

bool contains(int *arr, int len, int element)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == element)
        {
            return true;
        }
    }
    return false;
}
int *del_duplicates(int *arr, size_t len, size_t *result_len)
{
    int *result = malloc(len * sizeof(int));
    if (result == NULL)
    {
        return NULL;
    }
    size_t len_result = 0;
    for (size_t i = 0; i < len; i++)
    {
        if(contains(result,len_result,arr[i]))
        {
            result[len_result++] = arr[i];
        }
    }
    
    return result;
}

int main()
{
    int arr_1[] = {1, 2, 3, 2, 3, 3, 5, 6, 5};
    size_t len_arr = sizeof(arr_1) / sizeof(arr_1[0]);
    int result[len_arr];
    int *arr = malloc(len_arr * sizeof(int));
    if (arr == NULL)
    {
        return 1;
    }
    del_duplicates(arr_1,len_arr,result);
    print_array(arr_1, len_arr);

    return 0;
}
