//
//	CGameObject.cpp
//		Author:HIROMASA IKEDA	DATE:2018/09/29
//===============================================
#include<d3dx9.h>
#include<vector>
#include"Cube.h"

//Class
#include"CGameObject.h"

//===============================================
//	�O���[�o���ϐ�
//===============================================
std::vector<GameObject*> GameObject::pIndex;

//===============================================
//	GameObject �N���X
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
GameObject::GameObject(Transform* pTransform, Texture* pTexture) : render(&this->transform,&this->texture)
{
	this->transform		= *pTransform;
	this->texture		= *pTexture;
	this->pIndex.push_back(this);
	this->pParent = NULL;
}

//-------------------------------------
//	�e��ݒ�
//-------------------------------------
void GameObject::Set_Parent(GameObject* pParent)
{
	this->pParent = pParent;
}

//------------------------------------
//	�X�V����
//------------------------------------
void GameObject::Update()
{
}

//------------------------------------
//	�`�揈��
//------------------------------------
void GameObject::Render()
{
	render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, GetModel_Cube(), sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);
}

//===============================================
//	�O���[�o��
//===============================================

//-----------------------------------
//	�S�̍X�V
//-----------------------------------
void GameObject::g_Update()
{
	for(int i = 0; i < pIndex.size(); i++)
	{
		pIndex.at(i)->Update();
	}
}

//----------------------------------
//	�S�̕`��
//----------------------------------
void GameObject::g_Render()
{
	for(int i = 0; i< pIndex.size(); i++)
	{
		pIndex.at(i)->Render();
		int j = pIndex.size();
		j = j;
	}
}
