//============================================================
//
//�~��[MeshCylinder.cpp]
//Author:Rio Ohno
//
//============================================================

#include"meshcylinder.h"

//�O���[�o���ϐ��錾
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffMeshCylinder = NULL;						//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureMeshCylinder = NULL;							//�e�N�X�`���p�|�C���^
LPDIRECT3DINDEXBUFFER9 g_pIndxBuffMeshCylinder = NULL;						//�C���f�N�X�o�b�t�@�ւ̃|�C���^
MeshCylinder g_aMeshCylinder;

//============================================================
// ���b�V���t�B�[���h�̏���������
//============================================================
void InitMeshCylinder()
{
	//�f�o�C�X�ւ̃|�C���^�Ǝ擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * MAX_VERTEX_CYLINDER,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffMeshCylinder,
		NULL);

	//�C���f�b�N�X�o�b�t�@�̐���
	pDevice->CreateIndexBuffer(sizeof(WORD) * MAX_INDX_CYLINDER,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&g_pIndxBuffMeshCylinder,
		NULL);

	//�e�N�X�`���̓Ǎ�
	D3DXCreateTextureFromFile(pDevice,
		NULL,
		&g_pTextureMeshCylinder);

	//for (int nCnt = 0; nCnt < MAX_INDX; nCnt++)
	//{
	g_aMeshCylinder.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_aMeshCylinder.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//}

	//���_���ւ̃|�C���^
	VERTEX_3D* pVtx = NULL;
	int radius = 150;														//���a
	int index = 0;

	//���_�o�b�t�@�����b�N
	g_pVtxBuffMeshCylinder->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntz = 0; nCntz <= MAX_Z_CYLINDER; nCntz++)
	{
		for (int nCntx = 0; nCntx <= MAX_X_CYLINDER; nCntx++)
		{
			//int index = nCntx + nCntz * (MAX_X_CYLINDER + 1);

			float fAngle = D3DX_PI * 2 / MAX_X_CYLINDER * nCntx;
			//radian=180/D3DX_PI

			//���_���W�̐ݒ�
			pVtx[index].pos = D3DXVECTOR3(sinf(fAngle) * radius, 100.0f * (MAX_Z_CYLINDER - nCntz), cosf(fAngle) * radius);

			//�e���_���猴�_�ւ̃x�N�g��
			D3DXVECTOR3 vec = pVtx[index].pos - g_aMeshCylinder.pos;

			//�x�N�g���̐��K��,�e���_�̖@���̐ݒ�
			D3DXVec3Normalize(&pVtx[index].nor, &vec);
			
			//���_�J���[�̐ݒ�
			pVtx[index].col = D3DXCOLOR(1.0f, 0.5f, 0.5f, 1.0f);

			index++;
		}
	}
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffMeshCylinder->Unlock();

	//�C���f�b�N�X�o�b�t�@�����b�N
	WORD* pIndx;													//�C���f�b�N�X���ւ̃|�C���^
	g_pIndxBuffMeshCylinder->Lock(0, 0, (void**)&pIndx, 0);

	//�C���f�b�N�X�̐ݒ�
	int nCntx = 0;
	int nCntz = 0;

	for (nCntz = 0; nCntz < MAX_Z_CYLINDER; nCntz++)
	{
		for (nCntx = 0; nCntx <= MAX_X_CYLINDER; nCntx++)
		{

			pIndx[0] = (MAX_X_CYLINDER + 1) * (nCntz + 1) + nCntx;
			pIndx[1] = nCntx + (nCntz * (MAX_X_CYLINDER + 1));

			pIndx += 2;
		}

		if (nCntz < MAX_Z_CYLINDER - 1)
		{
			pIndx[0] = (nCntx - 1) + (nCntz * (MAX_X_CYLINDER + 1));
			pIndx[1] = (nCntx - 1) + (nCntz * (MAX_X_CYLINDER + 1)) + (MAX_X_CYLINDER + 2) * (nCntz + 1);
			pIndx += 2;
		}
	}

	//�C���f�b�N�X���A�����b�N
	g_pIndxBuffMeshCylinder->Unlock();
}

//============================================================
// �|���S���̏I������
//============================================================
void UninitMeshCylinder()
{
	//���_�o�b�t�@�̉��
	if (g_pVtxBuffMeshCylinder != NULL)
	{
		g_pVtxBuffMeshCylinder->Release();
		g_pVtxBuffMeshCylinder = NULL;
	}

	//�e�N�X�`���̉��
	if (g_pTextureMeshCylinder != NULL)
	{
		g_pTextureMeshCylinder->Release();
		g_pTextureMeshCylinder = NULL;
	}

	//�C���f�b�N�X�o�b�t�@�̉��
	if (g_pIndxBuffMeshCylinder != NULL)
	{
		g_pIndxBuffMeshCylinder->Release();
		g_pIndxBuffMeshCylinder = NULL;
	}
}

//============================================================
// �|���S���̍X�V����
//============================================================
void UpdateMeshCylinder()
{

}

//============================================================
// �|���S���̕`�揈��
//============================================================
void DrawMeshCylinder()
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	//for (int nCnt = 0; nCnt < MAX_INDX; nCnt++)
	//{
		//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_aMeshCylinder.mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_aMeshCylinder.rot.y, g_aMeshCylinder.rot.x, g_aMeshCylinder.rot.z);
	D3DXMatrixMultiply(&g_aMeshCylinder.mtxWorld, &g_aMeshCylinder.mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, g_aMeshCylinder.pos.x, g_aMeshCylinder.pos.y, g_aMeshCylinder.pos.z);
	D3DXMatrixMultiply(&g_aMeshCylinder.mtxWorld, &g_aMeshCylinder.mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &g_aMeshCylinder.mtxWorld);

	//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffMeshCylinder, 0, sizeof(VERTEX_3D));

	//�C���f�b�N�X�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetIndices(g_pIndxBuffMeshCylinder);

	//�e�N�X�`�����W�̐ݒ�
	pDevice->SetTexture(0, g_pTextureMeshCylinder);

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�|���S���̕`��
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, MAX_VERTEX_CYLINDER, 0, MAX_POLY_CYLINDER);//�^�C�v,?,�ǂ�pVtx����`�悷�邩,���_��,�ǂ̃C���f�b�N�X����`�悷�邩,�|���S����
//}
}