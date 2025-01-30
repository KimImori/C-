#include <stdio.h>

int main()
{

    unsigned int a, b, c;
    scanf("%u%u", &a, &b);
    c = a + b;
    printf("a=%u  b=%u\n", a, b);
    printf("+c=%u\n", c);
    c = a - b;
    printf("-c=%u\n",c);
    c = a * b;
    printf("*c=%u\n",c);
    c = a / b;
    printf("/c=%u\n",c);
    c = a % b;
    printf("%%c=%u\n",c);



    return 0;
    
}