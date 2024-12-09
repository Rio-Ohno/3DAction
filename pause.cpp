//============================================================
//
//�V���[�e�B���O�Q�[[pause.cpp]
//Author:Rio Ohno
//
//============================================================

#include"pause.h"
#include"input.h"
#include"fade.h"
#include"game.h"

//�}�N����`
#define MAX_POLY (4)										//���|���S����

static const char* PAUSE_TEXTURE[MAX_POLY] =
{
	NULL,													//���w�i
	"data\\TEXTURE\\Continue000.png",						//Continue
	"data\\TEXTURE\\Retry000.png",							//Retry
	"data\\TEXTURE\\Quit000.png",							//Quit
};

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_apTexturePause[MAX_POLY] = {};			//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffPause = NULL;				//���_�o�b�t�@�ւ̃|�C���^
PAUSE_MENU g_PauseMenu;										//�|�[�Y���j���[
int g_nCntMenu;												//�I�𔻕ʗp

//=====================================================================================
//�|�[�Y�̏���������
//=====================================================================================
void InitPause()
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	g_PauseMenu = PAUSE_MENU_CONTINUE;
	g_nCntMenu = 1;

	for (int nCnt = 0; nCnt < MAX_POLY; nCnt++)
	{
		//�e�N�X�`���̐ݒ�
		D3DXCreateTextureFromFile(pDevice,
			PAUSE_TEXTURE[nCnt],
			&g_apTexturePause[nCnt]);
	}

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_POLY,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffPause,
		NULL);

	VERTEX_2D* pVtx;

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntPause = 0; nCntPause < MAX_POLY; nCntPause++)
	{
		if (nCntPause == 0)
		{
			//���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(0.0f,   100.0f,0.0f);
			pVtx[1].pos = D3DXVECTOR3(1280.0f,100.0f,0.0f);
			pVtx[2].pos = D3DXVECTOR3(0.0f,   620.0f,0.0f);
			pVtx[3].pos = D3DXVECTOR3(1280.0f,620.0f,0.0f);
		}
		else
		{
			//���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(325.0f, 200.0f + 100.0f * nCntPause, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(925.0f, 200.0f + 100.0f * nCntPause, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(325.0f, 250.0f + 100.0f * nCntPause, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(925.0f, 250.0f + 100.0f * nCntPause, 0.0f);
		}

		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);

		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffPause->Unlock();

}

//=====================================================================================
//�|�[�Y�̏I������
//=====================================================================================
void UninitPause()
{
	for (int nCntPause = 0; nCntPause < MAX_POLY; nCntPause++)
	{
		//�e�N�X�`���̔j��
		if (g_apTexturePause[nCntPause] != NULL)
		{
			g_apTexturePause[nCntPause]->Release();
			g_apTexturePause[nCntPause] = NULL;
		}
	}

	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffPause != NULL)
	{
		g_pVtxBuffPause->Release();
		g_pVtxBuffPause = NULL;
	}

}

//=====================================================================================
//�|�[�Y�̍X�V����
//=====================================================================================
void UpdatePause()
{
	if (g_nCntMenu >= 1 && g_nCntMenu < 4)
	{
		if (KeyboardTrigger(DIK_DOWN) == true)//���L�[�������ꂽ
		{
			g_nCntMenu++;
		}

		if (KeyboardTrigger(DIK_UP) == true)//��L�[�������ꂽ
		{
			g_nCntMenu--;
		}
	}

	VERTEX_2D* pVtx;

		switch (g_nCntMenu)
		{
		case 1:

			g_PauseMenu = PAUSE_MENU_CONTINUE;

			//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
			g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);

			for (int nCountPause = 0; nCountPause < MAX_POLY; nCountPause++)
			{

				if (nCountPause == 1)
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
				else
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
				}
				pVtx += 4;
			}

			//���_�o�b�t�@���A�����b�N����
			g_pVtxBuffPause->Unlock();

			break;

		case 2:

			g_PauseMenu = PAUSE_MENU_RETRY;

			//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
			g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);

			for (int nCountPause = 0; nCountPause < MAX_POLY; nCountPause++)
			{
				if (nCountPause == 2)
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
				else
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
				}
				pVtx += 4;
			}

			//���_�o�b�t�@���A�����b�N����
			g_pVtxBuffPause->Unlock();

			break;

		case 3:

			g_PauseMenu = PAUSE_MENU_QUIT;

			//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
			g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);

			for (int nCountPause = 0; nCountPause < MAX_POLY; nCountPause++)
			{

				if (nCountPause == 3)
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
				else
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
				}
				pVtx += 4;
			}

			//���_�o�b�t�@���A�����b�N����
			g_pVtxBuffPause->Unlock();

			break;

		default:

			g_PauseMenu = PAUSE_MENU_CONTINUE;
			if (g_nCntMenu >= 4)
			{
				g_nCntMenu = 1;

			}
			else if (g_nCntMenu < 1)
			{
				g_nCntMenu = 3;
			}

			//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
			g_pVtxBuffPause->Lock(0, 0, (void**)&pVtx, 0);

			for (int nCountPause = 0; nCountPause < MAX_POLY; nCountPause++)
			{

				if (nCountPause == 1)
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				}
				else
				{
					pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
					pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
				}
				pVtx += 4;
			}

			//���_�o�b�t�@���A�����b�N����
			g_pVtxBuffPause->Unlock();

			break;
		}

		//����L�[�������ꂽ�Ƃ�
		if (KeyboardTrigger(DIK_RETURN) == true)
		{
			switch (g_PauseMenu)
			{
			case PAUSE_MENU_CONTINUE:

				SetEnablePause(false);

				break;

			case PAUSE_MENU_RETRY:

				SetFade(MODE_GAME);

				break;

			case PAUSE_MENU_QUIT:

				SetFade(MODE_TITLE);

				break;
			}
		}

}

//=====================================================================================
// �|�[�Y�̕`�揈��
//=====================================================================================
void DrawPause()
{
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffPause, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCntPause = 0; nCntPause < MAX_POLY; nCntPause++)
	{
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_apTexturePause[nCntPause]);

			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntPause * 4, 2);
	}
}