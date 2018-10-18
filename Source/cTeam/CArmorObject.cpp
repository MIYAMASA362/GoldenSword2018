//
//	CArmorObject.cpp
//		Author:HIROMASA IKEDA	DATE:2018/10/16
//===============================================
#include<d3dx9.h>
#include<math.h>
#include<vector>

//Class
#include"CArmorObject.h"
#include"Cube.h"

std::vector<ArmarObject*> ArmarObject::g_pIndex;

//===============================================
//	�֐�
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
ArmarObject::ArmarObject(Transform* pTransform,Texture* pTexture):GameObject(pTransform,pTexture)
{
	bBreak = false;
	this->Speed = D3DXVECTOR3(0.0f,0.0f,0.0f);
	this->Count = 0;
	this->g_pIndex.push_back(this);
}

//-------------------------------------
//	�X�V����
//-------------------------------------
void ArmarObject::Update()
{
	//--------------------------
	//	�o���o��
	//--------------------------
	if(bBreak)
	{
		
		if (this->Count < 5)
		{
			this->Speed.x = ((rand() % 20) - 10) * 0.1f;
			this->Speed.z = ((rand() % 20) - 10) * 0.1f;
			this->Speed.y = 0.1f;
			this->transform.Rotation.x += 10.0f;

			this->Count++;

		}
		this->transform.Rotation.x += 10;

		this->transform.Position += this->Speed;
	}
}


//===============================================
//	�O���[�o���֐�
//===============================================

//-------------------------------------
//	�X�V����
//-------------------------------------
void ArmarObject::g_Update()
{
	for(int i = 0; i < g_pIndex.size(); i++)
	{
		g_pIndex.at(i)->Update();
	}
}

//-------------------------------------
//	�`��
//-------------------------------------
void ArmarObject::g_Rednder()
{
	for(int i= 0; i < g_pIndex.size(); i++)
	{
		g_pIndex.at(i)->render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, GetModel_Cube(), sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);
	}
}


