//============================================================
//
//���b�V���t�B�[���h[MeshField.cpp]
//Author:Rio Ohno
//
//============================================================

#include"meshfield.h"

//�O���[�o���ϐ��錾
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffMeshField = NULL;						//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureMeshField = NULL;							//�e�N�X�`���p�|�C���^
LPDIRECT3DINDEXBUFFER9 g_pIndxBuffMeshField = NULL;						//�C���f�N�X�o�b�t�@�ւ̃|�C���^
MeshField g_aMeshField;

//============================================================
// ���b�V���t�B�[���h�̏���������
//============================================================
void InitMeshField()
{
	//�f�o�C�X�ւ̃|�C���^�Ǝ擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * MAX_VERTEX_FIELD,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffMeshField,
		NULL);

	//�C���f�b�N�X�o�b�t�@�̐���
	pDevice->CreateIndexBuffer(sizeof(WORD) * MAX_INDX_FIELD,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&g_pIndxBuffMeshField,
		NULL);

	//�e�N�X�`���̓Ǎ�
	D3DXCreateTextureFromFile(pDevice,
		NULL,
		&g_pTextureMeshField);

		g_aMeshField.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aMeshField.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aMeshField.fHight = 300.0f;
		g_aMeshField.fWidth = 300.0f;

	//���_���ւ̃|�C���^
	VERTEX_3D* pVtx = NULL;

	//���_�o�b�t�@�����b�N
	g_pVtxBuffMeshField->Lock(0, 0, (void**)&pVtx, 0);

	int nDatax = MAX_X_FIELD / 2;//���炷��
	int nDataz = MAX_Z_FIELD / 2;//���炷��
	int nCntx = 0;//�J�E���^�[
	int nCntz = 0;//�J�E���^�[

	for (nCntz = 0; nCntz <= MAX_Z_FIELD; nCntz++)
	{
		float posz = g_aMeshField.fHight * 2 / (MAX_Z_FIELD) * (nDataz - nCntz);
		if (nDataz - nCntz == 0)//0�Ŋ������Ȃ�
		{
			posz = 0.0f;
		}

		for (nCntx = 0; nCntx <= MAX_X_FIELD; nCntx++)
		{
			int nCntVertex = nCntx + nCntz * (MAX_X_FIELD + 1);

			float posx = g_aMeshField.fWidth * 2 / (MAX_X_FIELD) * (nCntx - nDatax);
			if (nCntx - nDatax == 0)//0�Ŋ������Ȃ�
			{
				posx = 0.0f;
			}

			//���_���W�̐ݒ�
			pVtx[nCntVertex].pos = D3DXVECTOR3(posx, 0.0f, posz);

			//�e���_�̖@���̐ݒ�
			pVtx[nCntVertex].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

			//���_�J���[�̐ݒ�
			pVtx[nCntVertex].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0);

			//�e�N�X�`�����W�̐ݒ�
			//pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			//pVtx[1].tex = D3DXVECTOR2(0.5f, 0.0f);
			//pVtx[2].tex = D3DXVECTOR2(1.0f, 0.0f);
			//pVtx[3].tex = D3DXVECTOR2(0.0f, 0.5f);
			//pVtx[4].tex = D3DXVECTOR2(0.5f, 0.5f);
			//pVtx[5].tex = D3DXVECTOR2(1.0f, 0.5f);
			//pVtx[6].tex = D3DXVECTOR2(0.0f, 1.0f);
			//pVtx[7].tex = D3DXVECTOR2(0.5f, 1.0f);
			//pVtx[8].tex = D3DXVECTOR2(1.0f, 1.0f);

		}

		//pVtx[0].pos.y = 20.0f;
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffMeshField->Unlock();

	//�C���f�b�N�X�o�b�t�@�����b�N
	WORD* pIndx;													//�C���f�b�N�X���ւ̃|�C���^
	g_pIndxBuffMeshField->Lock(0, 0, (void**)&pIndx, 0);

	//�C���f�b�N�X�̐ݒ�

	for (nCntz = 0; nCntz < MAX_Z_FIELD; nCntz++)
	{
		for (nCntx = 0; nCntx <= MAX_X_FIELD; nCntx++)
		{

			pIndx[0] = (MAX_X_FIELD + 1) * (nCntz + 1) + nCntx;
			pIndx[1] = nCntx + (nCntz * (MAX_X_FIELD + 1));

			pIndx += 2;
		}

		if (nCntz < MAX_Z_FIELD - 1)
		{
			pIndx[0] = (nCntx-1) + (nCntz * (MAX_X_FIELD + 1));
			pIndx[1] = (nCntx - 1) + (nCntz * (MAX_X_FIELD + 1)) + (MAX_X_FIELD + 2) * (nCntz + 1);
			pIndx += 2;
		}
	}

	//pIndx[0] = 3;
	//pIndx[1] = 0;

	//pIndx[2] = 4;
	//pIndx[3] = 1;

	//pIndx[4] = 5;
	//pIndx[5] = 2;

	//pIndx[6] = 2;
	//pIndx[7] = 6;

	//pIndx[8] = 6;
	//pIndx[9] = 3;

	//pIndx[10] = 7;
	//pIndx[11] = 4;

	//pIndx[12] = 8;
	//pIndx[13] = 5;

	//�C���f�b�N�X���A�����b�N
	g_pIndxBuffMeshField->Unlock();
}

//============================================================
// �|���S���̏I������
//============================================================
void UninitMeshField()
{
	//���_�o�b�t�@�̉��
	if (g_pVtxBuffMeshField != NULL)
	{
		g_pVtxBuffMeshField->Release();
		g_pVtxBuffMeshField = NULL;
	}

	//�e�N�X�`���̉��
	if (g_pTextureMeshField != NULL)
	{
		g_pTextureMeshField->Release();
		g_pTextureMeshField = NULL;
	}

	//�C���f�b�N�X�o�b�t�@�̉��
	if (g_pIndxBuffMeshField != NULL)
	{
		g_pIndxBuffMeshField->Release();
		g_pIndxBuffMeshField = NULL;
	}
}

//============================================================
// �|���S���̍X�V����
//============================================================
void UpdateMeshField()
{

}

//============================================================
// �|���S���̕`�揈��
//============================================================
void DrawMeshField()
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_aMeshField.mtxWorld);

		//�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_aMeshField.rot.y, g_aMeshField.rot.x, g_aMeshField.rot.z);
		D3DXMatrixMultiply(&g_aMeshField.mtxWorld, &g_aMeshField.mtxWorld, &mtxRot);

		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, g_aMeshField.pos.x, g_aMeshField.pos.y, g_aMeshField.pos.z);
		D3DXMatrixMultiply(&g_aMeshField.mtxWorld, &g_aMeshField.mtxWorld, &mtxTrans);

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_aMeshField.mtxWorld);

		//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(0, g_pVtxBuffMeshField, 0, sizeof(VERTEX_3D));

		//�C���f�b�N�X�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
		pDevice->SetIndices(g_pIndxBuffMeshField);

		//�e�N�X�`�����W�̐ݒ�
		pDevice->SetTexture(0, g_pTextureMeshField);

		//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_3D);

		//�|���S���̕`��
		pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0,0,MAX_VERTEX_FIELD,0,MAX_POLY_FIELD);//�^�C�v,?,�ǂ�pVtx����`�悷�邩,���_��,�ǂ̃C���f�b�N�X����`�悷�邩,�|���S����
}