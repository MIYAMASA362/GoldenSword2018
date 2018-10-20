//
//	CCoreObject.h
//		Author:HIROMASA IKEDA	DATE:2018/10/13
//===============================================
#pragma once
#ifndef COREOBJECT_H
#define COREOBJECT_H

#include<d3dx9.h>
#include<vector>

using namespace std;

#include"CGameObject.h"
#include"CBodyObject.h"
#include"CArmorObject.h"

//===============================================
//	CoreObject クラス
//===============================================
class CoreObject:public GameObject
{
private:
	vector<ArmarObject*> pArmar_Index;	//アーマーオブジェクト
	BodyObject*	pBodyObject;
	
public:
	ShapeSphere ColShape;
	CoreObject(Transform* pTransform, Texture* pTexture);
	~CoreObject();

	void Hit();
	void Set(ArmarObject* pArmarObject);
	void Set(ArmarObject* pArmarObject, BodyObject* pBodyObject);
	void Update();
	void Render();
};

#endif // !CCOREOBJECT_H




