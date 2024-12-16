//============================================================
//
//���f��[model.h]
//Author:Rio Ohno
//
//============================================================

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "main.h"

#define MAX_MAT (512)

//���f���\����
typedef struct
{
	LPD3DXMESH pMesh;									//���b�V��(���_���)�ւ̃|�C���^
	LPD3DXBUFFER pBuffMat;								//�}�e���A���ւ̃|�C���^
	DWORD dwNumMat;										//�}�e���A���̐�
	int nIndxObjectpParent;								//�e���f���̃C���f�N�X
	D3DXVECTOR3 pos;									//�ʒu(�I�t�Z�b�g)
	D3DXVECTOR3 rot;									//����
	LPDIRECT3DTEXTURE9 apTextureObject[MAX_MAT];		//�e�N�X�`��
	D3DXMATRIX mtxWorld;								//���[���h�}�g���b�N�X
}Object;

//�}�N����`
#define MAX_MAT_OBJECT (512)

//�v���g�^�C�v�錾
void InitObject();
void UninitObject();
void UpdateObject();
void DrawObject();

#endif // !_MODEL_H_

