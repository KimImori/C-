#include <stdio.h>

int sum(int a, int b)
{
    return a+b;
}


int main()
{
    int x = (sum(2,3) * 2) / 3;
    printf("%d\n", x);

}