#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
1) имей буффер на чтение 1 строки, тут достаточно до 255 символов(те это просто буффер-строка)
2) создай динамический массив для CsvRow на 5000 элементов, те это массив из 5000 CsvRow
3) в цикле читай строку из файла в буффер строки
4) бери сырую строку и вызови свою функцию которая ее распарситт в CsvRow
5) положи CsvRow в динамический, каждый раз увеличвая индекс
6) размер массив в  CsvFile - это количество прочитанных строк, но не больше 5000  иначе буде переполнение

*/

typedef char *csv_cell;

typedef struct __CsvRow
{
    csv_cell *arr;
    size_t len;
} CsvRow;

typedef struct __CsvFile
{
    CsvRow *arr;
    size_t len;
} CsvFile;

CsvRow parse_csv_row(const char *str, int column_len);
int find_index_char(const char *str, char symbol);
char *find_substr(const char *str, size_t start, size_t end);
CsvFile parse_csv_file(char *file_name, size_t row_numbers);
void free_csv_file(CsvFile *file);
size_t count_char(const char *str, char symbol);
void print_csv(CsvFile file);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "%s <csv_file> \n", argv[0]);
        return 1;
    }
    char *file_name = argv[1];

    CsvFile file = parse_csv_file(file_name, 0);
    if (file.arr == NULL)
    {
        fprintf(stderr, "Ошибка\n");
        return -1;
    }
    print_csv(file);
    free_csv_file(&file);
    return 0;
}

int find_index_char(const char *str, char symbol)
{
    if (str == NULL)
    {
        return -1;
    }

    int index = 0;
    while (str[index] != '\0')
    {
        if (str[index] == symbol)
        {
            return index;
        }
        index++;
    }
    return -1;
}

char *find_substr(const char *str, size_t start, size_t end)
{
    if (str == NULL)
    {
        return NULL;
    }
    if (end <= start)
    {
        return NULL;
    }
    size_t len_str = strlen(str);
    if (start >= len_str || end > len_str)
    {
        return NULL;
    }

    size_t len = end - start;
    char *result = malloc(len + 1);
    if (result == NULL)
    {
        return NULL;
    }
    size_t j = 0;
    for (size_t i = start; i < end; i++)
    {
        result[j] = str[i];
        j++;
    }
    result[j] = '\0';
    return result;
}

CsvRow parse_csv_row(const char *str, int column_len)
{
    CsvRow row;
    row.len = column_len;
    row.arr = malloc(sizeof(csv_cell) * column_len);
    if (row.arr == NULL)
    {
        row.len = 0;
        return row;
    }
    for (size_t i = 0; i < column_len; i++)
    {
        int index = find_index_char(str, ',');
        if (index == -1)
        {
            index = strlen(str);
        }
        char *substr = find_substr(str, 0, index);
        row.arr[i] = substr;
        str += index + 1;
    }
    return row;
}

CsvFile parse_csv_file(char *file_name, size_t row_numbers)
{
    CsvFile file_1;

    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("Error opening");
        file_1.arr = NULL;
        file_1.len = 0;
        return file_1;
    }
    file_1.arr = malloc(row_numbers * sizeof(CsvRow));
    if (file_1.arr == NULL)
    {
        file_1.arr = NULL;
        file_1.len = 0;
        fclose(file);
        return file_1;
    }

    char buffer[255];
    size_t current_row = 0;
    size_t column_len = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if (column_len == 0)
        {
            column_len = count_char(buffer, ',') + 1;
        }
        buffer[strlen(buffer) - 1] = '\0';
        CsvRow row = parse_csv_row(buffer, column_len);
        file_1.arr[current_row] = row;
        current_row++;
    }
    if (!feof(file))
    {
        perror("Error reading");
        file_1.arr = NULL;
        file_1.len = 0;
        fclose(file);
        return file_1;
    }

    file_1.len = current_row;
    fclose(file);
    return file_1;
}

void free_csv_file(CsvFile *file)
{
    if(file == NULL)
    {
        return;
    }
    for(size_t i = 0;)
}

size_t count_char(const char *str, char symbol)
{
    if (str == NULL)
    {
        return 0;
    }
    size_t counter = 0;
    while (*str != '\0')
    {
        if (*str == symbol)
        {
            counter++;
        }
        str++;
    }
    return counter;
}

void print_csv(CsvFile file)
{
    for (size_t i = 0; i < file.len; i++)
    {
        CsvRow row = file.arr[i];
        for (size_t j = 0; j < row.len; j++)
        {
            csv_cell cell = row.arr[j];
            printf("%s,", cell);
        }
        printf("\n");
    }
}