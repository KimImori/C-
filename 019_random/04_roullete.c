#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../library/random_utils.h"

enum RoulleteColor
{
    RED,
    GREEN,
    BLACK
};

int ITERATIONS = 1000000; 
typedef struct _Roullete
{
    int value_num; // [0;32]
    enum RoulleteColor color;

} Roullete;

Roullete roll_roullet();
int game_bet(enum RoulleteColor color,int price_bet);
int main()
{
    int balance = 0;
    srand(time(NULL));
    int counter = 0;
    while(counter < ITERATIONS)
    {
        int prize = game_bet(RED, 100);
        balance += prize;
        if((counter % 1000) == 0)
        {
            printf("#%d:\t%d\n",counter,balance);
        }
        counter++;
    
    }
    return 0;
}

Roullete roll_roullet()
{
    Roullete roll;
    roll.value_num = rand_range_inclusive(0,33);
    if(roll.value_num == 0 || roll.value_num == 33)
    {
        roll.color = GREEN;
    }
    else if ((roll.value_num % 2) == 0)
    {
        roll.color = RED;
    }
    else if ((roll.value_num % 2) == 1)
    {
        roll.color = BLACK;
    }
    

    return roll;
}

int game_bet(enum RoulleteColor color,int price_bet)
{
    Roullete roll = roll_roullet();
    if(color == roll.color)
    {
        return price_bet;
    } 
    return  price_bet * -1;

}