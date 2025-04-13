#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/*

1) находишь индекс запятой, это индекс 3
2) делаешь копию столбика передаешь от [0;3) (3 не включительно) - получаешь новую строку "Dan"
3) добавляешь в массив строк(result) по индексу 0
4) после чего ты строку двигаешь после запятой "Alex,Bob"
5) находишь снова запятую, это индекс 4
6) делаешь копию столбика передаешь от [0;4) (4 не включительно) - получаешь новую строку "Alex"
7) добавляешь в массив строк(result) по индексу 1
😍 после чего ты строку двигаешь после запятой "Bob"
9) находишь снова запятую, ее уже нет, будет индес -1
10) делаешь копию полной строки получаешь "Bob"
11) добавляешь в массив строк(result) по индексу 2
12) Конец
ты получаешь что у тебя есть массив строк (char **result) в котором по индексу 0 - "Dan" по индексу 1 "Alex" по индексу 2" Bob"


*/

typedef char* csv_cell;

typedef struct __CsvRow
{
    csv_cell* arr;
    size_t len;
}CsvRow;




CsvRow parse_csv_row(const char *str,int column_len);
int find_index_char(const char *str,char symbol);
char* find_substr(const char *str,size_t start,size_t end);



int main(int argc, char **argv)
{
   CsvRow row = parse_csv_row("Dan,Bob,Alex",3);
   assert(row.len == 3);
   assert(strcmp(row.arr[0],"Dan") == 0);
   assert(strcmp(row.arr[1],"Bob") == 0);
   assert(strcmp(row.arr[2],"Alex") == 0);

   CsvRow row_2 = parse_csv_row("Dan,,Alex",3);
   assert(row_2.len == 3);
   assert(strcmp(row_2.arr[0],"Dan") == 0);
   assert(row_2.arr[1] == NULL);
   assert(strcmp(row_2.arr[2],"Alex") == 0);

    return 0;
}

int find_index_char(const char *str,char symbol)
{
    if(str == NULL)
    {
        return -1;
    }

    int index = 0;
    while(str[index] != '\0')
    {
        if(str[index] == symbol)
        {
            return index;
        }
        index++;
    }
    return -1;
}

char* find_substr(const char *str,size_t start,size_t end)
{
    if(str == NULL)
    {
        return NULL;
    }
    if(end <= start )
    {
        return NULL;
    }
    size_t len_str = strlen(str);
    if(start >= len_str || end > len_str)
    {
        return NULL;
    }

    size_t len = end - start;
    char* result = malloc(len + 1);
    if(result == NULL)
    {
        return NULL;
    }
    size_t j = 0;
    for(size_t i = start; i < end;i++)
    {
        result[j] = str[i];
        j++;
    }
    result[j] = '\0';
    return result;

}

CsvRow parse_csv_row(const char *str,int column_len)
{
   CsvRow row;
   row.len = column_len;
   row.arr = malloc(sizeof(csv_cell)*column_len);
   if(row.arr == NULL)
   {
    row.len = 0;
    return row; 
   }
   for(size_t i = 0; i < column_len;i++)
   {
    int index = find_index_char(str, ',');
    if(index == -1)
    {
        index = strlen(str);
    }
    char * substr = find_substr(str,0,index);
    row.arr[i] = substr;
    str += index + 1;
   }
   return row;
}