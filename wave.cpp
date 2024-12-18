//============================================================
//
//�E�F�[�u����[wave.cpp]
//Author:Rio Ohno
//
//============================================================

#include"wave.h"
#include"enemy.h"
#include<stdio.h>

//�}�N����`
#define MAX_WORD (216)										//�ő啶����
#define WAVE_0 "data\\wave0.txt"							//�E�F�[�u0
#define WAVE_1 "data\\wave1.txt"							//�E�F�[�u1
#define WAVE_2 "data\\wave2.txt"							//�E�F�[�u2
#define WAVE_3 "data\\wave3.txt"							//�E�F�[�u3

//�E�F�[�u�\����
typedef struct
{
	D3DXVECTOR3 pos;										//�ʒu
	D3DXVECTOR3 move;										//�ړ���
	int nType;												//���
	bool bUse;												//�g�p���Ă��邩�ǂ���
}LoadInfo;

//�O���[�o���ϐ��錾
LoadInfo g_Info[MAX_ENEMY];
int g_nCntEnemy;
int g_nWave;												//�E�F�[�u�̃J�E���g
bool g_bFinish;												//�E�F�[�u�̏I������

//============================================================
// �E�F�[�u�̏���������
//============================================================
void InitWave()
{
	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		g_Info[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Info[nCnt].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Info[nCnt].nType = 0;
		g_Info[nCnt].bUse = false;
	}

	g_nCntEnemy = 0;
	g_nWave = 0;
	g_bFinish = false;
}

//============================================================
// �E�F�[�u�̓Ǎ�����
//============================================================
void LoadWave()
{
	FILE* pFile;											//�O���t�@�C���ւ̃|�C���^

	int nType = 0, nLife = 0;
	D3DXVECTOR3 pos = {};
	//D3DXVECTOR3 move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//�G�̐����擾
	//g_nCntEnemy = GetNumEnemy();

	//�e�E�F�[�u�̃t�@�C�����J��
	switch (g_nWave)
	{
	case 0://Wave1

		pFile = fopen(WAVE_0, "r");

		break;

	case 1://Wavw2

		pFile = fopen(WAVE_1, "r");

		break;

		//case 2://Wavw3

		//	pFile = fopen(WAVE_2, "r");

		//	break;

	default://��O

		pFile = NULL;

		g_bFinish = true;									//�E�F�[�u�I��

		break;
	}

	if (pFile != NULL)
	{
		while (1)
		{
			char aString[MAX_WORD];

			//�t�@�C����ǂ݂���
			fscanf(pFile, "%s", &aString[0]);
			if (strcmp(aString, "ENEMYSET") == 0)//ENEMYSET��Ǎ��񂾂Ȃ�
			{
				while (1)
				{
					fscanf(pFile, "%s", &aString[0]);

					if (strcmp(aString, "TYPE") == 0)//TYPE��Ǎ��񂾂Ȃ�
					{
						//��ނ̎擾
						fscanf(pFile, "%d", &nType);
					}
					else if (strcmp(aString, "POS") == 0)//POS��Ǎ��񂾂Ȃ�
					{
						//�ʒu�̎擾
						fscanf(pFile, "%f", &pos.x);
						fscanf(pFile, "%f", &pos.y);
						fscanf(pFile, "%f", &pos.z);
					}
					else if (strcmp(aString, "LIFE") == 0)//LIFE��Ǎ��񂾂Ȃ�
					{
						//�����̎擾
						fscanf(pFile, "%d", &nLife);
					}
					else if (strcmp(aString, "END_ENEMYSET") == 0)//END_ENEMYSET��Ǎ��񂾂Ȃ�
					{
						//�G�̐ݒ�
						//SetEnemy(pos, nType, nLife);

						break;
					}
				}
			}
			if (strcmp(aString, "END_SCRIPI") == 0)
			{
				break;
			}
		}

		//�t�@�C�������
		fclose(pFile);

		//�E�F�[�u�̃J�E���g�A�b�v
		g_nWave++;
	}
	else
	{
		return;
	}
}

//============================================================
// �E�F�[�u���̎擾
//============================================================
int GetWave()
{
	return g_nWave;
}

//============================================================
// �E�F�[�u�I���̎擾
//============================================================
bool GetFinish()
{
	return g_bFinish;
}