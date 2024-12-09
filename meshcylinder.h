//============================================================
//
//�C���f�b�N�X�o�b�t�@[meshfield.h]
//Author:Rio Ohno
//
//=============================================================

#ifndef _MESHCYLINDER_H_
#define _MESHCYLINDER_H_

#include"main.h"

//�}�N����`
#define MAX_X_CYLINDER (8)																		//x������
#define MAX_Z_CYLINDER (1)																		//z������
#define MAX_VERTEX_CYLINDER ((MAX_X_CYLINDER+1)*(MAX_Z_CYLINDER+1))										//���_��
#define MAX_INDX_CYLINDER ((MAX_Z_CYLINDER * 2) * (MAX_X_CYLINDER + (MAX_Z_CYLINDER * 2) -1))			//�C���f�b�N�X��((x+1)*2*z+(z-1)*(�k�ރ|���S����=4Z))
#define MAX_POLY_CYLINDER ((MAX_Z_CYLINDER*2)*(MAX_X_CYLINDER+(MAX_Z_CYLINDER-1)*2))						//�|���S����(x*z*2+(z-1)*(�k�ރ|���S��=4Z))

//���b�V���t�B�[���h�\����
typedef struct
{
	D3DXVECTOR3 pos;																			//�ʒu
	D3DXVECTOR3 rot;																			//����
	D3DXMATRIX mtxWorld;																		//���[���h�}�g���b�N�X
}MeshCylinder;

//�v���g�^�C�v�錾
void InitMeshCylinder();																		//������
void UninitMeshCylinder();																		//�I������
void UpdateMeshCylinder();																		//�X�V����
void DrawMeshCylinder();																		//�`�揈��

#endif // !_MeshCylinder_H_
