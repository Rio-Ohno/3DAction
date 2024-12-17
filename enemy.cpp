//============================================================
//
//敵[enemy.cpp]
//Author:Rio Ohno
//
//============================================================

#include"enemy.h"
//#include "block.h"
#include "wall.h"
#include"bullet.h"
#include"Item.h"

//グロ－バル変数宣言
Enemy g_enemy[MAX_ENEMY];
static  Key_ENEMY_Info g_keyNeutrall[] =
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
	{{0.0f,0.0f,0.0f,0.06f, 0.0f, 0.0f},
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

//============================================================
// 敵の初期化処理
//============================================================
void InitEnemy()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATERIAL* pMat;//マテリアルデータへのポインタ
	int nCntEnemy = 0;

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		//各種初期化
		g_enemy[nCntEnemy].pos = D3DXVECTOR3(50.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].vtxMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].vtxMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].motionType = MOTIONTYPE_ENEMY_NEUTRAL;
		g_enemy[nCntEnemy].nLife = 1;
		g_enemy[nCntEnemy].nNumModel = 0;
		g_enemy[nCntEnemy].nNumMotion = 0;
		g_enemy[nCntEnemy].nNumKey = 0;
		g_enemy[nCntEnemy].nKey = 1;
		g_enemy[nCntEnemy].nCounterMotion = 0;
		g_enemy[nCntEnemy].nCntFream = 0;
		g_enemy[nCntEnemy].nIndxShadow = SetShadow(g_enemy[nCntEnemy].pos, g_enemy[nCntEnemy].rot, D3DXVECTOR3(1.0f, 0.5f, 1.0f));
		g_enemy[nCntEnemy].bjump = false;
		g_enemy[nCntEnemy].bUse = true;
		g_enemy[nCntEnemy].bFrag = false;

		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_enemy[nCntEnemy].mtxWorldEnemy);


		//Xファイルの読込
		D3DXLoadMeshFromX("data\\MODEL\\enemy\\koshi.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[0].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[0].dwNumMat,
			&g_enemy[nCntEnemy].aModel[0].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\mune.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[1].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[1].dwNumMat,
			&g_enemy[nCntEnemy].aModel[1].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\atama.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[2].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[2].dwNumMat,
			&g_enemy[nCntEnemy].aModel[2].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rkata.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[3].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[3].dwNumMat,
			&g_enemy[nCntEnemy].aModel[3].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rnino.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[4].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[4].dwNumMat,
			&g_enemy[nCntEnemy].aModel[4].pMesh);


		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rude.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[5].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[5].dwNumMat,
			&g_enemy[nCntEnemy].aModel[5].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lkata.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[6].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[6].dwNumMat,
			&g_enemy[nCntEnemy].aModel[6].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lnino.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[7].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[7].dwNumMat,
			&g_enemy[nCntEnemy].aModel[7].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lude.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[8].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[8].dwNumMat,
			&g_enemy[nCntEnemy].aModel[8].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rmomo.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[9].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[9].dwNumMat,
			&g_enemy[nCntEnemy].aModel[9].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rhiza.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[10].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[10].dwNumMat,
			&g_enemy[nCntEnemy].aModel[10].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rashi.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[11].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[11].dwNumMat,
			&g_enemy[nCntEnemy].aModel[11].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lmomo.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[12].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[12].dwNumMat,
			&g_enemy[nCntEnemy].aModel[12].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lhiza.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[13].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[13].dwNumMat,
			&g_enemy[nCntEnemy].aModel[13].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lashi.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[14].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[14].dwNumMat,
			&g_enemy[nCntEnemy].aModel[14].pMesh);

		g_enemy[nCntEnemy].nNumModel = 15;												//パーツ数の設定

		//各パーツの階層構造設定
		g_enemy[nCntEnemy].aModel[0].nIndxModelpParent = -1;
		g_enemy[nCntEnemy].aModel[0].pos = D3DXVECTOR3(0.0f, 17.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[0].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[1].nIndxModelpParent = 0;
		g_enemy[nCntEnemy].aModel[1].pos = D3DXVECTOR3(0.0f, 12.5f, 0.0f);
		g_enemy[nCntEnemy].aModel[1].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[2].nIndxModelpParent = 1;
		g_enemy[nCntEnemy].aModel[2].pos = D3DXVECTOR3(0.0f, 12.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[2].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[3].nIndxModelpParent = 1;
		g_enemy[nCntEnemy].aModel[3].pos = D3DXVECTOR3(-2.5f, 10.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[3].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[4].nIndxModelpParent = 3;
		g_enemy[nCntEnemy].aModel[4].pos = D3DXVECTOR3(-5.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[4].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[5].nIndxModelpParent = 4;
		g_enemy[nCntEnemy].aModel[5].pos = D3DXVECTOR3(-10.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[5].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[6].nIndxModelpParent = 1;
		g_enemy[nCntEnemy].aModel[6].pos = D3DXVECTOR3(2.5f, 10.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[6].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[7].nIndxModelpParent = 6;
		g_enemy[nCntEnemy].aModel[7].pos = D3DXVECTOR3(5.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[7].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[8].nIndxModelpParent = 7;
		g_enemy[nCntEnemy].aModel[8].pos = D3DXVECTOR3(10.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[8].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[9].nIndxModelpParent = 0;
		g_enemy[nCntEnemy].aModel[9].pos = D3DXVECTOR3(-5.0f, 7.5f, 1.0f);
		g_enemy[nCntEnemy].aModel[9].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[10].nIndxModelpParent = 9;
		g_enemy[nCntEnemy].aModel[10].pos = D3DXVECTOR3(0.0f, -12.5f, 0.0f);
		g_enemy[nCntEnemy].aModel[10].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[11].nIndxModelpParent = 10;
		g_enemy[nCntEnemy].aModel[11].pos = D3DXVECTOR3(0.0f, -5.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[11].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[12].nIndxModelpParent = 0;
		g_enemy[nCntEnemy].aModel[12].pos = D3DXVECTOR3(5.0f, 7.5f, 1.0f);
		g_enemy[nCntEnemy].aModel[12].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[13].nIndxModelpParent = 12;
		g_enemy[nCntEnemy].aModel[13].pos = D3DXVECTOR3(0.0f, -12.5f, 0.0f);
		g_enemy[nCntEnemy].aModel[13].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[14].nIndxModelpParent = 13;
		g_enemy[nCntEnemy].aModel[14].pos = D3DXVECTOR3(0.0f, -5.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[14].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


		for (int nCntModel = 0; nCntModel < g_enemy[nCntEnemy].nNumModel; nCntModel++)
		{
			int nNumVtx;//最大頂点数
			DWORD sizeFVF;//頂点フォーマットのサイズ
			BYTE* pVtxBUff;//頂点バッファへのポインタ

			//頂点数の取得
			nNumVtx = g_enemy[nCntEnemy].aModel[nCntModel].pMesh->GetNumVertices();

			//頂点フォーマットのサイズを取得
			sizeFVF = D3DXGetFVFVertexSize(g_enemy[nCntEnemy].aModel[nCntModel].pMesh->GetFVF());

			//頂点バッファのロック
			g_enemy[nCntEnemy].aModel[nCntModel].pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBUff);

			for (int nCnt = 0; nCnt < nNumVtx; nCnt++)
			{
				//頂点座標の代入
				D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBUff;

				//頂点座標を比較してモデルの最大最小を取得

				if (vtx.x > g_enemy[nCntEnemy].vtxMax.x)//x最大値
				{
					g_enemy[nCntEnemy].vtxMax.x = vtx.x;
				}
				else if (vtx.x < g_enemy[nCntEnemy].vtxMin.x)//x最小値
				{
					g_enemy[nCntEnemy].vtxMin.x = vtx.x;
				}

				if (vtx.y > g_enemy[nCntEnemy].vtxMax.y)//y最大値
				{
					g_enemy[nCntEnemy].vtxMax.y = vtx.y;
				}
				else if (vtx.y < g_enemy[nCntEnemy].vtxMin.y)//y最小値
				{
					g_enemy[nCntEnemy].vtxMin.y = vtx.y;
				}

				if (vtx.z > g_enemy[nCntEnemy].vtxMax.z)//z最大値
				{
					g_enemy[nCntEnemy].vtxMax.z = vtx.z;
				}
				else if (vtx.z < g_enemy[nCntEnemy].vtxMin.z)//z最小値
				{
					g_enemy[nCntEnemy].vtxMin.z = vtx.z;
				}

				//頂点フォーマットのサイズ分ポインタを進める
				pVtxBUff += sizeFVF;
			}

			//頂点バッファのアンロック
			g_enemy[nCntEnemy].aModel[nCntModel].pMesh->UnlockVertexBuffer();

			//サイズの初期化
			g_enemy[nCntEnemy].size = g_enemy[nCntEnemy].vtxMax - g_enemy[nCntEnemy].vtxMin;

			//マテリアルデータへのポインタを取得
			pMat = (D3DXMATERIAL*)g_enemy[nCntEnemy].aModel[nCntModel].pBuffMat->GetBufferPointer();

			for (int nCnt = 0; nCnt < (int)g_enemy[nCntEnemy].aModel[nCntModel].dwNumMat; nCnt++)
			{
				//テクスチャポインタの初期化
				g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt] = {};

				if (pMat[nCnt].pTextureFilename != NULL)
				{
					//テクスチャの読込
					D3DXCreateTextureFromFile(pDevice,
						pMat[nCnt].pTextureFilename,
						&g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt]);
				}
			}
		}
	}
}

//============================================================
// 敵の終了処理
//============================================================
void UninitEnemy()
{
	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		for (int nCntModel = 0; nCntModel < g_enemy[nCntEnemy].nNumModel; nCntModel++)
		{

			//メッシュの破棄
			if (g_enemy[nCntEnemy].aModel[nCntModel].pMesh != NULL)
			{
				g_enemy[nCntEnemy].aModel[nCntModel].pMesh->Release();
				g_enemy[nCntEnemy].aModel[nCntModel].pMesh = NULL;
			}

			//マテリアルの破棄
			if (g_enemy[nCntEnemy].aModel[nCntModel].pBuffMat != NULL)
			{
				g_enemy[nCntEnemy].aModel[nCntModel].pBuffMat->Release();
				g_enemy[nCntEnemy].aModel[nCntModel].pBuffMat = NULL;
			}

			//テクスチャの破棄
			for (int nCnt1 = 0; nCnt1 < (int)g_enemy[nCntEnemy].aModel[nCntModel].dwNumMat; nCnt1++)
			{
				if (g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt1] != NULL)
				{
					g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt1]->Release();
					g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt1] = NULL;
				}
			}
		}
	}
}

//============================================================
// 敵の更新処理
//============================================================
void UpdateEnemy()
{
	//カメラの情報取得
	Camera* pCamera = GetCamera();

	//プレイヤーの情報取得
	Player* pPlayer = GetPlayer();

	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_enemy[nCntEnemy].bUse == true)
		{
			//行動パターン
			if (g_enemy[nCntEnemy].motionType == MOTIONTYPE_ENEMY_ESCAPE)
			{
				g_enemy[nCntEnemy].move.x = -sinf(g_enemy[nCntEnemy].rot.y) * 2.0f;
				g_enemy[nCntEnemy].move.z = -cosf(g_enemy[nCntEnemy].rot.y) * 2.0f;

				g_enemy[nCntEnemy].nCntFream++;

				if (g_enemy[nCntEnemy].nCntFream == 60)
				{
					g_enemy[nCntEnemy].bUse = false;
					DeleteShadow(g_enemy[nCntEnemy].nIndxShadow);
				}
				else if(g_enemy[nCntEnemy].nCntFream==30)
				{
					//アイテムドロップ
					int nType = rand() % 12;											//ドロップ率:25%	種類:33% (偏りなし)
					SetItem(g_enemy[nCntEnemy].pos, 1);
				}
			}

			//posOldの保存
			g_enemy[nCntEnemy].posOld = g_enemy[nCntEnemy].pos;

			//重力
			g_enemy[nCntEnemy].move.y -= 0.8f;

			//目標の移動方向（角度）の補正
			if (g_enemy[nCntEnemy].rotDest.y > D3DX_PI)
			{
				g_enemy[nCntEnemy].rotDest.y -= D3DX_PI * 2.0f;
			}
			else if (g_enemy[nCntEnemy].rotDest.y < -D3DX_PI)
			{
				g_enemy[nCntEnemy].rotDest.y += D3DX_PI * 2.0f;
			}

			//向きの更新
			g_enemy[nCntEnemy].rot.y += (g_enemy[nCntEnemy].rotDest.y - g_enemy[nCntEnemy].rot.y) * 0.15f;

			//目標の移動方向（角度）の補正
			if (g_enemy[nCntEnemy].rot.y > D3DX_PI)
			{
				g_enemy[nCntEnemy].rot.y -= D3DX_PI * 2.0f;
			}
			else if (g_enemy[nCntEnemy].rot.y < -D3DX_PI)
			{
				g_enemy[nCntEnemy].rot.y += D3DX_PI * 2.0f;
			}

			//位置の更新
			g_enemy[nCntEnemy].pos += g_enemy[nCntEnemy].move;

			//移動量の更新(減衰)
			g_enemy[nCntEnemy].move.x = (0.0f - g_enemy[nCntEnemy].move.x) * 0.1f;
			g_enemy[nCntEnemy].move.y = (0.0f - g_enemy[nCntEnemy].move.y) * 0.1f;
			g_enemy[nCntEnemy].move.z = (0.0f - g_enemy[nCntEnemy].move.z) * 0.1f;

			//床判定
			if (g_enemy[nCntEnemy].pos.y < 0)
			{
				g_enemy[nCntEnemy].pos.y = 0;
				g_enemy[nCntEnemy].bjump = false;
			}

			//影の位置更新
			SetPositionShadow(g_enemy[nCntEnemy].nIndxShadow, g_enemy[nCntEnemy].pos);

			//当たり判定
			//CollisionBlock_X();
			//CollisionBlock_Z();
			g_enemy[nCntEnemy].bFrag = CollisionWall();

			//モーション
			SetMotionEnemy();
		}
	}
}

