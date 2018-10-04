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
GameObject::GameObject() : Render3D(&this->transform, &this->texture)
{
	this->transform = {};
	this->texture	= {};
}

GameObject::GameObject(Transform* pTransform, Texture* pTexture) : Render3D(&this->transform,&this->texture)
{
	this->transform		= *pTransform;
	this->texture		= *pTexture;
}
