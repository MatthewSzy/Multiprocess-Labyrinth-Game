#include "Fun.h"

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void info_server(struct player *x1, struct player *x2, struct player *x3, struct player *x4, int x){
    pthread_mutex_lock(&mut);
    mvprintw(0, width+3, "Server's PID: %d", getpid());
    mvprintw(1, width+4, "Campsite X/Y: %d/%d", 25, 12);
    mvprintw(2, width+4, "Round number: %d", x);

    mvprintw(4, width+3, "Parameter:");
    mvprintw(5, width+4, "PID");
    mvprintw(6, width+4, "Type");
    mvprintw(7, width+4, "Curr X/Y");
    mvprintw(8, width+4, "Deaths");

    mvprintw(4, width+16, "Player1");
    if(x1->active == 1){
        mvprintw(5, width+16, "%d", x1->proces_id);
        if(x1->type == 0){
            mvprintw(6, width+16, "CPU");
        }
        else{
            mvprintw(6, width+16, "HUMAN");
        }
    }
    mvprintw(4, width+25, "Player2");
    if(x2->active == 1){
        mvprintw(5, width+25, "%d", x2->proces_id);
        if(x2->type == 0){
            mvprintw(6, width+25, "CPU");
        }
        else{
            mvprintw(6, width+25, "HUMAN");
        }
    }

    mvprintw(4, width+34, "Player3");
    if(x3->active == 1){
        mvprintw(5, width+34, "%d", x3->proces_id);
        if(x3->type == 0){
            mvprintw(6, width+34, "CPU");
        }
        else{
            mvprintw(6, width+34, "HUMAN");
        }
    }
    mvprintw(4, width+43, "Player4");
    if(x4->active == 1){
        mvprintw(5, width+43, "%d", x4->proces_id);
        if(x4->type == 0){
            mvprintw(6, width+43, "CPU");
        }
        else{
            mvprintw(6, width+43, "HUMAN");
        }
    }

    mvprintw(10, width+4, "Coins");
    mvprintw(11, width+8, "Carried");
    mvprintw(12, width+8, "Brought");

    mvprintw(14, width+3, "Legend:");
    attron(COLOR_PAIR(5)); mvprintw(15, width+4, "1234"); attroff(COLOR_PAIR(5));
    mvprintw(15, width+9, "- players");
    attron(COLOR_PAIR(2)); mvprintw(16, width+4, "X"); attroff(COLOR_PAIR(2));
    mvprintw(16, width+9, "- wall");
    attron(COLOR_PAIR(3)); mvprintw(17, width+4, "#"); attroff(COLOR_PAIR(3));
    mvprintw(17, width+9, "- bushes (slow down)");
    attron(COLOR_PAIR(6)); mvprintw(18, width+4, "*"); attroff(COLOR_PAIR(6));
    mvprintw(18, width+9, "- wild beast");
    attron(COLOR_PAIR(7)); mvprintw(19, width+4, "c"); attroff(COLOR_PAIR(7));
    mvprintw(19, width+9, "- one coin");
    attron(COLOR_PAIR(7)); mvprintw(20, width+4, "t"); attroff(COLOR_PAIR(7));
    mvprintw(20, width+9, "- treasure (10 coins)");
    attron(COLOR_PAIR(7)); mvprintw(21, width+4, "T"); attroff(COLOR_PAIR(7));
    mvprintw(21, width+9, "- large treasure (50 coins)");
    attron(COLOR_PAIR(8)); mvprintw(22, width+4, "D"); attroff(COLOR_PAIR(8));
    mvprintw(22, width+9, "- dropped treasure");
    attron(COLOR_PAIR(4)); mvprintw(23, width+4, "A"); attroff(COLOR_PAIR(4));
    mvprintw(23, width+9, "- campsite");
    refresh();
    pthread_mutex_unlock(&mut);
}

