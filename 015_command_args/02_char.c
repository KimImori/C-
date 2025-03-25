#include <stdio.h>

void foo(char *str);

int main() {
    char c = 'a';
    char str[] = "Hello";
    foo(&c);
    foo(str);

    return 0;
}