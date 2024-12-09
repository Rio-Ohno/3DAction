//============================================================
//
//�J����[camera.cpp]
//Author:Rio Ohno
//
//============================================================

#include"camera.h"

//�O���[�o���ϐ�
Camera g_camera;					//�J�������

//============================================================
// �J�����̏���������
//============================================================
void InitCamera()
{
	//�e�평����
	g_camera.posV = D3DXVECTOR3(0.0f, 100.0f, -200.0f);
	g_camera.posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_camera.vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	g_camera.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_camera.bAssent = false;

	//���_���璍���_�̋����v�Z
	float fDisX = g_camera.posR.x - g_camera.posV.x;
	float fDisY = g_camera.posR.y - g_camera.posV.y;
	float fDisZ = g_camera.posR.z - g_camera.posV.z;

	//�Ίp���̒������Z�o����
	g_camera.fDistance = sqrtf(fDisX * fDisX + fDisZ * fDisZ + fDisY * fDisY);
}

//============================================================
// �J�����̏I������
//============================================================
void UninitCamera()
{

}

//============================================================
//�J�����̍X�V����
//============================================================
void UpdateCamera()
{
	//���Z�b�g================================================================================
	if (KeyboardTrigger(DIK_R) == true)
	{
		InitCamera();
	}

	//�Ǐ]�̃I���I�t
	if (KeyboardTrigger(DIK_F) == true)
	{
		g_camera.bAssent = g_camera.bAssent ? false : true;
	}

	if (g_camera.bAssent == false)
	{
		g_camera.type = CAMERATYPE_NOMAL;
	}
	else if (g_camera.bAssent = true)
	{
		g_camera.type = CAMERATYPE_ASSENT;
	}


	if (g_camera.type == CAMERATYPE_NOMAL)
	{
		//�����_�̐���============================================================================
		if (GetKeyboardPress(DIK_A) == true)//A�{�^��
		{
			g_camera.rot.y -= 0.01f;

			//�ڕW�̈ړ������i�p�x�j�̕␳
			if (g_camera.rot.y < -D3DX_PI)
			{
				g_camera.rot.y += D3DX_PI * 2.0f;
			}

			g_camera.posR.x = g_camera.posV.x + sinf(g_camera.rot.y) * g_camera.fDistance;
			g_camera.posR.z = g_camera.posV.z + cosf(g_camera.rot.y) * g_camera.fDistance;
		}
		else if (GetKeyboardPress(DIK_D) == true)//D�{�^��
		{
			g_camera.rot.y += 0.01f;

			//�ڕW�̈ړ������i�p�x�j�̕␳
			if (g_camera.rot.y > D3DX_PI)
			{
				g_camera.rot.y -= D3DX_PI * 2.0f;
			}

			g_camera.posR.x = g_camera.posV.x + sinf(g_camera.rot.y) * g_camera.fDistance;
			g_camera.posR.z = g_camera.posV.z + cosf(g_camera.rot.y) * g_camera.fDistance;
		}

		//�J�����̈ړ�============================================================================
		if (GetKeyboardPress(DIK_I) == true)
		{
			g_camera.posV.x += sinf(g_camera.rot.y) * 1.0f;
			g_camera.posV.z += cosf(g_camera.rot.y) * 1.0f;

			g_camera.posR.x = g_camera.posV.x + sinf(g_camera.rot.y) * g_camera.fDistance;
			g_camera.posR.z = g_camera.posV.z + cosf(g_camera.rot.y) * g_camera.fDistance;
		}
		else if (GetKeyboardPress(DIK_K) == true)
		{
			g_camera.posV.x -= sinf(g_camera.rot.y) * 1.0f;
			g_camera.posV.z -= cosf(g_camera.rot.y) * 1.0f;

			g_camera.posR.x = g_camera.posV.x + sinf(g_camera.rot.y) * g_camera.fDistance;
			g_camera.posR.z = g_camera.posV.z + cosf(g_camera.rot.y) * g_camera.fDistance;

		}
		else if (GetKeyboardPress(DIK_J) == true)
		{

			g_camera.posV.x -= sinf(g_camera.rot.y + D3DX_PI / 2.0f) * 1.0f;
			g_camera.posV.z -= cosf(g_camera.rot.y + D3DX_PI / 2.0f) * 1.0f;

			g_camera.posR.x = g_camera.posV.x + sinf(g_camera.rot.y) * g_camera.fDistance;
			g_camera.posR.z = g_camera.posV.z + cosf(g_camera.rot.y) * g_camera.fDistance;

		}
		else if (GetKeyboardPress(DIK_L) == true)
		{

			g_camera.posV.x += sinf(g_camera.rot.y + D3DX_PI / 2.0f) * 1.0f;
			g_camera.posV.z += cosf(g_camera.rot.y + D3DX_PI / 2.0f) * 1.0f;

			g_camera.posR.x = g_camera.posV.x + sinf(g_camera.rot.y) * g_camera.fDistance;
			g_camera.posR.z = g_camera.posV.z + cosf(g_camera.rot.y) * g_camera.fDistance;

		}
		//else if (GetKeyboardPress(DIK_T) == true)
		//{
		//	g_camera.posV.y += 0.05f;
		//	g_camera.posR.y = g_camera.posV.y;
		//}
		//else if (GetKeyboardPress(DIK_G) == true)
		//{
		//	g_camera.posV.y -= 0.05f;
		//	g_camera.posR.y = g_camera.posV.y;
		//}
	}
	//�Ǐ]====================================================================================
	else if (g_camera.type == CAMERATYPE_ASSENT)
	{
		Player* pPlayer = GetPlayer();

		//�Ίp���̊p�x���Z�o����

		//�ړI�̒l
		g_camera.posRDest.x = pPlayer->pos.x + sinf(pPlayer->rot.y) * PLAYER_SPEED;
		g_camera.posRDest.y = pPlayer->pos.y;
		g_camera.posRDest.z = pPlayer->pos.z + cosf(pPlayer->rot.y) * PLAYER_SPEED;

		g_camera.posVDest.x = pPlayer->pos.x - sinf(g_camera.rot.y) * g_camera.fDistance;
		g_camera.posVDest.y = pPlayer->pos.y;
		g_camera.posVDest.z = pPlayer->pos.z - cosf(g_camera.rot.y) * g_camera.fDistance;

		//
		g_camera.posR.x += (g_camera.posRDest.x - g_camera.posR.x) * 0.05;
		g_camera.posR.y += (g_camera.posRDest.y - g_camera.posR.y) * 0.05;
		g_camera.posR.z += (g_camera.posRDest.z - g_camera.posR.z) * 0.05;

		g_camera.posV.x += (g_camera.posVDest.x - g_camera.posV.x) * 0.05;
		//g_camera.posV.y += (g_camera.posVDest.y - g_camera.posV.y) * 0.05;
		g_camera.posV.z += (g_camera.posVDest.z - g_camera.posV.z) * 0.05;

	}

	//���_�̐���============================================================================
	if (GetKeyboardPress(DIK_E) == true)//H�{�^��
	{
		g_camera.rot.y -= 0.01f;

		//�ڕW�̈ړ������i�p�x�j�̕␳
		if (g_camera.rot.y < -D3DX_PI)
		{
			g_camera.rot.y += D3DX_PI * 2.0f;
		}

		g_camera.posV.x = g_camera.posR.x - sinf(g_camera.rot.y) * g_camera.fDistance;
		g_camera.posV.z = g_camera.posR.z - cosf(g_camera.rot.y) * g_camera.fDistance;

	}
	else if (GetKeyboardPress(DIK_Q) == true)//F�{�^��
	{
		g_camera.rot.y += 0.01f;

		//�ڕW�̈ړ������i�p�x�j�̕␳
		if (g_camera.rot.y > D3DX_PI)
		{
			g_camera.rot.y -= D3DX_PI * 2.0f;
		}

		g_camera.posV.x = g_camera.posR.x - sinf(g_camera.rot.y) * g_camera.fDistance;
		g_camera.posV.z = g_camera.posR.z - cosf(g_camera.rot.y) * g_camera.fDistance;

	}
	else if (GetKeyboardPress(DIK_Y) == true)
	{
		g_camera.rot.x -= 0.01f;

		//�p�x�̐��K��
		if (g_camera.rot.x < -D3DX_PI)
		{
			g_camera.rot.x += D3DX_PI * 2.0f;
		}

		g_camera.posV.y = g_camera.posR.y - sinf(g_camera.rot.x) * g_camera.fDistance;
		g_camera.posV.z = g_camera.posR.z - cosf(g_camera.rot.x) * g_camera.fDistance;
	}
	else if (GetKeyboardPress(DIK_H) == true)
	{
		g_camera.rot.x += 0.01f;

		//�p�x�̐��K��
		if (g_camera.rot.x > D3DX_PI)
		{
			g_camera.rot.x -= D3DX_PI * 2.0f;
		}

		g_camera.posV.y = g_camera.posR.y - sinf(g_camera.rot.x) * g_camera.fDistance;
		g_camera.posV.z = g_camera.posR.z - cosf(g_camera.rot.x) * g_camera.fDistance;
	}
}

//============================================================
// �J�����̐ݒ菈��
//============================================================
void SetCamera()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();//�f�o�C�X�̃|�C���^

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_camera.mtxView);

	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&g_camera.mtxView, &g_camera.posV, &g_camera.posR, &g_camera.vecU);

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &g_camera.mtxView);

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_camera.mtxProjection);

	//�v���W�F�N�V�����}�g���b�N�X�̍쐬
	D3DXMatrixPerspectiveFovLH(&g_camera.mtxProjection, D3DXToRadian(45.0f),
														(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
														10.0f,
														1000.0f);

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &g_camera.mtxProjection);
}

//============================================================
// �J�����̏��擾
//============================================================
Camera*GetCamera()
{
	return &g_camera;
}