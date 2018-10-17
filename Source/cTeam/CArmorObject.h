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
//	ArmarObject クラス
//===============================================
class ArmarObject :public GameObject
{
private:
	D3DXVECTOR3 Speed;
	Collision mCollision;
	int Count;
public:
	ShapeSphere ColShape;
	bool bBreak;		//バラバラフラグ　True(バラバラになる)
	
	ArmarObject(Transform* pTransform, Texture* pTexture);
	void Update();		//更新処理
	
};


#endif // !ARMOROBJECT_H

