//============================================================
//
//敵[enemy.h]
//Author:Rio Ohno
//
//============================================================

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "main.h"
#include"input.h"
#include"camera.h"
#include"shadow.h"
#include"model.h"

//マクロ定義.......................................................
#define MAX_ENEMY (1)
#define MAX_KEY_ENEMY (10)						//キーの最大数
#define MAX_MAT_ENEMY (512)						//マトリックスの最大数
#define MAX_MOTION_ENEMY (4)					//モーションの最大数
#define MAX_PARTS_ENEMY (15)					//パーツの最大数
#define PLAYER_SPEED_ENEMY (1.5f)				//敵のスピード

//モーションの種類............................................
typedef enum
{
	MOTIONTYPE_ENEMY_NEUTRAL = 0,				//ニュートラル
	MOTIONTYPE_ENEMY_MOVE,						//移動
	MOTIONTYPE_ENEMY_ATTACK,					//アクション
	MOTIONTYPE_ENEMY_JUMP,						//ジャンプ
	MOTIONTYPE_ENEMY_ESCAPE,					//逃げる
	MOTIONTYPE_ENEMY_MAX
}MOTIONTYPE_ENEMY;

//キーの構造体................................................
typedef struct
{
	float fPosX;						//位置X
	float fPosY;						//位置Y
	float fPosZ;						//位置Z
	float fRotX;						//向きX
	float fRotY;						//向きY
	float fRotZ;						//向きZ
}Key_ENEMY;

//キー情報の構造体............................................
typedef struct
{
	int nFrame;							//再生フレーム
	Key_ENEMY aKEY[MAX_PARTS];				//各パーツのキー要素
}Key_ENEMY_Info;

//モーション情報の構造体......................................
typedef struct
{
	bool bLoop;							//ループするかどうか
	int nNumKey;						//キーの総数
	Key_ENEMY_Info aKeyInfo[MAX_KEY];			//キー情報
}Motion_ENEMY_Info;

//敵構造体....................................................
typedef struct
{
	D3DXVECTOR3 pos;											//位置
	D3DXVECTOR3 posOld;											//前回の位置
	D3DXVECTOR3 rot;											//向き
	D3DXVECTOR3 rotDest;										//目標の向き
	D3DXVECTOR3 vtxMin;											//モデルの最小値
	D3DXVECTOR3 vtxMax;											//モデルの最大値
	D3DXVECTOR3 size;											//サイズ(大きさ)
	D3DXVECTOR3 move;											//移動量
	D3DXMATRIX mtxWorldEnemy;									//敵のワールドマトリックス
	Model aModel[MAX_PARTS];									//モデル(パーツ)
	Motion_ENEMY_Info aMotionInfo[MOTIONTYPE_ENEMY_MAX];		//モーション情報
	MOTIONTYPE_ENEMY motionType;								//モーションの種類
	int nLife;													//体力
	int nNumModel;												//モデル(パーツ)の総数
	int nNumMotion;												//モーションの最大数
	int nNumKey;												//キーの最大数
	int nKey;													//現在のキーNO.
	int nCounterMotion;											//モーションカウンター
	int nCntFream;												//フレームカウンタ
	int nIndxShadow;											//影のインデックス格納用
	bool bLoopMotion;											//ループするかどうか
	bool bjump;													//ジャンプ
	bool bUse;													//使用しているかどうか
	bool bFrag;													//壁に当たっているかどうか
}Enemy;

//============================================================
//プロトタイプ宣言
//============================================================
void InitEnemy();												//敵の初期化処理
void UninitEnemy();												//敵の終了処理
void UpdateEnemy();												//敵の更新処理
void DrawEnemy();												//敵の描画処理
void SetEnemy(D3DXVECTOR3 pos, D3DXVECTOR3 rot);				//敵の設定処理
void SetMotionEnemy();											//敵のモーション設定
bool CollisionEnemy();											//敵の当たり判定
void HitEnemy(int nIndxEnemy);									//敵が被弾したときの処理
Enemy* GetEnemy();												//敵の情報取得

#endif // !_MODEL_H_
