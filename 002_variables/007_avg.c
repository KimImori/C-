#include <stdio.h>


int main() {

    int a1, a2, a3, a4, a5;
    printf("Введите 5 чисел:\n");
    scanf("%d%d%d%d%d",&a1, &a2, &a3, &a4, &a5);
    int avg = (a1+a2+a3+a4+a5) / 5;
    printf("Ответ: %d\n", avg);



    return 0;

}