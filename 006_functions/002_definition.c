#include <stdio.h>

void printer(); // declaration(объявление)

int main()
{
    printer();
    return 0;
}



void printer() // definition(определение)
{
    printf("Hello!");
}