//============================================================
// 敵の描画処理
//============================================================
void DrawEnemy()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;						//計算用マトリックス
	D3DMATERIAL9 matDef;								//現在のマテリアル保存用
	D3DXMATERIAL* pMat;									//マテリアルデータへのポインタ


	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_enemy[nCntEnemy].bUse == true)
		{
			//ワールドマトリックスの初期化
			D3DXMatrixIdentity(&g_enemy[nCntEnemy].mtxWorldEnemy);

			//向きを反映
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_enemy[nCntEnemy].rot.y, g_enemy[nCntEnemy].rot.x, g_enemy[nCntEnemy].rot.z);
			D3DXMatrixMultiply(&g_enemy[nCntEnemy].mtxWorldEnemy, &g_enemy[nCntEnemy].mtxWorldEnemy, &mtxRot);

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_enemy[nCntEnemy].pos.x, g_enemy[nCntEnemy].pos.y, g_enemy[nCntEnemy].pos.z);
			D3DXMatrixMultiply(&g_enemy[nCntEnemy].mtxWorldEnemy, &g_enemy[nCntEnemy].mtxWorldEnemy, &mtxTrans);

			//ワールドマトリックスの設定
			pDevice->SetTransform(D3DTS_WORLD, &g_enemy[nCntEnemy].mtxWorldEnemy);

			//現在のマテリアルを取得
			pDevice->GetMaterial(&matDef);


			for (int nCntModel = 0; nCntModel < g_enemy[nCntEnemy].nNumModel; nCntModel++)
			{
				D3DXMATRIX  mtxRotModel, mtxTransModel;	//計算用マトリックス
				D3DXMATRIX mtxParent;					//親のマtリックス

				//マテリアルデータへのポインタを取得
				pMat = (D3DXMATERIAL*)g_enemy[nCntEnemy].aModel[nCntModel].pBuffMat->GetBufferPointer();

				//パーツのワールドマトリックスの初期化
				D3DXMatrixIdentity(&g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld);

				//向きを反映
				D3DXMatrixRotationYawPitchRoll(&mtxRotModel, g_enemy[nCntEnemy].aModel[nCntModel].rot.y, g_enemy[nCntEnemy].aModel[nCntModel].rot.x, g_enemy[nCntEnemy].aModel[nCntModel].rot.z);
				D3DXMatrixMultiply(&g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &mtxRotModel);

				//位置を反映
				D3DXMatrixTranslation(&mtxTransModel, g_enemy[nCntEnemy].aModel[nCntModel].pos.x, g_enemy[nCntEnemy].aModel[nCntModel].pos.y, g_enemy[nCntEnemy].aModel[nCntModel].pos.z);
				D3DXMatrixMultiply(&g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &mtxTransModel);

				//パーツの親マトリックスの設定
				if (g_enemy[nCntEnemy].aModel[nCntModel].nIndxModelpParent != -1)//子の時
				{
					mtxParent = g_enemy[nCntEnemy].aModel[g_enemy[nCntEnemy].aModel[nCntModel].nIndxModelpParent].mtxWorld;
				}
				else//親の時
				{
					mtxParent = g_enemy[nCntEnemy].mtxWorldEnemy;
				}

				//算出したパーツのワールドマトリックスと親のマトリックスをかけ合わせる
				D3DXMatrixMultiply(&g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &mtxParent);

				//パーツのワールドマトリックスの設定
				pDevice->SetTransform(D3DTS_WORLD, &g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld);

				for (int nCnt1 = 0; nCnt1 < (int)g_enemy[nCntEnemy].aModel[nCntModel].dwNumMat; nCnt1++)
				{
					//マテリアルの設定
					pDevice->SetMaterial(&pMat[nCnt1].MatD3D);

					//テクスチャの設定
					pDevice->SetTexture(0, g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt1]);

					//モデル(パーツ)の描画
					g_enemy[nCntEnemy].aModel[nCntModel].pMesh->DrawSubset(nCnt1);
				}

			}
			//保存していたマテリアルを戻す
			pDevice->SetMaterial(&matDef);
		}
	}
}

