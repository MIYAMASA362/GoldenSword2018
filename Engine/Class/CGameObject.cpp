//
//	CGameObject.cpp
//		Author:HIROMASA IKEDA	DATE:2018/09/29
//===============================================
#include<d3dx9.h>
#include"CGameObject.h"

//===============================================
//	GameObject クラス
//===============================================

//-------------------------------------
//	コンストラクタ
//-------------------------------------
GameObject::GameObject() : render(&this->transform, &this->texture)
{
	this->transform = {};
	this->texture	= {};
}

GameObject::GameObject(Transform* pTransform):render(&this->transform, &this->texture)
{
	this->transform = *pTransform;
	this->texture = {};
}

GameObject::GameObject(Transform* pTransform, Texture* pTexture) : render(&this->transform,&this->texture)
{
	this->transform		= *pTransform;
	this->texture		= *pTexture;
}
