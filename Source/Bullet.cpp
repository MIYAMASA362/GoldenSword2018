//
//	Bullet.cpp
//		Author:�n��	DATE:
//===============================================
//	�ύX�� Change by
//		Author:HIROMASA IKEDA DATE:2018/10/17
//
//-----------------------------------------------
#include <d3dx9.h>
#include "Bullet.h"
#include "common.h"
#include "System.h"

#include"Cube.h"

//===============================================
//	�}�N����`
//===============================================
#define BULLET_NORMAL_SPEED (0.1f)
#define BULLET_NORMAL_RADIUS (1)		//�e�̔��a
#define BULLET_COUNT (256)
#define BULLET_MAX (256)

//===============================================
//	�\����
//===============================================

//===============================================
//	�O���[�o���ϐ�
//===============================================
Bullet g_Bullet[BULLET_MAX];

//===============================================
//	�֐�
//===============================================

//-------------------------------------
//	������
//-------------------------------------
void Bullet_Initialize()
{
	for(int i = 0; i<BULLET_MAX; i++)
	{
		g_Bullet[i].transform.Scale = {0.5f,0.5f,0.5f};
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
			g_Bullet[i].render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, GetModel_Cube(), sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);
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


//===============================================
//	Bullet �N���X
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
Bullet::Bullet():ColSphape(this->transform.Position,1)
{
	IsEnable = false;
}

Bullet::Bullet(Transform* pTransform, Texture* pTexture):GameObject(pTransform,pTexture),ColSphape(pTransform->Position,1.0f)
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

//-------------------------------------
//	�X�V����
//-------------------------------------
void Bullet::Update()
{
	ColSphape.Pos = this->transform.Position;

	switch (this->type)
	{
	case BULLET_NORMAL:
		this->transform.Position += this->face * BULLET_NORMAL_SPEED;
		break;
	default:
		break;
	}
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

	this->transform.Position = position;
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

