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
//	�萔
//===============================================
 // �Ƃ肠����
const D3DXVECTOR3 GRAVITY( 0.0f, -0.02f, 0.0f );	//�d��
//===============================================
//	�֐�
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
ArmorObject::ArmorObject(Transform* pTransform, Texture* pTexture, ARMOR_DISCHARGING_TYPE Type) :GameObject(pTransform,pTexture)
{
	bBreak = false;
	this->Discharging_Type = Type;
	this->Speed = D3DXVECTOR3(0.0f,0.0f,0.0f);
	this->DelayFrameForDrop = -1;
}

//-------------------------------------
//	�X�V����
//-------------------------------------
void ArmorObject::Update()
{
	//--------------------------
	//	�o���o��
	//--------------------------
	if(bBreak && DelayFrameForDrop <= 0 )
	{
		this->transform.Position += this->Speed;
		this->Speed += GRAVITY;
	}
	// 
	if( bBreak && 0 < DelayFrameForDrop )
	{
		DelayFrameForDrop--;
	}

}


//-------------------------------------
//	���x�x�N�g���Z�b�g
//-------------------------------------
void ArmorObject::SetSpeed( D3DXVECTOR3 InitVec )
{
	Speed = InitVec;
}


//-------------------------------------
//	���x�x�N�g���Z�b�g
//-------------------------------------
void ArmorObject::Break()
{
	bBreak = true;
}

//-------------------------------------
//	���x�x�N�g���Z�b�g
//-------------------------------------
void ArmorObject::Break( D3DXVECTOR3 InitVec, unsigned int InitDelay )
{
	Break();
	SetSpeed( InitVec );
	DelayFrameForDrop = InitDelay;

}

//-------------------------------------
//	�^�C�v���Z�b�g
//-------------------------------------
void ArmorObject::Set_DischargingType(ARMOR_DISCHARGING_TYPE Type)
{
	this->Discharging_Type = Type;
}


