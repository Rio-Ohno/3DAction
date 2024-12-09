//============================================================
//
//�e[shadow.cpp]
//Author:Rio Ohno
//
//============================================================

#include"shadow.h"

//�O���[�o���ϐ��錾
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffShadow = NULL;							//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureShadow = NULL;									//�e�N�X�`���ւ̃|�C���^
Shadow g_aShadow[MAX_SHADOW];

//============================================================
// �e�̏���������
//============================================================
void InitShadow()
{
	//�f�o�C�X�ւ̃|�C���^�Ǝ擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�e�N�X�`���̓Ǎ�
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\shadow000.jpg",
		&g_pTextureShadow);

	for (int nCnt = 0; nCnt < MAX_SHADOW; nCnt++)
	{
		g_aShadow[nCnt].pos = D3DXVECTOR3(0.0f, 0.5f, 0.0f);					//�ʒu�̏�����
		g_aShadow[nCnt].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//�����̏�����
		g_aShadow[nCnt].scale = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//�{���̏�����
		g_aShadow[nCnt].bUse = false;											//�g���Ă��Ȃ���Ԃɂ���
	}

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_SHADOW,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffShadow,
		NULL);

	//���_���ւ̃|�C���^
	VERTEX_3D* pVtx = NULL;

	//���_�o�b�t�@�����b�N
	g_pVtxBuffShadow->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_SHADOW; nCnt++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos.x = -BASIS_SIZE;
		pVtx[0].pos.y = 0.0f;	
		pVtx[0].pos.z = BASIS_SIZE;
												
		pVtx[1].pos.x = BASIS_SIZE;
		pVtx[1].pos.y = 0.0f;
		pVtx[1].pos.z = BASIS_SIZE;
												
		pVtx[2].pos.x = -BASIS_SIZE;
		pVtx[2].pos.y = 0.0f;	
		pVtx[2].pos.z = -BASIS_SIZE;
												
		pVtx[3].pos.x = BASIS_SIZE;
		pVtx[3].pos.y = 0.0f;	
		pVtx[3].pos.z = -BASIS_SIZE;

		//�e���_�̖@���̐ݒ�
		pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0);

		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;
	}

	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffShadow->Unlock();
}

//============================================================
// �e�̏I������
//============================================================
void UninitShadow()
{
	//���_�o�b�t�@�̉��
	if (g_pVtxBuffShadow != NULL)
	{
		g_pVtxBuffShadow->Release();
		g_pVtxBuffShadow = NULL;
	}

	//�e�N�X�`���̔j��
	if (g_pTextureShadow != NULL)
	{
		g_pTextureShadow->Release();
		g_pTextureShadow = NULL;
	}
}

//============================================================
// �e�̍X�V����
//============================================================
void UpdateShadow()
{

}

//============================================================
// �e�̕`�揈��
//============================================================
void DrawShadow()
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans,mtxScale;

	//���Z�����̐ݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	for (int nCnt = 0; nCnt < MAX_SHADOW; nCnt++)
	{
		if (g_aShadow[nCnt].bUse == true)
		{
			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_aShadow[nCnt].mtxWorld);

			//�{���𔽉f
			D3DXMatrixTranslation(&mtxScale, g_aShadow[nCnt].scale.x, 0.5f, g_aShadow[nCnt].scale.z);
			D3DXMatrixMultiply(&g_aShadow[nCnt].mtxWorld, &g_aShadow[nCnt].mtxWorld, &mtxScale);

			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_aShadow[nCnt].rot.y, g_aShadow[nCnt].rot.x, g_aShadow[nCnt].rot.z);
			D3DXMatrixMultiply(&g_aShadow[nCnt].mtxWorld, &g_aShadow[nCnt].mtxWorld, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_aShadow[nCnt].pos.x, g_aShadow[nCnt].pos.y, g_aShadow[nCnt].pos.z);
			D3DXMatrixMultiply(&g_aShadow[nCnt].mtxWorld, &g_aShadow[nCnt].mtxWorld, &mtxTrans);

			//���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &g_aShadow[nCnt].mtxWorld);

			//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(0, g_pVtxBuffShadow, 0, sizeof(VERTEX_3D));

			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTextureShadow);

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCnt * 4, 2);

		}
	}

	//�ݒ�����ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//============================================================
//�e�̐ݒ�
//============================================================
int SetShadow(D3DXVECTOR3 pos, D3DXVECTOR3 rot,D3DXVECTOR3 scale)
{
	int nCntShadow = 0;
	for (nCntShadow = 0; nCntShadow < MAX_SHADOW; nCntShadow++)
	{
		if (g_aShadow[nCntShadow].bUse == false)
		{
			g_aShadow[nCntShadow].pos = pos;//�ʒu�̐ݒ�
			g_aShadow[nCntShadow].rot = rot;//�����̐ݒ�
			g_aShadow[nCntShadow].scale = scale;//�{���̐ݒ�

			g_aShadow[nCntShadow].bUse = true;//�g���Ă��Ԃɂ���

			break;
		}
	}

	return nCntShadow;
}

//============================================================
//�e�̈ʒu�̍X�V����
//============================================================
void SetPositionShadow(int nIndxShadow, D3DXVECTOR3 pos)
{
	g_aShadow[nIndxShadow].pos = pos;
}
