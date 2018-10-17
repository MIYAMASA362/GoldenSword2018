//
//	CArmorObject.cpp
//		Author:HIROMASA IKEDA	DATE:2018/10/16
//===============================================
#include<d3dx9.h>
#include<math.h>

//Class
#include"CArmorObject.h"
#include"CCollisionableObject.h"
#include"Bullet.h"

//===============================================
//	関数
//===============================================

//-------------------------------------
//	コンストラクタ
//-------------------------------------
ArmarObject::ArmarObject(Transform* pTransform,Texture* pTexture):GameObject(pTransform,pTexture),ColShape(pTransform->Position,1.0f)
{
	bBreak = false;
	this->Speed = D3DXVECTOR3(0.0f,0.0f,0.0f);
	this->Count = 0;
}

//-------------------------------------
//	更新処理
//-------------------------------------
void ArmarObject::Update()
{
	//--------------------------
	//	バラバラ
	//--------------------------
	if(bBreak)
	{
		if (this->Count < 5)
		{
			this->transform.Position.z -= ((rand() % 2) - 1) * 0.1f;
			this->transform.Position.y += ((rand() % 2) - 1) * 0.1f;
			this->transform.Rotation.x += 10.0f;

			this->Count++;

		}

		this->transform.Position.z -= ((rand() % 2) - 1) * 0.1f;
		this->transform.Position.y -= ((rand() % 2) - 1) * 0.1f;
		this->transform.Rotation.x += 10;

		this->transform.Position += this->Speed;
	}
	
	for(int i = 0; i<BULLET_MAX; i++)
	{
		if(Bullet_IsEnable(i))
		{
			if(mCollision.SphereVsSphere(ColShape,*Bullet_ColShape(i)))
			{
				bBreak = true;
			}
		}
	}
	
}



