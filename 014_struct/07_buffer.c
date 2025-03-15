#include <stdio.h>
#include <stdlib.h>


typedef struct __Buffer {
    int *arr;
    size_t size;
    size_t capacity;
} Buffer;

Buffer create_buffer(size_t capacity);
void free_buffer(Buffer *buffer);
void print_buffer(const Buffer *buffer);
void add_in_buffer(Buffer *buffer,int n);
void delete_last_element(Buffer *buffer);


int main()
{
    Buffer b = create_buffer(2);
    print_buffer(&b);
    add_in_buffer(&b, 10);
    add_in_buffer(&b, 15);
    add_in_buffer(&b, 12);
    print_buffer(&b);
    delete_last_element(&b);
    delete_last_element(&b);
    delete_last_element(&b);
    delete_last_element(&b);
    print_buffer(&b);
    free_buffer(&b); 
    return 0;
}


Buffer create_buffer(size_t capacity)
{
    Buffer b;
    b.arr = malloc(sizeof(int) * capacity);
    if (b.arr == NULL)
    {
        b.capacity = 0;
        b.size = 0;
        return b;
    }
    b.capacity = capacity;
    b.size = 0;
    return b;

}

void free_buffer(Buffer *buffer)
{
    if(buffer == NULL)
    {
        return;
    }
    free(buffer->arr);
    buffer->capacity = 0;
    buffer->size = 0;
}

void print_buffer(const Buffer *buffer)
{
    if(buffer == NULL)
    {
        return;
    }
    for(size_t i = 0; i < buffer->size;i++)
    {
        printf("%d ",buffer->arr[i]);
    }
    printf("\n");
}

void add_in_buffer(Buffer *buffer,int n)
{
    if(buffer == NULL)
    {
        return;
    }
    if(buffer->size >= buffer->capacity)
    {
        return;
    }
    buffer->arr[buffer->size] = n;
    buffer->size++;
}

void delete_last_element(Buffer *buffer)
{
    if(buffer == NULL)
    {
        return;
    }
    if(buffer->size != 0)
    {
        buffer->size--;
    }
}
