#include <stdio.h>

#define BUFFER_LIMIT 256

int GLOBAL_BUFFER[BUFFER_LIMIT];
int GLOBAL_BUFFER_SIZE = 0;

void add_in_buffer(int num)
{
    if (GLOBAL_BUFFER_SIZE >= BUFFER_LIMIT)
    {
        return;
    }
    GLOBAL_BUFFER[GLOBAL_BUFFER_SIZE] = num;
    GLOBAL_BUFFER_SIZE++;
}

void print_buffer()
{
    for (size_t i = 0; i < GLOBAL_BUFFER_SIZE; i++)
    {
        printf("%d ", GLOBAL_BUFFER[i]);
    }
    printf("\n");
}

void remove_last_element_buffer()
{
    if (GLOBAL_BUFFER_SIZE == 0)
    {
        return;
    }
    GLOBAL_BUFFER_SIZE--;
}

void clear_buffer()
{
    GLOBAL_BUFFER_SIZE = 0;
}
int main()
{
    add_in_buffer(1);
    add_in_buffer(2);
    add_in_buffer(10);
    add_in_buffer(100);
    print_buffer();
    remove_last_element_buffer();
    remove_last_element_buffer();
    add_in_buffer(-1);
    print_buffer();
    clear_buffer();
    add_in_buffer(23);
    print_buffer();

    return 0;
}