//============================================================
//
//�V���[�e�B���O�Q�[[effect.h]
//Author:Rio Ohno
//
//============================================================

#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "main.h"

//�v���g�^�C�v�錾
void InitEffect();
void UninitEffect();
void UpdateEffect();
void DrawEffect();
void SetEffect(D3DXVECTOR3 pos,D3DXCOLOR col, D3DXVECTOR3 move, float fRadius, float nLife);

#endif // !_EFFECT_H
