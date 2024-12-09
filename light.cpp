//============================================================
//
//���C�g[light.cpp]
//Author:Rio Ohno
//
//============================================================

#include"light.h"

//�O���[�o���ϐ�
D3DLIGHT9 g_light[MAX_LIGHT];//���C�g���

//============================================================
// ���C�g�̏���������
//============================================================
void InitLight()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXVECTOR3 vecDir[MAX_LIGHT];//���C�g�̕����x�N�g��

	//���C�g���N���A
	ZeroMemory(&g_light, sizeof(g_light));

	for (int nCnt = 0; nCnt < MAX_LIGHT; nCnt++)
	{
		//���C�g�̎�ނ�ݒ�
		g_light[nCnt].Type = D3DLIGHT_DIRECTIONAL;//���s����

		//���C�g�̊g�U����ݒ�
		g_light[nCnt].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	}

	//���C�g�̕�����ݒ�
	vecDir[0] = D3DXVECTOR3(0.2f, -0.8f, -0.2f);
	vecDir[1] = D3DXVECTOR3(-0.2f, -0.8f, -0.4f);
	vecDir[2] = D3DXVECTOR3(0.0f, -0.8f, 0.2f);

	for (int nCnt = 0; nCnt < MAX_LIGHT; nCnt++)
	{
		//����������
		D3DXVec3Normalize(&vecDir[nCnt], &vecDir[nCnt]);
		g_light[nCnt].Direction = vecDir[nCnt];

		//���C�g��ݒ肷��
		pDevice->SetLight(nCnt, &g_light[nCnt]);
	}

	//���C�g��L���ɂ���
	pDevice->LightEnable(0, TRUE);
}

//============================================================
// ���C�g�̏I������
//============================================================
void UninitLight()
{

}

//============================================================
// ���C�g�̍X�V����
//============================================================
void UpdateLight()
{

}
