#include <stdio.h>
#include <stdlib.h>
#include "../library/array_utils.h"


int mining_profit(IntArr arr, IntArr memo);
int mining_profit_2(IntArr arr);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "%s [file.name]\n", argv[0]);
        return 1;
    }

    IntArr arr = create_arr(argv[1]);
    if (arr.arr == NULL)
    {
        fprintf(stderr, "can't create arr\n");
        return 1;
    }
    print_array(arr.arr, arr.n);
    IntArr memo;
    memo.n = arr.n;
    memo.arr =  calloc(sizeof(int), memo.n);
    
    int result = mining_profit(arr, memo);
    int result_2 = mining_profit_2(arr);
    printf("Summ_1 - %d\n", result);
    printf("Summ_2 - %d\n", result_2);
    free_arr(&arr);

    return 0;
}

int my_max(int a,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}
int mining_profit(IntArr arr, IntArr memo)
{
    if(arr.n == 1)
    {
        return arr.arr[0];
    }
    if(arr.n == 2)
    {
        return my_max(arr.arr[0], arr.arr[1]);
    }
    if(memo.arr[arr.n - 1] != 0)
    {
        return memo.arr[arr.n - 1];
    }
    IntArr candidate_1;
    candidate_1.arr = arr.arr;
    candidate_1.n = arr.n - 1;
    int profit_1 = mining_profit(candidate_1,memo);

    IntArr candidate_2;
    candidate_2.arr = arr.arr;
    candidate_2.n = arr.n - 2;
    int profit_2 = mining_profit(candidate_2, memo) + arr.arr[arr.n - 1];
    int result = my_max(profit_1,profit_2);
    memo.arr[arr.n - 1] = result;
    return result;
}

int mining_profit_2(IntArr arr)
{
    IntArr memo;
    memo.n = arr.n;
    memo.arr =  calloc(sizeof(int), memo.n);

    if(arr.n >= 1)
    {
        memo.arr[0] = arr.arr[0];
    }
    if(arr.n >= 2)
    {
        memo.arr[1] = my_max(arr.arr[0], arr.arr[1]);
    }

    for(size_t i = 2;i < arr.n;i++)
    {
        int profit_1 = memo.arr[i - 1];
        int profit_2 = memo.arr[i - 2] + arr.arr[i];
        int max_profit = my_max(profit_1, profit_2);
        memo.arr[i] = max_profit;
    }
    int result = memo.arr[arr.n - 1];
    free_arr(&memo);
    return result;
}
