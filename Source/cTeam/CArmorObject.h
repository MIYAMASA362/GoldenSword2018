//
//	ArmorObject.h
//		Author:HIROMASA IEKDA	DATE:2018/10/13
//===============================================
#pragma once
#ifndef ARMOROBJECT_H
#define ARMOROBJECT_H

#include<d3dx9.h>
#include<vector>

using namespace std;

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
	int Count;
public:

	bool bBreak;		//バラバラフラグ　True(バラバラになる)
	
	ArmarObject(Transform* pTransform) :ArmarObject(pTransform, &Texture(TEXTURE_NONE, { 0,0 }, { 0,0 })) {};
	ArmarObject(Transform* pTransform, Texture* pTexture);
	
	void Update();		//更新処理
	
};


#endif // !ARMOROBJECT_H

