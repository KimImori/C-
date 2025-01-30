#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d\t%d", &a, &b);
    c = a;
    a = b;
    b = c;
    printf("Первое число: %d\n", a);
    printf("Второе число: %d\n", b);

    return 0;
}