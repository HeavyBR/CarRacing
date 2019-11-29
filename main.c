#include "car.h"
#include "display.h"

int main(){
    char m[ROWS][COLUMNS];
    int ciclos=0;
    car player;
    car enemy1;
    car enemy2;
    int Rmov=0;
    int Lmov=0;
    int collision=0;
    int wall=0;
    int keypress=0;

    system("color FD");

    InitCarPlayer(&player);
    CarEnemyRight(&enemy1);
    CarEnemyLeft(&enemy2);
    startMtrx(m);
    ShowConsoleCursor(0);
    system("cls");

    while(keypress != 27){
        gotoxy(0,0);

        CarEnemy(m, enemy1, PIXEL);
        CarPlayer(m, player, PIXEL);

        printMtx(m, wall);

        // Verificando colisão
        if(Collision(enemy1, player) == 1 || Collision(enemy2, player) == 1){
            goto gameover;
        }

        CarEnemy(m, enemy1, EMPTY);
        CarPlayer(m, player, EMPTY);

        // Depois do desaparecimento completo, reinia carrinho
        if(enemy1.i == ROWS+3){
            EnemyAlone(m, &enemy1);
        }
        

        if(ciclos!=VELOCITY){
            ciclos++;
        } else {
            wall = orderWall(wall);
            enemy1.i++;
            ciclos=0;
        }

        keypress = EMPTY;
        if(_kbhit()){
            keypress = getch();
        }

        switch(keypress){
            case TECLA_A:
            case TECLA_a:{
                CarPlayerLeft(&player);
                break;
            }
            case TECLA_D:
            case TECLA_d:{
                CarPlayerRight(&player);
                break;
            }
                    
        }

    }

    gameover: GameOver(m);

    system("pause");

    return 0;
}