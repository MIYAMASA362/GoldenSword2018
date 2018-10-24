//
//	Bullet.cpp
//		Author:�n��	DATE:
//===============================================
//	�ύX�� Change by
//		Author:MinodaTakamasa DATE:2018/10/23
//
//-----------------------------------------------
#include <d3dx9.h>
#include<math.h>
#include "Bullet.h"
#include "common.h"
#include "System.h"

//===============================================
//	�}�N����`
//===============================================
#define BULLET_NORMAL_SPEED (0.05f)
#define BULLET_NORMAL_RADIUS (1)		//�e�̔��a
#define BULLET_COUNT (256)
#define BULLET_MAX (256)
#define CORRECT_WAIT(a) (a/100.f)		//�␳�̋���

//===============================================
//	�\����
//===============================================

//===============================================
//	�O���[�o���ϐ�
//===============================================
Bullet g_Bullet[BULLET_MAX];
float fRoll = 0;

//===============================================
//	�֐�
//===============================================

//-------------------------------------
//	������
//-------------------------------------
void Bullet_Initialize()
{
	XModel_Load(GetMeshData(BulletIndex), "./Models/bullet.x", &D3DXVECTOR3(0, 0, 0));

	for(int i = 0; i<BULLET_MAX; i++)
	{
		memcpy(&g_Bullet[i].BulletMesh, GetMeshData(BulletIndex), sizeof(MeshData));
	}
}

//-------------------------------------
//	�X�V
//-------------------------------------
void Bullet_Update()
{
	for(int i = 0; i< BULLET_MAX; i++)
	{
		if(g_Bullet[i].GetEnable())
		{
			g_Bullet[i].Update();
		}
	}
}

/*
	////�e�̖���(��ʊO�̏ꍇ
	//for (int i = 0; i < BULLET_COUNT; i++)
	//{
	//	if (Bullet[i].pos.x >= SCREEN_WIDTH || Bullet[i].pos.x <= -SCREEN_WIDTH || 
	//		Bullet[i].pos.y <= -SCREEN_HEIGHT || Bullet[i].pos.y >= SCREEN_HEIGHT ||
	//		Bullet[i].pos.z >=||Bullet[i].pos.z <=)				//����������킩��Ȃ�
	//	{
	//		Bullet_Destroy(i);
	//	}
	//}
*/

//-------------------------------------
//	�`��
//-------------------------------------
void Bullet_Render()
{
	for(int i = 0; i < BULLET_MAX; i++)
	{
		if(g_Bullet[i].GetEnable())
		{
			XModel_Render(&g_Bullet[i].BulletMesh);
		}
	}
}

//-------------------------------------
//	����
//-------------------------------------
void Bullet_Create(D3DXVECTOR3 position, D3DXVECTOR3 face, BULLET_TYPE type)
{
	for(int i= 0; i< BULLET_MAX; i++)
	{
		if(!g_Bullet[i].GetEnable())
		{
			g_Bullet[i].SetBullet(position,face,type);
			return;
		}
	}
}

//-------------------------------------
//	�폜
//-------------------------------------
void Bullet_Destroy(int index)
{
	g_Bullet[index].DisEnable();
}

//-------------------------------------
//	�L����
//-------------------------------------
bool Bullet_IsEnable(int index)
{
	return g_Bullet[index].GetEnable();
}

ShapeSphere Bullet_ColShape(int index)
{
	return g_Bullet[index].ColSphape;
}

//-------------------------------------
//	Bullet�N���X�擾
//-------------------------------------
Bullet* Bullet_GetBullet(int index)
{
	return &g_Bullet[index];
}


//===============================================
//	Bullet �N���X
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
Bullet::Bullet():ColSphape(this->BulletMesh.vecPosition,0.5f)
{
	IsEnable = false;
}

Bullet::Bullet(Transform* pTransform, Texture* pTexture):GameObject(pTransform,pTexture),ColSphape(pTransform->Position,0.5f)
{
	type = BULLET_NORMAL;
	Bullet();
}

//-------------------------------------
//	�e�̃^�C�v�ݒ�
//-------------------------------------
void Bullet::TypeSet(BULLET_TYPE tyep)
{
	this->type = type;
}

static float value = 0;

//-------------------------------------
//	�X�V����
//-------------------------------------
void Bullet::Update()
{
	ColSphape.Pos = this->BulletMesh.vecPosition;

	switch (this->type)
	{
	case BULLET_NORMAL:
		//�X�v���C�g�̒��S���W���X�V����
		this->BulletMesh.vecPosition += this->face * BULLET_NORMAL_SPEED;
		break;

	//��]������e
	case BULLET_TORNADO:
		this->BulletMesh.vecPosition += this->face * BULLET_NORMAL_SPEED;
		//this->transform.Position = MainPosition;

		this->BulletMesh.vecPosition.x += 0.01f * sinf(D3DXToRadian(value));
		this->BulletMesh.vecPosition.y +=0.01f * cosf(D3DXToRadian(value));

		break;
	default:
		break;
	}

	D3DXMATRIXA16 matPosition;
	D3DXMatrixIdentity(&this->BulletMesh.matWorld);
	D3DXMatrixTranslation(&matPosition, this->BulletMesh.vecPosition.x, this->BulletMesh.vecPosition.y, this->BulletMesh.vecPosition.z);

	D3DXMATRIX matRotationZ;
	D3DXMatrixRotationZ(&matRotationZ, fRoll);

	D3DXMATRIX matSize;
	D3DXMatrixScaling(&matSize, 0.2f, 0.2f, 0.2f);

	this->BulletMesh.matWorld =matSize*matRotationZ*matPosition;

	fRoll += 0.01f;
	value += 0.01f;
}

//-------------------------------------
//	Enable�擾
//-------------------------------------
bool Bullet::GetEnable()
{
	return this->IsEnable;
}

//--------------------------------------
//	�e��ݒ�
//--------------------------------------
void Bullet::SetBullet(D3DXVECTOR3 position, D3DXVECTOR3 face, BULLET_TYPE type)
{
	D3DXVec3Normalize(&face,&face);		//�P�ʉ�
	//this->MainPosition = position;
	memcpy(&this->BulletMesh.vecPosition, position, sizeof(D3DXVECTOR3));
	this->face = face;
	this->type = type;
	this->IsEnable = true;
}

//-------------------------------------
//	�e�𖳌���
//-------------------------------------
void Bullet::DisEnable()
{
	this->IsEnable = false;
}

//-------------------------------------
//	�e�̐i�s�������擾
//-------------------------------------
const D3DXVECTOR3* Bullet::GetFace()
{
	return &face;
}

//-------------------------------------
//	�e�̃|�W�V�������Z�b�g
//-------------------------------------
void Bullet::SetPos(D3DXVECTOR3 Pos)
{
	this->BulletMesh.vecPosition = Pos;
	this->ColSphape.Pos = Pos;
}

//-------------------------------------
//	�e�̐i�s�������Z�b�g
//-------------------------------------
void Bullet::SetFace(D3DXVECTOR3 face)
{
	this->face = face;
}

//-------------------------------------
//	�e�̐i�s�����ɕ␳��������
//-------------------------------------
void Bullet::CorrectFace(D3DXVECTOR3 vec)
{
	D3DXVECTOR3 newFace = face + vec * CORRECT_WAIT(30);
	D3DXVec3Normalize(&newFace, &newFace);
	SetFace(newFace);

}
