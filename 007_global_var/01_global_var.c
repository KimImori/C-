#include <stdio.h>

int GL_COUNTER_FOO = 0;

void foo()
{
    GL_COUNTER_FOO++;
    return;
}


int main()
{
    foo();
    foo();
    foo();

    printf("GL_COUNTER_FOO = %d\n", GL_COUNTER_FOO);

    foo();

    printf("GL_COUNTER_FOO = %d\n", GL_COUNTER_FOO);

    return 0;
}