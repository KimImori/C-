#include <stdio.h>

int main() {
    printf("My super program\n");
    int a;
    printf("Enter a number: ");
    if (scanf("%d", &a) != 1) {
        fprintf(stderr, "Error: Invalid number\n");
        return 1;
    }
    printf("You entered: %d\n", a);
    return 0;
}