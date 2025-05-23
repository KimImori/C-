#include <stdio.h>
#include <stdlib.h>
#include "../library/logger.h"

struct Savings
{
    int initial_amount;
    int years;
    int interest_rate_percent;
};

void fill_savings_from_args(struct Savings *savings, int argc, char *argv[]){
    if(argc != 4)
    {
        fprintf(stderr, "Usage: %s <initial_amount> <years> <interest_rate_percent>\n", argv[0]);
        return;
    }
    savings->initial_amount = atoi(argv[1]);
    savings->years = atoi(argv[2]);
    savings->interest_rate_percent = atoi(argv[3]);
}

int calculate_savings(const struct Savings *savings){
    if (savings == NULL)
    {
        return -1;
    }
    int result = savings->initial_amount;
    double percent = savings->interest_rate_percent / 100.0;
    for(int i = 0; i < savings->years; i++)
    {
        log_message("Year %d result %d", i, result);
        result += result * percent;
    }
    return result;
}

int main(int argc, char *argv[])
{
    init_logger("log.txt", 1);
    struct Savings savings;

    fill_savings_from_args(&savings, argc, argv);
    int result = calculate_savings(&savings);

    printf("The amount after %d years is %d\n", savings.years, result);
    return 0;
}