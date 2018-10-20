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
CoreObject::CoreObject(Transform* pTransform,Texture* pTexture):GameObject(pTransform, pTexture), ColShape(pTransform->Position, 1.0f)
{

}

void CoreObject::Set(ArmarObject* pArmarObject)
{
	this->pArmar_Index.push_back(pArmarObject);
}

void CoreObject::Set(ArmarObject* pArmarObject,BodyObject* pBodyObject)
{
	this->pArmar_Index.push_back(pArmarObject);
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
	if(this->pArmar_Index.size() > 0)
	{
		for(int i = 0; i < pArmar_Index.size(); i++)
		{
			this->pArmar_Index.at(i)->bBreak = true;
			this->pArmar_Index.erase(this->pArmar_Index.begin() + i);
		}
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
	if (this->pArmar_Index.size() > 0)
	{
		DebugBufferManager::Sphere_BatchBegin();

		render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, GetModel_Cube(), sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);

		DebugBufferManager::BatchDrawSphere(&this->ColShape);

		DebugBufferManager::Sphere_BatchRun();
	}
}



