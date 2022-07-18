/*!
  \file position.h
  \brief 盤面の位置を表す構造体と関連する関数の宣言
 */

/* 多重インクルードを回避するためのインクルードガードマクロ */
#ifndef POSITION_H
#define POSITION_H

enum {
    MAX_ROW = 9, /*!< 縦軸の最大値 */
    MAX_COL = 9, /*!< 横軸の最大値 */
};

/*!
  \struct Position
  \brief 盤面上のマス目位置を表す構造体
 */
typedef struct {
    int row; //!< 縦軸位置
    char col; //!< 横軸位置
} Position;

typedef struct {
    int squares[MAX_ROW][MAX_COL]; /*!< マス目の状態記録用 */
    Position submarine; /*!< 潜水艦の現在位置格納用 */
} Field;


/*!
    \brief マンハッタン距離を計算してその値を返す
    \param *field マス目の状態と潜水艦の現在位置を格納した構造体変数
    \param *position ユーザーが入力した最新の座標情報row,colを持った構造体変数
*/
int calculateDistance(const Field *field ,const Position *position);
#endif