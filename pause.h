//============================================================
//
//シューティングゲー[pause.h]
//Author:Rio Ohno
//
//============================================================

#ifndef _PAUSE_H_
#define _PAUSE_H_

#include "main.h"

//ポーズメニュー
typedef enum
{
	PAUSE_MENU_CONTINUE=0,	//ゲームに戻る
	PAUSE_MENU_RETRY,		//ゲームをやり直す
	PAUSE_MENU_QUIT,		//タイトルに戻る
	PAUSE_MENU_MAX			
}PAUSE_MENU;


//プロトタイプ宣言
void InitPause();
void UninitPause();
void UpdatePause();
void DrawPause();

#endif // !PAUSE_H_

