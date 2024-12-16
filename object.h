//============================================================
//
//モデル[model.h]
//Author:Rio Ohno
//
//============================================================

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "main.h"

#define MAX_MAT (512)

//モデル構造体
typedef struct
{
	LPD3DXMESH pMesh;									//メッシュ(頂点情報)へのポインタ
	LPD3DXBUFFER pBuffMat;								//マテリアルへのポインタ
	DWORD dwNumMat;										//マテリアルの数
	int nIndxObjectpParent;								//親モデルのインデクス
	D3DXVECTOR3 pos;									//位置(オフセット)
	D3DXVECTOR3 rot;									//向き
	LPDIRECT3DTEXTURE9 apTextureObject[MAX_MAT];		//テクスチャ
	D3DXMATRIX mtxWorld;								//ワールドマトリックス
}Object;

//マクロ定義
#define MAX_MAT_OBJECT (512)

//プロトタイプ宣言
void InitObject();
void UninitObject();
void UpdateObject();
void DrawObject();

#endif // !_MODEL_H_

