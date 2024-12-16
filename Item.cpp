//============================================================
//
//�A�C�e��[Item.cpp]
//Author:Rio Ohno
//
//============================================================

#include"Item.h"
#include "player.h"

//�O���|�o���ϐ��錾
Item g_Item[MAX_ITEM];
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItemBill = NULL;						//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureItemBill = NULL;							//�e�N�X�`���ւ̃|�C���^
int g_nCntItem = 0;														//����̃A�C�e����

//============================================================
// ���f���̏���������
//============================================================
void InitItem()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATERIAL* pMat;													//�}�e���A���f�[�^�ւ̃|�C���^
	g_nCntItem = 0;														//����̃A�C�e�����̏�����

	//�e�N�X�`���̓Ǎ�
	D3DXCreateTextureFromFile(pDevice,
		NULL,
		&g_pTextureItemBill);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_ITEM,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffItemBill,
		NULL);

	//���_���ւ̃|�C���^
	VERTEX_3D* pVtx = NULL;

	//���_�o�b�t�@�����b�N
	g_pVtxBuffItemBill->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		//�e�평����
		g_Item[nCntItem].pMesh = NULL;									//���b�V���|�C���^
		g_Item[nCntItem].pBuffMat = NULL;								//�}�e���A��
		g_Item[nCntItem].dwNumMat = 0;									//���_���
		g_Item[nCntItem].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//�ʒu
		g_Item[nCntItem].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//����
		g_Item[nCntItem].Type = 0;										//���
		g_Item[nCntItem].bUse = false;									//�g�p�����Ă��Ȃ����

		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		//�r���{�[�h
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

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

		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		//���f��
		//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_Item[nCntItem].mtxWorld);

		//X�t�@�C���̓Ǎ�
		D3DXLoadMeshFromX(NULL,
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_Item[nCntItem].pBuffMat,
			NULL,
			&g_Item[nCntItem].dwNumMat,
			&g_Item[nCntItem].pMesh);

		//�}�e���A���f�[�^�ւ̃|�C���^���擾
		pMat = (D3DXMATERIAL*)g_Item[nCntItem].pBuffMat->GetBufferPointer();

		for (int nCnt = 0; nCnt < (int)g_Item[nCntItem].dwNumMat; nCnt++)
		{
			//�e�N�X�`���|�C���^�̏�����
			g_Item[nCntItem].apTextureItem[nCnt] = {};

			if (pMat[nCnt].pTextureFilename != NULL)
			{
				//�e�N�X�`���̓Ǎ�
				D3DXCreateTextureFromFile(pDevice,
					pMat[nCnt].pTextureFilename,
					&g_Item[nCntItem].apTextureItem[nCnt]);

			}
		}
	}
}

//============================================================
// ���f���̏I������
//============================================================
void UninitItem()
{
	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		//���b�V���̔j��
		if (g_Item[nCntItem].pMesh != NULL)
		{
			g_Item[nCntItem].pMesh->Release();
			g_Item[nCntItem].pMesh = NULL;
		}

		//�}�e���A���̔j��
		if (g_Item[nCntItem].pBuffMat != NULL)
		{
			g_Item[nCntItem].pBuffMat->Release();
			g_Item[nCntItem].pBuffMat = NULL;
		}

		for (int nCnt = 0; nCnt < (int)g_Item[nCntItem].dwNumMat; nCnt++)
		{
			if (g_Item[nCntItem].apTextureItem[nCnt] != NULL)
			{
				g_Item[nCntItem].apTextureItem[nCnt]->Release();
				g_Item[nCntItem].apTextureItem[nCnt] = NULL;
			}
		}
	}
}

//============================================================
// ���f���̍X�V����
//============================================================
void UpdateItem()
{
	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		if (g_Item[nCntItem].bUse == true)
		{
		}
	}
}

//============================================================
// �A�C�e��(���f��)�̕`�揈��
//============================================================
void DrawItemModel()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;										//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;												//���݂̃}�e���A���ۑ��p
	D3DXMATERIAL* pMat;													//�}�e���A���f�[�^�ւ̃|�C���^

	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		if (g_Item[nCntItem].bUse == true)								//�g�p���Ă��鎞
		{
			if (g_Item[nCntItem].bModel == true)						//3D���f���̎�
			{
				//���[���h�}�g���b�N�X�̏�����
				D3DXMatrixIdentity(&g_Item[nCntItem].mtxWorld);

				//�����𔽉f
				D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Item[nCntItem].rot.y, g_Item[nCntItem].rot.x, g_Item[nCntItem].rot.z);
				D3DXMatrixMultiply(&g_Item[nCntItem].mtxWorld, &g_Item[nCntItem].mtxWorld, &mtxRot);

				//�ʒu�𔽉f
				D3DXMatrixTranslation(&mtxTrans, g_Item[nCntItem].pos.x, g_Item[nCntItem].pos.y, g_Item[nCntItem].pos.z);
				D3DXMatrixMultiply(&g_Item[nCntItem].mtxWorld, &g_Item[nCntItem].mtxWorld, &mtxTrans);

				//���[���h�}�g���b�N�X�̐ݒ�
				pDevice->SetTransform(D3DTS_WORLD, &g_Item[nCntItem].mtxWorld);

				//���݂̃}�e���A�����擾
				pDevice->GetMaterial(&matDef);

				//�}�e���A���f�[�^�ւ̃|�C���^���擾
				pMat = (D3DXMATERIAL*)g_Item[nCntItem].pBuffMat->GetBufferPointer();

				for (int nCnt = 0; nCnt < (int)g_Item[nCntItem].dwNumMat; nCnt++)
				{

					//�}�e���A���̐ݒ�
					pDevice->SetMaterial(&pMat[nCnt].MatD3D);

					//�e�N�X�`���̐ݒ�
					pDevice->SetTexture(0, g_Item[nCntItem].apTextureItem[nCnt]);

					//���f��(�p�[�c)�̕`��
					g_Item[nCntItem].pMesh->DrawSubset(nCnt);
				}

				//�ۑ����Ă����}�e���A����߂�
				pDevice->SetMaterial(&matDef);
			}
		}
	}
}

