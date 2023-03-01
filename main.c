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
#include <math.h>

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

    int distance = 0;
    bool boost = false;

    while (1) {
        scanf("%d%d%d%d%d%d", &player.x, &player.y, &checkpoint.x, &checkpoint.y, &checkpoint.distance, &checkpoint.angle);
        scanf("%d%d", &opponent.x, &opponent.y);

        if (checkpoint.angle > 90 || checkpoint.angle < -90) {
            player.thrust = 0;
        } else {
            player.thrust = 100;
        }

        printf("%d %d", checkpoint.x, checkpoint.y);

        if (checkpoint.angle == 0 && checkpoint.distance >= 5000 && boost == false) {
            printf(" BOOST\n");
            boost = true;
        } else {
            printf(" %d\n", player.thrust);
        }
    }
    return 0;
}
