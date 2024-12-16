//============================================================
//
//�G[enemy.h]
//Author:Rio Ohno
//
//============================================================

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "main.h"
#include"input.h"
#include"camera.h"
#include"shadow.h"
#include"model.h"

//�}�N����`.......................................................
#define MAX_ENEMY (1)
#define MAX_KEY_ENEMY (10)						//�L�[�̍ő吔
#define MAX_MAT_ENEMY (512)						//�}�g���b�N�X�̍ő吔
#define MAX_MOTION_ENEMY (4)					//���[�V�����̍ő吔
#define MAX_PARTS_ENEMY (15)					//�p�[�c�̍ő吔
#define PLAYER_SPEED_ENEMY (1.5f)				//�G�̃X�s�[�h

//���[�V�����̎��............................................
typedef enum
{
	MOTIONTYPE_ENEMY_NEUTRAL = 0,				//�j���[�g����
	MOTIONTYPE_ENEMY_MOVE,						//�ړ�
	MOTIONTYPE_ENEMY_ATTACK,					//�A�N�V����
	MOTIONTYPE_ENEMY_JUMP,						//�W�����v
	MOTIONTYPE_ENEMY_ESCAPE,					//������
	MOTIONTYPE_ENEMY_MAX
}MOTIONTYPE_ENEMY;

//�L�[�̍\����................................................
typedef struct
{
	float fPosX;						//�ʒuX
	float fPosY;						//�ʒuY
	float fPosZ;						//�ʒuZ
	float fRotX;						//����X
	float fRotY;						//����Y
	float fRotZ;						//����Z
}Key_ENEMY;

//�L�[���̍\����............................................
typedef struct
{
	int nFrame;							//�Đ��t���[��
	Key_ENEMY aKEY[MAX_PARTS];				//�e�p�[�c�̃L�[�v�f
}Key_ENEMY_Info;

//���[�V�������̍\����......................................
typedef struct
{
	bool bLoop;							//���[�v���邩�ǂ���
	int nNumKey;						//�L�[�̑���
	Key_ENEMY_Info aKeyInfo[MAX_KEY];			//�L�[���
}Motion_ENEMY_Info;

//�G�\����....................................................
typedef struct
{
	D3DXVECTOR3 pos;											//�ʒu
	D3DXVECTOR3 posOld;											//�O��̈ʒu
	D3DXVECTOR3 rot;											//����
	D3DXVECTOR3 rotDest;										//�ڕW�̌���
	D3DXVECTOR3 vtxMin;											//���f���̍ŏ��l
	D3DXVECTOR3 vtxMax;											//���f���̍ő�l
	D3DXVECTOR3 size;											//�T�C�Y(�傫��)
	D3DXVECTOR3 move;											//�ړ���
	D3DXMATRIX mtxWorldEnemy;									//�G�̃��[���h�}�g���b�N�X
	Model aModel[MAX_PARTS];									//���f��(�p�[�c)
	Motion_ENEMY_Info aMotionInfo[MOTIONTYPE_ENEMY_MAX];		//���[�V�������
	MOTIONTYPE_ENEMY motionType;								//���[�V�����̎��
	int nLife;													//�̗�
	int nNumModel;												//���f��(�p�[�c)�̑���
	int nNumMotion;												//���[�V�����̍ő吔
	int nNumKey;												//�L�[�̍ő吔
	int nKey;													//���݂̃L�[NO.
	int nCounterMotion;											//���[�V�����J�E���^�[
	int nCntFream;												//�t���[���J�E���^
	int nIndxShadow;											//�e�̃C���f�b�N�X�i�[�p
	bool bLoopMotion;											//���[�v���邩�ǂ���
	bool bjump;													//�W�����v
	bool bUse;													//�g�p���Ă��邩�ǂ���
	bool bFrag;													//�ǂɓ������Ă��邩�ǂ���
}Enemy;

//============================================================
//�v���g�^�C�v�錾
//============================================================
void InitEnemy();												//�G�̏���������
void UninitEnemy();												//�G�̏I������
void UpdateEnemy();												//�G�̍X�V����
void DrawEnemy();												//�G�̕`�揈��
void SetEnemy(D3DXVECTOR3 pos, D3DXVECTOR3 rot);				//�G�̐ݒ菈��
void SetMotionEnemy();											//�G�̃��[�V�����ݒ�
bool CollisionEnemy();											//�G�̓����蔻��
void HitEnemy(int nIndxEnemy);									//�G����e�����Ƃ��̏���
Enemy* GetEnemy();												//�G�̏��擾

#endif // !_MODEL_H_
