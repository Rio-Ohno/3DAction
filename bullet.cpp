//============================================================
//
//�e[Bullet.cpp]
//Author:Rio Ohno
//
//============================================================

#include"bullet.h"
#include "shadow.h"
#include "explosion.h"
#include"wall.h"

//�O���[�o���ϐ��錾
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBullet = NULL;										//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureBullet = NULL;												//�e�N�X�`���ւ̃|�C���^
Bullet g_aBullet[MAX_BULLET];															//�r���{�[�h�\����

//============================================================
// �e�̏���������
//============================================================
void InitBullet()
{
	//�f�o�C�X�ւ̃|�C���^�Ǝ擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�e�N�X�`���̓Ǎ�
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\bullet000.png",
		&g_pTextureBullet);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_BULLET,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBullet,
		NULL);

	for (int nCnt = 0; nCnt < MAX_BULLET; nCnt++)
	{
		g_aBullet[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCnt].posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCnt].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCnt].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCnt].dir = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCnt].nIndexShadow = 0;
		g_aBullet[nCnt].nLife = BULLET_LIFE;
		g_aBullet[nCnt].radius = 20.0f;
		g_aBullet[nCnt].bUse = false;
	}

	//���_���ւ̃|�C���^
	VERTEX_3D* pVtx = NULL;

	//���_�o�b�t�@�����b�N
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_BULLET; nCnt++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//�e���_�̖@���̐ݒ�
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

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
	g_pVtxBuffBullet->Unlock();
}

//============================================================
// �e�̏I������
//============================================================
void UninitBullet()
{
	//���_�o�b�t�@�̉��
	if (g_pVtxBuffBullet != NULL)
	{
		g_pVtxBuffBullet->Release();
		g_pVtxBuffBullet = NULL;
	}

	//�e�N�X�`���̔j��
	if (g_pTextureBullet != NULL)
	{
		g_pTextureBullet->Release();
		g_pTextureBullet = NULL;
	}
}

//============================================================
// �e�̍X�V����
//============================================================
void UpdateBullet()
{
	//���_���ւ̃|�C���^
	VERTEX_3D* pVtx = NULL;

	//���_�o�b�t�@�����b�N
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_BULLET; nCnt++)
	{
		if (g_aBullet[nCnt].bUse == true)
		{
			//�O��̈ʒu��ۑ�
			g_aBullet[nCnt].posOld = g_aBullet[nCnt].pos;

			float rot = g_aBullet[nCnt].dir.y + D3DX_PI;

			//�ڕW�̈ړ������i�p�x�j�̕␳
			if (rot > D3DX_PI)
			{
				rot -= D3DX_PI * 2.0f;
			}
			else if (g_aBullet[nCnt].dir.y + D3DX_PI < -D3DX_PI)
			{
				rot += D3DX_PI * 2.0f;
			}

			//�ړ��ʍX�V
			g_aBullet[nCnt].move.x = sinf(rot) * BULLET_SPEED;
			g_aBullet[nCnt].move.y = g_aBullet[nCnt].pos.y;
			g_aBullet[nCnt].move.z = cosf(rot) * BULLET_SPEED;

			//�������s���������
			g_aBullet[nCnt].nLife--;
			if (g_aBullet[nCnt].nLife <= 0)
			{
				g_aBullet[nCnt].bUse = false;
				SetExplosion(g_aBullet[nCnt].pos, D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.7f), g_aBullet[nCnt].rot, g_aBullet[nCnt].radius);
				DeleteShadow(g_aBullet[nCnt].nIndexShadow);
			}

			if ((CollisionBullet(nCnt)) == true)
			{
				g_aBullet[nCnt].bUse = false;
				DeleteShadow(g_aBullet[nCnt].nIndexShadow);
			}

			//�ʒu�̍X�V
			g_aBullet[nCnt].pos += g_aBullet[nCnt].move;

			//�e�̈ʒu�X�V
			SetPositionShadow(g_aBullet[nCnt].nIndexShadow, g_aBullet[nCnt].pos);

			//���_���W�̐ݒ�
			pVtx[0].pos.x = g_aBullet[nCnt].pos.x - g_aBullet[nCnt].radius;
			pVtx[0].pos.y = g_aBullet[nCnt].pos.y + g_aBullet[nCnt].radius;
			pVtx[0].pos.z = g_aBullet[nCnt].pos.z;

			pVtx[1].pos.x = g_aBullet[nCnt].pos.x + g_aBullet[nCnt].radius;
			pVtx[1].pos.y = g_aBullet[nCnt].pos.y + g_aBullet[nCnt].radius;
			pVtx[1].pos.z = g_aBullet[nCnt].pos.z;

			pVtx[2].pos.x = g_aBullet[nCnt].pos.x - g_aBullet[nCnt].radius;
			pVtx[2].pos.y = g_aBullet[nCnt].pos.y - g_aBullet[nCnt].radius;
			pVtx[2].pos.z = g_aBullet[nCnt].pos.z;

			pVtx[3].pos.x = g_aBullet[nCnt].pos.x + g_aBullet[nCnt].radius;
			pVtx[3].pos.y = g_aBullet[nCnt].pos.y - g_aBullet[nCnt].radius;
			pVtx[3].pos.z = g_aBullet[nCnt].pos.z;
		}
		pVtx += 4;
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffBullet->Unlock();
}

