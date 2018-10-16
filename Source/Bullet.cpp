#include <d3dx9.h>
#include "Bullet.h"
#include "common.h"
#include "System.h"

#define BULLET_NORMAL_SPEED (6.0f)
#define BULLET_NORMAL_RADIUS (1)		//�e�̔��a
#define BULLET_COUNT (256)

typedef struct 
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 face;
	bool Bullet_IsEnable;
	Ball BulletCollision;	//�����蔻��\����		typedef struct
												//	{
												//		D3DXVECTOR3 pos;
												//		float r;
												//	}Ball;
	Bullet_Type Bullet_Type;

}CBullet;

CBullet Bullet[BULLET_COUNT];

void Bullet_Init(void)
{
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		Bullet[i].Bullet_Type = kMAX;
		Bullet[i].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		Bullet[i].face = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		Bullet[i].BulletCollision.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		Bullet[i].BulletCollision.r = 0.0f;
		Bullet[i].Bullet_IsEnable = false;
	}
}

void Bullet_Draw(void)
{
	D3DXMATRIX mtxWorld;
	// �e�̕`��(�L���̏ꍇ
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		if (Bullet[i].Bullet_IsEnable)
		{
			D3DXMatrixTranslation(&mtxWorld, Bullet[i].pos.x, Bullet[i].pos.y, Bullet[i].pos.z);	//���s�ړ��s������
			System_GetDevice()->SetTransform(D3DTS_WORLD, &mtxWorld);										//���[���h�ϊ��s��̐ݒ�

			switch (Bullet[i].Bullet_Type)
			{
			case kNORMAL:
				//Ball_Render();
				break;
			default:
				break;
			}
		}
	}
}

void Bullet_Update(void)
{
	D3DXVECTOR3 MOVE;
	
	//�@�e�̍X�V(�L���̏ꍇ
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		D3DXVec3Normalize(&Bullet[i].face, &Bullet[i].face);

		if (Bullet[i].Bullet_IsEnable)
		{
			switch (Bullet[i].Bullet_Type)
			{
			case kNORMAL:
				MOVE = Bullet[i].face * BULLET_NORMAL_SPEED;
				Bullet[i].pos += MOVE;
				break;
			default:
				break;
				//Bullet[i].BulletCollision.pos = pos;
			}

		}
	}


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
}

void Bullet_Create(D3DXVECTOR3 pos, D3DXVECTOR3 face, Bullet_Type type)
{
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		if (Bullet[i].Bullet_IsEnable)
		{

		}
		else
		{
			Bullet[i].pos = pos;
			Bullet[i].face = face;
			Bullet[i].Bullet_Type = type;
			Bullet[i].BulletCollision.pos = pos;
			switch (Bullet[i].Bullet_Type)
			{
			case kNORMAL:
				Bullet[i].BulletCollision.r = BULLET_NORMAL_RADIUS;
				break;
			default:
				break;
			}
			Bullet[i].Bullet_IsEnable = true;
			break;
		}
	}
}

void Bullet_Destroy(int index)
{
	// �e�𖳌��ɂ���
	Bullet[index].Bullet_IsEnable = false;
}

bool Bullet_IsEnable(int index)
{
	return Bullet[index].Bullet_IsEnable;
}

const Ball * Bullet_Getcollosion(int index)
{
	return &Bullet[index].BulletCollision;
}
