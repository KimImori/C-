#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    time_t timestamp = time(NULL);
    const struct tm *local = localtime(&timestamp);
    if (local == NULL)
    {
        fprintf(stderr, "local time is NULL\n");
        return 1;
    }
    printf("Current time: %s", asctime(local));
    const struct tm *gmt = gmtime(&timestamp);
    if (gmt == NULL)
    {
        fprintf(stderr, "gmt time is NULL\n");
        return 1;
    }
    printf("Current time: %s", asctime(gmt));
    return 1;
}