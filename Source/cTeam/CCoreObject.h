//
//	CCoreObject.h
//		Author:HIROMASA IKEDA	DATE:2018/10/13
//===============================================
#pragma once
#ifndef COREOBJECT_H
#define COREOBJECT_H

#include<d3dx9.h>
#include"CGameObject.h"
#include"CBodyObject.h"
#include"CArmorObject.h"

//===============================================
//	CoreObject ƒNƒ‰ƒX
//===============================================
class CoreObject:public GameObject
{
private:
	ArmarObject*	pArmarObject;
	BodyObject*		pBodyObject;
public:
	CoreObject(Transform* pTransform, Texture* pTexture);
	void Hit();
	void Set(ArmarObject* pArmarObject, BodyObject* pBodyObject);
};

#endif // !CCOREOBJECT_H




