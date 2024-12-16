//============================================================
//
//�A�C�e��[Item.h]
//Author:Rio Ohno
//
//============================================================

#ifndef _ITEM_H_
#define _ITEM_H_

#include "main.h"

//�}�N����`
#define MAX_MAT_ITEM (512)								//�ő�}�e���A����
#define MAX_ITEM (5)									//�ő�A�C�e����
#define ITEM_RADIUS (30.0f)								//�A�C�e��(�r���{�[�h)�̔��a

//���f���\����
typedef struct
{
	LPD3DXMESH pMesh;									//���b�V��(���_���)�ւ̃|�C���^
	LPD3DXBUFFER pBuffMat;								//�}�e���A���ւ̃|�C���^
	DWORD dwNumMat;										//�}�e���A���̐�
	D3DXVECTOR3 pos;									//�ʒu(�I�t�Z�b�g)
	D3DXVECTOR3 rot;									//����
	LPDIRECT3DTEXTURE9 apTextureItem[MAX_MAT_ITEM];		//�e�N�X�`��
	D3DXMATRIX mtxWorld;								//���[���h�}�g���b�N�X
	int Type;											//���
	bool bUse;											//�g�p���Ă��邩�ǂ���
	bool bModel;										//���f�����ǂ���
}Item;

//�v���g�^�C�v�錾
void InitItem();										//����������
void UninitItem();										//�I������
void UpdateItem();										//�X�V����
void DrawItemModel();									//�`�揈��(���f��)
void DrawItemBillboard();								//�`�揈��(�r���{�[�h)
void SetItem(D3DXVECTOR3 pos,int nType);				//�ݒ菈��
void CollisionItem(int nIndexItem);						//�擾����

#endif // !_MODEL_H_