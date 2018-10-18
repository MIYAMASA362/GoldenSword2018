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
//	CoreObject �N���X
//===============================================
class CoreObject:public GameObject
{
private:
	vector<ArmarObject*> pArmar_Index;	//�A�[�}�[�I�u�W�F�N�g
	BodyObject*		pBodyObject;
	Collision mCollision;
	
public:
	static vector<CoreObject*> g_pIndex;//�C���f�b�N�X
	static void g_Update();				//�S�̍X�V
	static void g_Render();				//�S�̕`��

	ShapeSphere ColShape;
	CoreObject(Transform* pTransform, Texture* pTexture);
	~CoreObject();

	void Hit();
	void Set(ArmarObject* pArmarObject);
	void Set(ArmarObject* pArmarObject, BodyObject* pBodyObject);
	void Update();
};

#endif // !CCOREOBJECT_H




