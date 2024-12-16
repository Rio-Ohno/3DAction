//============================================================
//
//アイテム[Item.cpp]
//Author:Rio Ohno
//
//============================================================

#include"Item.h"
#include "player.h"

//グロ－バル変数宣言
Item g_Item[MAX_ITEM];
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItemBill = NULL;						//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureItemBill = NULL;							//テクスチャへのポインタ
int g_nCntItem = 0;														//現状のアイテム数

//============================================================
// モデルの初期化処理
//============================================================
void InitItem()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATERIAL* pMat;													//マテリアルデータへのポインタ
	g_nCntItem = 0;														//現状のアイテム数の初期化

	//テクスチャの読込
	D3DXCreateTextureFromFile(pDevice,
		NULL,
		&g_pTextureItemBill);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_ITEM,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffItemBill,
		NULL);

	//頂点情報へのポインタ
	VERTEX_3D* pVtx = NULL;

	//頂点バッファをロック
	g_pVtxBuffItemBill->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		//各種初期化
		g_Item[nCntItem].pMesh = NULL;									//メッシュポインタ
		g_Item[nCntItem].pBuffMat = NULL;								//マテリアル
		g_Item[nCntItem].dwNumMat = 0;									//頂点情報
		g_Item[nCntItem].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//位置
		g_Item[nCntItem].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//向き
		g_Item[nCntItem].Type = 0;										//種類
		g_Item[nCntItem].bUse = false;									//使用しいていない状態

		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		//ビルボード
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//各頂点の法線の設定
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0);

		//テクスチャ座標の設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;

		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		//モデル
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_Item[nCntItem].mtxWorld);

		//Xファイルの読込
		D3DXLoadMeshFromX(NULL,
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_Item[nCntItem].pBuffMat,
			NULL,
			&g_Item[nCntItem].dwNumMat,
			&g_Item[nCntItem].pMesh);

		//マテリアルデータへのポインタを取得
		pMat = (D3DXMATERIAL*)g_Item[nCntItem].pBuffMat->GetBufferPointer();

		for (int nCnt = 0; nCnt < (int)g_Item[nCntItem].dwNumMat; nCnt++)
		{
			//テクスチャポインタの初期化
			g_Item[nCntItem].apTextureItem[nCnt] = {};

			if (pMat[nCnt].pTextureFilename != NULL)
			{
				//テクスチャの読込
				D3DXCreateTextureFromFile(pDevice,
					pMat[nCnt].pTextureFilename,
					&g_Item[nCntItem].apTextureItem[nCnt]);

			}
		}
	}
}

//============================================================
// モデルの終了処理
//============================================================
void UninitItem()
{
	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		//メッシュの破棄
		if (g_Item[nCntItem].pMesh != NULL)
		{
			g_Item[nCntItem].pMesh->Release();
			g_Item[nCntItem].pMesh = NULL;
		}

		//マテリアルの破棄
		if (g_Item[nCntItem].pBuffMat != NULL)
		{
			g_Item[nCntItem].pBuffMat->Release();
			g_Item[nCntItem].pBuffMat = NULL;
		}

		for (int nCnt = 0; nCnt < (int)g_Item[nCntItem].dwNumMat; nCnt++)
		{
			if (g_Item[nCntItem].apTextureItem[nCnt] != NULL)
			{
				g_Item[nCntItem].apTextureItem[nCnt]->Release();
				g_Item[nCntItem].apTextureItem[nCnt] = NULL;
			}
		}
	}
}

//============================================================
// モデルの更新処理
//============================================================
void UpdateItem()
{
	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		if (g_Item[nCntItem].bUse == true)
		{
		}
	}
}

//============================================================
// アイテム(モデル)の描画処理
//============================================================
void DrawItemModel()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;										//計算用マトリックス
	D3DMATERIAL9 matDef;												//現在のマテリアル保存用
	D3DXMATERIAL* pMat;													//マテリアルデータへのポインタ

	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		if (g_Item[nCntItem].bUse == true)								//使用している時
		{
			if (g_Item[nCntItem].bModel == true)						//3Dモデルの時
			{
				//ワールドマトリックスの初期化
				D3DXMatrixIdentity(&g_Item[nCntItem].mtxWorld);

				//向きを反映
				D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Item[nCntItem].rot.y, g_Item[nCntItem].rot.x, g_Item[nCntItem].rot.z);
				D3DXMatrixMultiply(&g_Item[nCntItem].mtxWorld, &g_Item[nCntItem].mtxWorld, &mtxRot);

				//位置を反映
				D3DXMatrixTranslation(&mtxTrans, g_Item[nCntItem].pos.x, g_Item[nCntItem].pos.y, g_Item[nCntItem].pos.z);
				D3DXMatrixMultiply(&g_Item[nCntItem].mtxWorld, &g_Item[nCntItem].mtxWorld, &mtxTrans);

				//ワールドマトリックスの設定
				pDevice->SetTransform(D3DTS_WORLD, &g_Item[nCntItem].mtxWorld);

				//現在のマテリアルを取得
				pDevice->GetMaterial(&matDef);

				//マテリアルデータへのポインタを取得
				pMat = (D3DXMATERIAL*)g_Item[nCntItem].pBuffMat->GetBufferPointer();

				for (int nCnt = 0; nCnt < (int)g_Item[nCntItem].dwNumMat; nCnt++)
				{

					//マテリアルの設定
					pDevice->SetMaterial(&pMat[nCnt].MatD3D);

					//テクスチャの設定
					pDevice->SetTexture(0, g_Item[nCntItem].apTextureItem[nCnt]);

					//モデル(パーツ)の描画
					g_Item[nCntItem].pMesh->DrawSubset(nCnt);
				}

				//保存していたマテリアルを戻す
				pDevice->SetMaterial(&matDef);
			}
		}
	}
}

