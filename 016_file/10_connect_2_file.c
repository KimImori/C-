#include <stdio.h>
#include <stdlib.h>

/*
на вход принимаем 2 файла через аргументы командной строки

./a.out file_1.txt file_2.txt

нужно контент первого файла развернуть задом наперет и записать во второй файл


тут уже не получится строчка-за-строчкой работать, нужно за одно чтение вычитать весь файл в память,
нужно создать большой буффер чтобы он вместил себя файл, считаем что файлы не могут быть больше 10мб

буфер уже нельзя создававать на стеке нужно создать на куче его

*/

/*
1)проверка на количество аргументов равное 2
2)открываем файл argv[1] на чтение
2.1)проверка на открытие файла
2.2)открываем argv[2] на запись
2.3)проверка на открытие файла
3)ожидаем текстовый файл
4)создать буффер на 10мб на куче(стек может хранить максимум 1мб)
5)прочитать файл в буфер
5.1)закрыть  файл argv[1]
6)развернуть содержимое буффера
8)записываем содержимое буффера в argv[2]
9)закрыть файл
10)сделать free
*/

void reverse_text(char *str);
size_t dan_strlen(const char *str);
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Use: %s ... ...", argv[0]);
        return 1;
    }
    char *file_in = argv[1];
    char *file_out = argv[2];

    FILE *file_1 = fopen(file_in, "r");
    if (file_1 == NULL)
    {
        perror("Error open");
        return 1;
    }
    FILE *file_2 = fopen(file_out, "w");
    if (file_2 == NULL)
    {
        perror("Error open");
        fclose(file_1);
        return 1;
    }
    size_t size = 10*1024*1024;
    char *buffer = malloc(size);
    if(buffer == NULL)
    {
        perror("Error");
        fclose(file_1);
        fclose(file_2);
        return 1;
    }
    size_t number_of_object = fread(buffer,sizeof buffer[0],size,file_1);
    if (!feof(file_1))
    {
        perror("Error");
        fclose(file_1);
        fclose(file_2);
        free(buffer);
        return 1;
    }
    buffer[number_of_object] = '\0';
    fclose(file_1);
    reverse_text(buffer);
    size_t success_w_object = fwrite(buffer, sizeof buffer[0],number_of_object,file_2);
    if(number_of_object != success_w_object)
    {
        perror("Error");
        fclose(file_2);
        free(buffer);
        return 1;
    }
    fclose(file_2);
    free(buffer);
    return 0;
}

size_t dan_strlen(const char *str)
{
    if (str == NULL)
    {
        return 0;
    }
    size_t len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

void reverse_text(char *str)
{
    if (str == NULL)
    {
        return;
    }
    size_t i = 0;
    size_t j = dan_strlen(str) - 1;
    while (i < j)
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}
