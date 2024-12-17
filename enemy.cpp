//============================================================
//
//�G[enemy.cpp]
//Author:Rio Ohno
//
//============================================================

#include"enemy.h"
//#include "block.h"
#include "wall.h"
#include"bullet.h"
#include"Item.h"

//�O���|�o���ϐ��錾
Enemy g_enemy[MAX_ENEMY];
static  Key_ENEMY_Info g_keyNeutrall[] =
{ //Key0......................................................
	{40,
	//�p�[�c0
	{{0.0f,0.0f,0.0f,0.06f, 0.0f, 0.0f},
	//�p�[�c1
	 {0.0f ,0.0f ,0.0f,-0.16f, 0.0f, 0.0f},
	 //�p�[�c2
	  {0.0f,0.0f,0.0f,0.0f, 0.0f, 0.0f},
	  //�p�[�c3
	   {0.0f,0.0f,0.0f,0.0f, 0.0f, 0.0f},
	   //�p�[�c4
		{0.0f,0.0f,0.0f,0.0f, 0.0f, 1.19f},
		//�p�[�c5
		 {0.0f,0.0f,0.0f,0.0f,-0.6f,0.13f},
		 //�p�[�c6
		  {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
		  //�p�[�c7
		   {0.0f,0.0f,0.0f,0.0f,0.0f,-1.19f},
		   //�p�[�c8
			{0.0f,0.0f,0.0f,0.0f,0.6f,-0.13f},
			//�p�[�c9
			 {0.0f,0.0f,0.0f,0.13f,0.0f,0.0f},
			 //�p�[�c10
			  {0.0f,0.0f,0.0f,-0.6f,0.0,-0.22f},
			  //�p�[�c11
			   {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
			   //�p�[�c12
				{0.0f,0.0f,0.0f,0.13f,0.0f,0.0f},
				//�p�[�c13
				 {0.0f,0.0f,0.0f,-0.6f,0.0f,0.22f},
				 //�p�[�c14
				  {0.0f,0.0f,0.0f,-0.0f,0.0f,0.0f}
				 }},

	//Key1......................................................
   {40,
	//�p�[�c0
	{{0.0f,0.0f,0.0f,0.06f, 0.0f, 0.0f},
	//�p�[�c1
	 {0.0f,0.0f,0.0f,-0.09f, 0.0f, 0.0f},
	//�p�[�c2
	 {0.0f, 0.0f,0.0f, 0.0f, 0.0f, 0.0f},
	//�p�[�c3
	 {0.0f,0.0f,0.0f, 0.0f, 0.0f, 0.0f},
	//�p�[�c4
	 {0.0f,0.0f,0.0f,-0.06f,0.0f,1.13f},
	//�p�[�c5
	 {0.0f,0.0f,0.0f,0.0f,-0.6f,0.13f},
	//�p�[�c6
	  {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
	//�p�[�c7
	 {0.0f,0.0f,0.0f,-0.06f,0.0f,-1.13f},
	//�p�[�c8
	 {0.0f,0.0f,0.0f,0.0f,0.6f,-0.13f},
	//�p�[�c9
	 {0.0f,0.0f,0.0f,0.03f,0.0f,0.0f},
	//�p�[�c10
	 {0.0f,0.0f,0.0f,-0.5f,0.0f,-0.22f},
	//�p�[�c11
	 {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
	//�p�[�c12
	 {0.0f,0.0f,0.0f,0.03f,0.0f,0.0f},
	//�p�[�c13
	 {0.0f,0.0f,0.0f,-0.5f,0.0f,0.22f},
	//�p�[�c14
	 {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}
	}}
};

//============================================================
// �G�̏���������
//============================================================
void InitEnemy()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATERIAL* pMat;//�}�e���A���f�[�^�ւ̃|�C���^
	int nCntEnemy = 0;

	for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		//�e�평����
		g_enemy[nCntEnemy].pos = D3DXVECTOR3(50.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].vtxMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].vtxMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].motionType = MOTIONTYPE_ENEMY_NEUTRAL;
		g_enemy[nCntEnemy].nLife = 1;
		g_enemy[nCntEnemy].nNumModel = 0;
		g_enemy[nCntEnemy].nNumMotion = 0;
		g_enemy[nCntEnemy].nNumKey = 0;
		g_enemy[nCntEnemy].nKey = 1;
		g_enemy[nCntEnemy].nCounterMotion = 0;
		g_enemy[nCntEnemy].nCntFream = 0;
		g_enemy[nCntEnemy].nIndxShadow = SetShadow(g_enemy[nCntEnemy].pos, g_enemy[nCntEnemy].rot, D3DXVECTOR3(1.0f, 0.5f, 1.0f));
		g_enemy[nCntEnemy].bjump = false;
		g_enemy[nCntEnemy].bUse = true;
		g_enemy[nCntEnemy].bFrag = false;

		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_enemy[nCntEnemy].mtxWorldEnemy);


		//X�t�@�C���̓Ǎ�
		D3DXLoadMeshFromX("data\\MODEL\\enemy\\koshi.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[0].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[0].dwNumMat,
			&g_enemy[nCntEnemy].aModel[0].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\mune.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[1].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[1].dwNumMat,
			&g_enemy[nCntEnemy].aModel[1].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\atama.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[2].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[2].dwNumMat,
			&g_enemy[nCntEnemy].aModel[2].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rkata.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[3].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[3].dwNumMat,
			&g_enemy[nCntEnemy].aModel[3].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rnino.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[4].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[4].dwNumMat,
			&g_enemy[nCntEnemy].aModel[4].pMesh);


		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rude.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[5].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[5].dwNumMat,
			&g_enemy[nCntEnemy].aModel[5].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lkata.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[6].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[6].dwNumMat,
			&g_enemy[nCntEnemy].aModel[6].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lnino.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[7].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[7].dwNumMat,
			&g_enemy[nCntEnemy].aModel[7].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lude.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[8].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[8].dwNumMat,
			&g_enemy[nCntEnemy].aModel[8].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rmomo.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[9].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[9].dwNumMat,
			&g_enemy[nCntEnemy].aModel[9].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rhiza.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[10].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[10].dwNumMat,
			&g_enemy[nCntEnemy].aModel[10].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Rashi.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[11].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[11].dwNumMat,
			&g_enemy[nCntEnemy].aModel[11].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lmomo.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[12].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[12].dwNumMat,
			&g_enemy[nCntEnemy].aModel[12].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lhiza.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[13].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[13].dwNumMat,
			&g_enemy[nCntEnemy].aModel[13].pMesh);

		D3DXLoadMeshFromX("data\\MODEL\\enemy\\Lashi.x",
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_enemy[nCntEnemy].aModel[14].pBuffMat,
			NULL,
			&g_enemy[nCntEnemy].aModel[14].dwNumMat,
			&g_enemy[nCntEnemy].aModel[14].pMesh);

		g_enemy[nCntEnemy].nNumModel = 15;												//�p�[�c���̐ݒ�

		//�e�p�[�c�̊K�w�\���ݒ�
		g_enemy[nCntEnemy].aModel[0].nIndxModelpParent = -1;
		g_enemy[nCntEnemy].aModel[0].pos = D3DXVECTOR3(0.0f, 17.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[0].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[1].nIndxModelpParent = 0;
		g_enemy[nCntEnemy].aModel[1].pos = D3DXVECTOR3(0.0f, 12.5f, 0.0f);
		g_enemy[nCntEnemy].aModel[1].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[2].nIndxModelpParent = 1;
		g_enemy[nCntEnemy].aModel[2].pos = D3DXVECTOR3(0.0f, 12.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[2].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[3].nIndxModelpParent = 1;
		g_enemy[nCntEnemy].aModel[3].pos = D3DXVECTOR3(-2.5f, 10.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[3].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[4].nIndxModelpParent = 3;
		g_enemy[nCntEnemy].aModel[4].pos = D3DXVECTOR3(-5.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[4].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[5].nIndxModelpParent = 4;
		g_enemy[nCntEnemy].aModel[5].pos = D3DXVECTOR3(-10.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[5].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[6].nIndxModelpParent = 1;
		g_enemy[nCntEnemy].aModel[6].pos = D3DXVECTOR3(2.5f, 10.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[6].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[7].nIndxModelpParent = 6;
		g_enemy[nCntEnemy].aModel[7].pos = D3DXVECTOR3(5.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[7].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[8].nIndxModelpParent = 7;
		g_enemy[nCntEnemy].aModel[8].pos = D3DXVECTOR3(10.0f, 0.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[8].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[9].nIndxModelpParent = 0;
		g_enemy[nCntEnemy].aModel[9].pos = D3DXVECTOR3(-5.0f, 7.5f, 1.0f);
		g_enemy[nCntEnemy].aModel[9].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[10].nIndxModelpParent = 9;
		g_enemy[nCntEnemy].aModel[10].pos = D3DXVECTOR3(0.0f, -12.5f, 0.0f);
		g_enemy[nCntEnemy].aModel[10].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[11].nIndxModelpParent = 10;
		g_enemy[nCntEnemy].aModel[11].pos = D3DXVECTOR3(0.0f, -5.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[11].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[12].nIndxModelpParent = 0;
		g_enemy[nCntEnemy].aModel[12].pos = D3DXVECTOR3(5.0f, 7.5f, 1.0f);
		g_enemy[nCntEnemy].aModel[12].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[13].nIndxModelpParent = 12;
		g_enemy[nCntEnemy].aModel[13].pos = D3DXVECTOR3(0.0f, -12.5f, 0.0f);
		g_enemy[nCntEnemy].aModel[13].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_enemy[nCntEnemy].aModel[14].nIndxModelpParent = 13;
		g_enemy[nCntEnemy].aModel[14].pos = D3DXVECTOR3(0.0f, -5.0f, 0.0f);
		g_enemy[nCntEnemy].aModel[14].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


		for (int nCntModel = 0; nCntModel < g_enemy[nCntEnemy].nNumModel; nCntModel++)
		{
			int nNumVtx;//�ő咸�_��
			DWORD sizeFVF;//���_�t�H�[�}�b�g�̃T�C�Y
			BYTE* pVtxBUff;//���_�o�b�t�@�ւ̃|�C���^

			//���_���̎擾
			nNumVtx = g_enemy[nCntEnemy].aModel[nCntModel].pMesh->GetNumVertices();

			//���_�t�H�[�}�b�g�̃T�C�Y���擾
			sizeFVF = D3DXGetFVFVertexSize(g_enemy[nCntEnemy].aModel[nCntModel].pMesh->GetFVF());

			//���_�o�b�t�@�̃��b�N
			g_enemy[nCntEnemy].aModel[nCntModel].pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBUff);

			for (int nCnt = 0; nCnt < nNumVtx; nCnt++)
			{
				//���_���W�̑��
				D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBUff;

				//���_���W���r���ă��f���̍ő�ŏ����擾

				if (vtx.x > g_enemy[nCntEnemy].vtxMax.x)//x�ő�l
				{
					g_enemy[nCntEnemy].vtxMax.x = vtx.x;
				}
				else if (vtx.x < g_enemy[nCntEnemy].vtxMin.x)//x�ŏ��l
				{
					g_enemy[nCntEnemy].vtxMin.x = vtx.x;
				}

				if (vtx.y > g_enemy[nCntEnemy].vtxMax.y)//y�ő�l
				{
					g_enemy[nCntEnemy].vtxMax.y = vtx.y;
				}
				else if (vtx.y < g_enemy[nCntEnemy].vtxMin.y)//y�ŏ��l
				{
					g_enemy[nCntEnemy].vtxMin.y = vtx.y;
				}

				if (vtx.z > g_enemy[nCntEnemy].vtxMax.z)//z�ő�l
				{
					g_enemy[nCntEnemy].vtxMax.z = vtx.z;
				}
				else if (vtx.z < g_enemy[nCntEnemy].vtxMin.z)//z�ŏ��l
				{
					g_enemy[nCntEnemy].vtxMin.z = vtx.z;
				}

				//���_�t�H�[�}�b�g�̃T�C�Y���|�C���^��i�߂�
				pVtxBUff += sizeFVF;
			}

			//���_�o�b�t�@�̃A�����b�N
			g_enemy[nCntEnemy].aModel[nCntModel].pMesh->UnlockVertexBuffer();

			//�T�C�Y�̏�����
			g_enemy[nCntEnemy].size = g_enemy[nCntEnemy].vtxMax - g_enemy[nCntEnemy].vtxMin;

			//�}�e���A���f�[�^�ւ̃|�C���^���擾
			pMat = (D3DXMATERIAL*)g_enemy[nCntEnemy].aModel[nCntModel].pBuffMat->GetBufferPointer();

			for (int nCnt = 0; nCnt < (int)g_enemy[nCntEnemy].aModel[nCntModel].dwNumMat; nCnt++)
			{
				//�e�N�X�`���|�C���^�̏�����
				g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt] = {};

				if (pMat[nCnt].pTextureFilename != NULL)
				{
					//�e�N�X�`���̓Ǎ�
					D3DXCreateTextureFromFile(pDevice,
						pMat[nCnt].pTextureFilename,
						&g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt]);
				}
			}
		}
	}
}

//============================================================
// �G�̏I������
//============================================================
void UninitEnemy()
{
	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		for (int nCntModel = 0; nCntModel < g_enemy[nCntEnemy].nNumModel; nCntModel++)
		{

			//���b�V���̔j��
			if (g_enemy[nCntEnemy].aModel[nCntModel].pMesh != NULL)
			{
				g_enemy[nCntEnemy].aModel[nCntModel].pMesh->Release();
				g_enemy[nCntEnemy].aModel[nCntModel].pMesh = NULL;
			}

			//�}�e���A���̔j��
			if (g_enemy[nCntEnemy].aModel[nCntModel].pBuffMat != NULL)
			{
				g_enemy[nCntEnemy].aModel[nCntModel].pBuffMat->Release();
				g_enemy[nCntEnemy].aModel[nCntModel].pBuffMat = NULL;
			}

			//�e�N�X�`���̔j��
			for (int nCnt1 = 0; nCnt1 < (int)g_enemy[nCntEnemy].aModel[nCntModel].dwNumMat; nCnt1++)
			{
				if (g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt1] != NULL)
				{
					g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt1]->Release();
					g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt1] = NULL;
				}
			}
		}
	}
}

