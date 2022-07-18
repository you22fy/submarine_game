/*!
  \file board.h
  \brief 盤面情報を管理する構造体の宣言
 */

/* 多重インクルードを回避するためのインクルードガードマクロ */
#ifndef BOARD_H
#define BOARD_H

#include "position.h"


enum {
    EMPTY = 0, /*!< 未選択のマスを表す値 */
    SELECTED = 1, /*!< 選択済のマスを表す値 */
    HIT = 2, /*!< 撃沈を表す値 */
};

enum{
    EASY = 15,
    NORMAL = 8,
    HARD = 5,
};

/*!
    \brief 最初にプレイヤーに難易度を入力させる
    \param *level 難易度情報を保持する変数のポインタ
*/
void fieldSelecetLevel(int *level);

/*!
    \brief 盤面を初期化し、1機の潜水艦をランダムに仕込む
    \param *field 盤の情報、潜水艦の位置情報を持った構造体変数のポインタ
*/
void fieldInitialize(Field *field);

/*!
    \brief 潜水艦の位置情報をランダムで更新する
    \param *field 盤の情報、潜水艦の位置情報を持った構造体変数のポインタ
    \param submarine_move_flag 潜水艦が移動するターン数を保持する変数のポインタ
*/
void fieldSubmarineUpdate(Field *field, int *submarine_move_flag);

/*!
    \brief 盤面への値入力
    \param field 盤の情報、潜水艦の位置情報を持った構造体変数のポインタ
    \param position ユーザーが入力した座標情報  
 */
void fieldInput(Position *position , const Field *field);

/*!
    \brief 現在の盤面の表示
    \param field 盤の情報、潜水艦の位置情報を持った構造体変数のポインタ
*/
void fieldDisplay(const Field *field);

/*!
    \brief 撃沈判定.hitすれば1,そうでなければ0を返す
    \param field 盤面を表す2次元配列
    \param submarine_row 潜水艦の横列座標
    \param submarine_col 潜水艦の縦列座標
    \param row プレイヤーが入力した横列座標
    \param col プレイヤーが入力した縦列座標

*/
int isHit(Field *field, const Position *position);


/*!
    \brief 範囲外の値の入力を検知する。範囲外の入力であれば1を、そうでなければ0を返す。
    \param　*position ユーザーが入力した値row,colを持つ構造体変数のポインタ
*/
int checkInputRange(const Position *position);

/*!
    \brief すでに入力されたマスが再度選択された場合に1を返す関数
    \param *field 盤の情報、潜水艦の位置情報を持った構造体変数のポインタ
    \param *position ユーザが入力した値、row,colを持つ構造体変数のポインタ
*/
int checkAlreadyInput(const Field *field ,const Position *position);
#endif