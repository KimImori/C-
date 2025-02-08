#include <stdio.h>

// 5! = 1*2*3*4*5 = 120
/*
    1 iter: r=1 i=1 r = 1*1; r->1
    2 iter: r=1 i=2 r = 1*2; r->2
    3 iter: r=2 i=3 r = 2*3; r->6
    4 iter: r=6 i=4 r = 6*4; r->24
    5 iter: r=24 i=5 r = 24*5; r->120
*/
unsigned int factorial(unsigned int n)
{
    unsigned int result = 1;
    for(int i=1; i<=n; i++)
    {
        result = result * i;
    }
    return result;
}

// 5! = 4! * 5
// Если ты хочешь использовать рекурсию
// 1) найди индукционную формула n! = (n-1)! * n
// 2) определи точку останову
// 3) пойми глубину рекурсии - она не бесплатна
unsigned int factorial_rec(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    return factorial_rec(n-1) * n;
}


int main()
{
    unsigned int a;
    if(scanf("%u",&a) != 1)
    {
        return -1;
    }

    printf("%u! = %u\n", a, factorial_rec(a));

    return 0;
}