//============================================================
// �G�̍X�V����
//============================================================
void UpdateEnemy()
{
	//�J�����̏��擾
	Camera* pCamera = GetCamera();

	//�v���C���[�̏��擾
	Player* pPlayer = GetPlayer();

	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_enemy[nCntEnemy].bUse == true)
		{
			//�s���p�^�[��
			if (g_enemy[nCntEnemy].motionType == MOTIONTYPE_ENEMY_ESCAPE)
			{
				g_enemy[nCntEnemy].move.x = -sinf(g_enemy[nCntEnemy].rot.y) * 2.0f;
				g_enemy[nCntEnemy].move.z = -cosf(g_enemy[nCntEnemy].rot.y) * 2.0f;

				g_enemy[nCntEnemy].nCntFream++;

				if (g_enemy[nCntEnemy].nCntFream == 60)
				{
					g_enemy[nCntEnemy].bUse = false;
					DeleteShadow(g_enemy[nCntEnemy].nIndxShadow);
				}
				else if(g_enemy[nCntEnemy].nCntFream==30)
				{
					//�A�C�e���h���b�v
					int nType = rand() % 12;											//�h���b�v��:25%	���:33% (�΂�Ȃ�)
					SetItem(g_enemy[nCntEnemy].pos, 1);
				}
			}

			//posOld�̕ۑ�
			g_enemy[nCntEnemy].posOld = g_enemy[nCntEnemy].pos;

			//�d��
			g_enemy[nCntEnemy].move.y -= 0.8f;

			//�ڕW�̈ړ������i�p�x�j�̕␳
			if (g_enemy[nCntEnemy].rotDest.y > D3DX_PI)
			{
				g_enemy[nCntEnemy].rotDest.y -= D3DX_PI * 2.0f;
			}
			else if (g_enemy[nCntEnemy].rotDest.y < -D3DX_PI)
			{
				g_enemy[nCntEnemy].rotDest.y += D3DX_PI * 2.0f;
			}

			//�����̍X�V
			g_enemy[nCntEnemy].rot.y += (g_enemy[nCntEnemy].rotDest.y - g_enemy[nCntEnemy].rot.y) * 0.15f;

			//�ڕW�̈ړ������i�p�x�j�̕␳
			if (g_enemy[nCntEnemy].rot.y > D3DX_PI)
			{
				g_enemy[nCntEnemy].rot.y -= D3DX_PI * 2.0f;
			}
			else if (g_enemy[nCntEnemy].rot.y < -D3DX_PI)
			{
				g_enemy[nCntEnemy].rot.y += D3DX_PI * 2.0f;
			}

			//�ʒu�̍X�V
			g_enemy[nCntEnemy].pos += g_enemy[nCntEnemy].move;

			//�ړ��ʂ̍X�V(����)
			g_enemy[nCntEnemy].move.x = (0.0f - g_enemy[nCntEnemy].move.x) * 0.1f;
			g_enemy[nCntEnemy].move.y = (0.0f - g_enemy[nCntEnemy].move.y) * 0.1f;
			g_enemy[nCntEnemy].move.z = (0.0f - g_enemy[nCntEnemy].move.z) * 0.1f;

			//������
			if (g_enemy[nCntEnemy].pos.y < 0)
			{
				g_enemy[nCntEnemy].pos.y = 0;
				g_enemy[nCntEnemy].bjump = false;
			}

			//�e�̈ʒu�X�V
			SetPositionShadow(g_enemy[nCntEnemy].nIndxShadow, g_enemy[nCntEnemy].pos);

			//�����蔻��
			//CollisionBlock_X();
			//CollisionBlock_Z();
			g_enemy[nCntEnemy].bFrag = CollisionWall();

			//���[�V����
			SetMotionEnemy();
		}
	}
}

