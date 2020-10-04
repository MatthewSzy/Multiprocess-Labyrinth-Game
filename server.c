#include "Fun.h"

char map[height][width] =
{   {"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"},
    {"X       X     ##  X     X       X     #    X   X"},
    {"XXXX #X X XXX X XXX XXX     XXX X XXXXX XXXXXX X"},
    {"X   # X   X   X     X X # ##X X       X        X"},
    {"X XX #XXXXXXX XXX X X X X X X XXXXXXXXXXXXX XXXX"},
    {"X X   X     X   X X X   X X       X     X      X"},
    {"X XXX X XXX XXX X X X XXX X XXXXX X XXXXX XXX XX"},
    {"X   X     X   #  #X       X X    #    X     X  X"},
    {"XXX XXXXX XXX### #X     XXX XXXX#XXXX X   XXXXXX"},
    {"X X         X #  #            X       XXX   ## X"},
    {"X XXXXX XXXXXXXXX            XX XXXX    X  XX  X"},
    {"X      #    X       X   A            X      X #X"},
    {"X XXX## XXX X XXXXXXX        XXXX X  XXXXX  XXXX"},
    {"X X       X   X ##     X        X X#        X  X"},
    {"X X XXX X XXXXX  ## X XXXXX XXX X XXXXXXXXX #  X"},
    {"X X X   X   ##      X     X X   X      X  X ## X"},
    {"X X X XXXXXXXXXXXXX XXXXX X XXXXX X XXXX  X XXXX"},
    {"X   X X     X         X   X       X X     X    X"},
    {"XXX X XXX X XXX XXXXXXX XXXXX X X X XXXX##XXXXXX"},
    {"X   X     X   X X     X     # X X   X X ##X    X"},
    {"X XXX XXXXXXX#X X#XXX X X## X   X XXX X   XXX XX"},
    {"X XX##XX   X #X X X   X X   X XXX X   X       XX"},
    {"X   ##   X          X       X            XX  # X"},
    {"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"}};

int end = 0;

void *operator(void *arg){
    struct map *m = (struct map*)arg;
    while(1){
        char x = getch();
        if(x == 'c' || x == 'T' || x == 't'){
            put(m, x);
        }
        else if((x == 'b' || x == 'B') && m->number_beast < 5){
            put_beast_on_map(m);
        }
        else if(x == 'q' || x == 'Q'){
            end = 1;
            return NULL;
        }
    }
}

