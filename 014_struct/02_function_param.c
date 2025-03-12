#include <stdio.h>
#include <stdlib.h>

typedef struct __Dummy {
    int a;
    int b;
} Dummy;

void print_dummy(Dummy d)
{
    printf("a = %d b = %d \n", d.a, d.b);
}

void print_dummy_ptr(const Dummy* d)
{
    if (d == NULL)
    {
        printf("Null");
        return;
    }
    printf("a = %d b = %d \n", d->a, d->b);
}

int main()
{
    Dummy d1 = {
        .a = 10,
        .b = 15
    };

    Dummy *d2 = malloc(sizeof(Dummy));
    if (d2 == NULL)
    {
        return 1;
    }
    (*d2).a = 5;
    (*d2).b = 6;
    d2->a = 5;
    d2->b = 6;

    print_dummy(d1);
    print_dummy(*d2);

    print_dummy_ptr(&d1);
    print_dummy_ptr(d2);

    free(d2);
    return 0;
}