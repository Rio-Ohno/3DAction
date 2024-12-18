//============================================================
//
//ウェーブ処理[wave.cpp]
//Author:Rio Ohno
//
//============================================================

#include"wave.h"
#include"enemy.h"
#include<stdio.h>

//マクロ定義
#define MAX_WORD (216)										//最大文字数
#define WAVE_0 "data\\wave\\wave0.txt"						//ウェーブ0
//#define WAVE_1 "data\\wavw\\wave1.txt"						//ウェーブ1
//#define WAVE_2 "data\\wavw\\wave2.txt"						//ウェーブ2
//#define WAVE_3 "data\\wavw\\wave3.txt"						//ウェーブ3
//
//ウェーブ構造体
typedef struct
{
	D3DXVECTOR3 pos;										//位置
	D3DXVECTOR3 rot;										//向き
	bool bUse;												//使用しているかどうか
}LoadInfo;

//グローバル変数宣言
LoadInfo g_Info[MAX_ENEMY];
int g_nCntEnemy;
int g_nWave;												//ウェーブのカウント
bool g_bFinish;												//ウェーブの終了判定

//============================================================
// ウェーブの初期化処理
//============================================================
void InitWave()
{
	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		g_Info[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Info[nCnt].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Info[nCnt].bUse = false;
	}

	g_nCntEnemy = 0;
	g_nWave = 0;
	g_bFinish = false;
}

//============================================================
// ウェーブの読込処理
//============================================================
void LoadWave()
{
	FILE* pFile;											//外部ファイルへのポインタ

	D3DXVECTOR3 pos ,rot= {};

	//敵の数取得
	g_nCntEnemy = GetNumEnemy();

	//各ウェーブのファイルを開く
	switch (g_nWave)
	{
	case 0://Wave1

		pFile = fopen(WAVE_0, "r");

		break;

	//case 1://Wavw2

	//	pFile = fopen(WAVE_1, "r");

	//	break;

		//case 2://Wavw3

		//	pFile = fopen(WAVE_2, "r");

		//	break;

	default://例外

		pFile = NULL;

		//g_bFinish = true;									//ウェーブ終了

		break;
	}

	if (pFile != NULL)
	{
		while (1)
		{
			char aString[MAX_WORD];

			//ファイルを読みこむ
			fscanf(pFile, "%s", &aString[0]);
			if (strcmp(aString, "ENEMYSET") == 0)//ENEMYSETを読込んだなら
			{
				while (1)
				{
					fscanf(pFile, "%s", &aString[0]);

					if (strcmp(aString, "POS") == 0)//POSを読込んだなら
					{
						//位置の取得
						fscanf(pFile, "%f", &pos.x);
						fscanf(pFile, "%f", &pos.y);
						fscanf(pFile, "%f", &pos.z);
					}
					else if (strcmp(aString, "ROT") == 0)//ROTを読込んだなら
					{
						//向きの取得
						fscanf(pFile, "%f", &rot.x);
						fscanf(pFile, "%f", &rot.y);
						fscanf(pFile, "%f", &rot.z);
					}
					else if (strcmp(aString, "END_ENEMYSET") == 0)//END_ENEMYSETを読込んだなら
					{
						//敵の設定
						SetEnemy(pos, rot);

						break;
					}
				}
			}
			if (strcmp(aString, "END_SCRIPT") == 0)
			{
				break;
			}
		}

		//ファイルを閉じる
		fclose(pFile);

		//ウェーブのカウントアップ
		g_nWave++;
	}
	else
	{
		return;
	}
}

//============================================================
// ウェーブ数の取得
//============================================================
int GetWave()
{
	return g_nWave;
}

//============================================================
// ウェーブ終了の取得
//============================================================
bool GetFinish()
{
	return g_bFinish;
}