int main(){

    sem_t *p0 = sem_open("Server", O_CREAT|O_EXCL, 0600, 0);
    sem_t *p1 = sem_open("Player1", O_CREAT|O_EXCL, 0600, 0);
    sem_t *p2 = sem_open("Player2", O_CREAT|O_EXCL, 0600, 0);
    sem_t *p3 = sem_open("Player3", O_CREAT|O_EXCL, 0600, 0);
    sem_t *p4 = sem_open("Player4", O_CREAT|O_EXCL, 0600, 0);

    int memory_player_index = shm_open("Player_index", O_CREAT|O_RDWR, 0666);
    ftruncate(memory_player_index, 1);

    int memory_player_move = shm_open("Player_move", O_CREAT|O_RDWR, 0666);
    ftruncate(memory_player_move, 1);

    int memory_player_exit = shm_open("Player_exit", O_CREAT|O_RDWR, 0666);
    ftruncate(memory_player_exit, 1);

    int memory_player_one = shm_open("Player_one", O_CREAT|O_RDWR, 0666);
    ftruncate(memory_player_one, sizeof(struct player));

    int memory_player_two = shm_open("Player_two", O_CREAT|O_RDWR, 0666);
    ftruncate(memory_player_two, sizeof(struct player));

    int memory_player_three = shm_open("Player_three", O_CREAT|O_RDWR, 0666);
    ftruncate(memory_player_three, sizeof(struct player));

    int memory_player_four = shm_open("Player_four", O_CREAT|O_RDWR, 0666);
    ftruncate(memory_player_four, sizeof(struct player));

    int *player_index = mmap(NULL, 1, PROT_READ|PROT_WRITE, MAP_SHARED, memory_player_index, 0);
    *player_index = -1;

    int *player_move = mmap(NULL, 1, PROT_READ|PROT_WRITE, MAP_SHARED, memory_player_move, 0);
    *player_move = 1;

    int *player_exit = mmap(NULL, 1, PROT_READ|PROT_WRITE, MAP_SHARED, memory_player_exit, 0);
    *player_exit = 0;

    struct player *playerOne = mmap(NULL, sizeof(struct player), PROT_READ|PROT_WRITE, MAP_SHARED, memory_player_one, 0);
    set_player(playerOne, 1);

    struct player *playerTwo = mmap(NULL, sizeof(struct player), PROT_READ|PROT_WRITE, MAP_SHARED, memory_player_two, 0);
    set_player(playerTwo, 2);

    struct player *playerThree = mmap(NULL, sizeof(struct player), PROT_READ|PROT_WRITE, MAP_SHARED, memory_player_three, 0);
    set_player(playerThree, 3);

    struct player *playerFour = mmap(NULL, sizeof(struct player), PROT_READ|PROT_WRITE, MAP_SHARED, memory_player_four, 0);
    set_player(playerFour, 4);

    struct map *maps = (struct map*)malloc(sizeof(struct map));
    maps->number_drop = 0;
    maps->number_beast = 0;
    for(int i=0;i<height;i++){
        strcpy(maps->map[i], map[i]);
    }

    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_WHITE);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_GREEN);
    init_pair(5, COLOR_GREEN, COLOR_RED);
    init_pair(6, COLOR_RED, COLOR_BLUE);
    init_pair(7, COLOR_BLACK, COLOR_YELLOW);
    init_pair(8, COLOR_GREEN, COLOR_YELLOW);

    int round = 0;
    int tab[4];
    for(int i=0;i<4;i++){
        tab[i] = 0;
    }
    sem_post(p0);

    info_server(playerOne, playerTwo, playerThree, playerFour, round);
    drawmap(maps->map);
    pthread_t signal;
    pthread_create(&signal, NULL, operator, maps);

    while(1){
        for(int i=0;i<4;i++){
            if(tab[i] == 0){
                *player_index = i+1;
                break;
            }
            if(i == 3){
                *player_index = -1;
            }
        }

        if(end == 1){
            *player_exit = -1;
            break;
        }

        if(playerOne->active == 1 || playerTwo->active == 1 || playerThree->active == 1 || playerFour->active == 1){
            round += 1;
        }

        info_server_update(playerOne, playerTwo, playerThree, playerFour, round);

        if(playerOne->active == -2){
            tab[0] = 0;
            end_player(maps, playerOne);
            sem_trywait(p1);
        }
        if(playerTwo->active == -2){
            tab[1] = 0;
            end_player(maps, playerTwo);
            sem_trywait(p2);
        }
        if(playerThree->active == -2){
            tab[2] = 0;
            end_player(maps, playerThree);
            sem_trywait(p3);
        }
        if(playerFour->active == -2){
            tab[3] = 0;
            end_player(maps, playerFour);
            sem_trywait(p4);
        }

        if(playerOne->active == 0){
            if(sem_trywait(p1) == 0){
                tab[0] = 1;
                put_player_on_map(maps, playerOne);
                playerOne->active = 1;
            }
        }
        else if(playerOne->active == 1){
            if(sem_trywait(p1) == 0){
                if(playerOne->type == 0){
                    move_bot_on_map(maps, playerOne);
                }
                else if(playerOne->type == 1){
                    move_player_on_map(maps, playerOne, *player_move);
                }
            }
        }
        if(playerTwo->active == 0){
            if(sem_trywait(p2) == 0){
                tab[1] = 1;
                put_player_on_map(maps, playerTwo);
                playerTwo->active = 1;
            }
        }
        else if(playerTwo->active == 1){
            if(sem_trywait(p2) == 0){
                if(playerTwo->type == 0){
                    move_bot_on_map(maps, playerTwo);
                }
                else if(playerTwo->type == 1){
                    move_player_on_map(maps, playerTwo, *player_move);
                }
            }
        }
        if(playerThree->active == 0){
            if(sem_trywait(p3) == 0){
                tab[2] = 1;
                put_player_on_map(maps, playerThree);
                playerThree->active = 1;
            }
        }
        else if(playerThree->active == 1){
            if(sem_trywait(p3) == 0){
                if(playerThree->type == 0){
                    move_bot_on_map(maps, playerThree);
                }
                else if(playerThree->type == 1){
                    move_player_on_map(maps, playerThree, *player_move);
                }
            }
        }
        if(playerFour->active == 0){
            if(sem_trywait(p4) == 0){
                tab[3] = 1;
                put_player_on_map(maps, playerFour);
                playerFour->active = 1;
            }
        }
        else if(playerFour->active == 1){
            if(sem_trywait(p4) == 0){
                if(playerFour->type == 0){
                    move_bot_on_map(maps, playerFour);
                }
                else if(playerFour->type == 1){
                    move_player_on_map(maps, playerFour, *player_move);
                }
            }
        }
        if(playerOne->actualx == playerTwo->actualx && playerOne->actualy == playerTwo->actualy && playerOne->active == 1 && playerTwo->active == 1){
            destroy_players(playerOne, playerTwo, maps);
        }
        else if(playerOne->actualx == playerThree->actualx && playerOne->actualy == playerThree->actualy && playerOne->active == 1 && playerThree->active == 1){
            destroy_players(playerOne, playerThree, maps);
        }
        else if(playerOne->actualx == playerFour->actualx && playerOne->actualy == playerFour->actualy && playerOne->active == 1 && playerFour->active == 1){
            destroy_players(playerOne, playerFour, maps);
        }
        if(playerTwo->actualx == playerThree->actualx && playerTwo->actualy == playerThree->actualy && playerTwo->active == 1 && playerThree->active == 1){
            destroy_players(playerTwo, playerThree, maps);
        }
        else if(playerTwo->actualx == playerFour->actualx && playerTwo->actualy == playerFour->actualy && playerTwo->active == 1 && playerFour->active == 1){
            destroy_players(playerTwo, playerFour, maps);
        }
        if(playerThree->actualx == playerFour->actualx && playerThree->actualy == playerFour->actualy && playerThree->active == 1 && playerFour->active == 1){
            destroy_players(playerThree, playerFour, maps);
        }
        for(int i=0;i<maps->number_beast;i++){
            move_beast_on_map(maps, i);
            if(playerOne->actualx == maps->b[i].actualx && playerOne->actualy == maps->b[i].actualy){
                destroy_beast(maps, playerOne, i);
            }
            if(playerTwo->actualx == maps->b[i].actualx && playerTwo->actualy == maps->b[i].actualy){
                destroy_beast(maps, playerTwo, i);
            }
            if(playerThree->actualx == maps->b[i].actualx && playerThree->actualy == maps->b[i].actualy){
                destroy_beast(maps, playerThree, i);
            }
            if(playerFour->actualx == maps->b[i].actualx && playerFour->actualy == maps->b[i].actualy){
                destroy_beast(maps, playerFour, i);
            }
        }
        if(playerOne->active == 1){
            player_map_update(maps, playerOne);
        }
        if(playerTwo->active == 1){
            player_map_update(maps, playerTwo);
        }
        if(playerThree->active == 1){
            player_map_update(maps, playerThree);
        }
        if(playerFour->active == 1){
            player_map_update(maps, playerFour);
        }
        usleep(990000);
    }

    pthread_join(signal, NULL);

    clear();
    mvprintw(10, 10, "KONIEC GRY");
    refresh();
    usleep(5000000);

    sem_close(p0);
    sem_close(p1);
    sem_close(p2);
    sem_close(p3);
    sem_close(p4);
    close(memory_player_move);
    close(memory_player_exit);
    close(memory_player_one);
    close(memory_player_two);
    close(memory_player_three);
    close(memory_player_four);
    munmap(player_move, 1);
    munmap(player_exit, 1);
    munmap(playerOne, sizeof(struct player));
    munmap(playerTwo, sizeof(struct player));
    munmap(playerThree, sizeof(struct player));
    munmap(playerFour, sizeof(struct player));
    shm_unlink("Player_move");
    shm_unlink("Player_exit");
    shm_unlink("Player_one");
    shm_unlink("Player_two");
    shm_unlink("Player_three");
    shm_unlink("Player_four");

    endwin();
    return 0;
}
