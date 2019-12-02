#include "car.h"
#include "display.h"

int main(){
    char m[ROWS][COLUMNS];
    int ciclos=0;
    car player;
    car enemy[3];
    int status[3]; // Verificador de status
    int i=0;
    int j=0;
    int velocity=3; // velocidade de ciclos normal
    int wall=0;
    int keypress=0;
    int score=0;
    int option=0;

    system("color FD");
    Menu:option=MenuGame();
    if(option == 2){
        Highscore();
        goto Menu;
    } else if(option == 3){
        exit(0);
    }
    NovoJogo:
    status[1]=0;
    status[2]=0;
    velocity=3;
    score=0;
    option=0;
    keypress=0;
    wall=0;
    ciclos=0;

    InitCarPlayer(&player);
    for(i=0;i<3;i++)
        EnemyRandom(&enemy[i]);
    startMtrx(m);
    status[0] = 1; //Inicia o ciclo dos carros inimigos
    ShowConsoleCursor(0);
    system("cls");

    

    while(keypress != 27){
        gotoxy(0,0);

        for(i=0;i<3;i++){
            if(status[i] == 1){
                CarEnemy(m, enemy[i], PIXEL);
            }
        }
        CarPlayer(m, player, PIXEL);

        printMtx(m, wall, score);

        // Verificando colisão
        for(i=0;i<3;i++){
            if(Collision(enemy[i], player) == 1){
                option=GameOver(m, score);
                if(option == 1){
                    system("cls");
                    goto NovoJogo;                
                } else {
                    goto Menu;
                }
            }
        }


        for(i=0;i<3;i++){
            if(status[i] == 1){
                CarEnemy(m, enemy[i], EMPTY);
            }
        }
        CarPlayer(m, player, EMPTY);

        // Reiniciando carrinho, 
        for(i=0;i<3;i++){
            if(status[i] == 1){
                switch(enemy[i].i){
                    case 27:{
                        status[i]=0;
                        EnemyRandom(&enemy[i]);
                        score+=30;
                        break;
                    }
                    case 11:{
                        if(i==2)
                            status[i-2]=1;
                        else
                            status[i+1]=1;
                            
                    }
                }
            }
        }

        if(ciclos%velocity == 0){
            wall = orderWall(wall);
            for(i=0;i<3;i++){
                if(status[i] == 1){
                    enemy[i].i++;
                }
            }
        }

        if(score == 450){
            velocity = 2;
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
            case TECLA_W:
            case TECLA_w:{
                if(score <= 450){
                    if(velocity == 3){
                        velocity = 2;
                    } else {
                        velocity = 3;
                    }
                }
            }        
        }
        ciclos++;
    }

    system("pause");

    return 0;
}