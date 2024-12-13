//============================================================
//
//プレイヤー[player.cpp]
//Author:Rio Ohno
//
//============================================================

#include"player.h"
#include "bullet.h"
#include "wall.h"
#include"enemy.h"
#include"effect.h"
#include<stdio.h>
#include<string.h>

//グロ－バル変数宣言
Player g_player;
static  Key_Info g_keyNeutrall[] =
{ //Key0......................................................
	{40,
	//パーツ0
	{{0.0f,0.0f,0.0f,0.06f, 0.0f, 0.0f},
	//パーツ1
	 {0.0f ,0.0f ,0.0f,-0.16f, 0.0f, 0.0f},
	 //パーツ2
	  {0.0f,0.0f,0.0f,0.0f, 0.0f, 0.0f},
	  //パーツ3
	   {0.0f,0.0f,0.0f,0.0f, 0.0f, 0.0f},
	   //パーツ4
		{0.0f,0.0f,0.0f,0.0f, 0.0f, 1.19f},
		//パーツ5
		 {0.0f,0.0f,0.0f,0.0f,-0.6f,0.13f},
		 //パーツ6
		  {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
		  //パーツ7
		   {0.0f,0.0f,0.0f,0.0f,0.0f,-1.19f},
		   //パーツ8
			{0.0f,0.0f,0.0f,0.0f,0.6f,-0.13f},
			//パーツ9
			 {0.0f,0.0f,0.0f,0.13f,0.0f,0.0f},
			 //パーツ10
			  {0.0f,0.0f,0.0f,-0.6f,0.0,-0.22f},
			  //パーツ11
			   {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
			   //パーツ12
				{0.0f,0.0f,0.0f,0.13f,0.0f,0.0f},
				//パーツ13
				 {0.0f,0.0f,0.0f,-0.6f,0.0f,0.22f},
				 //パーツ14
				  {0.0f,0.0f,0.0f,-0.0f,0.0f,0.0f}
				 }},

	//Key1......................................................
   {40,
	//パーツ0
	{{0.0f,0.0f,0.0f,-0.0f, 0.0f, 0.0f},
	//パーツ1
	 {0.0f,0.0f,0.0f,-0.09f, 0.0f, 0.0f},
	//パーツ2
	 {0.0f, 0.0f,0.0f, 0.0f, 0.0f, 0.0f},
	//パーツ3
	 {0.0f,0.0f,0.0f, 0.0f, 0.0f, 0.0f},
	//パーツ4
	 {0.0f,0.0f,0.0f,-0.06f,0.0f,1.13f},
	//パーツ5
	 {0.0f,0.0f,0.0f,0.0f,-0.6f,0.13f},
	//パーツ6
	  {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
	//パーツ7
	 {0.0f,0.0f,0.0f,-0.06f,0.0f,-1.13f},
	//パーツ8
	 {0.0f,0.0f,0.0f,0.0f,0.6f,-0.13f},
	//パーツ9
	 {0.0f,0.0f,0.0f,0.03f,0.0f,0.0f},
	//パーツ10
	 {0.0f,0.0f,0.0f,-0.5f,0.0f,-0.22f},
	//パーツ11
	 {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
	//パーツ12
	 {0.0f,0.0f,0.0f,0.03f,0.0f,0.0f},
	//パーツ13
	 {0.0f,0.0f,0.0f,-0.5f,0.0f,0.22f},
	//パーツ14
	 {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}
	}}
};

static  Key_Info g_keyAction[] =
{
	   {20,
	   //パーツ0
	   {{0.0f,0.0f,0.0f,0.03f, 0.16f, 0.0f},
	   //パーツ1
		{0.0f,0.0f,0.0f,0.0f, 0.31f, 0.0f},
		//パーツ2
		 {0.0f, 0.0f,0.0f, -0.03f, 0.09f, 0.0f},
		 //パーツ3
		  {0.0f,0.0f,0.0f, 0.09f, 0.06f, 0.0f},
		  //パーツ4
		   {0.0f,0.0f,0.0f,-0.79f,0.35f,1.13f},
		   //パーツ5
			{0.0f,0.0f,0.0f,0.09f,-1.6f,0.0f},
			//パーツ6
			  {0.0f,0.0f,0.0f,0.0f,0.09f,0.03f},
			  //パーツ7
			   {0.0f,0.0f,0.0f,0.13f,1.54f,-1.04f},
			   //パーツ8
				{0.0f,0.0f,0.0f,0.03f,0.94f,-0.91f},
				//パーツ9
				 {0.0f,0.0f,0.0f,-0.53f,0.0f,0.0f},
				 //パーツ10
				  {0.0f,0.0f,0.0f,-0.44f,0.09f,0.0f},
				  //パーツ11
				   {0.0f,0.0f,0.0f,0.69f,0.0f,0.0f},
				   //パーツ12
					{0.0f,0.0f,0.0f,1.01f,0.03f,0.0f},
					//パーツ13
					 {0.0f,0.0f,0.0f,-1.04f,0.0f,0.0f},
					 //パーツ14
					  {0.0f,0.0f,0.0f,-0.06f,0.06f,0.0f}
					 }}
	,	   
	{20,
	//パーツ0
	{{0.0f,0.0f,0.0f,-0.25f, -0.16f, 0.0f},
	//パーツ1
	 {0.0f,0.0f,0.0f,0.0f, -0.19f, 0.0f},
	//パーツ2
	 {0.0f, 0.0f,0.0f, -0.03f, 0.16f, 0.0f},
	//パーツ3
	 {0.0f,0.0f,0.0f, 0.06f, -0.35f, 0.0f},
	//パーツ4
	 {0.0f,0.0f,0.0f,1.73f,0.57f,1.54f},
	//パーツ5
	 {0.0f,0.0f,0.0f,0.09f,0.0f,0.28f},
	//パーツ6
	  {0.0f,0.0f,0.0f,0.0f,-0.13f,0.03f},
	//パーツ7
	 {0.0f,0.0f,0.0f,-0.35f,1.48f,-2.39f},
	//パーツ8
	 {0.0f,0.0f,0.0f,-0.5f,0.35f,1.7f},
	//パーツ9
	 {0.0f,0.0f,0.0f,-0.69f,0.0f,0.0f},
	//パーツ10
	 {0.0f,0.0f,0.0f,-0.41f,0.09f,0.0f},
	//パーツ11
	 {0.0f,0.0f,0.0f,0.28f,0.0f,0.0f},
	//パーツ12
	 {0.0f,0.0f,0.0f,1.35f,0.03f,0.0f},
	//パーツ13
	 {0.0f,0.0f,0.0f,-1.23f,0.0f,0.0f},
	//パーツ14
	 {0.0f,0.0f,0.0f,-0.13f,0.06f,0.0f}
	}}


};

//============================================================
// プレイヤーの初期化処理
//============================================================
void InitPlayer()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATERIAL* pMat;//マテリアルデータへのポインタ

	//各種初期化
	g_player.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_player.posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_player.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_player.rotDest= D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_player.vtxMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_player.vtxMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_player.size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_player.move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_player.motionType = MOTIONTYPE_NEUTRAL;
	g_player.nNumModel = 0;
	g_player.nNumMotion = 0;
	g_player.nNumKey = 0;
	g_player.nKey = 0;
	g_player.nCounterMotion = 0;
	g_player.nIndxShadow = SetShadow(D3DXVECTOR3(g_player.pos.x, 0.1f, g_player.pos.z),g_player.rot,D3DXVECTOR3(1.0f,0.0f,1.0f));
	g_player.bjump = false;
	g_player.bUse = true;
	g_player.bFrag = false;

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_player.mtxWorldPlayer);

	//Xファイルの読込
	D3DXLoadMeshFromX("data\\MODEL\\player\\koshi.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[0].pBuffMat,
		NULL,
		&g_player.aModel[0].dwNumMat,
		&g_player.aModel[0].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\mune.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[1].pBuffMat,
		NULL,
		&g_player.aModel[1].dwNumMat,
		&g_player.aModel[1].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\atama.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[2].pBuffMat,
		NULL,
		&g_player.aModel[2].dwNumMat,
		&g_player.aModel[2].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\Rkata.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[3].pBuffMat,
		NULL,
		&g_player.aModel[3].dwNumMat,
		&g_player.aModel[3].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\Rnino.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[4].pBuffMat,
		NULL,
		&g_player.aModel[4].dwNumMat,
		&g_player.aModel[4].pMesh);


	D3DXLoadMeshFromX("data\\MODEL\\player\\Rude.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[5].pBuffMat,
		NULL,
		&g_player.aModel[5].dwNumMat,
		&g_player.aModel[5].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\Lkata.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[6].pBuffMat,
		NULL,			 
		&g_player.aModel[6].dwNumMat,
		&g_player.aModel[6].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\Lnino.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[7].pBuffMat,
		NULL,			 
		&g_player.aModel[7].dwNumMat,
		&g_player.aModel[7].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\Lude.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[8].pBuffMat,
		NULL,
		&g_player.aModel[8].dwNumMat,
		&g_player.aModel[8].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\Rmomo.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[9].pBuffMat,
		NULL,			 
		&g_player.aModel[9].dwNumMat,
		&g_player.aModel[9].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\Rhiza.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[10].pBuffMat,
		NULL,			
		&g_player.aModel[10].dwNumMat,
		&g_player.aModel[10].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\Rashi.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[11].pBuffMat,
		NULL,			  
		&g_player.aModel[11].dwNumMat,
		&g_player.aModel[11].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\Lmomo.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[12].pBuffMat,
		NULL,			  
		&g_player.aModel[12].dwNumMat,
		&g_player.aModel[12].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\Lhiza.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[13].pBuffMat,
		NULL,			  
		&g_player.aModel[13].dwNumMat,
		&g_player.aModel[13].pMesh);

	D3DXLoadMeshFromX("data\\MODEL\\player\\Lashi.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_player.aModel[14].pBuffMat,
		NULL,			  
		&g_player.aModel[14].dwNumMat,
		&g_player.aModel[14].pMesh);

	g_player.nNumModel = 15;												//パーツ数の設定

	//各パーツの階層構造設定
	g_player.aModel[0].nIndxModelpParent = -1;
	g_player.aModel[0].pos = D3DXVECTOR3(0.0f, 17.0f, 0.0f);
	g_player.aModel[0].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[1].nIndxModelpParent = 0;
	g_player.aModel[1].pos = D3DXVECTOR3(0.0f, 12.5f, 0.0f);
	g_player.aModel[1].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[2].nIndxModelpParent = 1;
	g_player.aModel[2].pos = D3DXVECTOR3(0.0f, 12.0f, 0.0f);
	g_player.aModel[2].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[3].nIndxModelpParent = 1;
	g_player.aModel[3].pos = D3DXVECTOR3(-2.5f, 10.0f, 0.0f);
	g_player.aModel[3].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[4].nIndxModelpParent = 3;
	g_player.aModel[4].pos = D3DXVECTOR3(-5.0f, 0.0f, 0.0f);
	g_player.aModel[4].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[5].nIndxModelpParent = 4;
	g_player.aModel[5].pos = D3DXVECTOR3(-10.0f, 0.0f, 0.0f);
	g_player.aModel[5].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[6].nIndxModelpParent = 1;
	g_player.aModel[6].pos = D3DXVECTOR3(2.5f, 10.0f, 0.0f);
	g_player.aModel[6].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[7].nIndxModelpParent = 6;
	g_player.aModel[7].pos = D3DXVECTOR3(5.0f, 0.0f, 0.0f);
	g_player.aModel[7].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[8].nIndxModelpParent = 7;
	g_player.aModel[8].pos = D3DXVECTOR3(10.0f, 0.0f, 0.0f);
	g_player.aModel[8].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[9].nIndxModelpParent = 0;
	g_player.aModel[9].pos = D3DXVECTOR3(-5.0f, 7.5f, 1.0f);
	g_player.aModel[9].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[10].nIndxModelpParent = 9;
	g_player.aModel[10].pos = D3DXVECTOR3(0.0f, -12.5f, 0.0f);
	g_player.aModel[10].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[11].nIndxModelpParent = 10;
	g_player.aModel[11].pos = D3DXVECTOR3(0.0f, -5.0f, 0.0f);
	g_player.aModel[11].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[12].nIndxModelpParent = 0;
	g_player.aModel[12].pos = D3DXVECTOR3(5.0f, 7.5f, 1.0f);
	g_player.aModel[12].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[13].nIndxModelpParent = 12;
	g_player.aModel[13].pos = D3DXVECTOR3(0.0f, -12.5f, 0.0f);
	g_player.aModel[13].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	g_player.aModel[14].nIndxModelpParent = 13;
	g_player.aModel[14].pos = D3DXVECTOR3(0.0f, -5.0f, 0.0f);
	g_player.aModel[14].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//外部からモーション読込
	LoadMotionPlayer();

	for (int nCntModel = 0; nCntModel < g_player.nNumModel; nCntModel++)
	{
		int nNumVtx;//最大頂点数
		DWORD sizeFVF;//頂点フォーマットのサイズ
		BYTE* pVtxBUff;//頂点バッファへのポインタ

		//頂点数の取得
		nNumVtx = g_player.aModel[nCntModel].pMesh->GetNumVertices();

		//頂点フォーマットのサイズを取得
		sizeFVF = D3DXGetFVFVertexSize(g_player.aModel[nCntModel].pMesh->GetFVF());

		//頂点バッファのロック
		g_player.aModel[nCntModel].pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBUff);

		for (int nCnt = 0; nCnt < nNumVtx; nCnt++)
		{
			//頂点座標の代入
			D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBUff;

			//頂点座標を比較してモデルの最大最小を取得

			if (vtx.x > g_player.vtxMax.x)//x最大値
			{
				g_player.vtxMax.x = vtx.x;
			}
			else if (vtx.x < g_player.vtxMin.x)//x最小値
			{
				g_player.vtxMin.x = vtx.x;
			}

			if (vtx.y > g_player.vtxMax.y)//y最大値
			{
				g_player.vtxMax.y = vtx.y;
			}
			else if (vtx.y < g_player.vtxMin.y)//y最小値
			{
				g_player.vtxMin.y = vtx.y;
			}

			if (vtx.z > g_player.vtxMax.z)//z最大値
			{
				g_player.vtxMax.z = vtx.z;
			}
			else if (vtx.z < g_player.vtxMin.z)//z最小値
			{
				g_player.vtxMin.z = vtx.z;
			}

			//頂点フォーマットのサイズ分ポインタを進める
			pVtxBUff += sizeFVF;
		}

		//頂点バッファのアンロック
		g_player.aModel[nCntModel].pMesh->UnlockVertexBuffer();

		//サイズの初期化
		g_player.size = g_player.vtxMax - g_player.vtxMin;

		//マテリアルデータへのポインタを取得
		pMat = (D3DXMATERIAL*)g_player.aModel[nCntModel].pBuffMat->GetBufferPointer();

		for (int nCnt = 0; nCnt < (int)g_player.aModel[nCntModel].dwNumMat; nCnt++)
		{
			//テクスチャポインタの初期化
			g_player.aModel[nCntModel].apTextureModel[nCnt] = {};

			if (pMat[nCnt].pTextureFilename != NULL)
			{
				//テクスチャの読込
				D3DXCreateTextureFromFile(pDevice,
					pMat[nCnt].pTextureFilename,
					&g_player.aModel[nCntModel].apTextureModel[nCnt]);
			}
		}
	}
}

//============================================================
// プレイヤーの終了処理
//============================================================
void UninitPlayer()
{
	for (int nCntModel = 0; nCntModel < g_player.nNumModel; nCntModel++)
	{

		//メッシュの破棄
		if (g_player.aModel[nCntModel].pMesh != NULL)
		{
			g_player.aModel[nCntModel].pMesh->Release();
			g_player.aModel[nCntModel].pMesh = NULL;
		}

		//マテリアルの破棄
		if (g_player.aModel[nCntModel].pBuffMat != NULL)
		{
			g_player.aModel[nCntModel].pBuffMat->Release();
			g_player.aModel[nCntModel].pBuffMat = NULL;
		}

		//テクスチャの破棄
		for (int nCnt1 = 0; nCnt1 < (int)g_player.aModel[nCntModel].dwNumMat; nCnt1++)
		{
			if (g_player.aModel[nCntModel].apTextureModel[nCnt1] != NULL)
			{
				g_player.aModel[nCntModel].apTextureModel[nCnt1]->Release();
				g_player.aModel[nCntModel].apTextureModel[nCnt1] = NULL;
			}
		}
	}
}

//============================================================
// プレイヤーの更新処理
//============================================================
void UpdatePlayer()
{
	//カメラの情報取得
	Camera* pCamera = GetCamera();

	g_player.posOld = g_player.pos;

	if (GetKeyboardPress(DIK_LEFT) == true)
	{
		g_player.move.x += sinf(pCamera->rot.y - D3DX_PI * 0.5f) * PLAYER_SPEED;
		g_player.move.z += cosf(pCamera->rot.y - D3DX_PI * 0.5f) * PLAYER_SPEED;
		g_player.rotDest.y = pCamera->rot.y + D3DX_PI / 2.0f;
	}
	else if (GetKeyboardPress(DIK_RIGHT) == true)
	{
		g_player.move.x += sinf(pCamera->rot.y + D3DX_PI / 2.0f) * PLAYER_SPEED;
		g_player.move.z += cosf(pCamera->rot.y + D3DX_PI / 2.0f) * PLAYER_SPEED;
		g_player.rotDest.y = pCamera->rot.y - D3DX_PI / 2.0f;

	}
	else if (GetKeyboardPress(DIK_UP) == true)
	{
		g_player.move.x += sinf(pCamera->rot.y) * PLAYER_SPEED;
		g_player.move.z += cosf(pCamera->rot.y) * PLAYER_SPEED;
		g_player.rotDest.y = pCamera->rot.y + D3DX_PI;
	}
	else if (GetKeyboardPress(DIK_DOWN) == true)
	{
		D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//右回り左回り

		if (g_player.rot > 0)
		{
			rot.y = pCamera->rot.y + D3DX_PI;
		}
		else if (g_player.rot < 0)
		{
			rot.y = -(pCamera->rot.y + D3DX_PI);
		}

		g_player.move.x += sinf(rot.y) * PLAYER_SPEED;
		g_player.move.z += cosf(rot.y) * PLAYER_SPEED;
		g_player.rotDest.y = pCamera->rot.y;
	}

	//ジャンプ
	if (g_player.bjump == false)
	{
		if (KeyboardTrigger(DIK_SPACE) == true)
		{
			g_player.motionType = MOTIONTYPE_JUMP;
			g_player.move.y += 30.0f;
			g_player.bjump = true;
		}
	}

	//攻撃
	if (KeyboardTrigger(DIK_RETURN) == true)
	{
		g_player.motionType = MOTIONTYPE_ACTION;
		SetBullet(g_player.pos, g_player.rot, 2.0f);
		g_player.move *= -1.0f;
		g_player.nKey = 0;
	}

	g_player.move.y -= 0.8f;

	//目標の移動方向（角度）の補正
	if (g_player.rotDest.y > D3DX_PI)
	{
		g_player.rotDest.y -= D3DX_PI * 2.0f;
	}
	else if (g_player.rotDest.y < -D3DX_PI)
	{
		g_player.rotDest.y += D3DX_PI * 2.0f;
	}

	g_player.rot.y += (g_player.rotDest.y - g_player.rot.y) * 0.15f;

	//目標の移動方向（角度）の補正
	if (g_player.rot.y > D3DX_PI)
	{
		g_player.rot.y -= D3DX_PI * 2.0f;
	}
	else if (g_player.rot.y < -D3DX_PI)
	{
		g_player.rot.y += D3DX_PI * 2.0f;
	}

	//位置の更新
	g_player.pos += g_player.move;

	//移動量の更新(減衰)
	g_player.move.x = (0.0f - g_player.move.x) * 0.1f;
	g_player.move.y = (0.0f - g_player.move.y) * 0.1f;
	g_player.move.z = (0.0f - g_player.move.z) * 0.1f;

	//床判定
	if (g_player.pos.y < 0)
	{
		g_player.pos.y = 0;
		g_player.bjump = false;
	}

	//影の位置更新
	SetPositionShadow(g_player.nIndxShadow, D3DXVECTOR3(g_player.pos.x,0.1f,g_player.pos.z));

	//当たり判定
	//CollisionBlock_X();
	//CollisionBlock_Z();
	g_player.bFrag = CollisionWall();
	bool bCollEnemy = CollisionEnemy();
  
	SetMotion(g_player.motionType);

}

//============================================================
// プレイヤーの描画処理
//============================================================
void DrawPlayer()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;//計算用マトリックス
	D3DMATERIAL9 matDef;//現在のマテリアル保存用
	D3DXMATERIAL* pMat;//マテリアルデータへのポインタ

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_player.mtxWorldPlayer);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_player.rot.y, g_player.rot.x, g_player.rot.z);
	D3DXMatrixMultiply(&g_player.mtxWorldPlayer, &g_player.mtxWorldPlayer, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, g_player.pos.x, g_player.pos.y, g_player.pos.z);
	D3DXMatrixMultiply(&g_player.mtxWorldPlayer, &g_player.mtxWorldPlayer, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &g_player.mtxWorldPlayer);

	//現在のマテリアルを取得
	pDevice->GetMaterial(&matDef);


	for (int nCntModel = 0; nCntModel < g_player.nNumModel; nCntModel++)
	{
		D3DXMATRIX  mtxRotModel, mtxTransModel;	//計算用マトリックス
		D3DXMATRIX mtxParent;				//親のマtリックス

		//マテリアルデータへのポインタを取得
		pMat = (D3DXMATERIAL*)g_player.aModel[nCntModel].pBuffMat->GetBufferPointer();

		//パーツのワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_player.aModel[nCntModel].mtxWorld);

		//向きを反映
		D3DXMatrixRotationYawPitchRoll(&mtxRotModel, g_player.aModel[nCntModel].rot.y, g_player.aModel[nCntModel].rot.x, g_player.aModel[nCntModel].rot.z);
		D3DXMatrixMultiply(&g_player.aModel[nCntModel].mtxWorld, &g_player.aModel[nCntModel].mtxWorld, &mtxRotModel);

		//位置を反映
		D3DXMatrixTranslation(&mtxTransModel, g_player.aModel[nCntModel].pos.x, g_player.aModel[nCntModel].pos.y, g_player.aModel[nCntModel].pos.z);
		D3DXMatrixMultiply(&g_player.aModel[nCntModel].mtxWorld, &g_player.aModel[nCntModel].mtxWorld, &mtxTransModel);

		//パーツの親マトリックスの設定
		if (g_player.aModel[nCntModel].nIndxModelpParent != -1)//子の時
		{
			mtxParent = g_player.aModel[g_player.aModel[nCntModel].nIndxModelpParent].mtxWorld;
		}
		else//親の時
		{
			mtxParent = g_player.mtxWorldPlayer;
		}

		//算出したパーツのワールドマトリックスと親のマトリックスをかけ合わせる
		D3DXMatrixMultiply(&g_player.aModel[nCntModel].mtxWorld, &g_player.aModel[nCntModel].mtxWorld, &mtxParent);

		//パーツのワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &g_player.aModel[nCntModel].mtxWorld);

		for (int nCnt1 = 0; nCnt1 < (int)g_player.aModel[nCntModel].dwNumMat; nCnt1++)
		{
			//マテリアルの設定
			pDevice->SetMaterial(&pMat[nCnt1].MatD3D);

			//テクスチャの設定
			pDevice->SetTexture(0, g_player.aModel[nCntModel].apTextureModel[nCnt1]);

			//モデル(パーツ)の描画
			g_player.aModel[nCntModel].pMesh->DrawSubset(nCnt1);
		}

	}
	//保存していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);

}