//============================================================
// �A�C�e��(�r���{�[�h)�̕`�揈��
//============================================================
void DrawItemBillboard()
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

	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		if (g_Item[nCntItem].bUse == true)
		{
			if (g_Item[nCntItem].bModel == false)
			{
				//���[���h�}�g���b�N�X�̏�����
				D3DXMatrixIdentity(&g_Item[nCntItem].mtxWorld);

				D3DXMATRIX mtxView;//�r���[�}�g���b�N�X

				//�r���[�}�g���b�N�X�̎擾
				pDevice->GetTransform(D3DTS_VIEW, &mtxView);

				//�J�����̋t�s���ݒ�
				g_Item[nCntItem].mtxWorld._11 = mtxView._11;
				g_Item[nCntItem].mtxWorld._12 = mtxView._21;
				g_Item[nCntItem].mtxWorld._13 = mtxView._31;
				g_Item[nCntItem].mtxWorld._21 = mtxView._12;
				g_Item[nCntItem].mtxWorld._22 = mtxView._22;
				g_Item[nCntItem].mtxWorld._23 = mtxView._32;
				g_Item[nCntItem].mtxWorld._31 = mtxView._13;
				g_Item[nCntItem].mtxWorld._32 = mtxView._23;
				g_Item[nCntItem].mtxWorld._33 = mtxView._33;

				//�ʒu�𔽉f
				D3DXMatrixTranslation(&mtxTrans, g_Item[nCntItem].pos.x, g_Item[nCntItem].pos.y, g_Item[nCntItem].pos.z);
				D3DXMatrixMultiply(&g_Item[nCntItem].mtxWorld, &g_Item[nCntItem].mtxWorld, &mtxTrans);

				//���[���h�}�g���b�N�X�̐ݒ�
				pDevice->SetTransform(D3DTS_WORLD, &g_Item[nCntItem].mtxWorld);

				//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
				pDevice->SetStreamSource(0, g_pVtxBuffItemBill, 0, sizeof(VERTEX_3D));

				//���_�t�H�[�}�b�g�̐ݒ�
				pDevice->SetFVF(FVF_VERTEX_3D);

				//�e�N�X�`�����W�̐ݒ�
				pDevice->SetTexture(0, g_pTextureItemBill);

				//�|���S���̕`��
				pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntItem * 4, 2);
			}
		}
	}

	//���C�g�L����
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	//�A���t�@�e�X�g�𖳌���
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//============================================================
// �A�C�e���̐ݒ菈��
//============================================================
void SetItem(D3DXVECTOR3 pos, int nType)
{
	for (int nCntItem = 0; nCntItem < MAX_ITEM; nCntItem++)
	{
		if (g_nCntItem != MAX_ITEM)//�ő�h���b�v���𒴂��ĂȂ��Ȃ�
		{
			if (g_Item[nCntItem].bUse == false)
			{
				g_Item[nCntItem].bUse = true;								//�g�p���Ă����Ԃɂ���
				g_Item[nCntItem].pos = pos;									//�ʒu�̐ݒ�
				g_Item[nCntItem].Type = nType;								//��ނ̐ݒ�
				g_nCntItem++;												//�A�C�e�����J�E���g

				switch (g_Item[nCntItem].Type)
				{
				case 0://����`��

					g_Item[nCntItem].bModel = false;

					break;

				case 1://�}�^�^�r

					g_Item[nCntItem].bModel = true;

					break;

				case 2://��������

					g_Item[nCntItem].bModel = true;

					break;

				default://�h���b�v���Ȃ�

					g_Item[nCntItem].bUse = false;							//�g�p���Ă��Ȃ���Ԃɂ���
					g_nCntItem--;											//�A�C�e�����f�N�������g

					break;
				}
			}
		}
		else if (g_nCntItem == MAX_ITEM)//�ő�h���b�v���𒴂��Ă�Ȃ�
		{
			break;
		}
	}
}

//============================================================
// �A�C�e���̎擾����
//============================================================
void CollisionItem(int nIndexItem)
{
	//�v���C���[�̏��擾
	Player* pPlayer = GetPlayer();

	if (g_Item[nIndexItem].bUse == true)//�g�p���Ă����ԂȂ�
	{
		if (g_Item[nIndexItem].bModel == true)//���f���Ȃ�
		{
		}
		else if (g_Item[nIndexItem].bModel == false)//�r���{�[�h�Ȃ�
		{
		}
	}
}