//============================================================
// �G�̕`�揈��
//============================================================
void DrawEnemy()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;						//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;								//���݂̃}�e���A���ۑ��p
	D3DXMATERIAL* pMat;									//�}�e���A���f�[�^�ւ̃|�C���^


	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_enemy[nCntEnemy].bUse == true)
		{
			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_enemy[nCntEnemy].mtxWorldEnemy);

			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_enemy[nCntEnemy].rot.y, g_enemy[nCntEnemy].rot.x, g_enemy[nCntEnemy].rot.z);
			D3DXMatrixMultiply(&g_enemy[nCntEnemy].mtxWorldEnemy, &g_enemy[nCntEnemy].mtxWorldEnemy, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_enemy[nCntEnemy].pos.x, g_enemy[nCntEnemy].pos.y, g_enemy[nCntEnemy].pos.z);
			D3DXMatrixMultiply(&g_enemy[nCntEnemy].mtxWorldEnemy, &g_enemy[nCntEnemy].mtxWorldEnemy, &mtxTrans);

			//���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &g_enemy[nCntEnemy].mtxWorldEnemy);

			//���݂̃}�e���A�����擾
			pDevice->GetMaterial(&matDef);


			for (int nCntModel = 0; nCntModel < g_enemy[nCntEnemy].nNumModel; nCntModel++)
			{
				D3DXMATRIX  mtxRotModel, mtxTransModel;	//�v�Z�p�}�g���b�N�X
				D3DXMATRIX mtxParent;					//�e�̃}t���b�N�X

				//�}�e���A���f�[�^�ւ̃|�C���^���擾
				pMat = (D3DXMATERIAL*)g_enemy[nCntEnemy].aModel[nCntModel].pBuffMat->GetBufferPointer();

				//�p�[�c�̃��[���h�}�g���b�N�X�̏�����
				D3DXMatrixIdentity(&g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld);

				//�����𔽉f
				D3DXMatrixRotationYawPitchRoll(&mtxRotModel, g_enemy[nCntEnemy].aModel[nCntModel].rot.y, g_enemy[nCntEnemy].aModel[nCntModel].rot.x, g_enemy[nCntEnemy].aModel[nCntModel].rot.z);
				D3DXMatrixMultiply(&g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &mtxRotModel);

				//�ʒu�𔽉f
				D3DXMatrixTranslation(&mtxTransModel, g_enemy[nCntEnemy].aModel[nCntModel].pos.x, g_enemy[nCntEnemy].aModel[nCntModel].pos.y, g_enemy[nCntEnemy].aModel[nCntModel].pos.z);
				D3DXMatrixMultiply(&g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &mtxTransModel);

				//�p�[�c�̐e�}�g���b�N�X�̐ݒ�
				if (g_enemy[nCntEnemy].aModel[nCntModel].nIndxModelpParent != -1)//�q�̎�
				{
					mtxParent = g_enemy[nCntEnemy].aModel[g_enemy[nCntEnemy].aModel[nCntModel].nIndxModelpParent].mtxWorld;
				}
				else//�e�̎�
				{
					mtxParent = g_enemy[nCntEnemy].mtxWorldEnemy;
				}

				//�Z�o�����p�[�c�̃��[���h�}�g���b�N�X�Ɛe�̃}�g���b�N�X���������킹��
				D3DXMatrixMultiply(&g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &mtxParent);

				//�p�[�c�̃��[���h�}�g���b�N�X�̐ݒ�
				pDevice->SetTransform(D3DTS_WORLD, &g_enemy[nCntEnemy].aModel[nCntModel].mtxWorld);

				for (int nCnt1 = 0; nCnt1 < (int)g_enemy[nCntEnemy].aModel[nCntModel].dwNumMat; nCnt1++)
				{
					//�}�e���A���̐ݒ�
					pDevice->SetMaterial(&pMat[nCnt1].MatD3D);

					//�e�N�X�`���̐ݒ�
					pDevice->SetTexture(0, g_enemy[nCntEnemy].aModel[nCntModel].apTextureModel[nCnt1]);

					//���f��(�p�[�c)�̕`��
					g_enemy[nCntEnemy].aModel[nCntModel].pMesh->DrawSubset(nCnt1);
				}

			}
			//�ۑ����Ă����}�e���A����߂�
			pDevice->SetMaterial(&matDef);
		}
	}
}

