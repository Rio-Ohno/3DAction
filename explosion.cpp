//============================================================
//
//��������[explosion.cpp]
//Author:Rio Ohno
//
//============================================================

#include "explosion.h"

//�}�N����`
#define MAX_EXPLOSION (128)                                   //�e�̍ő吔
#define EXPLOSION_WIDTH (50)                                  //�|���S���̕�
#define EXPLOSION_HEIGHT (50)                                 //�|���S���̍���

//�e�\���̂̒�`
typedef struct
{
	D3DXVECTOR3 pos;                                          //�ʒu
	D3DXVECTOR3 rot;                                          //����
	D3DXCOLOR col;                                            //�F
	D3DXMATRIX mtxWorld;									  //���[���h�}�g���b�N�X
	bool bUse;                                                //�g�p���Ă��邩�ǂ�
	int nCounterAnim;                                         //�A�j���[�V�����J�E���^�[
	int nPatternAnim;                                         //�A�j���[�V�����p�^�[��
	float radius;											  //���a
}EXPLOSION;


//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureExplosion = NULL;				  //�e�N�X�`���p�|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffExplosion = NULL;           //���_�o�b�t�@�ւ̃|�C���^
EXPLOSION g_aExplosion[MAX_EXPLOSION];                        //�e�̏��

//=============================================================================================================
//����������
//=============================================================================================================
void InitExplosion(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntExplosion = NULL;

	//�f�o�C�X�Ɏ擾
	pDevice = GetDevice();

	//�e�N�X�`���̓Ǎ�
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\Explosion000.png",
		&g_pTextureExplosion);


	//�����̏��̏�����
	for (nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
	{
		g_aExplosion[nCntExplosion].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aExplosion[nCntExplosion].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aExplosion[nCntExplosion].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		g_aExplosion[nCntExplosion].nCounterAnim = 0;
		g_aExplosion[nCntExplosion].nPatternAnim = 0;
		g_aExplosion[nCntExplosion].bUse = false;                      //�g�p���Ă��Ȃ���Ԃɂ���
	}

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_EXPLOSION,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffExplosion,
		NULL);

	VERTEX_3D* pVtx;

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffExplosion->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos.x = 0.0f;
		pVtx[0].pos.y = 0.0f;
		pVtx[0].pos.z = 0.0f;

		pVtx[1].pos.x = 0.0f;
		pVtx[1].pos.y = 0.0f;
		pVtx[1].pos.z = 0.0f;

		pVtx[2].pos.x = 0.0f;
		pVtx[2].pos.y = 0.0f;
		pVtx[2].pos.z = 0.0f;

		pVtx[3].pos.x = 0.0f;
		pVtx[3].pos.y = 0.0f;
		pVtx[3].pos.z = 0.0f;

		//�e���_�̖@���̐ݒ�
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.125, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.125f, 1.0f);

		pVtx += 4;//���_�f�[�^�̃|�C���^��4���i�߂�

	}
	g_pVtxBuffExplosion->Unlock();
}

//=============================================================================================================
//�e�̏I������
//=============================================================================================================
void UninitExplosion()
{
	//�e�N�X�`���̔j��
	if (g_pTextureExplosion != NULL)
	{
		g_pTextureExplosion->Release();
		g_pTextureExplosion = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffExplosion != NULL)
	{
		g_pVtxBuffExplosion->Release();
		g_pVtxBuffExplosion = NULL;
	}
}

//=============================================================================================================
//�e�̍X�V����
//=============================================================================================================
void UpdateExplosion()
{
	int nCntExplosion = 0;

	VERTEX_3D* pVtx;

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffExplosion->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
	{
		if (g_aExplosion[nCntExplosion].bUse == true)
		{//�e���g�p����Ă���Ƃ�

			g_aExplosion[nCntExplosion].nCounterAnim++;
			if ((g_aExplosion[nCntExplosion].nCounterAnim % 8) == 0)
			{
				g_aExplosion[nCntExplosion].nCounterAnim = 0;

				g_aExplosion[nCntExplosion].nPatternAnim = (g_aExplosion[nCntExplosion].nPatternAnim + 1) % 8;

				if (g_aExplosion[nCntExplosion].nPatternAnim >= 7)//���p�^�[�����𒴂���
				{
					g_aExplosion[nCntExplosion].bUse = false;//�g�p���Ă��Ȃ���Ԃɂ���
				}

				//�e�N�X�`�����W�̍X�V
				pVtx[0].tex = D3DXVECTOR2(0.125f * g_aExplosion[nCntExplosion].nPatternAnim, 0.0f);
				pVtx[1].tex = D3DXVECTOR2(0.125f + 0.125f * g_aExplosion[nCntExplosion].nPatternAnim, 0.0f);
				pVtx[2].tex = D3DXVECTOR2(0.125f * g_aExplosion[nCntExplosion].nPatternAnim, 1.0f);
				pVtx[3].tex = D3DXVECTOR2(0.125f + 0.125f * g_aExplosion[nCntExplosion].nPatternAnim, 1.0f);
			}
		}
		pVtx += 4;
	}
	g_pVtxBuffExplosion->Unlock();
}

