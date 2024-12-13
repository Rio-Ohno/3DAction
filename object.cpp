//============================================================
//
//モデル[model.cpp]
//Author:Rio Ohno
//
//============================================================

#include"object.h"

//グロ－バル変数宣言
LPD3DXMESH g_pMeshObject = NULL;
LPD3DXBUFFER g_pBuffmatObject = NULL;
DWORD g_dwNumMatObject = 0;
D3DXVECTOR3 g_posObject;
D3DXVECTOR3 g_rotObject;
D3DXMATRIX g_mtxWorldObject;
LPDIRECT3DTEXTURE9 apTextureObject[MAX_MAT];

//============================================================
// モデルの初期化処理
//============================================================
void InitObject()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATERIAL* pMat;//マテリアルデータへのポインタ

	//各種初期化
	g_pMeshObject = NULL;
	g_pBuffmatObject = NULL;
	g_dwNumMatObject = 0;
	g_posObject = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_rotObject = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_mtxWorldObject);

	//Xファイルの読込
	D3DXLoadMeshFromX("data\\MODEL\\TV.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_pBuffmatObject,
		NULL,
		&g_dwNumMatObject,
		&g_pMeshObject);

	//マテリアルデータへのポインタを取得
	pMat = (D3DXMATERIAL*)g_pBuffmatObject->GetBufferPointer();

	for (int nCnt = 0; nCnt < (int)g_dwNumMatObject; nCnt++)
	{
		//テクスチャポインタの初期化
		apTextureObject[nCnt] = {};

		if (pMat[nCnt].pTextureFilename != NULL)
		{
			//テクスチャの読込
			D3DXCreateTextureFromFile(pDevice,
				pMat[nCnt].pTextureFilename,
				&apTextureObject[nCnt]);

		}
	}
}

//============================================================
// モデルの終了処理
//============================================================
void UninitObject()
{
	//メッシュの破棄
	if (g_pMeshObject != NULL)
	{
		g_pMeshObject->Release();
		g_pMeshObject = NULL;
	}

	//マテリアルの破棄
	if (g_pBuffmatObject != NULL)
	{
		g_pBuffmatObject->Release();
		g_pBuffmatObject = NULL;
	}

	for (int nCnt = 0; nCnt < (int)g_dwNumMatObject; nCnt++)
	{
		if (apTextureObject[nCnt] != NULL)
		{
			apTextureObject[nCnt]->Release();
			apTextureObject[nCnt] = NULL;
		}
	}
}

//============================================================
// モデルの更新処理
//============================================================
void UpdateObject()
{

}

//============================================================
// モデルの描画処理
//============================================================
void DrawObject()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;//計算用マトリックス
	D3DMATERIAL9 matDef;//現在のマテリアル保存用
	D3DXMATERIAL* pMat;//マテリアルデータへのポインタ

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_mtxWorldObject);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotObject.y, g_rotObject.x, g_rotObject.z);
	D3DXMatrixMultiply(&g_mtxWorldObject, &g_mtxWorldObject, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, g_posObject.x, g_posObject.y, g_posObject.z);
	D3DXMatrixMultiply(&g_mtxWorldObject, &g_mtxWorldObject, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldObject);

	//現在のマテリアルを取得
	pDevice->GetMaterial(&matDef);

	//マテリアルデータへのポインタを取得
	pMat = (D3DXMATERIAL*)g_pBuffmatObject->GetBufferPointer();

	for (int nCnt = 0; nCnt < (int)g_dwNumMatObject; nCnt++)
	{

		//マテリアルの設定
		pDevice->SetMaterial(&pMat[nCnt].MatD3D);

		//テクスチャの設定
		pDevice->SetTexture(0, apTextureObject[nCnt]);

		//モデル(パーツ)の描画
		g_pMeshObject->DrawSubset(nCnt);
	}

	//保存していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);

}