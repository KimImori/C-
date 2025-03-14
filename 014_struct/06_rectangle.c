#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct __Point
{
    double x;
    double y;

} Point;

typedef struct __Rectangle
{
    Point a;
    Point b;
} Rectangle;

Rectangle *create_rectangle(Point a, Point b);
double area(const Rectangle *rectangle);

int main()
{

    Point a = {
        .x = 1,
        .y = 75
    };
    Point b = {
        .x = 1,
        .y = 5
    };

    Rectangle *rectangle_1 = create_rectangle(a, b);
    if (rectangle_1 == NULL)
    {
        return 1;
    }
    double area_rectangle = area(rectangle_1);
    printf("Area:%lf\n", area_rectangle);
    free(rectangle_1);
    return 0;
}

Rectangle *create_rectangle(Point a, Point b)
{
    if (a.x == b.x || a.y == b.y)
    {
        printf("Invalid points\n");
        return NULL;
    }
    Rectangle *r =  malloc(sizeof(Rectangle));
    if(r == NULL)
    {
        return NULL;
    }
    r->a = a;
    r->b = b;
    return r;
}

double area(const Rectangle *rectangle)
{
    if(rectangle == NULL)
    {
        return 0.0;
    }
    double d_x = fabs (rectangle->a.x - rectangle->b.x);
    double d_y = fabs (rectangle->a.y - rectangle->b.y);
    double area_rectangle = d_x * d_y;
    return area_rectangle;

}