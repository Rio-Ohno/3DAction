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
LPDIRECT3DTEXTURE9 g_pTextureItemBill = NULL;							//�e�N�X�`���ւ̃|�C���^(����[��)
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
		g_Item[nCntItem].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//�ʒu
		g_Item[nCntItem].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//����
		g_Item[nCntItem].vtxMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//���_�̍ő�
		g_Item[nCntItem].vtxMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//���_�̍ŏ�
		g_Item[nCntItem].size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//���a
		g_Item[nCntItem].Type = 0;										//���
		g_Item[nCntItem].bUse = false;									//�g�p�����Ă��Ȃ����
		g_Item[nCntItem].bModel = true;									//�Ƃ肠�������f�����Ă��Ƃɂ��Ƃ�
		g_Item[nCntItem].pMesh = NULL;									//���b�V��

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
		D3DXLoadMeshFromX("data\\MODEL\\box000.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_Item[nCntItem].pBuffMat,
			NULL,
			&g_Item[nCntItem].dwNumMat,
			&g_Item[nCntItem].pMesh);

		int nNumVtx;													//�ő咸�_��
		DWORD sizeFVF;													//���_�t�H�[�}�b�g�̃T�C�Y
		BYTE* pVtxBUff;													//���_�o�b�t�@�ւ̃|�C���^

		//���_���̎擾			
		nNumVtx = g_Item[nCntItem].pMesh->GetNumVertices();

		//���_�t�H�[�}�b�g�̃T�C�Y���擾
		sizeFVF = D3DXGetFVFVertexSize(g_Item[nCntItem].pMesh->GetFVF());

		//���_�o�b�t�@�̃��b�N
		g_Item[nCntItem].pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBUff);

		for (int nCnt = 0; nCnt < nNumVtx; nCnt++)
		{
			//���_���W�̑��
			D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBUff;

			//���_���W���r���ă��f���̍ő�ŏ����擾

			if (vtx.x > g_Item[nCntItem].vtxMax.x)//x�ő�l
			{
				g_Item[nCntItem].vtxMax.x = vtx.x;
			}
			else if (vtx.x < g_Item[nCntItem].vtxMin.x)//x�ŏ��l
			{
				g_Item[nCntItem].vtxMin.x = vtx.x;
			}

			if (vtx.y > g_Item[nCntItem].vtxMax.y)//y�ő�l
			{
				g_Item[nCntItem].vtxMax.y = vtx.y;
			}
			else if (vtx.y < g_Item[nCntItem].vtxMin.y)//y�ŏ��l
			{
				g_Item[nCntItem].vtxMin.y = vtx.y;
			}

			if (vtx.z > g_Item[nCntItem].vtxMax.z)//z�ő�l
			{
				g_Item[nCntItem].vtxMax.z = vtx.z;
			}
			else if (vtx.z < g_Item[nCntItem].vtxMin.z)//z�ŏ��l
			{
				g_Item[nCntItem].vtxMin.z = vtx.z;
			}

			//���_�t�H�[�}�b�g�̃T�C�Y���|�C���^��i�߂�
			pVtxBUff += sizeFVF;
		}

		//���_�o�b�t�@�̃A�����b�N
		g_Item[nCntItem].pMesh->UnlockVertexBuffer();

		//�T�C�Y�̏�����
		g_Item[nCntItem].size = g_Item[nCntItem].vtxMax - g_Item[nCntItem].vtxMin;


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
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffItemBill->Unlock();
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
			//�����蔻��
			CollisionItem(nCntItem);
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
	//���_���ւ̃|�C���^
	VERTEX_3D* pVtx = NULL;
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

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

					g_Item[nCntItem].bModel = false;//�r���{�[�h

					//���_�o�b�t�@�����b�N
					g_pVtxBuffItemBill->Lock(0, 0, (void**)&pVtx, 0);

					pVtx[0].pos.x = g_Item[nCntItem].pos.x - ITEM_RADIUS;
					pVtx[0].pos.y = g_Item[nCntItem].pos.y + ITEM_RADIUS;
					pVtx[0].pos.z = g_Item[nCntItem].pos.z ;

					pVtx[1].pos.x = g_Item[nCntItem].pos.x + ITEM_RADIUS;
					pVtx[1].pos.y = g_Item[nCntItem].pos.y + ITEM_RADIUS;
					pVtx[1].pos.z = g_Item[nCntItem].pos.z;

					pVtx[2].pos.x = g_Item[nCntItem].pos.x - ITEM_RADIUS;
					pVtx[2].pos.y = g_Item[nCntItem].pos.y - ITEM_RADIUS;
					pVtx[2].pos.z = g_Item[nCntItem].pos.z;

					pVtx[3].pos.x = g_Item[nCntItem].pos.x + ITEM_RADIUS;
					pVtx[3].pos.y = g_Item[nCntItem].pos.y - ITEM_RADIUS;
					pVtx[3].pos.z = g_Item[nCntItem].pos.z;

					pVtx += 4;

					//���_�o�b�t�@�̃A�����b�N
					g_pVtxBuffItemBill->Unlock();

					break;

				case 1://�}�^�^�r

					g_Item[nCntItem].bModel = true;

					//X�t�@�C���̓Ǎ�
					D3DXLoadMeshFromX("data\\MODEL\\box000.x",
						D3DXMESH_SYSTEMMEM,
						pDevice,
						NULL,
						&g_Item[nCntItem].pBuffMat,
						NULL,
						&g_Item[nCntItem].dwNumMat,
						&g_Item[nCntItem].pMesh);

					break;

				case 2://��������

					g_Item[nCntItem].bModel = true;

					//X�t�@�C���̓Ǎ�
					D3DXLoadMeshFromX("data\\MODEL\\box000.x",
						D3DXMESH_SYSTEMMEM,
						pDevice,
						NULL,
						&g_Item[nCntItem].pBuffMat,
						NULL,
						&g_Item[nCntItem].dwNumMat,
						&g_Item[nCntItem].pMesh);

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

	if (g_Item[nIndexItem].bModel == true)//���f���Ȃ�
	{
		//�v���C���[�̔��a�擾
		D3DXVECTOR3 playerRadius = pPlayer->size / 2.0f;

		//����
		float Distance = (pPlayer->pos.x - g_Item[nIndexItem].pos.x) * (pPlayer->pos.x - g_Item[nIndexItem].pos.x) +
			(pPlayer->pos.z - g_Item[nIndexItem].pos.z) * (pPlayer->pos.z - g_Item[nIndexItem].pos.z);

		//�Q�̔��a
		float Radius = (playerRadius.z + g_Item[nIndexItem].size.z / 2.0f) * (playerRadius.z + g_Item[nIndexItem].size.z / 2.0f);

		if (Distance <= Radius)//�������Ă�Ȃ�
		{
			g_Item[nIndexItem].bUse = false;						//�g�p���Ă��Ȃ���Ԃɂ���
			pPlayer->nCntItem++;									//�A�C�e���������J�E���g
			g_nCntItem--;											//�h���b�v���̃A�C�e�����f�N�������g
		}
	}
	else if (g_Item[nIndexItem].bModel == false)//�r���{�[�h�Ȃ�
	{
		D3DXVECTOR3 vecPlayer, vecWall;								//aPos[0]���炻�ꂼ��ւ̃x�N�g���i�[�p
		D3DXVECTOR3 aPos[2];										//�e���_�i�[�p
		D3DXVECTOR3 fver;											//�O�ϊi�[�p

		//���_���W�i�[
		aPos[0].x = g_Item[nIndexItem].pos.x - cosf(g_Item[nIndexItem].rot.y) * ITEM_RADIUS;
		aPos[0].z = g_Item[nIndexItem].pos.z + sinf(g_Item[nIndexItem].rot.y) * ITEM_RADIUS;

		aPos[1].x = g_Item[nIndexItem].pos.x + cosf(g_Item[nIndexItem].rot.y) * ITEM_RADIUS;
		aPos[1].z = g_Item[nIndexItem].pos.z - sinf(g_Item[nIndexItem].rot.y) * ITEM_RADIUS;

		//�x�N�g��
		vecWall = aPos[1] - aPos[0];								//�A�C�e���̃x�N�g��(���E���x�N�g��)
		vecPlayer = pPlayer->pos - aPos[0];							//aPos[0]����v���C���[�ւ̃x�N�g��

		//�O��
		D3DXVec3Cross(&fver, &vecWall, &vecPlayer);

		if (fver.y < 0)//�������Ă�Ȃ�
		{
			g_Item[nIndexItem].bUse = false;						//�g�p���Ă��Ȃ���Ԃɂ���
			pPlayer->nCntItem++;									//�A�C�e���������J�E���g
			g_nCntItem--;											//�h���b�v���̃A�C�e�����f�N�������g
		}
	}
}