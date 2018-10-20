//
//	GameObject.h
//		Author:HIROMASA IKEDA	DATE:2018/09/30
//===============================================
#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<d3dx9.h>
#include<vector>

//Class
#include"CTransform.h"
#include"CTexture.h"
#include"CRender.h"
#include"Component.h"

//===============================================
//	GameObject�@�N���X
//===============================================
class GameObject
{
private:
	static std::vector<GameObject*> pIndex;
	GameObject* pParent;	//�e

public:
	static void g_Update();	//�S�̍X�V
	static void g_Render();	//�S�̕`��

	Transform transform;	//�ʒu
	Texture texture;		//�e�N�X�`��
	Render3D render;		//�`��

	GameObject():GameObject(&Transform(), &Texture()) {};
	GameObject(Transform* pTransform):GameObject(pTransform, &Texture()) {};
	GameObject(Transform* pTransform,Texture* pTexture);

	void Set_Parent(GameObject* pParent);	//�e��ݒ�
	virtual void Update();
	virtual void Render();
};

#endif // !GAMEOBJECT_H


