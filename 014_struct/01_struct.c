#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct __Employe {
    unsigned int id;
    unsigned char age;
    unsigned char experience;
    float salary;
    // char name[255];
    char *name;
} Employe;


void emp_print(Employe emp)
{
    printf("--------------------\n");
    printf("id: %u\n", emp.id);
    printf("age: %u\n", emp.age);
    printf("exp: %u\n", emp.experience);
    printf("salary: %f\n", emp.salary);
    printf("salary: %s\n", emp.name);
    printf("--------------------\n\n");
}

int main()
{
    char name_static_array[10];
    strcpy(name_static_array, "Denis");
    
    Employe user_1 = {
        .id = 125,
        .age = 25,
        .experience = 2,
        .salary = 2500.1,
        .name = "Denis"
    };
    Employe user_2 = {
        .id = 126,
        .age = 35,
        .experience = 10,
        .salary = 4500.1,
        .name = "Nick"
    };
    // user_1.id = 125;
    // user_1.age = 25;
    // user_1.experience = 2;
    // user_1.salary = 2500.1;
    // user_1.name = "Denis"; 
    //user_1.name = name_static_array; 

    printf("sizeof(Employe) = %ld bytes\n", sizeof(Employe));
    emp_print(user_1);
    emp_print(user_2);


    return 0;
}