//============================================================
// アイテム(ビルボード)の描画処理
//============================================================
void DrawItemBillboard()
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//計算用マトリックス
	D3DXMATRIX mtxRot, mtxTrans;

	//ライトの無効化
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	//アルファテストを有効化
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);

	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		if (g_Item[nCntItem].bUse == true)
		{
			if (g_Item[nCntItem].bModel == false)
			{
				//ワールドマトリックスの初期化
				D3DXMatrixIdentity(&g_Item[nCntItem].mtxWorld);

				D3DXMATRIX mtxView;//ビューマトリックス

				//ビューマトリックスの取得
				pDevice->GetTransform(D3DTS_VIEW, &mtxView);

				//カメラの逆行列を設定
				g_Item[nCntItem].mtxWorld._11 = mtxView._11;
				g_Item[nCntItem].mtxWorld._12 = mtxView._21;
				g_Item[nCntItem].mtxWorld._13 = mtxView._31;
				g_Item[nCntItem].mtxWorld._21 = mtxView._12;
				g_Item[nCntItem].mtxWorld._22 = mtxView._22;
				g_Item[nCntItem].mtxWorld._23 = mtxView._32;
				g_Item[nCntItem].mtxWorld._31 = mtxView._13;
				g_Item[nCntItem].mtxWorld._32 = mtxView._23;
				g_Item[nCntItem].mtxWorld._33 = mtxView._33;

				//位置を反映
				D3DXMatrixTranslation(&mtxTrans, g_Item[nCntItem].pos.x, g_Item[nCntItem].pos.y, g_Item[nCntItem].pos.z);
				D3DXMatrixMultiply(&g_Item[nCntItem].mtxWorld, &g_Item[nCntItem].mtxWorld, &mtxTrans);

				//ワールドマトリックスの設定
				pDevice->SetTransform(D3DTS_WORLD, &g_Item[nCntItem].mtxWorld);

				//頂点バッファをデバイスのデータストリームに設定
				pDevice->SetStreamSource(0, g_pVtxBuffItemBill, 0, sizeof(VERTEX_3D));

				//頂点フォーマットの設定
				pDevice->SetFVF(FVF_VERTEX_3D);

				//テクスチャ座標の設定
				pDevice->SetTexture(0, g_pTextureItemBill);

				//ポリゴンの描画
				pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntItem * 4, 2);
			}
		}
	}

	//ライト有効化
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	//アルファテストを無効化
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//============================================================
// アイテムの設定処理
//============================================================
void SetItem(D3DXVECTOR3 pos, int nType)
{
	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		if (g_nCntItem != MAX_ITEM)//最大ドロップ数を超えてないなら
		{
			if (g_Item[nCntItem].bUse == false)
			{
				g_Item[nCntItem].bUse = true;								//使用している状態にする
				g_Item[nCntItem].pos = pos;									//位置の設定
				g_Item[nCntItem].Type = nType;								//種類の設定
				g_nCntItem++;												//アイテム数カウント

				switch (g_Item[nCntItem].Type)
				{
				case 0://ちゅ～る

					g_Item[nCntItem].bModel = false;

					break;

				case 1://マタタビ

					g_Item[nCntItem].bModel = true;

					break;

				case 2://おもちゃ

					g_Item[nCntItem].bModel = true;

					break;

				default://ドロップしない

					g_Item[nCntItem].bUse = false;							//使用していない状態にする
					g_nCntItem--;											//アイテム数デクリメント

					break;
				}
			}
		}
		else if (g_nCntItem == MAX_ITEM)//最大ドロップ数を超えてるなら
		{
			break;
		}
	}
}

//============================================================
// アイテムの取得処理
//============================================================
void CollisionItem(int nIndexItem)
{
	//プレイヤーの情報取得
	Player* pPlayer = GetPlayer();

	if (g_Item[nIndexItem].bUse == true)//使用している状態なら
	{
		if (g_Item[nIndexItem].bModel == true)//モデルなら
		{
		}
		else if (g_Item[nIndexItem].bModel == false)//ビルボードなら
		{
		}
	}
}