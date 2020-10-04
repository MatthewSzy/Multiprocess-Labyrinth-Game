#include "Fun.h"

void *move_player(void *arg){
    int *value = (int*)malloc(sizeof(int));
    int ch = getch();
    *value = ch;
    return value;
}

int main(){

    sem_t *p0 = sem_open("Server", O_CREAT, 0600, 0);

    int memory_player_index = shm_open("Player_index", O_CREAT|O_RDWR, 0666);
    ftruncate(memory_player_index, 1);

    int *player_index = mmap(NULL, 1, PROT_READ|PROT_WRITE, MAP_SHARED, memory_player_index, 0);

    int memory_player;
    struct player *Player;
    sem_t *P;

    sem_wait(p0);
    if(*player_index == 1){
        P = sem_open("Player1", O_CREAT, 0600, 0);

        memory_player = shm_open("Player_one", O_CREAT|O_RDWR, 0666);
        ftruncate(memory_player, sizeof(struct player));

        Player = mmap(NULL, sizeof(struct player), PROT_READ|PROT_WRITE, MAP_SHARED, memory_player, 0);
    }
    else if(*player_index == 2){
        P = sem_open("Player2", O_CREAT, 0600, 0);

        memory_player = shm_open("Player_two", O_CREAT|O_RDWR, 0666);
        ftruncate(memory_player, sizeof(struct player));

        Player = mmap(NULL, sizeof(struct player), PROT_READ|PROT_WRITE, MAP_SHARED, memory_player, 0);
    }
    else if(*player_index == 3){
        P = sem_open("Player3", O_CREAT, 0600, 0);

        memory_player = shm_open("Player_three", O_CREAT|O_RDWR, 0666);
        ftruncate(memory_player, sizeof(struct player));

        Player = mmap(NULL, sizeof(struct player), PROT_READ|PROT_WRITE, MAP_SHARED, memory_player, 0);
    }
    else if(*player_index == 4){
        P = sem_open("Player4", O_CREAT, 0600, 0);

        memory_player = shm_open("Player_four", O_CREAT|O_RDWR, 0666);
        ftruncate(memory_player, sizeof(struct player));

        Player = mmap(NULL, sizeof(struct player), PROT_READ|PROT_WRITE, MAP_SHARED, memory_player, 0);
    }
    else if(*player_index == -1){
        sem_post(p0);
        printf("BRAK MIEJSCA, NIE MOZNA ROZPOCZAC GRY!!\n");
        usleep(5000000);

        sem_close(p0);
        close(memory_player_index);
        munmap(player_index, 1);
        return 0;
    }
    sem_post(p0);

    int memory_player_exit = shm_open("Player_exit", O_CREAT|O_RDWR, 0666);
    ftruncate(memory_player_exit, 1);

    int memory_player_move = shm_open("Player_move", O_CREAT|O_RDWR, 0666);
    ftruncate(memory_player_move, 1);

    int *player_exit = mmap(NULL, 1, PROT_READ|PROT_WRITE, MAP_SHARED, memory_player_exit, 0);

    int *player_move = mmap(NULL, 1, PROT_READ|PROT_WRITE, MAP_SHARED, memory_player_move, 0);

    Player->proces_id = getpid();
    Player->type = 1;
    Player->t = human;
    Player->active = 0;
    sem_post(P);

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

    pthread_t signal;
    pthread_create(&signal, NULL, move_player, NULL);

    while(1){
        if(*player_exit == -1){
            break;
        }
        int *result;
        if(pthread_tryjoin_np(signal, (void**)&result)==0){
            if(*result == 'q' || *result == 'Q'){
                Player->active = -2;
                break;
            }
            *player_move = *result;
            sem_post(P);
            free(result);
            pthread_create(&signal, NULL, move_player, NULL);
        }
        usleep(100000);
        if(Player->active == 1){
            print_player_on_map(Player);
            info_client(Player);
        }
    }

    clear();
    mvprintw(10, 10, "KONIEC GRY");
    refresh();
    usleep(5000000);

    sem_close(p0);
    sem_close(P);
    close(memory_player_index);
    close(memory_player_move);
    close(memory_player_exit);
    close(memory_player);
    munmap(player_index, 1);
    munmap(player_move, 1);
    munmap(player_exit, 1);
    munmap(Player, sizeof(struct player));

    endwin();
    return 0;
}
