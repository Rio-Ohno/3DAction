//============================================================
//
//�v���C���[[player.h]
//Author:Rio Ohno
//
//============================================================

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "main.h"
#include"input.h"
#include"camera.h"
#include"shadow.h"
#include"model.h"

//�}�N����`.......................................................
#define MAX_KEY (10)					//�L�[�̍ő吔
#define MAX_MAT_PLAYER (512)			//�}�g���b�N�X�̍ő吔
#define MAX_MOTION (4)					//���[�V�����̍ő吔
#define MAX_PARTS (15)					//�p�[�c�̍ő吔
#define PLAYER_SPEED (1.5f)				//�v���C���[�̃X�s�[�h

//���[�V�����̎��............................................
typedef enum
{
	MOTIONTYPE_NEUTRAL=0,				//�j���[�g����
	MOTIONTYPE_MOVE,					//�ړ�
	MOTIONTYPE_ACTION,					//�A�N�V����
	MOTIONTYPE_JUMP,					//�W�����v
	MOTIONTYPE_MAX
}MOTIONTYPE;

//�L�[�̍\����................................................
typedef struct
{
	float fPosX;						//�ʒuX
	float fPosY;						//�ʒuY
	float fPosZ;						//�ʒuZ
	float fRotX;						//����X
	float fRotY;						//����Y
	float fRotZ;						//����Z
}Key;

//�L�[���̍\����............................................
typedef struct
{
	int nFrame;							//�Đ��t���[��
	Key aKEY[MAX_PARTS];				//�e�p�[�c�̃L�[�v�f
}Key_Info;

//���[�V�������̍\����......................................
typedef struct
{
	bool bLoop;							//���[�v���邩�ǂ���
	int nNumKey;						//�L�[�̑���
	Key_Info aKeyInfo[MAX_KEY];			//�L�[���
}Motion_Info;

//�v���C���[�\����....................................................
typedef struct
{
	D3DXVECTOR3 pos;					//�ʒu
	D3DXVECTOR3 posOld;					//�O��̈ʒu
	D3DXVECTOR3 rot;					//����
	D3DXVECTOR3 rotDest;				//�ڕW�̌���
	D3DXVECTOR3 vtxMin;					//���f���̍ŏ��l
	D3DXVECTOR3 vtxMax;					//���f���̍ő�l
	D3DXVECTOR3 size;					//�T�C�Y(�傫��)
	D3DXVECTOR3 move;					//�ړ���
	D3DXMATRIX mtxWorldPlayer;			//�v���C���[�̃��[���h�}�g���b�N�X
	Model aModel[MAX_PARTS];			//���f��(�p�[�c)
	Motion_Info aMotionInfo[MOTIONTYPE_MAX];//���[�V�������
	MOTIONTYPE motionType;				//���[�V�����̎��
	int nNumModel;						//���f��(�p�[�c)�̑���
	int nNumMotion;						//���[�V�����̍ő吔
	int nNumKey;						//�L�[�̍ő吔
	int nKey;							//���݂̃L�[NO.
	int nCounterMotion;					//���[�V�����J�E���^�[
	int nIndxShadow;					//�e�̃C���f�b�N�X�i�[�p
	bool bLoopMotion;					//���[�v���邩�ǂ���
	bool bjump;							//�W�����v
	bool bUse;							//�g�p���Ă��邩�ǂ���
	bool bFrag;							//�ǂɓ������Ă��邩�ǂ���
}Player;

//============================================================
//�v���g�^�C�v�錾
//============================================================
void InitPlayer();						//�v���C���[�̏���������
void UninitPlayer();					//�v���C���[�̏I������
void UpdatePlayer();					//�v���C���[�̍X�V����
void DrawPlayer();						//�v���C���[�̕`�揈��
void SetMotion(MOTIONTYPE type);		//�v���C���[�̃��[�V�����ݒ�
void LoadModel(int index);						//�v���C���[�̃��f���Ǎ�
Player* GetPlayer();					//�v���C���[�̏��擾

#endif // !_MODEL_H_
