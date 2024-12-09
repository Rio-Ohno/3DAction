//============================================================
//
//シューティングゲー[pause.cpp]
//Author:Rio Ohno
//
//============================================================

#include"pause.h"
#include"input.h"
#include"fade.h"
#include"game.h"

//マクロ定義
#define MAX_POLY (4)										//総ポリゴン数

static const char* PAUSE_TEXTURE[MAX_POLY] =
{
	NULL,													//白背景
	"data\\TEXTURE\\Continue000.png",						//Continue
	"data\\TEXTURE\\Retry000.png",							//Retry
	"data\\TEXTURE\\Quit000.png",							//Quit
};

//グローバル変数
LPDIRECT3DTEXTURE9 g_apTexturePause[MAX_POLY] = {};			//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffPause = NULL;				//頂点バッファへのポインタ
PAUSE_MENU g_PauseMenu;										//ポーズメニュー
int g_nCntMenu;												//選択判別用

//=====================================================================================
//ポーズの初期化処理
//=====================================================================================
void InitPause()
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	g_PauseMenu = PAUSE_MENU_CONTINUE;
	g_nCntMenu = 1;

	for (int nCnt = 0; nCnt < MAX_POLY; nCnt++)
	{
		//テクスチャの設定
		D3DXCreateTextureFromFile(pDevice,
			PAUSE_TEXTURE[nCnt],
			&g_apTexturePause[nCnt]);
	}

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_POLY,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffPause,
		NULL);

	VERTEX_2D* pVtx;

	//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntPause = 0; nCntPause < MAX_POLY; nCntPause++)
	{
		if (nCntPause == 0)
		{
			//頂点座標の設定
			pVtx[0].pos = D3DXVECTOR3(0.0f,   100.0f,0.0f);
			pVtx[1].pos = D3DXVECTOR3(1280.0f,100.0f,0.0f);
			pVtx[2].pos = D3DXVECTOR3(0.0f,   620.0f,0.0f);
			pVtx[3].pos = D3DXVECTOR3(1280.0f,620.0f,0.0f);
		}
		else
		{
			//頂点座標の設定
			pVtx[0].pos = D3DXVECTOR3(325.0f, 200.0f + 100.0f * nCntPause, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(925.0f, 200.0f + 100.0f * nCntPause, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(325.0f, 250.0f + 100.0f * nCntPause, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(925.0f, 250.0f + 100.0f * nCntPause, 0.0f);
		}

		//rhwの設定
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);

		//テクスチャ座標の設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;
	}

	//頂点バッファをアンロックする
	g_pVtxBuffPause->Unlock();

}

//=====================================================================================
//ポーズの終了処理
//=====================================================================================
void UninitPause()
{
	for (int nCntPause = 0; nCntPause < MAX_POLY; nCntPause++)
	{
		//テクスチャの破棄
		if (g_apTexturePause[nCntPause] != NULL)
		{
			g_apTexturePause[nCntPause]->Release();
			g_apTexturePause[nCntPause] = NULL;
		}
	}

	//頂点バッファの破棄
	if (g_pVtxBuffPause != NULL)
	{
		g_pVtxBuffPause->Release();
		g_pVtxBuffPause = NULL;
	}

}

//=====================================================================================
//ポーズの更新処理
//=====================================================================================
void UpdatePause()
{
	if (g_nCntMenu >= 1 && g_nCntMenu < 4)
	{
		if (KeyboardTrigger(DIK_DOWN) == true)//下キーを押された
		{
			g_nCntMenu++;
		}

		if (KeyboardTrigger(DIK_UP) == true)//上キーを押された
		{
			g_nCntMenu--;
		}
	}

	VERTEX_2D* pVtx;

		switch (g_nCntMenu)
		{
		case 1:

			g_PauseMenu = PAUSE_MENU_CONTINUE;

			//頂点バッファをロックし、頂点データへのポインタを取得
			g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);

			for (int nCountPause = 0; nCountPause < MAX_POLY; nCountPause++)
			{

				if (nCountPause == 1)
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
				else
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
				}
				pVtx += 4;
			}

			//頂点バッファをアンロックする
			g_pVtxBuffPause->Unlock();

			break;

		case 2:

			g_PauseMenu = PAUSE_MENU_RETRY;

			//頂点バッファをロックし、頂点データへのポインタを取得
			g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);

			for (int nCountPause = 0; nCountPause < MAX_POLY; nCountPause++)
			{
				if (nCountPause == 2)
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
				else
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
				}
				pVtx += 4;
			}

			//頂点バッファをアンロックする
			g_pVtxBuffPause->Unlock();

			break;

		case 3:

			g_PauseMenu = PAUSE_MENU_QUIT;

			//頂点バッファをロックし、頂点データへのポインタを取得
			g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);

			for (int nCountPause = 0; nCountPause < MAX_POLY; nCountPause++)
			{

				if (nCountPause == 3)
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
				else
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
				}
				pVtx += 4;
			}

			//頂点バッファをアンロックする
			g_pVtxBuffPause->Unlock();

			break;

		default:

			g_PauseMenu = PAUSE_MENU_CONTINUE;
			if (g_nCntMenu >= 4)
			{
				g_nCntMenu = 1;

			}
			else if (g_nCntMenu < 1)
			{
				g_nCntMenu = 3;
			}

			//頂点バッファをロックし、頂点データへのポインタを取得
			g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);

			for (int nCountPause = 0; nCountPause < MAX_POLY; nCountPause++)
			{

				if (nCountPause == 1)
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
				else
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
				}
				pVtx += 4;
			}

			//頂点バッファをアンロックする
			g_pVtxBuffPause->Unlock();

			break;
		}

		//決定キーを押されたとき
		if (KeyboardTrigger(DIK_RETURN) == true)
		{
			switch (g_PauseMenu)
			{
			case PAUSE_MENU_CONTINUE:

				SetEnablePause(false);

				break;

			case PAUSE_MENU_RETRY:

				SetFade(MODE_GAME);

				break;

			case PAUSE_MENU_QUIT:

				SetFade(MODE_TITLE);

				break;
			}
		}

}

//=====================================================================================
// ポーズの描画処理
//=====================================================================================
void DrawPause()
{
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffPause, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCntPause = 0; nCntPause < MAX_POLY; nCntPause++)
	{
			//テクスチャの設定
			pDevice->SetTexture(0, g_apTexturePause[nCntPause]);

			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntPause * 4, 2);
	}
}