#include <stdio.h>
#include <time.h>
#include <assert.h>

typedef struct MyLittleTm__
{
    int year;
    int month;
    int day;
    int hours;
    int minitues;
    int seconds;
} MyLittleTm;

void print_my_tm(const MyLittleTm* tm) {

    assert(tm);
    printf("%d.%.2d.%.2d %.2d:%.2d:%.2d\n", tm->year, tm->month, tm->day, tm->hours, tm->minitues, tm->seconds);
}

MyLittleTm construct_tm_from_timestamp(time_t timestamp)
{
    MyLittleTm tm;
    // TODO:
    return tm;
}

int main()
{
    time_t timestamp = time(NULL);
    struct tm *local = gmtime(&timestamp);
    printf("GMT time: %s \n", asctime(local));
    MyLittleTm tm = construct_tm_from_timestamp(timestamp);
    print_my_tm(&tm);
    return 0;
}