void info_server_update(struct player *x1, struct player *x2, struct player *x3, struct player *x4, int x){
    mvprintw(2, width+4, "Round number: %d", x);
    if(x1->active == 1){
        mvprintw(5, width+16, "%d", x1->proces_id);
        if(x1->type == 0){
            mvprintw(6, width+16, "CPU");
        }
        else{
            mvprintw(6, width+16, "HUMAN");
        }
        mvprintw(7, width+16, "      ");
        mvprintw(7, width+16, "%d/%d", x1->actualx, x1->actualy);
        mvprintw(8, width+16, "%d", x1->deaths);
    }
    else{
        mvprintw(5, width+16, "      ");
        mvprintw(5, width+16, "-");
        mvprintw(6, width+16, "      ");
        mvprintw(6, width+16, "-");
        mvprintw(7, width+16, "      ");
        mvprintw(7, width+16, "--/--");
        mvprintw(8, width+16, "      ");
        mvprintw(8, width+16, "-");
    }
    if(x2->active == 1){
        mvprintw(5, width+25, "%d", x2->proces_id);
        if(x2->type == 0){
            mvprintw(6, width+25, "CPU");
        }
        else{
            mvprintw(6, width+25, "HUMAN");
        }
        mvprintw(7, width+25, "      ");
        mvprintw(7, width+25, "%d/%d", x2->actualx, x2->actualy);
        mvprintw(8, width+25, "%d", x2->deaths);
    }
    else{
        mvprintw(5, width+25, "      ");
        mvprintw(5, width+25, "-");
        mvprintw(6, width+25, "      ");
        mvprintw(6, width+25, "-");
        mvprintw(7, width+25, "      ");
        mvprintw(7, width+25, "--/--");
        mvprintw(8, width+25, "      ");
        mvprintw(8, width+25, "-");
    }
    if(x3->active == 1){
        mvprintw(5, width+34, "%d", x3->proces_id);
        if(x3->type == 0){
            mvprintw(6, width+34, "CPU");
        }
        else{
            mvprintw(6, width+34, "HUMAN");
        }
        mvprintw(7, width+34, "      ");
        mvprintw(7, width+34, "%d/%d", x2->actualx, x2->actualy);
        mvprintw(8, width+34, "%d", x2->deaths);
    }
    else{
        mvprintw(5, width+34, "      ");
        mvprintw(5, width+34, "-");
        mvprintw(6, width+34, "      ");
        mvprintw(6, width+34, "-");
        mvprintw(7, width+34, "      ");
        mvprintw(7, width+34, "--/--");
        mvprintw(8, width+34, "      ");
        mvprintw(8, width+34, "-");
    }
    if(x4->active == 1){
        mvprintw(5, width+43, "%d", x1->proces_id);
        if(x1->type == 0){
            mvprintw(6, width+43, "CPU");
        }
        else{
            mvprintw(6, width+43, "HUMAN");
        }
        mvprintw(7, width+43, "      ");
        mvprintw(7, width+43, "%d/%d", x2->actualx, x2->actualy);
        mvprintw(8, width+43, "%d", x2->deaths);
    }
    else{
        mvprintw(5, width+43, "      ");
        mvprintw(5, width+43, "-");
        mvprintw(6, width+43, "      ");
        mvprintw(6, width+43, "-");
        mvprintw(7, width+43, "      ");
        mvprintw(7, width+43, "--/--");
        mvprintw(8, width+43, "      ");
        mvprintw(8, width+43, "-");
    }
    if(x1->active == 1){
        mvprintw(11, width+16, "   ");
        mvprintw(11, width+16, "%d", x1->carried);
        mvprintw(12, width+16, "   ");
        mvprintw(12, width+16, "%d", x1->brought);
    }
    else{
        mvprintw(11, width+16, "---");
        mvprintw(12, width+16, "---");
    }
    if(x2->active == 1){
        mvprintw(11, width+25, "   ");
        mvprintw(11, width+25, "%d", x2->carried);
        mvprintw(12, width+25, "   ");
        mvprintw(12, width+25, "%d", x2->brought);
    }
    else{
        mvprintw(11, width+25, "---");
        mvprintw(12, width+25, "---");
    }
    if(x3->active == 1){
        mvprintw(11, width+34, "   ");
        mvprintw(11, width+34, "%d", x3->carried);
        mvprintw(12, width+34, "   ");
        mvprintw(12, width+34, "%d", x3->brought);
    }
    else{
        mvprintw(11, width+34, "---");
        mvprintw(12, width+34, "---");
    }
    if(x4->active == 1){
        mvprintw(11, width+43, "   ");
        mvprintw(11, width+43, "%d", x4->carried);
        mvprintw(12, width+43, "   ");
        mvprintw(12, width+43, "%d", x4->brought);
    }
    else{
        mvprintw(11, width+43, "---");
        mvprintw(12, width+43, "---");
    }
    refresh();
}

void info_client(struct player *player){
    pthread_mutex_lock(&mut);
    mvprintw(1, width+3, "Parameter:");
    mvprintw(2, width+4, "Type");
    mvprintw(3, width+4, "Curr X/Y");
    mvprintw(4, width+4, "Deaths");
    mvprintw(5, width+4, "Carried");
    mvprintw(6, width+4, "Brought");

    if(player->active == 1){
        if(player->type == 0){
            mvprintw(2, width+14, "CPU");
        }
        else{
            mvprintw(2, width+14, "HUMAN");
        }
        mvprintw(3, width+14, "%d/%d", player->actualx, player->actualy);
        mvprintw(4, width+14, "%d", player->deaths);
        mvprintw(5, width+14, "%d", player->carried);
        mvprintw(6, width+14, "%d", player->brought);
    }
    else{
        mvprintw(2, width+14, "-");
        mvprintw(3, width+14, "-/-");
        mvprintw(4, width+14, "-");
        mvprintw(5, width+14, "-");
        mvprintw(6, width+14, "-");
    }
    refresh();
    pthread_mutex_unlock(&mut);
}

void drawmap(char map[height][width]){
    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            pthread_mutex_lock(&mut);
            switch (*(*(map+i)+j)){
                case ' ': attron(COLOR_PAIR(1)); mvprintw(i, j, "X"); attroff(COLOR_PAIR(1)); break;
                case 'X': attron(COLOR_PAIR(2)); mvprintw(i, j, "X"); attroff(COLOR_PAIR(2)); break;
                case '#': attron(COLOR_PAIR(3)); mvprintw(i, j, "#"); attroff(COLOR_PAIR(3)); break;
                case 'A': attron(COLOR_PAIR(4)); mvprintw(i, j, "A"); attroff(COLOR_PAIR(4)); break;
                case '*': attron(COLOR_PAIR(6)); mvprintw(i, j, "*"); attroff(COLOR_PAIR(6)); break;
                case 'c': attron(COLOR_PAIR(7)); mvprintw(i, j, "c"); attroff(COLOR_PAIR(7)); break;
                case 't': attron(COLOR_PAIR(7)); mvprintw(i, j, "t"); attroff(COLOR_PAIR(7)); break;
                case 'T': attron(COLOR_PAIR(7)); mvprintw(i, j, "T"); attroff(COLOR_PAIR(7)); break;
            }
            pthread_mutex_unlock(&mut);
        }
    }
    refresh();
}

void put(struct map *map, char ch){
    int x = 1+rand()%width;
    int y = 1+rand()%height;
    while(1){
        if(map->map[y][x] == ' '){
            if(ch == 'c'){
                map->map[y][x] = 'c';
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(y, x, "c"); attroff(COLOR_PAIR(7));
                pthread_mutex_unlock(&mut);
            }
            if(ch == 't'){
                map->map[y][x] = 't';
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(y, x, "t"); attroff(COLOR_PAIR(7));
                pthread_mutex_unlock(&mut);
            }
            if(ch == 'T'){
                map->map[y][x] = 'T';
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(y, x, "T"); attroff(COLOR_PAIR(7));
                pthread_mutex_unlock(&mut);
            }
            break;
        }
        else{
            x = 1+rand()%width;
            y = 1+rand()%height;
        }
    }
}

