#include <stdio.h>

int main()
{
    int salary_1, salary_2, salary_3;
    if (scanf("%d %d %d", &salary_1, &salary_2, &salary_3) != 3)
    {
        return 1;
    }
    int min_salary = salary_1;
    int max_salary = salary_1;

    if (salary_2 < min_salary)
    {
        min_salary = salary_2;
    }

    if (salary_2 > max_salary)
    {
        max_salary = salary_2;
    }

    if (salary_3 < min_salary)
    {
        min_salary = salary_3;
    }

    if (salary_3 > max_salary)
    {
        max_salary = salary_3;
    }

    int diff = max_salary - min_salary;
    printf("%d\n", diff);
    return 0;
}