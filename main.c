/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct player_s
{
    int x;
    int y;
    int thrust;
};

struct checkpoint_s
{
    int x;
    int y;
    int distance;
    int angle;
};

struct opponent_s
{
    int x;
    int y;
};

int main(void)
{
    struct player_s player = {0, 0, 100};
    struct checkpoint_s checkpoint = {0, 0, 0, 0};
    struct opponent_s opponent = {0, 0};

    while (1) {
        scanf("%d%d%d%d%d%d", &player.x, &player.y, &checkpoint.x, &checkpoint.y, &checkpoint.distance, &checkpoint.angle);
        scanf("%d%d", &opponent.x, &opponent.y);

        if (checkpoint.angle > -10 && checkpoint.angle < 10 && checkpoint.distance > 500) {
            player.thrust = 100;
        } else {
            if (checkpoint.angle > 90 || checkpoint.angle < -45) {
                player.thrust = 0;
            } else {
                player.thrust = 100;
            }
        }
        if (checkpoint.angle == 0 && checkpoint.distance < 1000) {
            player.thrust = 0;
        }

        printf("%d %d", checkpoint.x, checkpoint.y);

        if (checkpoint.angle == 0 && checkpoint.distance >= 3000) {
            printf(" BOOST\n");
        } else {
            printf(" %d\n", player.thrust);
        }
    }
    return 0;
}
