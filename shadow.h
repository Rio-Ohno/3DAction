//============================================================
//
//�e[shadow.h]
//Author:Rio Ohno
//
//=============================================================

#ifndef _SHADOW_H_
#define _SHADOW_H_

#include"main.h"

//�}�N����`
#define MAX_SHADOW (1024)												//�e�̍ő吔
#define BASIS_SIZE (30.0f)												//�T�C�Y�̊

//�e�̍\����
typedef struct
{
	D3DXVECTOR3 pos;													//�ʒu
	D3DXVECTOR3 rot;													//����
	D3DXVECTOR3 scale;													//�{��(�30)
	D3DXMATRIX mtxWorld;												//���[���h�}�g���b�N�X
	bool bUse;															//�g�p���Ă��邩�ǂ���
}Shadow;

//�v���g�^�C�v�錾
void InitShadow();														//�e�̏�����
void UninitShadow();													//�e�̏I������
void UpdateShadow();													//�e�̍X�V����
void DrawShadow();														//�e�̕`�揈��
int SetShadow(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale);		//�e�̐ݒ菈��
void SetPositionShadow(int nIndxShadow, D3DXVECTOR3 pos);				//�e�̈ʒu�ݒ菈��
void DeleteShadow(int nIndx);											//�e����������

#endif // !_Shadow_H_
#pragma once
