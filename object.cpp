//============================================================
//
//���f��[model.cpp]
//Author:Rio Ohno
//
//============================================================

#include"object.h"

//�O���|�o���ϐ��錾
LPD3DXMESH g_pMeshObject = NULL;
LPD3DXBUFFER g_pBuffmatObject = NULL;
DWORD g_dwNumMatObject = 0;
D3DXVECTOR3 g_posObject;
D3DXVECTOR3 g_rotObject;
D3DXMATRIX g_mtxWorldObject;
LPDIRECT3DTEXTURE9 apTextureObject[MAX_MAT];

//============================================================
// ���f���̏���������
//============================================================
void InitObject()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATERIAL* pMat;//�}�e���A���f�[�^�ւ̃|�C���^

	//�e�평����
	g_pMeshObject = NULL;
	g_pBuffmatObject = NULL;
	g_dwNumMatObject = 0;
	g_posObject = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_rotObject = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_mtxWorldObject);

	//X�t�@�C���̓Ǎ�
	D3DXLoadMeshFromX("data\\MODEL\\TV.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_pBuffmatObject,
		NULL,
		&g_dwNumMatObject,
		&g_pMeshObject);

	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)g_pBuffmatObject->GetBufferPointer();

	for (int nCnt = 0; nCnt < (int)g_dwNumMatObject; nCnt++)
	{
		//�e�N�X�`���|�C���^�̏�����
		apTextureObject[nCnt] = {};

		if (pMat[nCnt].pTextureFilename != NULL)
		{
			//�e�N�X�`���̓Ǎ�
			D3DXCreateTextureFromFile(pDevice,
				pMat[nCnt].pTextureFilename,
				&apTextureObject[nCnt]);

		}
	}
}

//============================================================
// ���f���̏I������
//============================================================
void UninitObject()
{
	//���b�V���̔j��
	if (g_pMeshObject != NULL)
	{
		g_pMeshObject->Release();
		g_pMeshObject = NULL;
	}

	//�}�e���A���̔j��
	if (g_pBuffmatObject != NULL)
	{
		g_pBuffmatObject->Release();
		g_pBuffmatObject = NULL;
	}

	for (int nCnt = 0; nCnt < (int)g_dwNumMatObject; nCnt++)
	{
		if (apTextureObject[nCnt] != NULL)
		{
			apTextureObject[nCnt]->Release();
			apTextureObject[nCnt] = NULL;
		}
	}
}

//============================================================
// ���f���̍X�V����
//============================================================
void UpdateObject()
{

}

//============================================================
// ���f���̕`�揈��
//============================================================
void DrawObject()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;//���݂̃}�e���A���ۑ��p
	D3DXMATERIAL* pMat;//�}�e���A���f�[�^�ւ̃|�C���^

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_mtxWorldObject);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotObject.y, g_rotObject.x, g_rotObject.z);
	D3DXMatrixMultiply(&g_mtxWorldObject, &g_mtxWorldObject, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, g_posObject.x, g_posObject.y, g_posObject.z);
	D3DXMatrixMultiply(&g_mtxWorldObject, &g_mtxWorldObject, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldObject);

	//���݂̃}�e���A�����擾
	pDevice->GetMaterial(&matDef);

	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)g_pBuffmatObject->GetBufferPointer();

	for (int nCnt = 0; nCnt < (int)g_dwNumMatObject; nCnt++)
	{

		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCnt].MatD3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, apTextureObject[nCnt]);

		//���f��(�p�[�c)�̕`��
		g_pMeshObject->DrawSubset(nCnt);
	}

	//�ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);

}