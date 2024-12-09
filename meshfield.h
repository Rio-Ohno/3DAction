//============================================================
//
//�C���f�b�N�X�o�b�t�@[meshfield.h]
//Author:Rio Ohno
//
//=============================================================

#ifndef _MESHFIELD_H_
#define _MESHFIELD_H_

#include"main.h"

//�}�N����`
#define MAX_X_FIELD (6)																	//x������
#define MAX_Z_FIELD (6)																	//z������
#define MAX_VERTEX_FIELD ((MAX_X_FIELD+1)*(MAX_Z_FIELD+1))								//���_��
#define MAX_INDX_FIELD ((MAX_Z_FIELD * 2) * (MAX_X_FIELD + (MAX_Z_FIELD * 2) -1))		//�C���f�b�N�X��((x+1)*2*z+(z-1)*(�k�ރ|���S���̒��_��=4Z))
#define MAX_POLY_FIELD ((MAX_Z_FIELD * 2) * (MAX_X_FIELD + (MAX_Z_FIELD - 1) * 2))		//�|���S����(x*z*2+(z-1)*(�k�ރ|���S��=4Z))

//���b�V���t�B�[���h�\����
typedef struct
{
	D3DXVECTOR3 pos;																	//�ʒu
	D3DXVECTOR3 rot;																	//����
	float  fHight;																		//����
	float  fWidth;																		//��
	D3DXMATRIX mtxWorld;																//���[���h�}�g���b�N�X
}MeshField;

//�v���g�^�C�v�錾
void InitMeshField();																	//������
void UninitMeshField();																	//�I������
void UpdateMeshField();																	//�X�V����
void DrawMeshField();																	//�`�揈��

#endif // !_MeshField_H_
