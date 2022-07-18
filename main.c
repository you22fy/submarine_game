#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "position.h"
#include "field.h"

int main(){
    //変数宣言
    Position cie;
    Field field;
    int turn_counter = 0;
    int level;
    int submarine_move_counter=0 , submarine_move_flag;


    //難易度選択
    fieldSelecetLevel(&level);

    //潜水艦が移動するターン数を乱数で生成
    srand(time(NULL));
    submarine_move_flag = rand()%9;
    submarine_move_flag++;

    //盤の初期化
    fieldInitialize(&field);
    //盤の表示
    fieldDisplay(&field);

    //入力
    while(field.squares[field.submarine.row][field.submarine.col+0]==-1){
        if(turn_counter < level){
            if( submarine_move_counter == submarine_move_flag){
                fieldSubmarineUpdate(&field, &submarine_move_flag);
                submarine_move_counter =0;
            }

            printf("%d ターン目\n",turn_counter+1);
            fieldInput(&cie , &field); 
            turn_counter++;
            submarine_move_counter++;

            if(isHit(&field, &cie)==1){
                fieldDisplay(&field);
                printf("潜水艦の位置は(%d,%c)\n",field.submarine.row+1,field.submarine.col+65);
                printf("撃沈しました\n");
            }
            else{
                fieldDisplay(&field);
                printf("入力位置から潜水艦までの距離は%d\n",calculateDistance(&field, &cie));
            }
        }
        else{
            printf("You Lost\n");
            break;
        }
    }
}