//============================================================
// �e�̕`�揈��
//============================================================
void DrawBullet()
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	//���C�g�̖�����
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	//�A���t�@�e�X�g��L����
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);

	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	for (int nCnt = 0; nCnt < MAX_BULLET; nCnt++)
	{
		if (g_aBullet[nCnt].bUse == true)
		{
			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_aBullet[nCnt].mtxWorld);

			D3DXMATRIX mtxView;//�r���[�}�g���b�N�X

			//�r���[�}�g���b�N�X�̎擾
			pDevice->GetTransform(D3DTS_VIEW, &mtxView);

			//�J�����̋t�s���ݒ�
			g_aBullet[nCnt].mtxWorld._11 = mtxView._11;
			g_aBullet[nCnt].mtxWorld._12 = mtxView._21;
			g_aBullet[nCnt].mtxWorld._13 = mtxView._31;
			g_aBullet[nCnt].mtxWorld._21 = mtxView._12;
			g_aBullet[nCnt].mtxWorld._22 = mtxView._22;
			g_aBullet[nCnt].mtxWorld._23 = mtxView._32;
			g_aBullet[nCnt].mtxWorld._31 = mtxView._13;
			g_aBullet[nCnt].mtxWorld._32 = mtxView._23;
			g_aBullet[nCnt].mtxWorld._33 = mtxView._33;

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_aBullet[nCnt].pos.x, g_aBullet[nCnt].pos.y, g_aBullet[nCnt].pos.z);
			D3DXMatrixMultiply(&g_aBullet[nCnt].mtxWorld, &g_aBullet[nCnt].mtxWorld, &mtxTrans);

			//���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &g_aBullet[nCnt].mtxWorld);

			//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(0, g_pVtxBuffBullet, 0, sizeof(VERTEX_3D));

			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);

			//�e�N�X�`�����W�̐ݒ�
			pDevice->SetTexture(0, g_pTextureBullet);

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCnt * 4, 2);
		}
	}

	//���C�g�L����
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	//�A���t�@�e�X�g�𖳌���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//============================================================
// �e�̐ݒ菈��
//============================================================
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 dir, float radius)
{
	//���_���ւ̃|�C���^
	VERTEX_3D* pVtx = NULL;

	//���_�o�b�t�@�����b�N
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_BULLET; nCnt++)
	{
		if (g_aBullet[nCnt].bUse == false)
		{
			g_aBullet[nCnt].pos = pos;													//�ʒu�̐ݒ�
			g_aBullet[nCnt].dir = dir;													//�����x�N�g���̐ݒ�
			g_aBullet[nCnt].radius = radius;											//���a�̐ݒ�
			g_aBullet[nCnt].nLife = BULLET_LIFE;

			pVtx[0].pos.x = g_aBullet[nCnt].pos.x - g_aBullet[nCnt].radius;
			pVtx[0].pos.y = g_aBullet[nCnt].pos.y + g_aBullet[nCnt].radius;
			pVtx[0].pos.z = g_aBullet[nCnt].pos.z;

			pVtx[1].pos.x = g_aBullet[nCnt].pos.x + g_aBullet[nCnt].radius;
			pVtx[1].pos.y = g_aBullet[nCnt].pos.y + g_aBullet[nCnt].radius;
			pVtx[1].pos.z = g_aBullet[nCnt].pos.z;

			pVtx[2].pos.x = g_aBullet[nCnt].pos.x - g_aBullet[nCnt].radius;
			pVtx[2].pos.y = g_aBullet[nCnt].pos.y - g_aBullet[nCnt].radius;
			pVtx[2].pos.z = g_aBullet[nCnt].pos.z;

			pVtx[3].pos.x = g_aBullet[nCnt].pos.x + g_aBullet[nCnt].radius;
			pVtx[3].pos.y = g_aBullet[nCnt].pos.y - g_aBullet[nCnt].radius;
			pVtx[3].pos.z = g_aBullet[nCnt].pos.z;

			//�e�̃C���f�b�N�X�̐ݒ�
			g_aBullet[nCnt].nIndexShadow = SetShadow(g_aBullet[nCnt].pos, g_aBullet[nCnt].rot,D3DXVECTOR3(0.25f,0.5f,0.25f));
			g_aBullet[nCnt].bUse = true;												//�g�p���Ă����Ԃɂ���
			break;
		}
		pVtx += 4;
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffBullet->Unlock();
}

//============================================================
// �e�̏��擾
//============================================================
Bullet* GetBullet()
{
	return &g_aBullet[0];
}

//============================================================
// �e�̓����蔻��
//============================================================
bool CollisionBullet(int Index)		
{
	//�ǂ̏��擾
	Wall* pWall = GetWall();

	bool ver = false;

		if (g_aBullet[Index].bUse == true)
		{	
			for (int nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
			{
				if (pWall[nCntWall].bUse == true)
				{
					//++++++++++++++++
					//�ǂƂ̓����蔻��
					//++++++++++++++++


					D3DXVECTOR3 vecLine = pWall[nCntWall].vecWall;//vecLine�i�[
					D3DXVECTOR3 vecMove = g_aBullet[Index].pos - pWall[nCntWall].aPos[0];

					//�v�Z���ʊi�[�p
					D3DXVECTOR3 vecNor = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

					//�O��
					D3DXVec3Cross(&vecNor, &pWall[nCntWall].vecWall, &vecMove);

					if (vecNor.y < 0)
					{
						//�@���̐��K��
						D3DXVec3Normalize(&vecNor, &vecNor);

						SetExplosion(g_aBullet[Index].posOld, D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.7f), g_aBullet[Index].rot, g_aBullet[Index].radius * 0.9f);
						vecNor *= -1;

						//����
						float fvec = (vecMove.x * vecNor.x) + (vecMove.z * vecNor.z);

						//float vecC = vecNor * fvec;

						ver = true;
					}
				}
			}
		}
	return ver;
}