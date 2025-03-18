#include <stdio.h>
#include <stdlib.h>

typedef enum __USER_CHOICE
{
    PRINT_HELLO = 1,
    PRINT_WORLD,
    EXIT,
    INVALID
} USER_CHOICE;

void start_event_loop();
void print_menu();
USER_CHOICE get_user_choice();
int process_user_choice(USER_CHOICE user_choice);
void press_for_continue();

int main()
{
    start_event_loop();
    return 0;
}

void start_event_loop()
{
    while (1)
    {
        system("clear");
        print_menu();
        USER_CHOICE user_choice = get_user_choice();
        if (!process_user_choice(user_choice))
        {
            break;
        }
        press_for_continue();
    }
}
void print_menu()
{
    printf("--------------------------------\n");
    printf("Menu\n");
    printf("1-Print Hello\n");
    printf("2-Print World\n");
    printf("3-Exit\n");
    printf("--------------------------------\n");
}
USER_CHOICE get_user_choice()
{
    USER_CHOICE user_choice;
    printf("Choice number from menu:\n");
    if (scanf("%u", &user_choice) != 1)
    {
        user_choice = INVALID;
    }
    return user_choice;
}
int process_user_choice(USER_CHOICE user_choice)
{
    switch (user_choice)
    {
    case PRINT_HELLO:
        printf("Hello\n");
        break;
    case PRINT_WORLD:
        printf("World\n");
        break;
    case EXIT:
        printf("Goodbye!\n");
        return 0;
    default:
        printf("Your choice incorrect!\n");
    }
    return 1;
}
void press_for_continue()
{
    char c;
    printf("Press any key for continue\n");
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    getchar();
}
