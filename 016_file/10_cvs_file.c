#include "../library/csv.h"
#include "../library/string_utils.h"
#include <stdbool.h>

int main(int argc, char **argv)
{
    
    if (argc != 3)
    {
        fprintf(stderr, "%s <csv_file>  <column_index>\n", argv[0]);
        return 1;
    }
    char *file_name = argv[1];
    size_t column_index = 0;
    if (sscanf(argv[2], "%ld", &column_index) != 1)
    {
        fprintf(stderr, "Second arg is not num %s\n", argv[2]);
        return -1;
    }

    CsvFile file = parse_csv_file(file_name, 30000);
    if (file.arr == NULL)
    {
        fprintf(stderr, "Ошибка\n");
        return -1;
    }
    double sum_height = 0;
    double min = 0;
    double max = 0;
    bool is_min_max_defined = false;
    size_t len = 0;
    for (size_t i = 0; i < file.len; i++)
    {
        CsvRow row = file.arr[i];
        csv_cell cell = row.arr[column_index];
        if (cell == NULL)
        {
            continue;
        }
        double height;
        if (sscanf(cell, "%lf", &height) != 1)
        {
            fprintf(stderr, "Cannot parse %s", cell);
            continue;
        }

        if (!is_min_max_defined)
        {
            min = height;
            max = height;
            is_min_max_defined = true;
        }
        else
        {
            if (height < min)
            {
                min = height;
            }
            if (height > max)
            {
                max = height;
            }
        }

        sum_height += height;
        len++;
    }
    double avg = sum_height / len;
    printf("Min value - %lf\nMax value - %lf\n", min, max);
    printf("Avg - %lf\n", avg);
    free_csv_file(&file);
    return 0;
}
