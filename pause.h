//============================================================
//
//�V���[�e�B���O�Q�[[pause.h]
//Author:Rio Ohno
//
//============================================================

#ifndef _PAUSE_H_
#define _PAUSE_H_

#include "main.h"

//�|�[�Y���j���[
typedef enum
{
	PAUSE_MENU_CONTINUE=0,	//�Q�[���ɖ߂�
	PAUSE_MENU_RETRY,		//�Q�[������蒼��
	PAUSE_MENU_QUIT,		//�^�C�g���ɖ߂�
	PAUSE_MENU_MAX			
}PAUSE_MENU;


//�v���g�^�C�v�錾
void InitPause();
void UninitPause();
void UpdatePause();
void DrawPause();

#endif // !PAUSE_H_

