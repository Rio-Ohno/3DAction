//============================================================
//
//3Dアクションゲー[main.h]
//Author:Rio Ohno
//
//=============================================================

#ifndef _MAIN_H_
#define _MAIN_H_

#include<windows.h>
#include"d3dx9.h"
#define DIRECTINPUT_VERSION (0x0800)        //ビルド時の警告対処用マクロ
#include"dinput.h"                          //入力処理に必要
#include"Xinput.h"                          //ジョイパッドに必要
#include"xaudio2.h"							//サウンド処理に必要

//ライブラリ・潟塔N 
#pragma comment(lib,"d3d9.lib")             //描画処理に必要
#pragma comment(lib,"d3dx9.lib")            //[d3d9.lib]の拡張ライブラリ
#pragma comment(lib,"dxguid.lib")           //DirectXコンポーネント（部品）使用に必要
#pragma comment(lib,"winmm.lib")            //システム時刻取得に必要
#pragma comment(lib,"dinput8.lib")          //入力処理に必要
#pragma comment(lib,"xinput.lib")           //ジョイパッド処理に必要

//マクロ定義
#define CLASS_NAME "WindowClass"			//ウィンドウクラスの名前
#define WINDOW_NAME "action"				//ウィンドウの名前（キャプションに表示）
#define SCREEN_WIDTH (1280)					//ウィンドウの幅
#define SCREEN_HEIGHT (720)				    //ウィンドウの高さ
#define FVF_VERTEX_2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
#define FVF_VERTEX_3D (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_DIFFUSE|D3DFVF_TEX1)//座標・法線・カラー・テクスチャ
#define NUM_EIGHT (8)						//８

//頂点情報[2D]の構造体
typedef struct
{

	D3DXVECTOR3 pos;                        //頂点座標
	float rhw;                              //座標・ｷ用係数（1.0f・?閨j
	D3DCOLOR col;                           //頂点カラー
	D3DXVECTOR2 tex;                        //テクスチャ座標

}VERTEX_2D;

//頂点情報[3D]の構造体
typedef struct
{
	D3DXVECTOR3 pos;						//頂点座標
	D3DXVECTOR3 nor;						//法線ベクトル
	D3DCOLOR col;							//頂点カラー
	D3DXVECTOR2 tex;						//テクスチャ座標
}VERTEX_3D;

//画面モードの種類
typedef enum
{
	MODE_TITLE = 0,                           //タイトル画面
	MODE_TUTORIAL,							//チュートリアル画面
	MODE_GAME,                              //ゲーム画面
	MODE_RESULT,                            //リザルト画面
	MODE_RANKING,							//ランキング画面
	MODE_MAX
}MODE;

//プロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
void Uninit();
void Update();
void Draw();
void DrawFPS();
void DrawCameraType();
void DrawCameraControl();
void DrawCameraRot();
void DrawPlayerRot();
void DrawPlayerPos();
LPDIRECT3DDEVICE9 GetDevice(void);
void SetMode(MODE mode);
MODE GetMode();
void onWireFrame();
void offWireFrame();

#endif // !_MAIN_H_