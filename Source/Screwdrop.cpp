//
//	Screwdrop.cpp
//		Author:�n��	DATE:2018/10/23
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------
#include "Screwdrop.h"
//===============================================
//	�}�N����`
//===============================================
#define BULLET_MAX (256)
#define SCREW_DROP_SPEED (0.01f)		//�������x
#define SCREW_ROTATION_SPEED (0.01f)	//��]���̈ړ����x
#define ROTATION_FRAME_MAX (120)		//��]�t���[����

//===============================================
//	�\����
//===============================================

//===============================================
//	�O���[�o���ϐ�
//===============================================
Screwdrop g_Screwdrop[BULLET_MAX];
//================================================
//	�֐�		
//================================================
//-------------------------------------
//	������
//-------------------------------------
void Screwdrop_Init()
{
	XModel_Load(GetMeshData(ScrewIndex), "./Models/neji.x", &D3DXVECTOR3(0, 0, 0));

	for (int i = 0; i<BULLET_MAX; i++)
	{
		g_Screwdrop[i].IsEnable = false;
		g_Screwdrop[i].BulletPosition = D3DXVECTOR3(0.5f, 0.5f,0.5f);
		g_Screwdrop[i].ScrewPosition = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
		g_Screwdrop[i].bullet_type = BULLET_NORMAL;
		g_Screwdrop[i].face = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
		g_Screwdrop[i].rotation_count = 0;
		memcpy(&g_Screwdrop[i].BulletMesh, GetMeshData(BulletIndex), sizeof(MeshData));
		memcpy(&g_Screwdrop[i].ScrewMesh, GetMeshData(ScrewIndex), sizeof(MeshData));
	}
}

//-------------------------------------
//	�X�V
//-------------------------------------
void Screwdrop_Update()
{
	for (int i = 0; i< BULLET_MAX; i++)
	{
		if (g_Screwdrop[i].IsEnable)
		{
			if (g_Screwdrop[i].rotation_count <= ROTATION_FRAME_MAX)
			{
				g_Screwdrop[i].BulletPosition -= g_Screwdrop[i].face * SCREW_ROTATION_SPEED;
				g_Screwdrop[i].ScrewPosition -= g_Screwdrop[i].face * SCREW_ROTATION_SPEED;
				g_Screwdrop[i].rotation_count++;
			}
			else
			{
				if (g_Screwdrop[i].BulletPosition.y >= 0.0f/*�n��*/)
				{
					g_Screwdrop[i].BulletPosition.y -= SCREW_DROP_SPEED;
					g_Screwdrop[i].ScrewPosition.y -= SCREW_DROP_SPEED;
				}
				else
				{
					Screwdrop_DisEnable(i);
				}
			}
		}
	}
}

//-------------------------------------
//	�`��
//-------------------------------------
void Screwdrop_Render()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (g_Screwdrop[i].IsEnable)
		{
			D3DXMATRIX mtxWorld;
			D3DXMATRIX mtxRotation;
			D3DXMATRIX mtxTranslation;
			D3DXMATRIX mtxScaling;

			D3DXMatrixTranslation(&mtxTranslation, g_Screwdrop[i].BulletPosition.x, g_Screwdrop[i].BulletPosition.y, g_Screwdrop[i].BulletPosition.z);

			D3DXMatrixRotationAxis(&mtxRotation, &g_Screwdrop[i].face,D3DXToRadian(g_Screwdrop[i].rotation_count));
			//D3DXMatrixRotationY(&mtxRotation, D3DXToRadian(g_Screwdrop[i].rotation_count));
			D3DXMatrixScaling(&mtxScaling, 0.3f, 0.3f, 0.3f);

			mtxWorld = mtxRotation * mtxScaling * mtxTranslation;
			System_GetDevice()->SetTransform(D3DTS_WORLD, &mtxWorld);

			//�o���b�g�̕`��֐�
			XModel_Render(&g_Screwdrop[i].BulletMesh, mtxWorld);

			D3DXMATRIX mtxTranlationScrew;		// �l�W�����_�Ɉړ����邽�߂̕��s�ړ��s��
			D3DXMATRIX mtxRotationScrew;		// �l�W�𐳑΂����邽�߂̉�]�s��
			D3DXMatrixTranslation(&mtxTranlationScrew, 0.0f, -0.5f, 0.0f);

			D3DXMatrixScaling(&mtxScaling, 0.5f, 0.5f, 0.5f);
			D3DXMatrixRotationY(&mtxRotationScrew, D3DX_PI);
			D3DXMatrixTranslation(&mtxTranslation, g_Screwdrop[i].ScrewPosition.x, g_Screwdrop[i].ScrewPosition.y, g_Screwdrop[i].ScrewPosition.z);
			mtxWorld = mtxTranlationScrew * mtxRotationScrew * mtxScaling * mtxRotation * mtxTranslation;
			System_GetDevice()->SetTransform(D3DTS_WORLD, &mtxWorld);

			//�l�W�̕`��֐�
			XModel_Render(&g_Screwdrop[i].ScrewMesh, mtxWorld);

		}
	}
}

//-------------------------------------
//	����
//-------------------------------------
void  Screwdrop_Create(D3DXVECTOR3 pos_bullet, D3DXVECTOR3 pos_screw, BULLET_TYPE type, D3DXVECTOR3 face)
{
	for (int i = 0; i< BULLET_MAX; i++)
	{
		if (!g_Screwdrop[i].IsEnable)
		{
			g_Screwdrop[i].ScrewPosition = pos_screw;
			g_Screwdrop[i].BulletPosition = pos_bullet;
			g_Screwdrop[i].bullet_type = type;
			g_Screwdrop[i].face = face;
			g_Screwdrop[i].rotation_count = 0;
			g_Screwdrop[i].IsEnable = true;
			return;
		}
	}
}

//-------------------------------------
//	�폜
//-------------------------------------
void Screwdrop_DisEnable(int index)
{
	g_Screwdrop[index].IsEnable = false;
}