void set_player(struct player *player, int x){
    player->id = x;
    player->active = -1;
    player->type = 0;
    player->actualx = 0;
    player->actualy = 0;
    player->brought = 0;
    player->bush = 0;
    player->carried = 0;
    player->deaths = 0;
    player->spawnx = 0;
    player->spawny = 0;
}

void end_player(struct map *map, struct player *player){
    map->map[player->actualy][player->actualx] = player->stand;
    if(player->stand == ' '){
        pthread_mutex_lock(&mut);
        attron(COLOR_PAIR(1)); mvprintw(player->actualy, player->actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
        pthread_mutex_unlock(&mut);
    }
    else if(player->stand == '#'){
        pthread_mutex_lock(&mut);
        attron(COLOR_PAIR(3)); mvprintw(player->actualy, player->actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
        pthread_mutex_unlock(&mut);
    }
    else if(player->stand == 'A'){
        pthread_mutex_lock(&mut);
        attron(COLOR_PAIR(4)); mvprintw(player->actualy, player->actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
        pthread_mutex_unlock(&mut);
    }
    set_player(player, player->id);
}

void put_player_on_map(struct map *map, struct player *player){
    srand(time(NULL));
    int x = 1+rand()%width;
    int y = 1+rand()%height;
    while(1){
        if(map->map[y][x] == ' '){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(5)); mvprintw(y, x, "%d", player->id); attroff(COLOR_PAIR(5));
            pthread_mutex_unlock(&mut);
            refresh();
            player->spawnx = x;
            player->spawny = y;
            player->actualx = x;
            player->actualy = y;
            player->stand = ' ';
            map->map[y][x] = player->id+'0';
            break;
        }
        else{
            x = 1+rand()%width;
            y = 1+rand()%height;
        }
    }
}

void put_beast_on_map(struct map *map){
    srand(time(NULL));
    int x = 1+rand()%width;
    int y = 1+rand()%height;
    while(1){
        if(map->map[y][x] == ' '){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(6)); mvprintw(y, x, "*"); attroff(COLOR_PAIR(6));
            pthread_mutex_unlock(&mut);
            refresh();
            map->map[y][x] = '*';
            map->b[map->number_beast].actualx = x;
            map->b[map->number_beast].actualy = y;
            map->b[map->number_beast].t = stay;
            map->b[map->number_beast].bush = 0;
            map->b[map->number_beast].stand = ' ';
            int a = 0;
            int b = 0;
            for(int i = map->b[map->number_beast].actualy-2;i <= map->b[map->number_beast].actualy+2;i++){
                for(int j = map->b[map->number_beast].actualx-2;j <= map->b[map->number_beast].actualx+2;j++){
                    map->b[map->number_beast].vision[a][b] = map->map[i][j];
                    b += 1;
                }
                b = 0;
                a += 1;
            }
            map->b[map->number_beast].vision[2][2] = '*';
            map->number_beast += 1;
            break;
        }
        else{
            x = 1+rand()%width;
            y = 1+rand()%height;
        }
    }
}

void print_player_on_map(struct player *player){
    pthread_mutex_lock(&mut);
    clear();
    int a = 0;
    int b = 0;
    for(int i = player->actualy-2;i <= player->actualy+2;i++){
        for(int j = player->actualx-2;j <= player->actualx+2;j++){
            switch (player->vision[a][b]){
                        case ' ': attron(COLOR_PAIR(1)); mvprintw(i, j, "X"); attroff(COLOR_PAIR(1)); break;
                        case 'X': attron(COLOR_PAIR(2)); mvprintw(i, j, "X"); attroff(COLOR_PAIR(2)); break;
                        case '#': attron(COLOR_PAIR(3)); mvprintw(i, j, "#"); attroff(COLOR_PAIR(3)); break;
                        case 'A': attron(COLOR_PAIR(4)); mvprintw(i, j, "A"); attroff(COLOR_PAIR(4)); break;
                        case '1': attron(COLOR_PAIR(5)); mvprintw(i, j, "1"); attroff(COLOR_PAIR(5)); break;
                        case '2': attron(COLOR_PAIR(5)); mvprintw(i, j, "2"); attroff(COLOR_PAIR(5)); break;
                        case '3': attron(COLOR_PAIR(5)); mvprintw(i, j, "3"); attroff(COLOR_PAIR(5)); break;
                        case '4': attron(COLOR_PAIR(5)); mvprintw(i, j, "4"); attroff(COLOR_PAIR(5)); break;
                        case '*': attron(COLOR_PAIR(6)); mvprintw(i, j, "*"); attroff(COLOR_PAIR(6)); break;
                        case 'c': attron(COLOR_PAIR(7)); mvprintw(i, j, "c"); attroff(COLOR_PAIR(7)); break;
                        case 't': attron(COLOR_PAIR(7)); mvprintw(i, j, "t"); attroff(COLOR_PAIR(7)); break;
                        case 'T': attron(COLOR_PAIR(7)); mvprintw(i, j, "T"); attroff(COLOR_PAIR(7)); break;
                        case 'D': attron(COLOR_PAIR(8)); mvprintw(i, j, "D"); attroff(COLOR_PAIR(8)); break;
            }
            b += 1;

        }
    }
    for(int i=player->actualy-3;i<=player->actualy+3;i++){
        attron(COLOR_PAIR(3)); mvprintw(i, player->actualx-3, "X"); attroff(COLOR_PAIR(3));
    }
    for(int i=player->actualy-3;i<=player->actualy+3;i++){
        attron(COLOR_PAIR(3)); mvprintw(i, player->actualx+3, "X"); attroff(COLOR_PAIR(3));
    }
    for(int i=player->actualx-3;i<=player->actualx+3;i++){
        attron(COLOR_PAIR(3)); mvprintw(player->actualy-3, i, "X"); attroff(COLOR_PAIR(3));
    }
    for(int i=player->actualx-3;i<=player->actualx+3;i++){
        attron(COLOR_PAIR(3)); mvprintw(player->actualy+3, i, "X"); attroff(COLOR_PAIR(3));
    }
    refresh();
    pthread_mutex_unlock(&mut);
}

void move_bot_on_map(struct map *map, struct player *player){
    int tab[4];
    int type;
    if(map->map[player->actualy-1][player->actualx] == 'X'){
        tab[0] = 0;
    }
    else{
        tab[0] = 1;
    }
    if(map->map[player->actualy][player->actualx+1] == 'X'){
        tab[1] = 0;
    }
    else{
        tab[1] = 1;
    }
    if(map->map[player->actualy+1][player->actualx] == 'X'){
        tab[2] = 0;
    }
    else{
        tab[2] = 1;
    }
    if(map->map[player->actualy][player->actualx-1] == 'X'){
        tab[3] = 0;
    }
    else{
        tab[3] = 1;
    }
    int x = -1;
    int y = -1;
    int tabvis[5][5] = {0};
    for(int i=0;i<5;i++){
        if(player->vision[0][i] == 'X'){
            tabvis[0][i] = 1;
        }
        if(player->vision[4][i] == 'X'){
            tabvis[4][i] = 1;
        }
        if(player->vision[i][0] == 'X'){
            tabvis[i][0] = 1;
        }
        if(player->vision[i][4] == 'X'){
            tabvis[i][4] = 1;
        }
    }
    if(player->vision[1][1] == 'X'){
        tabvis[0][0] = 1;
        tabvis[1][0] = 1;
        tabvis[0][1] = 1;
        tabvis[1][1] = 1;
    }
    if(player->vision[1][2] == 'X'){
        tabvis[0][1] = 1;
        tabvis[0][2] = 1;
        tabvis[0][3] = 1;
        tabvis[1][2] = 1;
    }
    if(player->vision[1][3] == 'X'){
        tabvis[0][3] = 1;
        tabvis[0][4] = 1;
        tabvis[1][4] = 1;
        tabvis[1][3] = 1;
    }
    if(player->vision[2][3] == 'X'){
        tabvis[1][4] = 1;
        tabvis[2][4] = 1;
        tabvis[3][4] = 1;
        tabvis[2][3] = 1;
    }
    if(player->vision[3][3] == 'X'){
        tabvis[3][4] = 1;
        tabvis[4][4] = 1;
        tabvis[4][3] = 1;
        tabvis[3][3] = 1;
    }
    if(player->vision[3][2] == 'X'){
        tabvis[4][1] = 1;
        tabvis[4][2] = 1;
        tabvis[4][3] = 1;
        tabvis[3][2] = 1;
    }
    if(player->vision[3][1] == 'X'){
        tabvis[3][0] = 1;
        tabvis[4][0] = 1;
        tabvis[4][1] = 1;
        tabvis[3][1] = 1;
    }
    if(player->vision[2][1] == 'X'){
        tabvis[1][0] = 1;
        tabvis[2][0] = 1;
        tabvis[3][0] = 1;
        tabvis[2][1] = 1;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(player->vision[i][j] == '*' && tabvis[i][j] == 0){
                player->t = run;
                x = j;
                y = i;
            }
        }
    }
    for(int i=1;i<3;i++){
        for(int j=1;j<3;j++){
            if(player->vision[i][j] == '*' && tabvis[i][j] == 0){
                player->t = run;
                x = j;
                y = i;
            }
        }
    }
    if(x == -1 && y == -1){
        player->t = movee;
    }
    srand(time(NULL));
    if(player->t == movee){
        type = rand()%4;
        while(1){
            if(tab[type] == 1){
                break;
            }
            else{
                type = rand()%4;
            }
        }
    }
    else if(player->t == run){
        if(y > 2 && tab[0] == 1){
            type = 0;
        }
        else if(y < 2 && tab[2] == 1){
            type = 2;
        }
        else if(x > 2 && tab[3] == 1){
            type = 3;
        }
        else if(x < 2 && tab[1] == 1){
            type = 1;
        }
        else{
            type = rand()%4;
            while(1){
                if(tab[type] == 1){
                    break;
                }
                else{
                    type = rand()%4;
                }
            }
        }
    }
    if(player->bush == 1){
        player->bush = 0;
    }
    else if(type == 0){
        map->map[player->actualy][player->actualx] = player->stand;
        if(player->stand == ' '){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(1)); mvprintw(player->actualy, player->actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == '#'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(3)); mvprintw(player->actualy, player->actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == 'A'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(4)); mvprintw(player->actualy, player->actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
            pthread_mutex_unlock(&mut);
        }
        player->actualy -= 1;
        if(map->map[player->actualy][player->actualx] == '#'){
            player->bush = 1;
        }
        else if(map->map[player->actualy][player->actualx] == 'A'){
            player->brought = player->carried;
            player->carried = 0;
        }
        else if(map->map[player->actualy][player->actualx] == 'c'){
            player->carried += 1;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 't'){
            player->carried += 10;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'T'){
            player->carried += 50;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'D'){
            for(int i=0;i<map->number_drop;i++){
                if(map->d[i].x == player->actualx && map->d[i].y == player->actualy){
                    player->carried += map->d[i].value;
                    map->number_drop -= 1;
                    for(int j=i;j<map->number_drop;j++){
                        map->d[j] = map->d[j+1];
                    }
                    break;
                }
            }
            map->map[player->actualy][player->actualx] = ' ';
        }
        player->stand = map->map[player->actualy][player->actualx];
        map->map[player->actualy][player->actualx] = player->id+'0';
        pthread_mutex_lock(&mut);
        attron(COLOR_PAIR(5)); mvprintw(player->actualy, player->actualx, "%d", player->id); attroff(COLOR_PAIR(5)); refresh();
        pthread_mutex_unlock(&mut);
    }
    else if(type == 1){
        map->map[player->actualy][player->actualx] = player->stand;
        if(player->stand == ' '){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(1)); mvprintw(player->actualy, player->actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == '#'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(3)); mvprintw(player->actualy, player->actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == 'A'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(4)); mvprintw(player->actualy, player->actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
            pthread_mutex_unlock(&mut);
        }
        player->actualx += 1;
        if(map->map[player->actualy][player->actualx] == '#'){
            player->bush = 1;
        }
        else if(map->map[player->actualy][player->actualx] == 'A'){
            player->brought = player->carried;
            player->carried = 0;
        }
        else if(map->map[player->actualy][player->actualx] == 'c'){
            player->carried += 1;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 't'){
            player->carried += 10;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'T'){
            player->carried += 50;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'D'){
            for(int i=0;i<map->number_drop;i++){
                if(map->d[i].x == player->actualx && map->d[i].y == player->actualy){
                    player->carried += map->d[i].value;
                    map->number_drop -= 1;
                    for(int j=i;j<map->number_drop;j++){
                        map->d[j] = map->d[j+1];
                    }
                    break;
                }
            }
            map->map[player->actualy][player->actualx] = ' ';
        }
        player->stand = map->map[player->actualy][player->actualx];
        map->map[player->actualy][player->actualx] = player->id+'0';
        pthread_mutex_lock(&mut);
        attron(COLOR_PAIR(5)); mvprintw(player->actualy, player->actualx, "%d", player->id); attroff(COLOR_PAIR(5)); refresh();
        pthread_mutex_unlock(&mut);
    }
    else if(type == 2){
        map->map[player->actualy][player->actualx] = player->stand;
        if(player->stand == ' '){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(1)); mvprintw(player->actualy, player->actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == '#'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(3)); mvprintw(player->actualy, player->actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == 'A'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(4)); mvprintw(player->actualy, player->actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
            pthread_mutex_unlock(&mut);
        }
        player->actualy += 1;
        if(map->map[player->actualy][player->actualx] == '#'){
        player->bush = 1;
        }
        else if(map->map[player->actualy][player->actualx] == 'A'){
            player->brought = player->carried;
            player->carried = 0;
        }
        else if(map->map[player->actualy][player->actualx] == 'c'){
            player->carried += 1;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 't'){
            player->carried += 10;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'T'){
            player->carried += 50;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'D'){
            for(int i=0;i<map->number_drop;i++){
                if(map->d[i].x == player->actualx && map->d[i].y == player->actualy){
                    player->carried += map->d[i].value;
                    map->number_drop -= 1;
                    for(int j=i;j<map->number_drop;j++){
                        map->d[j] = map->d[j+1];
                    }
                    break;
                }
            }
            map->map[player->actualy][player->actualx] = ' ';
        }
        player->stand = map->map[player->actualy][player->actualx];
        map->map[player->actualy][player->actualx] = player->id+'0';
        pthread_mutex_lock(&mut);
        attron(COLOR_PAIR(5)); mvprintw(player->actualy, player->actualx, "%d", player->id); attroff(COLOR_PAIR(5)); refresh();
        pthread_mutex_unlock(&mut);
    }
    else if(type == 3){
        map->map[player->actualy][player->actualx] = player->stand;
        if(player->stand == ' '){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(1)); mvprintw(player->actualy, player->actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == '#'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(3)); mvprintw(player->actualy, player->actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == 'A'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(4)); mvprintw(player->actualy, player->actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
            pthread_mutex_unlock(&mut);
        }
        player->actualx -= 1;
        if(map->map[player->actualy][player->actualx] == '#'){
            player->bush = 1;
        }
        else if(map->map[player->actualy][player->actualx] == 'A'){
            player->brought = player->carried;
            player->carried = 0;
        }
        else if(map->map[player->actualy][player->actualx] == 'c'){
            player->carried += 1;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 't'){
            player->carried += 10;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'T'){
            player->carried += 50;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'D'){
            for(int i=0;i<map->number_drop;i++){
                if(map->d[i].x == player->actualx && map->d[i].y == player->actualy){
                    player->carried += map->d[i].value;
                    map->number_drop -= 1;
                    for(int j=i;j<map->number_drop;j++){
                        map->d[j] = map->d[j+1];
                    }
                    break;
                }
            }
            map->map[player->actualy][player->actualx] = ' ';
        }
        player->stand = map->map[player->actualy][player->actualx];
        map->map[player->actualy][player->actualx] = player->id+'0';
        pthread_mutex_lock(&mut);
        attron(COLOR_PAIR(5)); mvprintw(player->actualy, player->actualx, "%d", player->id); attroff(COLOR_PAIR(5)); refresh();
        pthread_mutex_unlock(&mut);
    }
}

