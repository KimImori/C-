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

Dummy create_dummy(int a, int b)
{
    Dummy d = {
        .a = a,
        .b = b
    };
    return d;
}

Dummy* create_dummy_dynamic(int a, int b)
{
    Dummy *d = malloc(sizeof(Dummy));
    if (d == NULL)
    {
        return NULL;
    }
    d->a = a;
    d->b = b;
    return d;
}

int main()
{
    Dummy d = create_dummy(12,15);
    print_dummy(d);

    Dummy* d_ptr = create_dummy_dynamic(12, 15);
    if (d_ptr == NULL)
    {
        return 1;
    }
    print_dummy(*d_ptr);
    free(d_ptr);

    return 0;
}