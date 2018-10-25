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

#include "Debug_Sphere.h"

//===============================================
//	CoreObject	�N���X
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
CoreObject::CoreObject(Transform* pTransform, Texture* pTexture, CORE_DISCHARGE_JUDGE_TYPE Type):GameObject(pTransform, pTexture), ColShape(pTransform->Position, 1.0f)
{
	this->Type = Type;
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
	if(this->pArmor_Index.size() > 0)
	{
		DischargeArmor( 120.0f, 1.0f, D3DXVECTOR3( 1.0f, 0.0f, 0.0f ) );
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
			if (Collision::SphereVsSphere(ColShape, Bullet_ColShape(i)))
			{
				Hit();
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

		DebugBufferManager::Sphere_BatchRun();
	}
}

//-------------------------------------
//	����ݒ�
//-------------------------------------
void CoreObject::Set_JudgeType(CORE_DISCHARGE_JUDGE_TYPE Type)
{
	this->Type = Type;
}

//-------------------------------------
//	�`��
//-------------------------------------
void CoreObject::DischargeArmor( float Margin, float Weight, D3DXVECTOR3 AddUnitVec, float SpeedRatio ) 
{
	for( int i = 0; i < pArmor_Index.size(); i++ )
	{
		// �A�[�}�[�j���C�x���g�܂ł̒x���t���[�����Z�o
		float DelayFrame;

		float SquaredDist = D3DXVec3LengthSq( &( pArmor_Index.at( i )->transform.Position - transform.Position ) );

		switch (this->Type)
		{
		case CORE_JUDGE_TYPE_0:	//����
			DelayFrame = SquaredDist * Weight + Margin;
			break;
		case CORE_JUDGE_TYPE_1:	// �qArmor�S�Ĉ�x��
			DelayFrame = Weight + Margin;
			break;
		default:
			//NULL
			break;
		}

		// ���x���w��
		D3DXVECTOR3* pInitSpeed;
		const ARMOR_DISCHARGING_TYPE Type = pArmor_Index.at(i)->Discharging_Type;

		switch( Type )
		{

			case FALL:	//����ė�����
				pInitSpeed = new D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
				*pInitSpeed += AddUnitVec;
				break;
			case RADIALLY: //���ˏ�ɍL����
				pInitSpeed = new D3DXVECTOR3( pArmor_Index.at( i )->transform.Position - transform.Position );
				D3DXVec3Normalize( pInitSpeed, pInitSpeed );
				*pInitSpeed = ( *pInitSpeed + AddUnitVec ) * SpeedRatio;
					
		}

		pArmor_Index.at( i )->Break( *pInitSpeed, DelayFrame );
		this->pArmor_Index.erase( this->pArmor_Index.begin() + i );
	}
}