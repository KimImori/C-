// Алфавит (a-z) (A-Z) (0-9) ($, &)
// Написать функцию, которая на вход принимает длину пароля
// и генерирует случайный пароль из этого алфавита

/*
1 - Выделить память на хипе(n + 1)
2 - Для каждого символа пароля выбрать случайное значение из алфавита
3 - Поставить /0

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789$&";
size_t len_alphabet = 64;
char *generate_pass(int n);

int main()
{
    srand(time(NULL));
    char *pass = generate_pass(8);
    printf("pass - \"%s\"\n", pass);
    free(pass);
    return 0;
}
int my_rand(int from, int to)
{
    int c = to - from + 1;
    return (rand() % c) + from;
}

char *generate_pass(int n)
{
    char *password = malloc((n + 1) * sizeof(char));
    if (password == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < n; i++)
    {
        password[i] = alphabet[my_rand(0,len_alphabet - 1)];
    }
    password[n] = '\0';
    return password;
}