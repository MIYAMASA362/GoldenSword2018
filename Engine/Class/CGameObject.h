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
class GameObject
{
private:

public:
	Transform transform;
	Texture texture;
	Render3D render;

	GameObject();
	GameObject(Transform* pTransform);
	GameObject(Transform* pTransform,Texture* pTexture);
};

#endif // !GAMEOBJECT_H


