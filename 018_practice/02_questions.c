#include <stdio.h>

struct Sku
{
    int sku_id;
    char name[100];
    double price;
    int review_count;
};

const struct Sku* find_sku_by_id(const struct Sku *arr, size_t n, int id)
{
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i].sku_id == id)
        {
            return arr + i;
        }
    }
    return NULL;
}

int main()
{
    struct Sku skus[5];
}