//============================================================
// 敵の設定処理
//============================================================
void SetEnemy(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_enemy[nCntEnemy].bUse == false)
		{
			g_enemy[nCntEnemy].pos = pos;//位置の設定
			g_enemy[nCntEnemy].rot = rot;//向きの設定

			g_enemy[nCntEnemy].bUse = true;//使用している状態にする
		}
	}
}

//============================================================
// 敵のモーション設定・動かし
//============================================================
void SetMotionEnemy()
{
	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		switch (g_enemy[nCntEnemy].motionType)
		{
		case MOTIONTYPE_ENEMY_NEUTRAL:

			g_enemy[nCntEnemy].bLoopMotion = true;
			g_enemy[nCntEnemy].nNumKey = 2;

			break;

		case MOTIONTYPE_ENEMY_MOVE:
			break;

		case MOTIONTYPE_ENEMY_ATTACK:
			break;

		case MOTIONTYPE_ENEMY_JUMP:
			break;

		case MOTIONTYPE_ENEMY_ESCAPE:
			break;
		}

		//全モデル(パーツ)の更新
		for (int nCntModel = 0; nCntModel < g_enemy[nCntEnemy].nNumModel; nCntModel++)
		{//キー情報から位置と向きを算出

			//次のキー
			int NextKey = (g_enemy[nCntEnemy].nKey + 1) % g_enemy[nCntEnemy].nNumKey;
			if (g_enemy[nCntEnemy].bLoopMotion == true)
			{
				if (g_enemy[nCntEnemy].nKey >= g_enemy[nCntEnemy].nNumKey)
				{//キーの最大数より大きくなったら
					g_enemy[nCntEnemy].nKey = 0;
				}
				else if (NextKey >= g_enemy[nCntEnemy].nNumKey)
				{
					NextKey = 0;
				}
			}

			//差分格納用　　
			D3DXVECTOR3 sPos, sRot;

			sPos.x = g_keyNeutrall[NextKey].aKEY[nCntModel].fPosX - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosX;
			sPos.y = g_keyNeutrall[NextKey].aKEY[nCntModel].fPosY - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosY;
			sPos.z = g_keyNeutrall[NextKey].aKEY[nCntModel].fPosZ - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosZ;

			sRot.x = g_keyNeutrall[NextKey].aKEY[nCntModel].fRotX - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotX;
			sRot.y = g_keyNeutrall[NextKey].aKEY[nCntModel].fRotY - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotY;
			sRot.z = g_keyNeutrall[NextKey].aKEY[nCntModel].fRotZ - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotZ;


			//計算結果格納用
			D3DXVECTOR3 fAnsPos, fAnsRot;

			//(モーションカウンター)/(再生フレーム数)
			float fData = (float)g_enemy[nCntEnemy].nCounterMotion / g_keyNeutrall[g_enemy[nCntEnemy].nKey].nFrame;

			fAnsPos.x = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosX + sPos.x * fData;
			fAnsPos.y = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosY + sPos.y * fData;
			fAnsPos.z = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosZ + sPos.z * fData;

			fAnsRot.x = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotX + sRot.x * fData;
			fAnsRot.y = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotY + sRot.y * fData;
			fAnsRot.z = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotZ + sRot.z * fData;

			//位置と向きを反映
			g_enemy[nCntEnemy].aModel[nCntModel].pos += fAnsPos;

			g_enemy[nCntEnemy].aModel[nCntModel].rot = fAnsRot;
		}
		//モーションカウンターを進める
		g_enemy[nCntEnemy].nCounterMotion++;

		//カウンターが再生フレームより大きくなったら
		if (g_enemy[nCntEnemy].nCounterMotion >= g_keyNeutrall[g_enemy[nCntEnemy].nKey].nFrame)
		{
			g_enemy[nCntEnemy].nCounterMotion = 0;
			g_enemy[nCntEnemy].nKey++;
		}
	}
}

