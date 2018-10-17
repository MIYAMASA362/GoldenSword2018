//
//	ArmorObject.h
//		Author:HIROMASA IEKDA	DATE:2018/10/13
//===============================================
#pragma once
#ifndef ARMOROBJECT_H
#define ARMOROBJECT_H

//Class
#include"CGameObject.h"
#include"CCollisionableObject.h"

//===============================================
//	ArmarObject �N���X
//===============================================
class ArmarObject :public GameObject
{
private:
	D3DXVECTOR3 Speed;
	Collision mCollision;
	int Count;
public:
	ShapeSphere ColShape;
	bool bBreak;		//�o���o���t���O�@True(�o���o���ɂȂ�)
	
	ArmarObject(Transform* pTransform, Texture* pTexture);
	void Update();		//�X�V����
	
};


#endif // !ARMOROBJECT_H