//============================================================
// �G�̐ݒ菈��
//============================================================
void SetEnemy(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_enemy[nCntEnemy].bUse == false)
		{
			g_enemy[nCntEnemy].pos = pos;//�ʒu�̐ݒ�
			g_enemy[nCntEnemy].rot = rot;//�����̐ݒ�

			g_enemy[nCntEnemy].bUse = true;//�g�p���Ă����Ԃɂ���
		}
	}
}

//============================================================
// �G�̃��[�V�����ݒ�E������
//============================================================
void SetMotionEnemy()
{
	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		switch (g_enemy[nCntEnemy].motionType)
		{
		case MOTIONTYPE_ENEMY_NEUTRAL:

			g_enemy[nCntEnemy].bLoopMotion = true;
			g_enemy[nCntEnemy].nNumKey = 2;

			break;

		case MOTIONTYPE_ENEMY_MOVE:
			break;

		case MOTIONTYPE_ENEMY_ATTACK:
			break;

		case MOTIONTYPE_ENEMY_JUMP:
			break;

		case MOTIONTYPE_ENEMY_ESCAPE:
			break;
		}

		//�S���f��(�p�[�c)�̍X�V
		for (int nCntModel = 0; nCntModel < g_enemy[nCntEnemy].nNumModel; nCntModel++)
		{//�L�[��񂩂�ʒu�ƌ������Z�o

			//���̃L�[
			int NextKey = (g_enemy[nCntEnemy].nKey + 1) % g_enemy[nCntEnemy].nNumKey;
			if (g_enemy[nCntEnemy].bLoopMotion == true)
			{
				if (g_enemy[nCntEnemy].nKey >= g_enemy[nCntEnemy].nNumKey)
				{//�L�[�̍ő吔���傫���Ȃ�����
					g_enemy[nCntEnemy].nKey = 0;
				}
				else if (NextKey >= g_enemy[nCntEnemy].nNumKey)
				{
					NextKey = 0;
				}
			}

			//�����i�[�p�@�@
			D3DXVECTOR3 sPos, sRot;

			sPos.x = g_keyNeutrall[NextKey].aKEY[nCntModel].fPosX - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosX;
			sPos.y = g_keyNeutrall[NextKey].aKEY[nCntModel].fPosY - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosY;
			sPos.z = g_keyNeutrall[NextKey].aKEY[nCntModel].fPosZ - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosZ;

			sRot.x = g_keyNeutrall[NextKey].aKEY[nCntModel].fRotX - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotX;
			sRot.y = g_keyNeutrall[NextKey].aKEY[nCntModel].fRotY - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotY;
			sRot.z = g_keyNeutrall[NextKey].aKEY[nCntModel].fRotZ - g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotZ;


			//�v�Z���ʊi�[�p
			D3DXVECTOR3 fAnsPos, fAnsRot;

			//(���[�V�����J�E���^�[)/(�Đ��t���[����)
			float fData = (float)g_enemy[nCntEnemy].nCounterMotion / g_keyNeutrall[g_enemy[nCntEnemy].nKey].nFrame;

			fAnsPos.x = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosX + sPos.x * fData;
			fAnsPos.y = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosY + sPos.y * fData;
			fAnsPos.z = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fPosZ + sPos.z * fData;

			fAnsRot.x = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotX + sRot.x * fData;
			fAnsRot.y = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotY + sRot.y * fData;
			fAnsRot.z = g_keyNeutrall[g_enemy[nCntEnemy].nKey].aKEY[nCntModel].fRotZ + sRot.z * fData;

			//�ʒu�ƌ����𔽉f
			g_enemy[nCntEnemy].aModel[nCntModel].pos += fAnsPos;

			g_enemy[nCntEnemy].aModel[nCntModel].rot = fAnsRot;
		}
		//���[�V�����J�E���^�[��i�߂�
		g_enemy[nCntEnemy].nCounterMotion++;

		//�J�E���^�[���Đ��t���[�����傫���Ȃ�����
		if (g_enemy[nCntEnemy].nCounterMotion >= g_keyNeutrall[g_enemy[nCntEnemy].nKey].nFrame)
		{
			g_enemy[nCntEnemy].nCounterMotion = 0;
			g_enemy[nCntEnemy].nKey++;
		}
	}
}

