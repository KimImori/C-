#include <stdio.h>

int main()
{

    long a, b, c;
    scanf("%ld%ld", &a, &b);
    c = a + b;
    printf("a=%ld  b=%ld\n", a, b);
    printf("+c=%ld\n", c);
    c = a - b;
    printf("-c=%ld\n",c);
    c = a * b;
    printf("*c=%ld\n",c);
    c = a / b;
    printf("/c=%ld\n",c);
    c = a % b;
    printf("%%c=%ld\n",c);



    return 0;
    
}

 
