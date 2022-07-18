#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "field.h"

void fieldSelecetLevel(int *level){
    printf("Please Select Level \n");
    printf("EASY -> 1\nNORMAL -> 2\nHARD -> 3\n");
    int tmp;
    do{
        scanf("%d%*c",&tmp);
        if(tmp == 1){
            *level = EASY;
            break;
        } 
        else if(tmp == 2){
            *level = NORMAL;
            break;
        }
        else if(tmp == 3){
            *level = HARD;
            break;
        }
        else{
            printf("Illegal Input!\n");
        }

    }
    while(1);
}

void fieldInitialize(Field *field){
    int i,j,n;
    for(i=0;i<MAX_ROW;i++){
        for(j=0;j<MAX_COL;j++){
            field->squares[i][j]=EMPTY;
        }
    }
    
    //潜水艦の位置を乱数で生成(0~8)
    srand(time(NULL));
    for(n = 0; n < 20; ++n){
        field->submarine.row = rand() % 9;
        field->submarine.col = rand() % 9;
    }    

    //潜水艦のいる位置を-1でマーク
    field->squares[ field->submarine.row][field->submarine.col+0]= -1;

}

void fieldSubmarineUpdate(Field *field , int *submarine_move_flag){
    int row_tmp,col_tmp;
    srand(time(NULL));
    while(1){
        row_tmp = rand() % 9;
        col_tmp = rand()%9;
        if(field->squares[row_tmp][col_tmp] == SELECTED || field->squares[row_tmp][col_tmp] == -1){
        }
        else{
            field->submarine.row = rand() % 9;
            field->submarine.col = rand() % 9;
            field->squares[ field->submarine.row][field->submarine.col+0]= -1;
            printf("潜水艦が移動したようだ \n");
            break;
        }
    }
    srand(time(NULL));
    *submarine_move_flag = rand()%5;

}

void fieldDisplay(const Field *field){
    int i,j;
    for(i=0;i<MAX_ROW+1;i++){
        for(j=0;j<MAX_COL+1;j++){
            if(i==0 && j==0){
                printf("  ");
            }
            else if(i==0 && j >0){
                printf("%2c",'A'+j-1);
            }
            else if (j==0 && i >0){
                printf("%2d|",i);
            }
            else{
                if(field->squares[i-1][j-1]==SELECTED){
                    printf("*|");
                }
                else if(field->squares[i-1][j-1]==HIT){
                    printf("x|");
                }
                else{
                    printf(" |");
                }
            }
        }
        printf("\n");
    }

}

void fieldInput(Position *position , const Field *field){

    char buf[256];
    while ( fgets( buf, sizeof( buf ), stdin ) != NULL ){
        if (sscanf( buf, " %d %c ", &position->row, &position->col ) != 2  && sscanf( buf, " %c %d ", &position->col, &position->row ) != 2 ){
            printf( "Illegal input.\n" );
            continue;
        }
        
        if(checkInputRange(position) || checkAlreadyInput(field, position)){
            printf("Illegal Input.\n");
        }
        else{
            break;
        }
    }

}

int isHit(Field *field, const Position *position){
    if(calculateDistance(field , position)==0){
        field->squares[position->row-1][position->col-65] = HIT;
        return 1;
    }
    else{
        field->squares[position->row-1][position->col-65] = SELECTED;
        return 0;
    }

}

int checkInputRange(const Position *position){
        if(position->row>MAX_ROW && position->col>MAX_COL+65){
            printf("Row and Col value is illegal. \n");
            return 1;
        }
        else if(position->row>MAX_ROW){
            printf("Row value is illegal. \n");
            return 1;
        }
        else if(position->col>MAX_COL+65){
            printf("Col value is illegal. \n");
            return 1;
        }
        else{
            return 0;
        }

}

int checkAlreadyInput(const Field *field , const Position *position){
    if(field->squares[position->row-1][position->col-65] == SELECTED){
        printf("The field has already been entered.\n");
        return 1;
    }
    else{
        return  0;
    }
}