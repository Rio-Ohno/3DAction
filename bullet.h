//============================================================
//
//�e[bullet.h]
//Author:Rio Ohno
//
//=============================================================

#ifndef _BULLET_H_
#define _BULLET_H_

#include"main.h"

//�}�N����`
#define MAX_BULLET (256)											//�e�̍ő吔
#define BULLET_SPEED (1.0f)											//�e�̃X�s�[�h
#define BULLET_LIFE (180)											//�e�̃��C�t

//�e�̎��
typedef enum
{
	BULLETTYPE_NULL=0,
	BULLETTYPE_BOUND,
	BULLETTYPE_MAX
}BULLETTYPE;

//�e�̍\����
typedef struct
{
	D3DXVECTOR3 pos;												//�ʒu
	D3DXVECTOR3 posOld;												//�ʒu
	D3DXVECTOR3 move;												//�ړ���
	D3DXVECTOR3 rot;												//����
	D3DXVECTOR3 dir;												//�����x�N�g��(move?)
	D3DXMATRIX mtxWorld;											//���[���h�}�g���b�N�X
	BULLETTYPE type;												//�e�̎��
	int nIndexShadow;												//�e�̃C���f�b�N�X
	float radius;													//���a
	int nLife;														//����
	bool ver;														//�����������ǂ���
	bool bUse;														//�g�p���Ă��邩�ǂ���
}Bullet;

//�v���g�^�C�v�錾
void InitBullet();													//����������
void UninitBullet();												//�I������
void UpdateBullet();												//�X�V����
void DrawBullet();													//�`�揈��
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 dir, float radius);		//�ݒ菈��
bool CollisionBullet();												//�e�Ƃ̓����蔻��
Bullet* GetBullet();												//���n��

#endif // !_Bullet_H_