//=============================================================================================================
//�e�̕`�揈��
//=============================================================================================================
void DrawExplosion()
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

	for (int nCnt = 0; nCnt < MAX_EXPLOSION; nCnt++)
	{
		if (g_aExplosion[nCnt].bUse == true)
		{
			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_aExplosion[nCnt].mtxWorld);

			D3DXMATRIX mtxView;//�r���[�}�g���b�N�X

			//�r���[�}�g���b�N�X�̎擾
			pDevice->GetTransform(D3DTS_VIEW, &mtxView);

			//�J�����̋t�s���ݒ�
			g_aExplosion[nCnt].mtxWorld._11 = mtxView._11;
			g_aExplosion[nCnt].mtxWorld._12 = mtxView._21;
			g_aExplosion[nCnt].mtxWorld._13 = mtxView._31;
			g_aExplosion[nCnt].mtxWorld._21 = mtxView._12;
			g_aExplosion[nCnt].mtxWorld._22 = mtxView._22;
			g_aExplosion[nCnt].mtxWorld._23 = mtxView._32;
			g_aExplosion[nCnt].mtxWorld._31 = mtxView._13;
			g_aExplosion[nCnt].mtxWorld._32 = mtxView._23;
			g_aExplosion[nCnt].mtxWorld._33 = mtxView._33;

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_aExplosion[nCnt].pos.x, g_aExplosion[nCnt].pos.y, g_aExplosion[nCnt].pos.z);
			D3DXMatrixMultiply(&g_aExplosion[nCnt].mtxWorld, &g_aExplosion[nCnt].mtxWorld, &mtxTrans);

			//���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &g_aExplosion[nCnt].mtxWorld);

			//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(0, g_pVtxBuffExplosion, 0, sizeof(VERTEX_3D));

			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);

			//�e�N�X�`�����W�̐ݒ�
			pDevice->SetTexture(0, g_pTextureExplosion);

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCnt * 4, 2);
		}
	}

	//���C�g�L����
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	//�A���t�@�e�X�g�𖳌���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//=============================================================================================================
//�����̐ݒ菈��
//=============================================================================================================
void SetExplosion(D3DXVECTOR3 pos, D3DXCOLOR col, D3DXVECTOR3 rot, float radius)
{
	VERTEX_3D* pVtx;
	int nCntExplosion;

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffExplosion->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntExplosion = 0; nCntExplosion < MAX_EXPLOSION; nCntExplosion++)
	{
		if (g_aExplosion[nCntExplosion].bUse == false)
		{
			//�e���g�p����Ă��Ȃ��Ƃ�
			g_aExplosion[nCntExplosion].pos = pos;
			g_aExplosion[nCntExplosion].radius = radius;

			//���_���W�̐ݒ�
			pVtx[0].pos.x = g_aExplosion[nCntExplosion].pos.x - g_aExplosion[nCntExplosion].radius;
			pVtx[0].pos.y = g_aExplosion[nCntExplosion].pos.y + g_aExplosion[nCntExplosion].radius;
			pVtx[0].pos.z = g_aExplosion[nCntExplosion].pos.z;

			pVtx[1].pos.x = g_aExplosion[nCntExplosion].pos.x + g_aExplosion[nCntExplosion].radius;
			pVtx[1].pos.y = g_aExplosion[nCntExplosion].pos.y + g_aExplosion[nCntExplosion].radius;
			pVtx[1].pos.z = g_aExplosion[nCntExplosion].pos.z;

			pVtx[2].pos.x = g_aExplosion[nCntExplosion].pos.x - g_aExplosion[nCntExplosion].radius;
			pVtx[2].pos.y = g_aExplosion[nCntExplosion].pos.y - g_aExplosion[nCntExplosion].radius;
			pVtx[2].pos.z = g_aExplosion[nCntExplosion].pos.z;

			pVtx[3].pos.x = g_aExplosion[nCntExplosion].pos.x + g_aExplosion[nCntExplosion].radius;
			pVtx[3].pos.y = g_aExplosion[nCntExplosion].pos.y - g_aExplosion[nCntExplosion].radius;
			pVtx[3].pos.z = g_aExplosion[nCntExplosion].pos.z;

			g_aExplosion[nCntExplosion].bUse = true;//�g�p���Ă��Ԃɂ���
			break;
		}
		pVtx += 4;
	}
	g_pVtxBuffExplosion->Unlock();
}
