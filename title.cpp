//============================================================
//
//�^�C�g�����[title.cpp]
//Author:Rio Ohno
//
//============================================================


#include"title.h"
#include"input.h"
#include"fade.h"
#include"sound.h"

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureTitle = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTitle;

//=============================================================================================================
//�^�C�g����ʂ̏���������
//=============================================================================================================
void InitTitle()
{
	LPDIRECT3DDEVICE9 pDevice;                                                  //�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓Ǎ�
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\title000.png",
		&g_pTextureTitle);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffTitle,
		NULL);

	VERTEX_2D* pVtx{};

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffTitle->Lock(0, 0, (void**)&pVtx, 0);

	//���_���̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffTitle->Unlock();

	////�T�E���h�̍Đ�
	//PlaySound(SOUND_LABEL_TITLE);
}

//=============================================================================================================
//�^�C�g����ʂ̏I������
//=============================================================================================================
void UninitTitle()
{
	////�T�E���h�̒�~
	//StopSound(SOUND_LABEL_TITLE);

	//�e�N�X�`���̔j��
	if (g_pTextureTitle!= NULL)
	{
		g_pTextureTitle->Release();
		g_pTextureTitle = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffTitle != NULL)
	{
		g_pVtxBuffTitle->Release();
		g_pVtxBuffTitle = NULL;
	}
}

//=============================================================================================================
//�^�C�g����ʂ̍X�V����
//=============================================================================================================
void UpdateTitle()
{
	//����L�[�iENTER�L�[�j�������ꂽ
	if (KeyboardTrigger(DIK_RETURN) == true)
	{
		//���[�h�ݒ�i�Q�[����ʂɈڍs�j
		SetFade(MODE_GAME);
	}
}

//=============================================================================================================
//�^�C�g����ʂ̕`�揈��
//=============================================================================================================
void DrawTitle()
{
	LPDIRECT3DDEVICE9 pDevice;                                                  //�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffTitle, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pTextureTitle);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}