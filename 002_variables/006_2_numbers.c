#include <stdio.h>


int main() {


int numbers, first_number, second_number;

scanf("%d", &numbers);


first_number = numbers / 10;
second_number = numbers % 10;


printf("Первое число: %d\n",first_number);
printf("Второе число: %d\n",second_number);
return 0;

}