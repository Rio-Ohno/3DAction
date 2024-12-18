//============================================================
//
//�Q�[�����[game.cpp]
//Author:Rio Ohno
//
//============================================================

#include"game.h"
#include<time.h>
#include"player.h"
#include"bullet.h"
#include"explosion.h"
#include"fade.h"
#include"pause.h"
#include "meshcylinder.h"
#include "meshfield.h"
#include "explosion.h"
#include "light.h"
#include"wall.h"
#include"shadow.h"
#include"input.h"
#include"enemy.h"
#include "effect.h"
#include "Item.h"
#include"wave.h"

//�O���[�o���ϐ�
GAMESTATE g_gameState = GAMESTATE_NONE;
int g_nCounterGameStat = 0;
bool g_bPause = false;
bool g_bParticle = false;

//=============================================================================================================
//�Q�[����ʂ̏���������
//=============================================================================================================
void InitGame()
{
	g_gameState = GAMESTATE_NORMAL;
	g_bPause = false;
	g_nCounterGameStat = 0;
	srand((int)time(0));//�V�[�h�l

	//�|�[�Y�̏���������
	InitPause();

	//�����̏���������
	InitExplosion();

	//�G�t�F�N�g�̏���������
	InitEffect();

	//�e�̏���������
	InitShadow();

	//�e�̏���������
	InitBullet();

	//�A�C�e���̏���������
	InitItem();

	//�v���C���[�̏���������
	InitPlayer();

	//�G�̏���������
	InitEnemy();

	//InitPolygon();
	
	//���b�V���t�B�[���h�̏���������
	InitMeshField();

	//InitBillboard();

	//SetBillboard(D3DXVECTOR3(0.0f, 5.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 10.0f);

	//InitMeshWall();
	//SetMeshWall(D3DXVECTOR3(-100.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, -D3DX_PI / 2.0f, 0.0f));
	//SetMeshWall(D3DXVECTOR3(100.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, D3DX_PI / 2.0f, 0.0f));
	//SetMeshWall(D3DXVECTOR3(0.0f, 0.0f, 100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	//SetMeshWall(D3DXVECTOR3(0.0f, 0.0f, -100.0f), D3DXVECTOR3(0.0f, D3DX_PI, 0.0f));


	//InitMeshCylinder();

	//�ǂ̏���������
	InitWall();

	//�ǂ̐ݒ菈��(pos,rot,width,hight,a)
	SetWall(D3DXVECTOR3(0.0f, 50.0f, 300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 600.0f, 100.0f, 0.7f);//��
	SetWall(D3DXVECTOR3(300.0f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, D3DX_PI / 2.0f, 0.0f), 600.0f, 100.0f, 0.7f);//�E
	SetWall(D3DXVECTOR3(-300.0f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, -D3DX_PI / 2.0f, 0.0f), 600.0f, 100.0f, 0.7f);//��
	SetWall(D3DXVECTOR3(0.0f, 50.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), -600.0f, 100.0f, 0.7f);//��O

	//SetWall(D3DXVECTOR3(-100.1f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, D3DX_PI / 2.0f, 0.0f), 200.0f, 100.0f, 0.3f);//����
	//SetWall(D3DXVECTOR3(100.1f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, -D3DX_PI / 2.0f, 0.0f), 200.0f, 100.0f, 0.3f);//�E��
	//SetWall(D3DXVECTOR3(0.0f, 50.0f, 100.1f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), -200.0f, 100.0f, 0.3f);//����
	//SetWall(D3DXVECTOR3(0.0f, 50.0f, -100.1f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 100.0f, 0.3f);//��O��

	InitCamera();

	InitLight();

	//�E�F�[�u�̏�����
	InitWave();

	////�X�R�A�̏�����
	//InitScore();
	//SetScore(0);

	////�p�[�e�B�N������������
	//InitParticle();

	//�Q�[���̓Ǎ�����
	LoadWave();
}

//=============================================================================================================
//�Q�[����ʂ̏I������
//=============================================================================================================
void UninitGame()
{

	//�|�[�Y�̏I������
	UninitPause();


	////�X�R�A�̏I������
	//UninitScore();

	//UninitModel();

	//�����̏���������
	UninitExplosion();

	//�G�t�F�N�g�̏I������
	UninitEffect();

	//�e�̏���������
	UninitShadow();

	//�e�̏I������
	UninitBullet();

	//�A�C�e���̏I������
	UninitItem();
	
	//�v���C���[�̏I������
	UninitPlayer();

	//�G�̏I������
	UninitEnemy();

	//UninitPolygon();

	//���b�V���t�B�[���h�̏I������
	UninitMeshField();

	//UninitMeshWall();

	//UninitMeshCylinder();

	//�ǂ̏I������
	UninitWall();

	//�J�����̏���������
	UninitCamera();

	//���C�g�̏���������
	UninitLight();

	////�G�t�F�N�g�̏I������
	//UninitEffect();

	////�G�̏I������
	//UninitEnemy();

	////�p�[�e�B�N���̏I������
	//UninitParticle();

}

//=============================================================================================================
//�Q�[����ʂ̍X�V����
//=============================================================================================================
void UpdateGame()
{
	if (KeyboardTrigger(DIK_P) == true)
	{//�|�[�Y�iP�L�[�j�������ꂽ�Ƃ�
		g_bPause = g_bPause ? false : true;
	}

	//�|�[�Y��
	if (g_bPause == true)
	{
		//�|�[�Y�̍X�V����
		UpdatePause();
	}
		////�w�i�̍X�V����
		//Updatebackgraund();

		if (g_bPause == false)
		{
			//�e�̍X�V����
			UpdateBullet();

			//�A�C�e���̍X�V����
			UpdateItem();

			//�e�̍X�V����
			UpdateShadow();

			//�����̍X�V����
			UpdateExplosion();

			//�G�t�F�N�g�̍X�V����
			UpdateEffect();

			//UpdatePolygon();

			//���b�V���t�B�[���h�̍X�V����
			UpdateMeshField();

			//UpdateMeshWall();

			//UpdateMeshCylinder();

			//�ǂ̍X�V����
			UpdateWall();

			//�v���C���[�̍X�V����
			UpdatePlayer();

			//�G�̍X�V����
			UpdateEnemy();

			//�J�����̍X�V����
			UpdateCamera();

			//���C�g�̍X�V����
			UpdateLight();

			////�G�t�F�N�g�̍X�V����
			//UpdateEffect();

			////�X�R�A�̍X�V����
			//UpdateScore();

			////�p�[�e�B�N���̍X�V����
			//UpdateParticle();
		}

	Enemy* pEnemy;                                                      //�G���ւ̃|�C���^

	//�G�̎擾
	pEnemy = GetEnemy();

	//�G���̎擾
	int NumEnemy = GetNumEnemy();
	//bool finish = false;

	if (NumEnemy <= 0)
	{
		//�E�F�[�u�̓Ǎ�����
		LoadWave();
	}


	//�f�o�b�N�p......................................................
	#ifdef  _DEBUG
	
		if (KeyboardTrigger(DIK_O) == true)
		{
			g_bParticle = g_bParticle ? false : true;
		}

		if (KeyboardTrigger(DIK_M)==true)//�Q�[���̏I������
		{
			//g_gameState = GAMESTATE_END;
			//��ʂ̐ݒ�
			SetFade(MODE_RESULT);
		}
	
	#endif //  _DEBUG
	//...........................................................

	//�v���C���[�̏��擾
	Player* pPlayer = GetPlayer();

	if (pPlayer->bFrag == true)
	{
		//��ʑJ��(Result��)
		SetFade(MODE_RESULT);
	}
			
	//switch (g_gameState)
	//{
	//case GAMESTATE_NORMAL:

	//finish = GetFinish();

	//if (finish==true)
	//{
	//	//SetResult(RESULT_WIN);
	//	//��ʂ̐ݒ�
	//	SetFade(MODE_RESULT);
	//}

	//	break;

	//case GAMESTATE_END:
	//	g_nCounterGameStat++;
	//	if (g_nCounterGameStat >= 60)
	//	{
	//		g_nCounterGameStat = 0;
	//		g_gameState = GAMESTATE_NONE;

	//		//��ʂ̐ݒ�
	//		SetFade(MODE_RESULT);
	//	}
	//	break;
	//}
}

//=============================================================================================================
//�Q�[����ʂ̕`�揈��
//=============================================================================================================
void DrawGame()
{
	//�J�����̐ݒ菈��
	SetCamera();

	//�����̕`�揈��
	DrawExplosion();

	////�G�t�F�N�g�̕`�揈��
	//DrawEffect();

	//�e�̕`�揈��
	DrawBullet();

	//�A�C�e���̕`�揈��
	DrawItemModel();
	DrawItemBillboard();

	//�|���S���̕`�揈��
	//DrawPolygon();

	//�r���{�[�h�̕`�揈��
	//DrawBillboard();

	//�v���C���[�̕`�揈��
	DrawPlayer();

	//�G�̕`�揈��
	DrawEnemy();

	//���b�V���t�B�[���h�̕`�揈��
	DrawMeshField();

	//�e�̕`�揈��
	DrawShadow();

	//DrawMeshWall();

	//DrawMeshCylinder();

	//�ǂ̕`�揈��
	DrawWall();

	//DrawModel();

	////�X�R�A�̕`�揈��
	//DrawScore();

	////�p�[�e�B�N���̕`�揈��
	//DrawParticle();

	//�|�[�Y��
	if (g_bPause == true)
	{
		//�|�[�Y�̕`�揈��
		DrawPause();
	}
}

//=============================================================================================================
//�Q�[���̏�Ԃ̐ݒ�
//=============================================================================================================
void SetGameState(GAMESTATE state)
{
	g_gameState = state;
}

//=============================================================================================================
//�|�[�Y�̗L�������ݒ�ݒ�
//=============================================================================================================
void SetEnablePause(bool bPause) 
{
	g_bPause = bPause;
}

//=============================================================================================================
//�Q�[���̏�Ԃ̎擾
//=============================================================================================================
GAMESTATE GetGameState()
{
	return g_gameState;
}