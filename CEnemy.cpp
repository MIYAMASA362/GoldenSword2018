//
//	CEnemy.cpp
//		Author:HIROMASA IKEDA	DATE:2018/10/19
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

//===============================================
//	�C���N���[�h	include
//===============================================
#include"common.h"
#include<d3dx9.h>
#include<vector>

//class
#include"CEnemy.h"

//===============================================
//	�}�N����`		define
//===============================================


//===============================================
//	�O���[�o���ϐ�	global
//===============================================
vector<BodyObject*> pBody_Index;

//===============================================
//	Enemy		class
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
Enemy::Enemy(Transform* pTransform,Texture* pTexture):GameObject(pTransform,pTexture)
{

}

//------------------------------------
//	�f�X�g���N�^
//------------------------------------
Enemy::~Enemy()
{

}

//------------------------------------
//	Body��ݒ�
//------------------------------------
void Enemy::Add_Body(BodyObject* pBodyObject)
{
	pBodyObject->Set_Parent(this);
	pBody_Index.push_back(pBodyObject);
}


