//
//	GameObject.h
//		Author:HIROMASA IKEDA	DATE:2018/09/30
//===============================================
#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<d3dx9.h>
#include"CTransform.h"
#include"CTexture.h"
#include"CRender.h"

//===============================================
//	GameObjectÅ@ÉNÉâÉX
//===============================================
class GameObject:public Render3D
{
private:

public:
	Transform transform;
	Texture texture;

	GameObject();
	GameObject(Transform* pTransform);
	GameObject(Transform* pTransform,Texture* pTexture);
};

#endif // !GAMEOBJECT_H