//============================================================
// 敵の当たり判定
//============================================================
bool CollisionEnemy()
{
	D3DXVECTOR3 ver[16];
	D3DXVECTOR3 Pos[2];
	Player* pPlayer = GetPlayer();
	bool bLanding = false;

	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_enemy[nCntEnemy].motionType != MOTIONTYPE_ENEMY_ESCAPE)
		{
			//左右の当たり判定
			if ((pPlayer->pos.z - (pPlayer->size.z / 2)) < (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMax.z) &&
				(pPlayer->pos.z + (pPlayer->size.z / 2)) > (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMin.z))
			{
				if ((pPlayer->posOld.x + (pPlayer->size.x / 2)) <= (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMin.x) &&
					(pPlayer->pos.x + (pPlayer->size.x / 2)) > (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMin.x))
				{
					HitEnemy(nCntEnemy);
					bLanding = true;
				}
				else if ((pPlayer->posOld.x - (pPlayer->size.x / 2)) >= (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMax.x) &&
					(pPlayer->pos.x - (pPlayer->size.x / 2)) < (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMax.x))
				{
					HitEnemy(nCntEnemy);
					bLanding = true;
				}
			}

			//前後の当たり判定
			if ((pPlayer->pos.x - (pPlayer->size.x / 2)) < (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMax.x) &&
				(pPlayer->pos.x + (pPlayer->size.x / 2)) > (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMin.x))
			{
				if ((pPlayer->posOld.z + (pPlayer->size.z / 2)) <= (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMin.z) &&
					(pPlayer->pos.z + (pPlayer->size.z / 2)) > (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMin.z))
				{
					HitEnemy(nCntEnemy);
					bLanding = true;
				}
				else if ((pPlayer->posOld.z - (pPlayer->size.z / 2)) >= (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMax.z) &&
					(pPlayer->pos.z - (pPlayer->size.z / 2)) < (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMax.z))
				{
					HitEnemy(nCntEnemy);
					bLanding = true;
				}
			}
		}
	}
	return bLanding;
}

//============================================================
// 敵が被弾したときの処理
//============================================================
void HitEnemy(int nIndxEnemy)
{
	//プレイヤーの情報取得
	Player* pPlayer = GetPlayer();

	if (g_enemy[nIndxEnemy].nLife > 0)
	{
		g_enemy[nIndxEnemy].nLife--;
	}
	else if (g_enemy[nIndxEnemy].nLife <= 0)
	{
		g_enemy[nIndxEnemy].motionType = MOTIONTYPE_ENEMY_ESCAPE;
		g_enemy[nIndxEnemy].rotDest.y = pPlayer->rot.y;
		g_enemy[nIndxEnemy].rot.y = pPlayer->rot.y;
	}
}

//============================================================
// 敵の情報取得
//============================================================
Enemy* GetEnemy()
{
	return &g_enemy[0];
}