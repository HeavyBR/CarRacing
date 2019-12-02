#include "car.h"
//==========================================================
// Iniciando a Matriz
void startMtrx(char matrix[ROWS][COLUMNS]){
    int i, j;

    /* Criando a Matrix principal do jogo e atribuindo
       valor nulo a cada espaço da matrix */
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            matrix[i][j] = ' ';
        }
    }
}
//==========================================================
// Visual e animações
void printMtx(char matrix[ROWS][COLUMNS], int detect, int pontos){
    int i, j, resto;

    printf("\n\t\t\t");
    for(j=0;j<COLUMNS+4;j++){ /* linha de cima */
        printf("\xB1");
    }
    printf(" ");
    for(i=0;i<14;i++){
        printf("\xDC");
    }
    printf("\n");

    for(i=0;i<ROWS;i++){ /* Linhas da matriz */
        resto = i%2;
        if(detect==1){
            if(resto==0){
                printf("\t\t\t\xB1\xDB");
            } else {
                printf("\t\t\t\xB1 ");
            }
        } else {
            if(resto==0){
                printf("\t\t\t\xB1 ");
            } else {
                printf("\t\t\t\xB1\xDB");
            }
        }

        for(j=0;j<COLUMNS;j++){
            printf("%c", matrix[i][j]);
        }

        if(detect==1){
            if(resto==0){
                printf("\xDB\xB1");
            } else {
                printf(" \xB1");
            }
        } else {
            if(resto==0){
                printf(" \xB1");
            } else {
                printf("\xDB\xB1");
            }
        }
        // Print score e nivel
        if(i==1){
            if(pontos >= 450)
                printf("    NIVEL 2");
            else 
                printf("    NIVEL 1");
        }
        if(i==3){
            printf(" ");
            for(j=0;j<14;j++){
                printf("\xDF");
            } 
        }
        if(i==4){
            printf("  SCORE: %d", pontos);
        }
        if(i==6){
            printf(" ");
            for(j=0;j<14;j++){
                printf("\xDF");
            }  
        }
        printf("\n");
    }

    printf("\t\t\t");
    for(j=0;j<COLUMNS+4;j++){ /* linha de baixo */
        printf("\xB1");
    }
    printf("\n");
}
//==========================================================
// Inverção de animação de Parede
int orderWall(int order){
    if(order==1){
        order=0;
    } else {
        order=1;
    }
    return order;
}
//==========================================================
// Iniciando carro Player
void InitCarPlayer(car *block){
    block->i = 24;
    block->j = 4;
    block->position = LEFT;
    block->width = 5;
    block->height = 4;
}
//==========================================================
// Posicionando carro player e inimigo
void CarPlayerLeft(car *block){
    block->i = 24;
    block->j = 4;
    block->position = LEFT;
    block->width = 5;
    block->height = 4;
}
void CarEnemyLeft(car *block){
    block->i = -1;
    block->j = 4;
    block->position = LEFT;
    block->width = 5;
    block->height = 4;
}
//------
void CarPlayerRight(car *block){
    block->i = 24;
    block->j = 10;
    block->position = RIGHT;
    block->width = 5;
    block->height = 4;
}
void CarEnemyRight(car *block){
    block->i = -1;
    block->j = 10;
    block->position = RIGHT;
    block->width = 5;
    block->height = 4;
}
//==========================================================
// Construindo carro Player
void CarPlayer(char matrix[ROWS][COLUMNS], car block, char symbol){
    matrix[block.i][block.j+1] = symbol;
    matrix[block.i][block.j+2] = symbol;
    matrix[block.i][block.j-1] = symbol;
    matrix[block.i][block.j-2] = symbol;
    matrix[block.i-1][block.j] = symbol;
    matrix[block.i-2][block.j] = symbol;
    matrix[block.i-2][block.j+1] = symbol;
    matrix[block.i-2][block.j+2] = symbol;
    matrix[block.i-2][block.j-1] = symbol;
    matrix[block.i-2][block.j-2] = symbol;
    matrix[block.i-3][block.j] = symbol;
}
//==========================================================
// Construindo carro Enemy
void CarEnemy(char matrix[ROWS][COLUMNS], car block, char symbol){
    if(block.i>=0 && block.i <= ROWS-1)matrix[block.i][block.j+1] = symbol;
    if(block.i>=0 && block.i <= ROWS-1)matrix[block.i][block.j+2] = symbol;
    if(block.i>=0 && block.i <= ROWS-1)matrix[block.i][block.j-1] = symbol;
    if(block.i>=0 && block.i <= ROWS-1)matrix[block.i][block.j-2] = symbol;
    if(block.i-1>=0 && block.i-1 <= ROWS-1)matrix[block.i-1][block.j] = symbol;
    if(block.i-2 >= 0 && block.i-2 <= ROWS-1)matrix[block.i-2][block.j] = symbol;
    if(block.i-2 >= 0 && block.i-2 <= ROWS-1)matrix[block.i-2][block.j+1] = symbol;
    if(block.i-2 >= 0 && block.i-2 <= ROWS-1)matrix[block.i-2][block.j+2] = symbol;
    if(block.i-2 >= 0 && block.i-2 <= ROWS-1)matrix[block.i-2][block.j-1] = symbol;
    if(block.i-2 >= 0 && block.i-2 <= ROWS-1)matrix[block.i-2][block.j-2] = symbol;
    if(block.i-3 >= 0 && block.i-3 <= ROWS-1)matrix[block.i-3][block.j] = symbol;
}
//==========================================================
// Randomizando posição do Carro inimigo
void EnemyRandom(car *enemy){

    int posit=0;
    srand(time(NULL));

    posit= (rand() % 6);
    
    if(posit%2 != 0){
        CarEnemyLeft(enemy);
    } else {
        CarEnemyRight(enemy);
    }

}
//==========================================================
// Reset Car Enemy
void ResetEnemy(car enemy){
    if(enemy.i == ROWS+3){
        EnemyRandom(&enemy);
    }
}
//==========================================================
//Verifica colisão
int Collision(car enemy, car player){
    if(enemy.i >= 21 && player.position == enemy.position){
        return 1;
    } else {
        return 0;
    }
}
//==========================================================
// função de game over, apos batida.
int GameOver(char matrix[ROWS][COLUMNS], int pontos){
    mark:
    system("cls");
    int i=0;
    int opc=0;
    
    printf("\n\t");
    for(i=0;i<25;i++){
        printf("\xB1");
    }

    printf("\n\t\xB1\t\t\t\xB1\n");
    printf("\t\xB1     \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\t\xB1\n");
    printf("\t\xB1     \xB3 GAME OVER \xB3\t\xB1\n");
    printf("\t\xB1     \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\t\xB1\n");
    printf("\t\xB1\t\t\t\xB1\n");
    printf("\t\xB1      PONTOS: %d\t\xB1\n", pontos);
    printf("\t\xB1\t\t\t\xB1\n");
    printf("\t\xB1      1-Novo Jogo\t\xB1\n");
    printf("\t\xB1\t 2-Menu  \t\xB1\n");
    printf("\t\xB1\t\t\t\xB1\n");

    printf("\t");
    for(i=0;i<25;i++){
        printf("\xB1");
    }
    printf("\n");

    printf("\tOpcao: ");
    scanf("%d", &opc);
    if(opc<1 || opc>3){
        printf("Valor Invalido! Digite uma das opcoes listadas.");
        getch();
        goto mark;
    }

    return opc;
}
//==========================================================
// Menu game
int MenuGame(){
    mark:
    system("cls");
    int i=0;
    int opc=0;
    
    printf("\n\t");
    for(i=0;i<25;i++){
        printf("\xB1");
    }

    printf("\n\t\xB1\t\t\t\xB1\n");
    printf("\t\xB1    \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\t\xB1\n");
    printf("\t\xB1          MENU     \t\xB1\n");
    printf("\t\xB1    \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\t\xB1\n");
    printf("\t\xB1\t\t\t\xB1\n");
    printf("\t\xB1      1-Novo Jogo\t\xB1\n");
    printf("\t\xB1      2-Highscore\t\xB1\n");
    printf("\t\xB1         3-Sair  \t\xB1\n");
    printf("\t\xB1\t\t\t\xB1\n");

    printf("\t");
    for(i=0;i<25;i++){
        printf("\xB1");
    }
    printf("\n");

    printf("\tOpcao: ");
    scanf("%d", &opc);
    if(opc<1 || opc>3){
        printf("Valor Invalido! Digite uma das opcoes listadas.");
        getch();
        goto mark;
    }

    return opc;
}
//==========================================================
// void numsei(){
//     FILE *arquivo;

//     if((arquivo = fopen("Pontuacao.txt", "r")) == NULL){
//         printf("\nError: File cannot be found or opened");
//     } else {
        
//     }
// }
