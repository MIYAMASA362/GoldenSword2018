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
