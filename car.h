#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// Matrix Game
#define ROWS 25
#define COLUMNS 15
// Matrix Menu e GameOver
#define ROWS1 25
#define COLUMNS1 15
// Movimentação carros
#define TECLA_a 97
#define TECLA_d 100
#define TECLA_A 65
#define TECLA_D 68
// Aumento de velocidade
#define TECLA_W 87
#define TECLA_w 119
// Posições carro jogador
#define LEFT 1
#define RIGHT 2
// Simbolos
#define PIXEL 219
#define EMPTY 32

typedef struct{
    int i;
    int j;
    int position;
    int height;
    int width;
} car; 

void startMtrx(char matrix[ROWS][COLUMNS]);

void printMtx(char matrix[ROWS][COLUMNS], int detect, int pontos);

int orderWall(int ordem);

void CarPlayer(char matrix[ROWS][COLUMNS], car block, char symbol);

void CarPlayerLeft(car *block);

void CarPlayerRight(car *block);

void CarEnemy(char matrix[ROWS][COLUMNS], car block, char symbol);

void CarEnemyLeft(car *block);

void CarEnemyRight(car *block);

void CarEnemyClear(char matrix[ROWS][COLUMNS], car block);

int GameOver(char matrix[ROWS][COLUMNS], int pontos);

void InitCarPlayer(car *block);

void EnemyRandom(car *enemy);

int Collision(car enemy, car player);

void ResetEnemy(car enemy);

void VelocityGame(int *moment);

void Menu();