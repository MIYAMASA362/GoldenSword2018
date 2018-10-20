//
//	CEnemy.h
//		Author:HIROMASA IKEDA	DATE:2018/10/19
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

#pragma once
#ifndef CENEMY_H
#define CENEMY_H

//================================================
//	�C���N���[�h	include
//================================================
#include"common.h"
#include<d3dx9.h>
#include<vector>

//Class
#include"CGameObject.h"
#include"CCoreObject.h"
#include"CArmorObject.h"
#include"CBodyObject.h"

//================================================
//	�}�N����`	define
//================================================


//================================================
//	�񋓌^		enum
//================================================


//================================================
//	�\����		struct/typedef
//================================================


//================================================
//	�O���[�o���ϐ��@global
//================================================


//================================================
//	�N���X		class
//================================================


//-------------------------------------
//	Enemy �N���X
//-------------------------------------
class Enemy:public GameObject
{
private:
	std::vector<BodyObject*> pBody_Index;
public:

	Enemy(Transform* pTransform) :Enemy(pTransform, &Texture()) {};
	Enemy(Transform* pTransform,Texture* pTexture);

	~Enemy();

	void Add_Body(BodyObject* pBodyObject);
};

#endif