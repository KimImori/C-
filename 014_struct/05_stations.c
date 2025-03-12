#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct __Point {
    double x;
    double y;
} Point;

typedef struct __Station {
    int id;
    char *name;
    Point center;
    double radius;
} Station;

typedef struct __Stations {
    Station* arr;
    size_t len;
} Stations;

Stations make_stations(size_t n);
bool is_station_signal_cover_point(const Station *s, Point p);
void print_station(const Station* s);
void print_stations_which_cover_point(Stations stations, Point p);

int main()
{
    Stations stations = make_stations(1000);
    Point p = {
        .x = 15,
        .y = 15
    };
    print_stations_which_cover_point(stations, p);
    return 0;
}

void print_station(const Station* s)
{
    if (s == NULL)
    {
        return;    
    }
    printf("---------------\n");
    printf("Id:\t\t\t%d\n", s->id);
    printf("Name:\t\t\t%s\n", s->name);
    printf("Radius:\t\t\t%lf\n", s->radius);
    printf("Center.x:\t\t%lf\n", s->center.x);
    printf("Center.y:\t\t%lf\n", s->center.y);
    printf("---------------\n\n");
}

int my_random(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

char* generate_station_name(int id)
{
    char* station_name = malloc(50);
    if (station_name == NULL)
    {
        return NULL;
    }
  
    sprintf(station_name, "Station #%d", id);
    return station_name;
}

Stations make_stations(size_t n)
{
    Stations result;
    result.arr = malloc(sizeof(Station)*n);
    if (result.arr == NULL)
    {
        result.len = 0;
        return result;
    }
    result.len = n;

    for(size_t i=0; i<n; i++)
    {
        result.arr[i].id = 1+i;
        result.arr[i].name = generate_station_name(result.arr[i].id);
        result.arr[i].radius = (double)my_random(10, 100);
        result.arr[i].center.x = (double)my_random(0, 300);
        result.arr[i].center.y = (double)my_random(0, 300);
    }

    return result;
}

bool is_station_signal_cover_point(const Station *s, Point p)
{
    if (s == NULL)
    {
        return false;
    }

    double dx = fabs(s->center.x - p.x);
    double dy = fabs(s->center.y - p.y);
    double c = sqrt(dx*dx + dy*dy);

    return c < s->radius;
}

void print_stations_which_cover_point(Stations stations, Point p)
{
    for(size_t i=0; i < stations.len; i++)
    {
        if (is_station_signal_cover_point(stations.arr + i, p))
        {
            print_station(stations.arr + i);
        }
    }
}