//============================================================
// プレイヤーのモーション設定・動かし
//============================================================
void SetMotion(MOTIONTYPE type)
{
	int nCntLoad = 0;//読込を繰り返す回数
	int nCntKey = 0;
	int ModelIndex = 0;

	switch (g_player.motionType)
	{
	case MOTIONTYPE_NEUTRAL:

		g_player.nNumKey = 2;
		g_player.bLoopMotion = true;

		for (int nCnt = 0; nCnt < g_player.nNumKey; nCnt++)
		{
			g_player.aMotionInfo[g_player.motionType].aKeyInfo[nCnt] = g_keyNeutrall[nCnt];
		}

		break;

	case MOTIONTYPE_MOVE:

		nCntLoad = 2;

		break;

	case MOTIONTYPE_ACTION:

		g_player.nNumKey = 2;
		g_player.bLoopMotion = false;

		for (int nCnt = 0; nCnt < g_player.nNumKey; nCnt++)
		{
			g_player.aMotionInfo[g_player.motionType].aKeyInfo[nCnt] = g_keyAction[nCnt];
		}

		break;

	case MOTIONTYPE_JUMP:

		nCntLoad = 4;

		break;

	}


	//全モデル(パーツ)の更新
	for (int nCntModel = 0; nCntModel < g_player.nNumModel; nCntModel++)
	{//キー情報から位置と向きを算出

		//次のキー
		int NextKey = (g_player.nKey + 1) % g_player.nNumKey;
		if (g_player.bLoopMotion == true)
		{
			if (g_player.nKey >= g_player.nNumKey)
			{//キーの最大数より大きくなったら
				g_player.nKey = 0;
			}
		}
		else if (g_player.bLoopMotion == false)
		{
			if (g_player.nKey >= g_player.nNumKey)
			{//キーの最大数より大きくなったら
				g_player.motionType = MOTIONTYPE_NEUTRAL;
				g_player.nKey = 0;
			}
		}

		//差分格納用　　
		D3DXVECTOR3 sPos, sRot;

		sPos.x = g_player.aMotionInfo[g_player.motionType].aKeyInfo[NextKey].aKEY[nCntModel].fPosX - g_player.aMotionInfo[g_player.motionType].aKeyInfo[g_player.nKey].aKEY[nCntModel].fPosX;
		sPos.y = g_player.aMotionInfo[g_player.motionType].aKeyInfo[NextKey].aKEY[nCntModel].fPosY - g_player.aMotionInfo[g_player.motionType].aKeyInfo[g_player.nKey].aKEY[nCntModel].fPosY;
		sPos.z = g_player.aMotionInfo[g_player.motionType].aKeyInfo[NextKey].aKEY[nCntModel].fPosZ - g_player.aMotionInfo[g_player.motionType].aKeyInfo[g_player.nKey].aKEY[nCntModel].fPosZ;

		sRot.x = g_player.aMotionInfo[g_player.motionType].aKeyInfo[NextKey].aKEY[nCntModel].fRotX - g_player.aMotionInfo[g_player.motionType].aKeyInfo[g_player.nKey].aKEY[nCntModel].fRotX;
		sRot.y = g_player.aMotionInfo[g_player.motionType].aKeyInfo[NextKey].aKEY[nCntModel].fRotY - g_player.aMotionInfo[g_player.motionType].aKeyInfo[g_player.nKey].aKEY[nCntModel].fRotY;
		sRot.z = g_player.aMotionInfo[g_player.motionType].aKeyInfo[NextKey].aKEY[nCntModel].fRotZ - g_player.aMotionInfo[g_player.motionType].aKeyInfo[g_player.nKey].aKEY[nCntModel].fRotZ;

		//計算結果格納用
		D3DXVECTOR3 fAnsPos, fAnsRot;

		//(モーションカウンター)/(再生フレーム数)
		float fData = (float)g_player.nCounterMotion / g_player.aMotionInfo[g_player.motionType].aKeyInfo[g_player.nKey].nFrame;

		fAnsPos.x = sPos.x * fData;
		fAnsPos.y = sPos.y * fData;
		fAnsPos.z = sPos.z * fData;

		fAnsRot.x = g_player.aMotionInfo[g_player.motionType].aKeyInfo[g_player.nKey].aKEY[nCntModel].fRotX + sRot.x * fData;
		fAnsRot.y = g_player.aMotionInfo[g_player.motionType].aKeyInfo[g_player.nKey].aKEY[nCntModel].fRotY + sRot.y * fData;
		fAnsRot.z = g_player.aMotionInfo[g_player.motionType].aKeyInfo[g_player.nKey].aKEY[nCntModel].fRotZ + sRot.z * fData;

		//位置と向きを反映
		g_player.aModel[nCntModel].pos += fAnsPos;

		g_player.aModel[nCntModel].rot = fAnsRot;
	}
	//モーションカウンターを進める
	g_player.nCounterMotion++;

	//カウンターが再生フレームより大きくなったら
	if (g_player.nCounterMotion >= g_player.aMotionInfo[g_player.motionType].aKeyInfo[g_player.nKey].nFrame)
	{
		g_player.nCounterMotion = 0;
		g_player.nKey++;
	}
}

