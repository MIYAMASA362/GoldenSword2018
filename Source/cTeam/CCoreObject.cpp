//
//	CCoreObject.cpp	
//		Author:HIROMASA IKEDA	DATE:2018/10/13
//===============================================
#include<d3dx9.h>
#include<vector>

//Class
#include"Cube.h"
#include"CCoreObject.h"
#include"CCollisionableObject.h"
#include"Bullet.h"
#include"Screwdrop.h"

#include "Debug_Sphere.h"

//===============================================
//	CoreObject	�N���X
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
CoreObject::CoreObject(Transform* pTransform, Texture* pTexture, CORE_DISCHARGE_JUDGE_TYPE Type) :GameObject(pTransform, pTexture), ColShape(pTransform->Position, 0.5f), CorrectSphere(pTransform->Position, 1.0f)
{
	this->Type = Type;
	this->face = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
}

CoreObject::CoreObject(Transform* pTransform, Texture* pTexture, CORE_DISCHARGE_JUDGE_TYPE Type, D3DXVECTOR3 face) : GameObject(pTransform, pTexture), ColShape(pTransform->Position, 0.5f), CorrectSphere(pTransform->Position, 1.0f)
{
	this->face = face;
}

void CoreObject::Set(ArmorObject* pArmorObject)
{
	this->pArmor_Index.push_back(pArmorObject);
}

void CoreObject::Set(ArmorObject* pArmorObject,BodyObject* pBodyObject)
{
	this->pArmor_Index.push_back(pArmorObject);
	this->pBodyObject = pBodyObject;
	this->Set_Parent(this->pBodyObject);
}


//-------------------------------------
//	�f�X�g���N�^
//-------------------------------------
CoreObject::~CoreObject()
{

}


//-------------------------------------
//	�e�ɓ�������
//-------------------------------------
void CoreObject::Hit()
{
	this->bHit = true;
	if(this->pArmor_Index.size() > 0)
	{
		DischargeArmor( 5.0f, 50.0f);
	}
}

//-------------------------------------
//	�X�V����
//-------------------------------------
void CoreObject::Update()
{
	for (int i = 0; i<BULLET_MAX; i++)
	{
		if (Bullet_IsEnable(i))
		{
			//�����񂹂�	
			if (Collision::SphereVsSphere(CorrectSphere, Bullet_ColShape(i)))
			{
				const D3DXVECTOR3* bullet_face = Bullet_GetBullet(i)->GetFace();
				D3DXVECTOR3 vec = CorrectSphere.Pos - Bullet_ColShape(i).Pos;		// �l�W�ƒe�̒��S�ԃx�N�g��
				float Angle = acosf(D3DXVec3Dot(bullet_face, &vec));				// �e�̐i�s������vec�̐����p

				if (Angle <= D3DX_PI / 4 && Angle > 0.0f)
				{
					Bullet_GetBullet(i)->CorrectFace(vec);
				}
			}
		}
	}

	for (int i = 0; i<BULLET_MAX; i++)
	{
		
		if (Bullet_IsEnable(i))
		{
			if (Collision::SphereVsSphere(ColShape, Bullet_ColShape(i)))
			{
				Hit();
				Bullet_GetBullet(i)->SetFace(face);
				Bullet_GetBullet(i)->SetPos(this->transform.Position - ColShape.Radius * face * 1.0f);
				Screwdrop_Create(Bullet_GetBullet(i)->ColSphape.Pos, CorrectSphere.Pos, BULLET_NORMAL, *Bullet_GetBullet(i)->GetFace());
				Bullet_GetBullet(i)->DisEnable();
			}
		}
		
	}

}

//-------------------------------------
//	�`��
//-------------------------------------
void CoreObject::Render()
{
	if (this->pArmor_Index.size() > 0)
	{
		DebugBufferManager::Sphere_BatchBegin();

		render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, GetModel_Cube(), sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);

		DebugBufferManager::BatchDrawSphere(&this->ColShape);
		DebugBufferManager::BatchDrawSphere(&this->CorrectSphere);

		DebugBufferManager::Sphere_BatchRun();
	}
}

//-------------------------------------
//	�l�W�̌����̎擾
//-------------------------------------
D3DXVECTOR3 CoreObject::GetFace()
{
	return face;
}

//-------------------------------------
//	����ݒ�
//-------------------------------------
void CoreObject::Set_JudgeType(CORE_DISCHARGE_JUDGE_TYPE Type)
{
	this->Type = Type;
}

//-------------------------------------
//	�A�[�}�[��΂�
//-------------------------------------
void CoreObject::DischargeArmor( float MaxDist, float Weight, float SpeedRatio )
{
	for(int i = 0; i < pArmor_Index.size(); i++ )
	{
		const D3DXVECTOR3* pInitSpeed;
		// ���̃A�[�}�[�Ƃ̋������v�Z
		const float SquaredDist = D3DXVec3LengthSq( &( pArmor_Index.at( i )->transform.Position - transform.Position ) );
		// �A�[�}�[�j���C�x���g�܂ł̒x���t���[�����Z�o
		// �����t���[�������ő�l���Ⴏ��΃A�[�}�[�j�������s

		float DelayFrame;

		if( SquaredDist < MaxDist * MaxDist )
		{
			switch (this->Type)
			{
			case CORE_JUDGE_TYPE_0:	//����
				DelayFrame = SquaredDist * Weight;
				break;
			case CORE_JUDGE_TYPE_1:	//�͈�
				DelayFrame = MaxDist * Weight;
				break;
			default:
				//NULL
				break;
			}

			
			const ARMOR_DISCHARGING_TYPE Type = pArmor_Index.at(i)->Discharging_Type;

			switch( Type )
			{

				case FALL:	//����ė�����
					pInitSpeed = new D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
					break;
				case RADIALLY: //���ˏ�ɍL����
					D3DXVECTOR3 Vec = pArmor_Index.at( i )->transform.Position - transform.Position;
					D3DXVec3Normalize( &Vec, &Vec );
					Vec *= SpeedRatio;
					pInitSpeed = new D3DXVECTOR3( Vec );
					break;
			}

			
		}
		pArmor_Index.at(i)->Break(*pInitSpeed, DelayFrame);

	}

	this->pArmor_Index.clear();
}