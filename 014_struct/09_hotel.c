#include <stdio.h>
#include <stdlib.h>

/*
Программа управления отелем
1)В отеле есть комнаты, у каждой комнаты есть:номер,тип комнаты(luxe,econom)
2)Luxe-5550 в сутки, Econom- 2220
3)Комнату можно зарезервировать за гостем, у гостя есть Имя
4)Комнату можно освободить
Написать программу, которая
1)Позволяет зарезервировать комнату, если она еще не была зарезервирована
2)Позволяет освободить комнату
3)Позволяет посмотреть информацию по комнате
4)Показывает статистику отеля(сколько комнат зарезервировано по каждому типу и на какую сумму)
*/
typedef unsigned int room_id;
typedef enum __ROOM_TYPE
{
    LUXURY = 1,
    ECONOME
} ROOM_TYPE;

typedef struct __Guest
{
    char *name;
} Guest;

typedef struct __Room
{
    ROOM_TYPE type;
    room_id id;
    Guest *guest;
} Room;

typedef struct __Hotel
{
    Room *rooms;
    size_t len_rooms;
} Hotel;

Hotel create_hotel(size_t len_rooms);
void free_hotel(Hotel *hotel);
int reserve_room(Hotel *hotel, room_id id,Guest *guest);
int free_room(Hotel *hotel, room_id id);
Room *get_room_by_id(Hotel *hotel, room_id id);
int get_reserved_rooms_count_by_type(const Hotel *hotel, ROOM_TYPE type);
int get_reserved_rooms_price_by_type(const Hotel *hotel, ROOM_TYPE type);

typedef enum __USER_CHOICE
{
    ROOM_INFO = 1,
    RESERVE_GUEST,
    FREE_GUEST,
    STATISTIC,
    EXIT,
    INVALID
} USER_CHOICE;

void start_event_loop(Hotel *h);
void print_menu();
USER_CHOICE get_user_choice();
int process_user_choice(USER_CHOICE user_choice, Hotel *h);
void press_for_continue();

int main()
{
    Hotel h = create_hotel(50);

    start_event_loop(&h);
    free_hotel(&h);

    return 0;
}

void start_event_loop(Hotel *h)
{
    while (1)
    {
        system("clear");
        print_menu();
        USER_CHOICE user_choice = get_user_choice();
        if (!process_user_choice(user_choice, h))
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
    printf("1- ROOM_INFO\n");
    printf("2- RESERVE_GUEST\n");
    printf("3- FREE_GUEST\n");
    printf("4- STATISTIC\n");
    printf("5- Exit\n");
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
int process_user_choice(USER_CHOICE user_choice, Hotel *h)
{
    room_id room_number;
    switch (user_choice)
    {
    case ROOM_INFO:
        printf("Please enter room number\n");
        if (scanf("%u", &room_number) == 1)
        {
            Room *room = get_room_by_id(h, room_number);
            if (room == NULL)
            {
                printf("room not found\n");
            }
            else
            {
                printf("Id- %d\n Type- %u\n", room->id, room->type);
                if (room->guest == NULL)
                {
                    printf("Without Guest\n");
                }
                else
                {
                    printf("Guest Name - %s\n", room->guest->name);
                }
            }
        }
        break;
    case RESERVE_GUEST:
        printf("Please enter room number\n");
        if (scanf("%u", &room_number) == 1)
        {
            Guest *g = malloc(sizeof(Guest));
            g->name = "Dan";
            int result = reserve_room(h, room_number, g);
            if (result)
            {
                printf("Sucess!\n");
            }
            else
            {
                printf("Failed\n");
            }
        }
        break;
    case FREE_GUEST:
        printf("Please enter room number\n");
        if (scanf("%u", &room_number) == 1)
        {
            int result = free_room(h, room_number);
            if (result)
            {
                printf("Sucess!\n");
            }
            else
            {
                printf("Failed\n");
            }
        }
        break;
    case STATISTIC:
        int lux_count = get_reserved_rooms_count_by_type(h, LUXURY);
        int econome_count = get_reserved_rooms_count_by_type(h, ECONOME);
        int lux_price = get_reserved_rooms_price_by_type(h, LUXURY);
        int econome_price = get_reserved_rooms_price_by_type(h, ECONOME);
        printf("Lux count = %d, Lux price = %d\n", lux_count, lux_price);
        printf("Econome count = %d, Econome Price = %d\n", econome_count, econome_price);
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

Hotel create_hotel(size_t len_rooms)
{
    Hotel hotel;
    hotel.rooms = malloc(sizeof(Room) * len_rooms);
    if (hotel.rooms == NULL)
    {
        hotel.len_rooms = 0;
        return hotel;
    }
    hotel.len_rooms = len_rooms;
    for (size_t i = 0; i < hotel.len_rooms; i++)
    {
        hotel.rooms[i].id = 1 + i;
        hotel.rooms[i].guest = NULL;
        if (hotel.len_rooms - i <= 10)
        {
            hotel.rooms[i].type = LUXURY;
        }
        else
        {
            hotel.rooms[i].type = ECONOME;
        }
    }
    return hotel;
}

void free_hotel(Hotel *hotel)
{
    if (hotel == NULL)
    {
        return;
    }
    for(size_t i = 0; i < hotel->len_rooms;i++)
    {
        free(hotel->rooms[i].guest);
    }
    free(hotel->rooms);
    hotel->len_rooms = 0;
}

Room *get_room_by_id(Hotel *hotel, room_id id)
{
    if (hotel == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < hotel->len_rooms; i++)
    {
        if (hotel->rooms[i].id == id)
        {
            return hotel->rooms + i;
        }
    }
    return NULL;
}

int reserve_room(Hotel *hotel, room_id id,Guest *guest)
{
    if (hotel == NULL || guest == NULL)
    {
        return 0;
    }
    Room *room = get_room_by_id(hotel, id);
    if (room == NULL)
    {
        return 0;
    }
    if (room->guest != NULL)
    {
        return 0;
    }
    room->guest = guest;
    return 1;
}

int free_room(Hotel *hotel, room_id id)
{
    if (hotel == NULL)
    {
        return 0;
    }
    Room *room = get_room_by_id(hotel, id);
    if (room == NULL)
    {
        return 0;
    }
    free(room->guest);
    room->guest = NULL;
    return 1;
}

int get_reserved_rooms_count_by_type(const Hotel *hotel, ROOM_TYPE type)
{
    if (hotel == NULL)
    {
        return 0;
    }
    int counter = 0;
    for (size_t i = 0; i < hotel->len_rooms; i++)
    {
        if (hotel->rooms[i].type == type && hotel->rooms[i].guest != NULL)
        {
            counter++;
        }
    }
    return counter;
}

int get_reserved_rooms_price_by_type(const Hotel *hotel, ROOM_TYPE type)
{
    if (hotel == NULL)
    {
        return 0;
    }
    int price = 0;
    for (size_t i = 0; i < hotel->len_rooms; i++)
    {
        if (hotel->rooms[i].type == type && hotel->rooms[i].guest != NULL)
        {
            if (type == LUXURY)
            {
                price += 5500;
            }
            else
            {
                price += 2400;
            }
        }
    }
    return price;
}