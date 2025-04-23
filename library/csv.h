#ifndef CSV_UTILS_H
#define CSV_UTILS_H
#include "string_utils.h"
#include <stdio.h>
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

void free_csv_file(CsvFile *file);

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
    CsvFile csv_file;

    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("Error opening");
        csv_file.arr = NULL;
        csv_file.len = 0;
        return csv_file;
    }
    csv_file.arr = malloc(row_numbers * sizeof(CsvRow));
    if (csv_file.arr == NULL)
    {
        csv_file.arr = NULL;
        csv_file.len = 0;
        fclose(file);
        return csv_file;
    }

    char buffer[255];
    size_t row_read_len = 0;
    size_t column_len = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if (column_len == 0)
        {
            column_len = count_char(buffer, ',') + 1;
        }
        buffer[strlen(buffer) - 1] = '\0';
        CsvRow row = parse_csv_row(buffer, column_len);
        csv_file.arr[row_read_len] = row;
        row_read_len++;
        if(row_read_len >= row_numbers)
        {
            break;
        }
    }
    csv_file.len = row_read_len;
    if (!feof(file))
    {
        free_csv_file(&csv_file);
        perror("Error reading");
        csv_file.arr = NULL;
        csv_file.len = 0;
        fclose(file);
        return csv_file;
    }
    fclose(file);
    return csv_file;
}

void free_csv_file(CsvFile *file)
{
    if(file == NULL)
    {
        return;
    }
    for(size_t i = 0; i < file->len;i++)
    {
        CsvRow row = file->arr[i];
        for(size_t j = 0; j < row.len;j++)
        {
            csv_cell cell = row.arr[j];
            free(cell);
        }
        free(row.arr);
    }
    free(file->arr);
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
#endif