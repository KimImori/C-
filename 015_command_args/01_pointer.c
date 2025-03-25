#include <stdio.h>

// a - pointer to 1 int, NOT ARRAY
void foo(int *a);

int main() {
    int a = 10;
    int arr[] = {1, 2, 3, 4, 5};

    foo(&a);
    foo(arr);

    int *p = &a;
    int *parr = arr;


    foo(a); // wrong
    foo(&a); // correct
    foo(arr); // correct
    foo(arr[0]); // wrong
    foo(&arr[0]); // correct
    foo(arr[1]); // wrong
    foo(arr + 1); // correct
    foo(p); // correct
    foo(*p); // correct
    foo(&p); // wrong

    printf("p = %p\n", p);
    printf("p = %d\n", *p);
    printf("arr = %p\n", arr);
    printf("arr[0] = %p\n", &arr[0]);
    printf("arr[0] = %d\n", arr[0]);
    return 0;
}
