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
//	CoreObject	クラス
//===============================================

//-------------------------------------
//	コンストラクタ
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
//	デストラクタ
//-------------------------------------
CoreObject::~CoreObject()
{

}


//-------------------------------------
//	弾に当たった
//-------------------------------------
void CoreObject::Hit()
{
	if(this->pArmor_Index.size() > 0)
	{
		DischargeArmor( 5.0f, 50.0f);
	}
}

//-------------------------------------
//	更新処理
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
//	描画
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
//	判定設定
//-------------------------------------
void CoreObject::Set_JudgeType(CORE_DISCHARGE_JUDGE_TYPE Type)
{
	this->Type = Type;
}

//-------------------------------------
//	描画
//-------------------------------------
void CoreObject::DischargeArmor( float MaxDist, float Weight, float SpeedRatio )
{
	for( int i = 0; i < pArmor_Index.size(); i++ )
	{
		
		// そのアーマーとの距離を計算
		const float SquaredDist = D3DXVec3LengthSq( &( pArmor_Index.at( i )->transform.Position - transform.Position ) );
		// アーマー破棄イベントまでの遅延フレームを算出
		// 得たフレーム数が最大値より低ければアーマー破棄を実行

		float DelayFrame;

		if( SquaredDist < MaxDist * MaxDist )
		{
			switch (this->Type)
			{
			case CORE_JUDGE_TYPE_0:	//距離
				DelayFrame = SquaredDist * Weight;
				break;
			case CORE_JUDGE_TYPE_1:	//範囲
				DelayFrame = MaxDist * Weight;
				break;
			default:
				//NULL
				break;
			}

			const D3DXVECTOR3* pInitSpeed;
			const ARMOR_DISCHARGING_TYPE Type = pArmor_Index.at(i)->Discharging_Type;

			switch( Type )
			{

				case FALL:	//ずれて落ちる
					pInitSpeed = new D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
					break;
				case RADIALLY: //放射状に広がる
					D3DXVECTOR3 Vec = pArmor_Index.at( i )->transform.Position - transform.Position;
					D3DXVec3Normalize( &Vec, &Vec );
					Vec *= SpeedRatio;
					pInitSpeed = new D3DXVECTOR3( Vec );
					
			}

			pArmor_Index.at( i )->Break( *pInitSpeed, DelayFrame );
			this->pArmor_Index.erase( this->pArmor_Index.begin() + i );
		}
	}
}