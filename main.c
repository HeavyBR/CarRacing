#include "car.h"
#include "display.h"

int main(){
    char m[ROWS][COLUMNS];
    int ciclos=0;
    car player;
    car enemy;
    int wall=0;
    int keypress=0;

    system("color FD");

    CarPlayerLeft(&player);
    CarEnemyRight(&enemy);
    startMtrx(m);
    ShowConsoleCursor(0);
    system("cls");

    while(keypress != 27){
        gotoxy(0,0);
        
        CarEnemy(m, enemy, PIXEL);
        CarPlayer(m, player, PIXEL);

        printMtx(m, wall);

        CarEnemy(m, enemy, EMPTY);
        CarPlayer(m, player, EMPTY);
        

        if(ciclos!=VELOCITY){
            ciclos++;
        } else {
            wall = orderWall(wall);
            enemy.i++;
            ciclos=0;
        }

        if(kbhit()){
            keypress = getch();
        }

        switch(keypress){
            case TECLA_A:
            case TECLA_a:
                    CarPlayerLeft(&player);
                    break;
            case TECLA_D:
            case TECLA_d:
                    CarPlayerRight(&player);
                    break;
        }

    }

    system("pause");

    return 0;
}