//============================================================
// �G�̓����蔻��
//============================================================
bool CollisionEnemy()
{
	D3DXVECTOR3 ver[16];
	D3DXVECTOR3 Pos[2];
	Player* pPlayer = GetPlayer();
	bool bLanding = false;

	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_enemy[nCntEnemy].motionType != MOTIONTYPE_ENEMY_ESCAPE)
		{
			//���E�̓����蔻��
			if ((pPlayer->pos.z - (pPlayer->size.z / 2)) < (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMax.z) &&
				(pPlayer->pos.z + (pPlayer->size.z / 2)) > (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMin.z))
			{
				if ((pPlayer->posOld.x + (pPlayer->size.x / 2)) <= (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMin.x) &&
					(pPlayer->pos.x + (pPlayer->size.x / 2)) > (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMin.x))
				{
					HitEnemy(nCntEnemy);
					bLanding = true;
				}
				else if ((pPlayer->posOld.x - (pPlayer->size.x / 2)) >= (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMax.x) &&
					(pPlayer->pos.x - (pPlayer->size.x / 2)) < (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMax.x))
				{
					HitEnemy(nCntEnemy);
					bLanding = true;
				}
			}

			//�O��̓����蔻��
			if ((pPlayer->pos.x - (pPlayer->size.x / 2)) < (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMax.x) &&
				(pPlayer->pos.x + (pPlayer->size.x / 2)) > (g_enemy[nCntEnemy].pos.x + g_enemy[nCntEnemy].vtxMin.x))
			{
				if ((pPlayer->posOld.z + (pPlayer->size.z / 2)) <= (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMin.z) &&
					(pPlayer->pos.z + (pPlayer->size.z / 2)) > (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMin.z))
				{
					HitEnemy(nCntEnemy);
					bLanding = true;
				}
				else if ((pPlayer->posOld.z - (pPlayer->size.z / 2)) >= (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMax.z) &&
					(pPlayer->pos.z - (pPlayer->size.z / 2)) < (g_enemy[nCntEnemy].pos.z + g_enemy[nCntEnemy].vtxMax.z))
				{
					HitEnemy(nCntEnemy);
					bLanding = true;
				}
			}
		}
	}
	return bLanding;
}

//============================================================
// �G����e�����Ƃ��̏���
//============================================================
void HitEnemy(int nIndxEnemy)
{
	//�v���C���[�̏��擾
	Player* pPlayer = GetPlayer();

	if (g_enemy[nIndxEnemy].nLife > 0)
	{
		g_enemy[nIndxEnemy].nLife--;
	}
	else if (g_enemy[nIndxEnemy].nLife <= 0)
	{
		g_enemy[nIndxEnemy].motionType = MOTIONTYPE_ENEMY_ESCAPE;
		g_enemy[nIndxEnemy].rotDest.y = pPlayer->rot.y;
		g_enemy[nIndxEnemy].rot.y = pPlayer->rot.y;
	}
}

//============================================================
// �G�̏��擾
//============================================================
Enemy* GetEnemy()
{
	return &g_enemy[0];
}