//============================================================
// プレイヤーのモーション読込
//============================================================
void LoadMotionPlayer()
{
	int motionType = MOTIONTYPE_NEUTRAL;
	int nNummodel = 0;
	int nNumKey = 0;
	int ver = 0;

	FILE* pFile;
	pFile = fopen("data\\MODEL\\player\\motion.txt", "r");

	if (pFile != NULL)
	{
		while (1)
		{
			char aString[128];
			//ファイルを読みこむ
			fscanf(pFile, "%s", &aString[0]);

			if (strcmp(aString, "MOTIONSET") == 0)//ENEMYSETを読込んだなら
			{
				while (1)
				{
					//ファイルを読みこむ
					fscanf(pFile, "%s", &aString[0]);

					if (strcmp(aString, "LOOP") == 0)
					{
						//ループの有無取得
						fscanf(pFile, "%d", &ver);

						if (ver == 1)
						{
							g_player.aMotionInfo[motionType].bLoop = true;
						}
						else if (ver == 0)
						{
							g_player.aMotionInfo[motionType].bLoop = false;
						}

						g_player.bLoopMotion = g_player.aMotionInfo[motionType].bLoop;

					}
					else if (strcmp(aString, "NUM_KEY") == 0)
					{
						//最大キーの取得
						fscanf(pFile, "%d", &g_player.aMotionInfo[motionType].nNumKey);

						g_player.nNumKey = g_player.aMotionInfo[motionType].nNumKey;
					}
					else if (strcmp(aString, "KEYSET") == 0)
					{
						while (1)
						{
							//ファイルを読みこむ
							fscanf(pFile, "%s", &aString[0]);

							if (strcmp(aString, "FRAME") == 0)
							{
								fscanf(pFile, "%d", &g_player.aMotionInfo[motionType].aKeyInfo[nNumKey].nFrame);
							}
							else if (strcmp(aString, "KEY") == 0)
							{
								//モデルの取得
								//fscanf(pFile, "%d", &nNummodel);
								while (1)
								{
									//ファイルを読みこむ
									fscanf(pFile, "%s", &aString[0]);
									if (strcmp(aString, "POS") == 0)
									{
										g_player.aMotionInfo[motionType].aKeyInfo[nNumKey].aKEY[nNummodel].fPosX = 0.0f;
										g_player.aMotionInfo[motionType].aKeyInfo[nNumKey].aKEY[nNummodel].fPosY = 0.0f;
										g_player.aMotionInfo[motionType].aKeyInfo[nNumKey].aKEY[nNummodel].fPosZ = 0.0f;
									}
									else if (strcmp(aString, "ROT") == 0)
									{
										fscanf(pFile, "%f", &g_player.aMotionInfo[motionType].aKeyInfo[nNumKey].aKEY[nNummodel].fRotX);
										fscanf(pFile, "%f", &g_player.aMotionInfo[motionType].aKeyInfo[nNumKey].aKEY[nNummodel].fRotY);
										fscanf(pFile, "%f", &g_player.aMotionInfo[motionType].aKeyInfo[nNumKey].aKEY[nNummodel].fRotZ);
									}
									else if (strcmp(aString, "END_KEY") == 0)
									{
										 nNummodel++;
										 break;
									}
								}

							}										
							else if (strcmp(aString, "END_KEYSET") == 0)
							{
								nNumKey++;
								break;
							}
						}
					}
					else if (strcmp(aString, "END_MOTIONSET") == 0)
					{
						motionType++;
						break;
					}
				}

			}
			else if (strcmp(aString, "END_SCRIPT") == 0)
			{
				break;
			}
		}

		fclose(pFile);
	}
	else
	{
		return;
	}
}

//============================================================
// プレイヤーの情報取得
//============================================================
Player* GetPlayer()
{
	return &g_player;
}

