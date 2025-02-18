/*
дан массив [1,2, 3, 4]
и задан индекс с клавиатуры
если задать индекс 2 то должны получить масиив 1,2,4
написать функцию которая принимает массивв и индекс элемента, который нужно удалить в массиве


*/

#include <stdio.h>
#include "array_utils.h"
#include <stdlib.h>

void arr_delete_index(int arr[], size_t *arr_len, int index_delete)
{
    if (index_delete >= *arr_len) {
        printf("Некорректный индекс\n");
        abort();
    }
    for (size_t i = index_delete; i < *arr_len - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    *arr_len= *arr_len - 1;
}

int main()
{
    int index_delete = 0;
    int arr[] = {1, 2, 3, 4};
    size_t len_arr = sizeof(arr) / sizeof(arr[0]);
    scanf("%d", &index_delete);
    arr_delete_index(arr, &len_arr, index_delete);
    print_array(arr, len_arr);

    return 0;
}
