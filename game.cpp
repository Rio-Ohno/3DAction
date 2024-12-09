//============================================================
//
//ゲーム画面[game.cpp]
//Author:Rio Ohno
//
//============================================================

#include"game.h"
//#include"backgraund.h"
#include"player.h"
#include"bullet.h"
#include"explosion.h"
#include"fade.h"
#include"pause.h"
#include "meshcylinder.h"
#include "meshfield.h"
#include "explosion.h"
#include "light.h"
#include"wall.h"
#include"shadow.h"
#include"input.h"
#include"enemy.h"

//グローバル変数
GAMESTATE g_gameState = GAMESTATE_NONE;
int g_nCounterGameStat = 0;
bool g_bPause = false;
bool g_bParticle = false;

//=============================================================================================================
//ゲーム画面の初期化処理
//=============================================================================================================
void InitGame()
{
	g_gameState = GAMESTATE_NORMAL;
	g_bPause = false;
	g_nCounterGameStat = 0;

	//ポーズの初期化処理
	InitPause();

	//爆発の初期化処理
	InitExplosion();

	//影の初期化処理
	InitShadow();

	//弾の初期化処理
	InitBullet();

	//プレイヤーの初期化処理
	InitPlayer();

	//敵の初期化処理
	InitEnemy();

	//InitBlock();

	//InitPolygon();
	
	//メッシュフィールドの初期化処理
	InitMeshField();
	//InitModel();

	//InitBillboard();

	//SetBillboard(D3DXVECTOR3(0.0f, 5.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 10.0f);

	//InitMeshWall();
	//SetMeshWall(D3DXVECTOR3(-100.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, -D3DX_PI / 2.0f, 0.0f));
	//SetMeshWall(D3DXVECTOR3(100.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, D3DX_PI / 2.0f, 0.0f));
	//SetMeshWall(D3DXVECTOR3(0.0f, 0.0f, 100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	//SetMeshWall(D3DXVECTOR3(0.0f, 0.0f, -100.0f), D3DXVECTOR3(0.0f, D3DX_PI, 0.0f));


	//InitMeshCylinder();

	//壁の初期化処理
	InitWall();

	//壁の設定処理(pos,rot,width,hight,a)
	SetWall(D3DXVECTOR3(-100.0f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, -D3DX_PI / 2.0f, 0.0f), 200.0f, 100.0f, 0.7f);//左
	SetWall(D3DXVECTOR3(100.0f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, D3DX_PI / 2.0f, 0.0f), 200.0f, 100.0f, 0.7f);//右
	SetWall(D3DXVECTOR3(0.0f, 50.0f, 100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 100.0f, 0.7f);//奥
	SetWall(D3DXVECTOR3(0.0f, 50.0f, -100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), -200.0f, 100.0f, 0.7f);//手前

	//SetWall(D3DXVECTOR3(-100.1f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, D3DX_PI / 2.0f, 0.0f), 200.0f, 100.0f, 0.3f);//左裏
	//SetWall(D3DXVECTOR3(100.1f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, -D3DX_PI / 2.0f, 0.0f), 200.0f, 100.0f, 0.3f);//右裏
	//SetWall(D3DXVECTOR3(0.0f, 50.0f, 100.1f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), -200.0f, 100.0f, 0.3f);//奥裏
	//SetWall(D3DXVECTOR3(0.0f, 50.0f, -100.1f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 100.0f, 0.3f);//手前裏

	InitCamera();

	InitLight();

	////敵の初期化
	//InitEnemy();

	////ウェーブの初期化
	//InitWave();

	////SetEnemy(D3DXVECTOR3(300.0f, 300.0f, 0.0f), 0, 2);
	//SetEnemy(D3DXVECTOR3(640.0f, 100.0f, 0.0f), 2, 2);

	////スコアの初期化
	//InitScore();
	//SetScore(0);

	////パーティクル初期化処理
	//InitParticle();

	////ゲームの読込処理
	//LoadWave();
}

//=============================================================================================================
//ゲーム画面の終了処理
//=============================================================================================================
void UninitGame()
{

	//ポーズの終了処理
	UninitPause();


	////スコアの終了処理
	//UninitScore();


	//UninitModel();

	//影の初期化処理
	UninitShadow();

	//爆発の初期化処理
	UninitExplosion();

	//弾の終了処理
	UninitBullet();
	
	//プレイヤーの終了処理
	UninitPlayer();

	//敵の終了処理
	UninitEnemy();

	//UninitBlock();

	//UninitPolygon();

	//メッシュフィールドの終了処理
	UninitMeshField();

	//UninitBillboard();

	//UninitMeshWall();

	//UninitMeshCylinder();

	//壁の終了処理
	UninitWall();

	//カメラの初期化処理
	UninitCamera();

	//ライトの初期化処理
	UninitLight();

	////エフェクトの終了処理
	//UninitEffect();

	////敵の終了処理
	//UninitEnemy();

	////パーティクルの終了処理
	//UninitParticle();

}

//=============================================================================================================
//ゲーム画面の更新処理
//=============================================================================================================
void UpdateGame()
{
	if (KeyboardTrigger(DIK_P) == true)
	{//ポーズ（Pキー）が押されたとき
		g_bPause = g_bPause ? false : true;
	}

	//ポーズ中
	if (g_bPause == true)
	{
		//ポーズの更新処理
		UpdatePause();
	}
		////背景の更新処理
		//Updatebackgraund();

		if (g_bPause == false)
		{

			//弾の更新処理
			UpdateBullet();

			//影の更新処理
			UpdateShadow();

			//爆発の更新処理
			UpdateExplosion();

			//弾の更新処理
			UpdateBullet();

			//ブロックの更新処理
			//UpdateBlock();

			//UpdatePolygon();

			//メッシュフィールドの更新処理
			UpdateMeshField();

			//UpdateBillboard();

			//UpdateMeshWall();

			//UpdateMeshCylinder();

			//壁の更新処理
			UpdateWall();

			//プレイヤーの更新処理
			UpdatePlayer();

			//敵の更新処理
			UpdateEnemy();

			//カメラの更新処理
			UpdateCamera();

			//ライトの更新処理
			UpdateLight();

			////エフェクトの更新処理
			//UpdateEffect();

			////スコアの更新処理
			//UpdateScore();

			////パーティクルの更新処理
			//UpdateParticle();
		}

	//Enemy* pEnemy;                                                      //敵情報へのポインタ

	////敵の取得
	//pEnemy = GetEnemy();

	////敵数の取得
	//int NumEnemy = GetNumEnemy();
	//bool finish = false;

	//if (NumEnemy <= 0)
	//{
	//	//ウェーブの読込処理
	//	LoadWave();
	//}


	//デバック用......................................................
	#ifdef  _DEBUG
	
		if (KeyboardTrigger(DIK_O) == true)
		{
			g_bParticle = g_bParticle ? false : true;
		}

		if (KeyboardTrigger(DIK_M)==true)//ゲームの終わる条件
		{
			//g_gameState = GAMESTATE_END;
			//画面の設定
			SetFade(MODE_RESULT);
		}
	
	#endif //  _DEBUG
	//...........................................................

		//プレイヤーの情報取得
		Player* pPlayer = GetPlayer();

		if (pPlayer->bFrag == true)
		{
			//画面遷移(Resultへ)
			SetFade(MODE_RESULT);
		}
			
	//switch (g_gameState)
	//{
	//case GAMESTATE_NORMAL:

	//	//finish = GetFinish();

	//	//if (finish==true)
	//	//{
	//	//	SetResult(RESULT_WIN);
	//	//	SetGameState(GAMESTATE_END);
	//	//}

	//	break;

	//case GAMESTATE_END:
	//	g_nCounterGameStat++;
	//	if (g_nCounterGameStat >= 60)
	//	{
	//		g_nCounterGameStat = 0;
	//		g_gameState = GAMESTATE_NONE;

	//		//画面の設定
	//		SetFade(MODE_RESULT);
	//	}
	//	break;
	//}
}

//=============================================================================================================
//ゲーム画面の描画処理
//=============================================================================================================
void DrawGame()
{
	//カメラの設定処理
	SetCamera();

	//爆発の描画処理
	DrawExplosion();

	//弾の描画処理
	DrawBullet();

	//ブロックの描画処理
	//DrawBlock();

	//ポリゴンの描画処理
	//DrawPolygon();

	//ビルボードの描画処理
	//DrawBillboard();

	//プレイヤーの描画処理
	DrawPlayer();

	//敵の描画処理
	DrawEnemy();

	//メッシュフィールドの描画処理
	DrawMeshField();

	//影の描画処理
	DrawShadow();

	//DrawMeshWall();

	//DrawMeshCylinder();

	//壁の描画処理
	DrawWall();

	//DrawModel();

	//エフェクトの描画処理
	//DrawEffect();

	////敵の描画処理
	//DrawEnemy();

	////スコアの描画処理
	//DrawScore();

	////パーティクルの描画処理
	//DrawParticle();

	//ポーズ中
	if (g_bPause == true)
	{
		//ポーズの描画処理
		DrawPause();
	}
}

//=============================================================================================================
//ゲームの状態の設定
//=============================================================================================================
void SetGameState(GAMESTATE state)
{
	g_gameState = state;
}

//=============================================================================================================
//ポーズの有効無効設定設定
//=============================================================================================================
void SetEnablePause(bool bPause) 
{
	g_bPause = bPause;
}

//=============================================================================================================
//ゲームの状態の取得
//=============================================================================================================
GAMESTATE GetGameState()
{
	return g_gameState;
}