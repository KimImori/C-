#include <stdio.h>

struct Student
{
    int id;
    int grade;
};

// callback
void print_array(const void *arr, size_t element_size, size_t len, void (*print_func)(const void *))
{
    if (arr == NULL)
    {
        return;
    }
    const char *casted_arr = (const char *)arr;
    for (size_t i = 0; i < len; i++)
    {
        print_func(casted_arr + (i * element_size));
        printf(" ");
    }
    printf("\n");
}

void print_int(const void *value)
{
   int *int_value = (int *)value;
   printf("%d",*int_value);
}

void print_str(const void *value)
{
    char **str_value = (char **)value;
    printf("%s",*str_value);
}

void print_student(const void *value)
{
    struct Student *student_value = (struct Student *)value;
    printf("id: %d, grade: %d",student_value->id,student_value->grade);
}

int main()
{
    int arr_int[] = {1,2,3,4,5};
    char* arr_str[] = {"hello","world","noi","dan","tuy"};
    struct Student arr_student[] = {{1,9},{2,8},{3,7},{4,6},{5,5}};
    print_array(arr_int, sizeof(int), 5, print_int);
    print_array(arr_str, sizeof(char*), 5, print_str);
    print_array(arr_student, sizeof(struct Student), 5, print_student);
    return 0;
}