void move_player_on_map(struct map *map, struct player *player, int move){
    if(player->bush == 1){
        player->bush = 0;
    }
    else if(move == KEY_UP && map->map[player->actualy-1][player->actualx] != 'X'){
        map->map[player->actualy][player->actualx] = player->stand;
        if(player->stand == ' '){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(1)); mvprintw(player->actualy, player->actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == '#'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(3)); mvprintw(player->actualy, player->actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == 'A'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(4)); mvprintw(player->actualy, player->actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
            pthread_mutex_unlock(&mut);
        }
        player->actualy -= 1;
        if(map->map[player->actualy][player->actualx] == '#'){
            player->bush = 1;
        }
        else if(map->map[player->actualy][player->actualx] == 'A'){
            player->brought = player->carried;
            player->carried = 0;
        }
        else if(map->map[player->actualy][player->actualx] == 'c'){
            player->carried += 1;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 't'){
            player->carried += 10;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'T'){
            player->carried += 50;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'D'){
            for(int i=0;i<map->number_drop;i++){
                if(map->d[i].x == player->actualx && map->d[i].y == player->actualy){
                    player->carried += map->d[i].value;
                    map->number_drop -= 1;
                    for(int j=i;j<map->number_drop;j++){
                        map->d[j] = map->d[j+1];
                    }
                    break;
                }
            }
            map->map[player->actualy][player->actualx] = ' ';
        }
        player->stand = map->map[player->actualy][player->actualx];
        map->map[player->actualy][player->actualx] = player->id+'0';
        pthread_mutex_lock(&mut);
        attron(COLOR_PAIR(5)); mvprintw(player->actualy, player->actualx, "%d", player->id); attroff(COLOR_PAIR(5)); refresh();
        pthread_mutex_unlock(&mut);
    }
    else if(move == KEY_RIGHT && map->map[player->actualy][player->actualx+1] != 'X'){
        map->map[player->actualy][player->actualx] = player->stand;
        if(player->stand == ' '){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(1)); mvprintw(player->actualy, player->actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == '#'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(3)); mvprintw(player->actualy, player->actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == 'A'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(4)); mvprintw(player->actualy, player->actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
            pthread_mutex_unlock(&mut);
        }
        player->actualx += 1;
        if(map->map[player->actualy][player->actualx] == '#'){
            player->bush = 1;
        }
        else if(map->map[player->actualy][player->actualx] == 'A'){
            player->brought = player->carried;
            player->carried = 0;
        }
        else if(map->map[player->actualy][player->actualx] == 'c'){
            player->carried += 1;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 't'){
            player->carried += 10;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'T'){
            player->carried += 50;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'D'){
            for(int i=0;i<map->number_drop;i++){
                if(map->d[i].x == player->actualx && map->d[i].y == player->actualy){
                    player->carried += map->d[i].value;
                    map->number_drop -= 1;
                    for(int j=i;j<map->number_drop;j++){
                        map->d[j] = map->d[j+1];
                    }
                    break;
                }
            }
            map->map[player->actualy][player->actualx] = ' ';
        }
        player->stand = map->map[player->actualy][player->actualx];
        map->map[player->actualy][player->actualx] = player->id+'0';
        pthread_mutex_lock(&mut);
        attron(COLOR_PAIR(5)); mvprintw(player->actualy, player->actualx, "%d", player->id); attroff(COLOR_PAIR(5)); refresh();
        pthread_mutex_unlock(&mut);
    }
    else if(move == KEY_DOWN && map->map[player->actualy+1][player->actualx] != 'X'){
        map->map[player->actualy][player->actualx] = player->stand;
        if(player->stand == ' '){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(1)); mvprintw(player->actualy, player->actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == '#'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(3)); mvprintw(player->actualy, player->actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == 'A'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(4)); mvprintw(player->actualy, player->actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
            pthread_mutex_unlock(&mut);
        }
        player->actualy += 1;
        if(map->map[player->actualy][player->actualx] == '#'){
            player->bush = 1;
        }
        else if(map->map[player->actualy][player->actualx] == 'A'){
            player->brought = player->carried;
            player->carried = 0;
        }
        else if(map->map[player->actualy][player->actualx] == 'c'){
            player->carried += 1;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 't'){
            player->carried += 10;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'T'){
            player->carried += 50;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'D'){
            for(int i=0;i<map->number_drop;i++){
                if(map->d[i].x == player->actualx && map->d[i].y == player->actualy){
                    player->carried += map->d[i].value;
                    map->number_drop -= 1;
                    for(int j=i;j<map->number_drop;j++){
                        map->d[j] = map->d[j+1];
                    }
                    break;
                }
            }
            map->map[player->actualy][player->actualx] = ' ';
        }
        player->stand = map->map[player->actualy][player->actualx];
        map->map[player->actualy][player->actualx] = player->id+'0';
        pthread_mutex_lock(&mut);
        attron(COLOR_PAIR(5)); mvprintw(player->actualy, player->actualx, "%d", player->id); attroff(COLOR_PAIR(5)); refresh();
        pthread_mutex_unlock(&mut);
    }
    else if(move == KEY_LEFT && map->map[player->actualy][player->actualx-1] != 'X'){
        map->map[player->actualy][player->actualx] = player->stand;
        if(player->stand == ' '){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(1)); mvprintw(player->actualy, player->actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == '#'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(3)); mvprintw(player->actualy, player->actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(player->stand == 'A'){
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(4)); mvprintw(player->actualy, player->actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
            pthread_mutex_unlock(&mut);
        }
        player->actualx -= 1;
        if(map->map[player->actualy][player->actualx] == '#'){
            player->bush = 1;
        }
        else if(map->map[player->actualy][player->actualx] == 'A'){
            player->brought = player->carried;
            player->carried = 0;
        }
        else if(map->map[player->actualy][player->actualx] == 'c'){
            player->carried += 1;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 't'){
            player->carried += 10;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'T'){
            player->carried += 50;
            map->map[player->actualy][player->actualx] = ' ';
        }
        else if(map->map[player->actualy][player->actualx] == 'D'){
            for(int i=0;i<map->number_drop;i++){
                if(map->d[i].x == player->actualx && map->d[i].y == player->actualy){
                    player->carried += map->d[i].value;
                    map->number_drop -= 1;
                    for(int j=i;j<map->number_drop;j++){
                        map->d[j] = map->d[j+1];
                    }
                    break;
                }
            }
            map->map[player->actualy][player->actualx] = ' ';
        }
        player->stand = map->map[player->actualy][player->actualx];
        map->map[player->actualy][player->actualx] = player->id+'0';
        pthread_mutex_lock(&mut);
        attron(COLOR_PAIR(5)); mvprintw(player->actualy, player->actualx, "%d", player->id); attroff(COLOR_PAIR(5)); refresh();
        pthread_mutex_unlock(&mut);
    }
}

void move_beast_on_map(struct map *map, int ch){
    int tab[4];
    int type;
    if(map->map[map->b[ch].actualy-1][map->b[ch].actualx] == 'X'){
        tab[0] = 0;
    }
    else{
        tab[0] = 1;
    }
    if(map->map[map->b[ch].actualy][map->b[ch].actualx+1] == 'X'){
        tab[1] = 0;
    }
    else{
        tab[1] = 1;
    }
    if(map->map[map->b[ch].actualy+1][map->b[ch].actualx] == 'X'){
        tab[2] = 0;
    }
    else{
        tab[2] = 1;
    }
    if(map->map[map->b[ch].actualy][map->b[ch].actualx-1] == 'X'){
        tab[3] = 0;
    }
    else{
        tab[3] = 1;
    }
    int x = -1;
    int y = -1;
    int tabvis[5][5] = {0};
    for(int i=0;i<5;i++){
        if(map->b[ch].vision[0][i] == 'X'){
            tabvis[0][i] = 1;
        }
        if(map->b[ch].vision[4][i] == 'X'){
            tabvis[4][i] = 1;
        }
        if(map->b[ch].vision[i][0] == 'X'){
            tabvis[i][0] = 1;
        }
        if(map->b[ch].vision[i][4] == 'X'){
            tabvis[i][4] = 1;
        }
    }
    if(map->b[ch].vision[1][1] == 'X'){
        tabvis[0][0] = 1;
        tabvis[1][0] = 1;
        tabvis[0][1] = 1;
        tabvis[1][1] = 1;
    }
    if(map->b[ch].vision[1][2] == 'X'){
        tabvis[0][1] = 1;
        tabvis[0][2] = 1;
        tabvis[0][3] = 1;
        tabvis[1][2] = 1;
    }
    if(map->b[ch].vision[1][3] == 'X'){
        tabvis[0][3] = 1;
        tabvis[0][4] = 1;
        tabvis[1][4] = 1;
        tabvis[1][3] = 1;
    }
    if(map->b[ch].vision[2][3] == 'X'){
        tabvis[1][4] = 1;
        tabvis[2][4] = 1;
        tabvis[3][4] = 1;
        tabvis[2][3] = 1;
    }
    if(map->b[ch].vision[3][3] == 'X'){
        tabvis[3][4] = 1;
        tabvis[4][4] = 1;
        tabvis[4][3] = 1;
        tabvis[3][3] = 1;
    }
    if(map->b[ch].vision[3][2] == 'X'){
        tabvis[4][1] = 1;
        tabvis[4][2] = 1;
        tabvis[4][3] = 1;
        tabvis[3][2] = 1;
    }
    if(map->b[ch].vision[3][1] == 'X'){
        tabvis[3][0] = 1;
        tabvis[4][0] = 1;
        tabvis[4][1] = 1;
        tabvis[3][1] = 1;
    }
    if(map->b[ch].vision[2][1] == 'X'){
        tabvis[1][0] = 1;
        tabvis[2][0] = 1;
        tabvis[3][0] = 1;
        tabvis[2][1] = 1;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if((map->b[ch].vision[i][j] == '1' || map->b[ch].vision[i][j] == '2' || map->b[ch].vision[i][j] == '3' || map->b[ch].vision[i][j] == '4') && tabvis[i][j] == 0){
                map->b[ch].t = hunt;
                x = j;
                y = i;
            }
        }
    }
    for(int i=1;i<3;i++){
        for(int j=1;j<3;j++){
            if((map->b[ch].vision[i][j] == '1' || map->b[ch].vision[i][j] == '2' || map->b[ch].vision[i][j] == '3' || map->b[ch].vision[i][j] == '4') && tabvis[i][j] == 0){
                map->b[ch].t = hunt;
                x = j;
                y = i;
            }
        }
    }
    if(x == -1 && y == -1){
        map->b[ch].t = stay;
    }
    if(map->b[ch].t == hunt){
        if(y > 2 && tab[2] == 1){
            type = 2;
        }
        else if(y < 2 && tab[0] == 1){
            type = 0;
        }
        else if(x > 2 && tab[1] == 1){
            type = 1;
        }
        else if(x < 2 && tab[3] == 1){
            type = 3;
        }
        else{
            type = -1;
        }
        if(map->b[ch].bush == 1){
            map->b[ch].bush = 0;
        }
        else if(type == 0){
            map->map[map->b[ch].actualy][map->b[ch].actualx] = map->b[ch].stand;
            if(map->b[ch].stand == ' '){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(1)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == '#'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(3)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'A'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(4)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 't'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "t"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'c'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "c"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'T'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "T"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'D'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(8)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "D"); attroff(COLOR_PAIR(8)); refresh();
                pthread_mutex_unlock(&mut);
            }
            map->b[ch].actualy -= 1;
            if(map->map[map->b[ch].actualy][map->b[ch].actualx] == '#'){
                map->b[ch].bush = 1;
            }
            map->b[ch].stand = map->map[map->b[ch].actualy][map->b[ch].actualx];
            map->map[map->b[ch].actualy][map->b[ch].actualx] ='*';
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(6)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "*"); attroff(COLOR_PAIR(6)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(type == 1){
            map->map[map->b[ch].actualy][map->b[ch].actualx] = map->b[ch].stand;
            if(map->b[ch].stand == ' '){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(1)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == '#'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(3)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'A'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(4)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 't'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "t"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'c'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "c"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'T'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "T"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'D'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(8)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "D"); attroff(COLOR_PAIR(8)); refresh();
                pthread_mutex_unlock(&mut);
            }
            map->b[ch].actualx += 1;
            if(map->map[map->b[ch].actualy][map->b[ch].actualx] == '#'){
                map->b[ch].bush = 1;
            }
            map->b[ch].stand = map->map[map->b[ch].actualy][map->b[ch].actualx];
            map->map[map->b[ch].actualy][map->b[ch].actualx] ='*';
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(6)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "*"); attroff(COLOR_PAIR(6)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(type == 2){
            map->map[map->b[ch].actualy][map->b[ch].actualx] = map->b[ch].stand;
            if(map->b[ch].stand == ' '){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(1)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == '#'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(3)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'A'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(4)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 't'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "t"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'c'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "c"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'T'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "T"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'D'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(8)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "D"); attroff(COLOR_PAIR(8)); refresh();
                pthread_mutex_unlock(&mut);
            }
            map->b[ch].actualy += 1;
            if(map->map[map->b[ch].actualy][map->b[ch].actualx] == '#'){
                map->b[ch].bush = 1;
            }
            map->b[ch].stand = map->map[map->b[ch].actualy][map->b[ch].actualx];
            map->map[map->b[ch].actualy][map->b[ch].actualx] ='*';
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(6)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "*"); attroff(COLOR_PAIR(6)); refresh();
            pthread_mutex_unlock(&mut);
        }
        else if(type == 3){
            map->map[map->b[ch].actualy][map->b[ch].actualx] = map->b[ch].stand;
            if(map->b[ch].stand == ' '){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(1)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == '#'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(3)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'A'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(4)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "A"); attroff(COLOR_PAIR(4)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 't'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "t"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'c'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "c"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'T'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(7)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "T"); attroff(COLOR_PAIR(7)); refresh();
                pthread_mutex_unlock(&mut);
            }
            else if(map->b[ch].stand == 'D'){
                pthread_mutex_lock(&mut);
                attron(COLOR_PAIR(8)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "D"); attroff(COLOR_PAIR(8)); refresh();
                pthread_mutex_unlock(&mut);
            }
            map->b[ch].actualx -= 1;
            if(map->map[map->b[ch].actualy][map->b[ch].actualx] == '#'){
                map->b[ch].bush = 1;
            }
            map->b[ch].stand = map->map[map->b[ch].actualy][map->b[ch].actualx];
            map->map[map->b[ch].actualy][map->b[ch].actualx] ='*';
            pthread_mutex_lock(&mut);
            attron(COLOR_PAIR(6)); mvprintw(map->b[ch].actualy, map->b[ch].actualx, "*"); attroff(COLOR_PAIR(6)); refresh();
            pthread_mutex_unlock(&mut);
        }
    }
    int a = 0;
    int b = 0;
    for(int i = map->b[ch].actualy-2;i <= map->b[ch].actualy+2;i++){
        for(int j = map->b[ch].actualx-2;j <= map->b[ch].actualx+2;j++){
            map->b[ch].vision[a][b] = map->map[i][j];
            b += 1;
        }
        b = 0;
        a += 1;
        }
    map->b[ch].vision[2][2] = '*';
}

