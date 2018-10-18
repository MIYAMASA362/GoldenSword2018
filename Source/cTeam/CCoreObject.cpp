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

std::vector<CoreObject*> CoreObject::g_pIndex;

//===============================================
//	CoreObject	クラス
//===============================================

//-------------------------------------
//	コンストラクタ
//-------------------------------------
CoreObject::CoreObject(Transform* pTransform,Texture* pTexture):GameObject(pTransform, pTexture), ColShape(pTransform->Position, 1.0f)
{
	this->g_pIndex.push_back(this);
}

void CoreObject::Set(ArmarObject* pArmarObject)
{
	this->pArmar_Index.push_back(pArmarObject);
}

void CoreObject::Set(ArmarObject* pArmarObject,BodyObject* pBodyObject)
{
	this->pArmar_Index.push_back(pArmarObject);
	this->pBodyObject = pBodyObject;
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
			if (mCollision.SphereVsSphere(ColShape, *Bullet_ColShape(i)))
			{
				Hit();
			}
		}
	}

}

//===============================================
//	グローバル
//===============================================

//-------------------------------------
//	全体更新
//-------------------------------------
void CoreObject::g_Update()
{
	for(int i= 0; i< g_pIndex.size(); i++)
	{
		if(g_pIndex.at(i)->pArmar_Index.size() > 0)
		{
			g_pIndex.at(i)->Update();
		}
	}
}

//-------------------------------------
//	全体描画
//-------------------------------------
void CoreObject::g_Render()
{
	for (int i = 0; i< g_pIndex.size(); i++)
	{
		if (g_pIndex.at(i)->pArmar_Index.size() > 0)
		{
			g_pIndex.at(i)->render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, GetModel_Cube(), sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);
		}
	}
}


