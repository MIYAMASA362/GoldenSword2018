//
//	ArmorObject.h
//		Author:HIROMASA IEKDA	DATE:2018/10/13
//===============================================
#pragma once
#ifndef ARMOROBJECT_H
#define ARMOROBJECT_H

#include"CGameObject.h"

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
	void Update();		//更新処理


	ArmarObject(Transform* pTransform,Texture* pTexture);
};


#endif // !ARMOROBJECT_H

