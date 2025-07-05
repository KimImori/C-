#include <stdio.h>
#include <time.h>
#include <assert.h>

struct Employee
{
    char *name;
    time_t start_work_timestamp;
    time_t *end_work_timestamp;
};

void print_info_emp(struct Employee emp)
{
    struct tm *t = gmtime(&emp.start_work_timestamp);
    printf("Имя: %s\n",emp.name);
    printf("Дата устройства на работу: %s\n",asctime(t));
}


int extract_day_from_timestamp(time_t t)
{
    return t/60/60/24;
}

void print_work_period(struct Employee emp)
{
    time_t time_now = time(NULL);
    if (emp.end_work_timestamp != NULL)
    {
        assert(*emp.end_work_timestamp >= emp.start_work_timestamp);
    }
    if (emp.end_work_timestamp == NULL)
    {
        assert(time_now >= emp.start_work_timestamp);
    }
    time_t end_work = emp.end_work_timestamp == NULL ? time_now : *emp.end_work_timestamp;
    time_t diff = end_work - emp.start_work_timestamp;
    printf("%ld days\n", extract_day_from_timestamp(diff));
}



int main()
{
    struct tm start_work;
    start_work.tm_year = 2019 - 1900;
    start_work.tm_mon = 5;
    start_work.tm_mday = 19;
    start_work.tm_hour = 11;
    start_work.tm_min = 0;
    start_work.tm_sec = 0;

    struct Employee emp;
    emp.name = "Dan";
    emp.start_work_timestamp = mktime(&start_work);
    emp.end_work_timestamp = NULL;
    print_work_period(emp);
    print_info_emp(emp);

    return 0;
}