//
//	ArmorObject.h
//		Author:HIROMASA IEKDA	DATE:2018/10/13
//===============================================
#pragma once
#ifndef ARMOROBJECT_H
#define ARMOROBJECT_H

#include"CGameObject.h"

//===============================================
//	ArmarObject �N���X
//===============================================
class ArmarObject :public GameObject
{
private:
	D3DXVECTOR3 Speed;
	int Count;
public:
	bool bBreak;		//�o���o���t���O�@True(�o���o���ɂȂ�)
	void Update();		//�X�V����


	ArmarObject(Transform* pTransform,Texture* pTexture);
};


#endif // !ARMOROBJECT_H

