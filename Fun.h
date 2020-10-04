#ifndef FUN_H
#define FUN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>
#include <ncurses.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/mman.h>

#define height 24
#define width 48

enum move_type{
    stay = 0,
    movee = 1,
    run = 2,
    hunt = 3,
    human = 4,
};

struct drop_t{
    int x;
    int y;
    int value;
};

struct beast_t{
    enum move_type t;
    char vision[5][5];
    char stand;
    int bush;
    int actualx;
    int actualy;
};

struct map{
    char map[height][width];
    struct drop_t d[20];
    struct beast_t b[5];
    int number_beast;
    int number_drop;
};

struct player{
    pid_t proces_id;
    enum move_type t;
    char vision[5][5];
    char stand;
    int id;
    int type;
    int active;
    int bush;
    int spawnx;
    int spawny;
    int actualx;
    int actualy;
    int carried;
    int brought;
    int deaths;
};

void info_server(struct player *x1, struct player *x2, struct player *x3, struct player *x4, int x);
void info_server_update(struct player *x1, struct player *x2, struct player *x3, struct player *x4, int x);
void info_client(struct player *player);
void drawmap(char map[height][width]);
void put(struct map *map, char ch);
void set_player(struct player *player, int x);
void end_player(struct map *map, struct player *player);
void put_player_on_map(struct map *map, struct player *player);
void put_beast_on_map(struct map *map);
void print_player_on_map(struct player *player);
void move_bot_on_map(struct map *map, struct player *player);
void move_player_on_map(struct map *map, struct player *player, int move);
void move_beast_on_map(struct map *map, int ch);
void player_map_update(struct map *map, struct player *player);
void destroy_players(struct player *x1, struct player *x2, struct map *map);
void destroy_beast(struct map *map, struct player *player, int bn);


#endif // FUN_H
