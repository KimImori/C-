#include <stdio.h>
#include <stdlib.h>

typedef struct __Hero
{
    int health;
    int attack;
    int potions;
} Hero;

typedef struct __Dragon
{
    int health;
    int attack;
} Dragon;

typedef enum
{
    STATUS = 1,
    ATTACK_DRAGON,
    POTION,
    EXIT,
    INVALID
} USER_CHOICE;

void game();
void status(const Hero *hero, const Dragon *dragon);
void attack_dragon(Hero *hero, Dragon *dragon);
void use_potion(Hero *hero);
void exit_();
void print_menu();
USER_CHOICE get_user_choice();
void press_for_continue();

int main()
{
    game();
    return 0;
}

void game()
{
    Hero hero =
        {100,
         20,
         2};
    Dragon dragon =
        {150,
         15};

    while (1)
    {
        system("clear");
        print_menu();
        USER_CHOICE user_choice = get_user_choice();

        switch (user_choice)
        {
        case STATUS:
            status(&hero, &dragon);
            break;
        case ATTACK_DRAGON:
            attack_dragon(&hero, &dragon);
            break;
        case POTION:
            use_potion(&hero);
            break;
        case EXIT:
            exit_();
            return;
        default:
            printf("Некорректный ввод!\n");
        }
        press_for_continue();
    }
}

void print_menu()
{
    printf("--------------------------------\n");
    printf("Menu\n");
    printf("1- Cтатус героя\n");
    printf("2- Атаковать дракона\n");
    printf("3- Использовать зелья\n");
    printf("4- Выход\n");
    printf("--------------------------------\n");
}

USER_CHOICE get_user_choice()
{
    USER_CHOICE user_choice;
    printf("Enter your choice: ");
    if (scanf("%u", &user_choice) != 1)
    {
        user_choice = INVALID;
    }
    return user_choice;
}

void press_for_continue()
{
    char c;
    printf("Press any key to continue...\n");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    getchar();
}

void status(const Hero *hero, const Dragon *dragon)
{
    if (hero == NULL || dragon == NULL)
    {
        return;
    }
    printf("Герой: Здоровье= %d, Урон= %d, Зелья= %d\n", hero->health, hero->attack, hero->potions);
    printf("Дракон: Здоровье= %d, Урон= %d\n", dragon->health, dragon->attack);
}

int my_random(int min, int max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int calculate_damage(int base_damage)
{
    int result = base_damage;
    int percent = my_random(0, 10);
    int add_damage = (result * percent) / 100;
    result += add_damage;
    if (my_random(1, 100) == 15)
    {
        result *= 5;
    }
    return result;
}

void attack_dragon(Hero *hero, Dragon *dragon)
{
    if (hero == NULL || dragon == NULL)
    {
        return;
    }
    if (hero->health <= 0)
    {
        printf("Вы погибли :(\n");
        return;
    }
    if (dragon->health <= 0)
    {
        printf("Победа!\n");
        return;
    }
    dragon->health -= calculate_damage(hero->attack);
    if (dragon->health > 0)
    {
        hero->health -= calculate_damage(dragon->attack);
        printf("Дракон атаковал вас, ваше здоровье = %d\n", hero->health);
    }
}

void use_potion(Hero *hero)
{
    if (hero == NULL)
    {
        return;
    }
    if (hero->potions > 0)
    {
        hero->health += 30;
        hero->potions--;
        printf("Вы использовали зелье. Здоровье - %d. Зелья - %d\n", hero->health, hero->potions);
    }
    else
    {
        printf("Зелья кончились.\n");
    }
}

void exit_()
{
    printf("Удачи!\n");
}
