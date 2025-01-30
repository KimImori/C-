#include <stdio.h>

int main()
{

    int a, b, c;
    scanf("%d%d", &a, &b);
    c = a + b;
    printf("a=%d  b=%d\n", a, b);
    printf("+c=%d\n", c);
    c = a - b;
    printf("-c=%d\n",c);
    c = a * b;
    printf("*c=%d\n",c);
    c = a / b;
    printf("/c=%d\n",c);
    c = a % b;
    printf("%%c=%d\n",c);




    return 0;
    
}