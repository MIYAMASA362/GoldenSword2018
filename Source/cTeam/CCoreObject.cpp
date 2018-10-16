//
//	CCoreObject.cpp	
//		Author:HIROMASA IKEDA	DATE:2018/10/13
//===============================================
#include<d3dx9.h>
#include"CCoreObject.h"

//===============================================
//	CoreObject	クラス
//===============================================

//-------------------------------------
//	コンストラクタ
//-------------------------------------
CoreObject::CoreObject(Transform* pTransform,Texture* pTexture):GameObject(pTransform, pTexture)
{

}

void CoreObject::Set(ArmarObject* pArmarObject,BodyObject* pBodyObject)
{
	this->pArmarObject = pArmarObject;
	this->pBodyObject = pBodyObject;
}

//-------------------------------------
//	弾に当たった
//-------------------------------------
void CoreObject::Hit()
{
	if(pArmarObject != NULL)
	{
		pArmarObject->bBreak = true;
	}
}






