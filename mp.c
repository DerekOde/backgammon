#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

typedef struct piece
{
    int position;
    bool inBar;
    bool bearOff;
    bool blackPiece;
}piece;

typedef struct player
{
    piece pc[15];
    bool turn;
}player;

typedef struct game
{
    player play1;
    player play2;
    bool over;
}game;

void randomizeDice(int dice[2])
{
    dice[0] = rand() % 6 + 1;
    dice[1] = rand() % 6 + 1;
}

void printBackgammonBoard(int board[24])
{
    for (int i = 24; i > 11; i++)
    {
        printf("%d ", board[i]);
    }

    for (int i = 0; i < 12; i++)
    {
        printf("%d ", board[i]);

    }


}

int main()
{
    int dice[2];
    int triangles[2][24] = {{0,0,0,0,0,5,
                        0,3,0,0,0,0,
                        5,0,0,0,0,0,
                        0,0,0,0,0,2}, 
                        {2,0,0,0,0,0,
                        0,0,0,0,0,5,
                        0,0,0,0,3,0,
                        5,0,0,0,0,0}};
    game backgammon;
    backgammon.over = false;
    backgammon.play1.turn = true;
    backgammon.play2.turn = false;
    
    for(int i = 0; i < 15; i++)
    {
        backgammon.play1.pc[i].inBar = false;
        backgammon.play2.pc[i].inBar = false;
    }

    for(int i = 0; i < 15; i++)
    {
        backgammon.play1.pc[i].bearOff = false;
        backgammon.play2.pc[i].bearOff = false;
    }

    for(int i = 0; i < 15; i++)
    {
        backgammon.play1.pc[i].blackPiece = true;
        backgammon.play2.pc[i].blackPiece = false;
    }

    while(backgammon.over == false)
    {
        for (int i = 0; i < 12; i++){
            if (i + 6 > 10){
                printf(" %d ", i + 6);
            }else{
                printf(" 0%d  ", i + 6);
            }
        }
        printf("\n");
        for(int x = 0; x < 15; x++){
            for(int i = 0; i < 12; i++){
                for(int j = 0; j < 15; j++){
                    if (backgammon.play1.pc[j].position == i && backgammon.play1.pc[j].inBar == false && backgammon.play1.pc[j].bearOff == false){
                        printf(" X ");
                    }
                    else if (backgammon.play2.pc[j].position == i && backgammon.play2.pc[j].inBar == false && backgammon.play2.pc[j].bearOff == false){
                        printf(" O ");
                    }
                    else{
                        printf("   ");
                    }
                }
            }
            printf("\n");
        }
        printf("\n");
        char t;
        scanf(" %c", &t);

    }


    return 0;
}