void player_map_update(struct map *map, struct player *player){
    int a = 0;
    int b = 0;
    for(int i = player->actualy-2;i <= player->actualy+2;i++){
        for(int j = player->actualx-2;j <= player->actualx+2;j++){
            player->vision[a][b] = map->map[i][j];
            b += 1;
        }
        b = 0;
        a += 1;
    }
    player->vision[2][2] = player->id+'0';
}

void destroy_players(struct player *x1, struct player *x2, struct map *map){
    pthread_mutex_lock(&mut);
    if(x1->carried + x2->carried != 0){
        map->d[map->number_drop].x = x1->actualx;
        map->d[map->number_drop].y = x1->actualy;
        map->d[map->number_drop].value = x1->carried + x2->carried;
        map->number_drop += 1;
        map->map[x1->actualy][x1->actualx] = 'D';
        attron(COLOR_PAIR(8)); mvprintw(x1->actualy, x1->actualx, "D"); attroff(COLOR_PAIR(8)); refresh();
        x1->stand = ' ';
        x2->stand = ' ';
    }
    else{
        if(x1->stand == '#' || x2->stand == '#'){
            map->map[x1->actualy][x1->actualx] = '#';
            attron(COLOR_PAIR(3)); mvprintw(x1->actualy, x1->actualx, "#"); attroff(COLOR_PAIR(3)); refresh();
            x1->stand = ' ';
            x2->stand = ' ';
        }
        else if(x1->stand == ' ' || x2->stand == ' '){
            map->map[x1->actualy][x1->actualx] = ' ';
            attron(COLOR_PAIR(1)); mvprintw(x1->actualy, x1->actualx, "X"); attroff(COLOR_PAIR(1)); refresh();
            x1->stand = ' ';
            x2->stand = ' ';
        }
    }

    x1->actualx = x1->spawnx;
    x1->actualy = x1->spawny;
    x1->carried = 0;
    x1->deaths += 1;
    x1->stand = ' ';

    map->map[x1->spawny][x1->spawnx] = x1->id+'0';
    attron(COLOR_PAIR(5)); mvprintw(x1->spawny, x1->spawnx, "%c", x1->id+'0'); attroff(COLOR_PAIR(5)); refresh();

    x2->actualx = x2->spawnx;
    x2->actualy = x2->spawny;
    x2->carried = 0;
    x2->deaths += 1;
    x2->stand = ' ';

    map->map[x2->spawny][x2->spawnx] = x2->id+'0';
    attron(COLOR_PAIR(5)); mvprintw(x2->spawny, x2->spawnx, "%c", x2->id+'0'); attroff(COLOR_PAIR(5)); refresh();

    pthread_mutex_unlock(&mut);
}

void destroy_beast(struct map *map, struct player *player, int bn){
    pthread_mutex_lock(&mut);
    map->b[bn].stand = player->stand;
    player->actualx = player->spawnx;
    player->actualy = player->spawny;
    player->carried = 0;
    player->deaths += 1;
    player->stand = ' ';
    map->map[player->spawny][player->spawnx] = player->id+'0';
    attron(COLOR_PAIR(5)); mvprintw(player->spawny, player->spawnx, "%c", player->id+'0'); attroff(COLOR_PAIR(5)); refresh();
    pthread_mutex_unlock(&mut);
}
