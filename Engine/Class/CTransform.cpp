//
//	Transform.cpp
//		Author:HIROMASA IKEDA	DATA:2018/09/28
//===============================================
#include<d3dx9.h>
#include"CTransform.h"

//===============================================
//	Transform3
//===============================================

//-------------------------------------
//	コンストラクタ
//-------------------------------------
Transform::Transform()
{
	Position = {0.0f,0.0f,0.0f};
	Scale = {1.0f,1.0f,1.0f};
	Rotation = {0.0f,0.0f,0.0f};
	Color = D3DCOLOR_RGBA(255,255,255,255);
}

Transform::Transform(D3DXVECTOR3 Position, D3DXVECTOR3 Scale, D3DXVECTOR3 Rotation)
{
	this->Position = Position;
	this->Scale = Scale;
	this->Rotation = Rotation;
	Color = D3DCOLOR_RGBA(255, 255, 255, 255);
}

Transform::Transform(D3DXVECTOR3 Position, D3DXVECTOR3 Scale, D3DXVECTOR3 Rotation, D3DCOLOR Color)
{
	this->Position = Position;
	this->Scale = Scale;
	this->Rotation = Rotation;
	this->Color = Color;
}

//-------------------------------------
//	
//-------------------------------------


//===============================================
//	Transform2
//===============================================

//-------------------------------------
//	コンストラクタ
//-------------------------------------
Transform2::Transform2()
{
	Position = {0.0f,0.0f};
	Scale = {1.0f,1.0f};
	Rotation = 0;
	Color = Color;
}

Transform2::Transform2(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, float Rotation)
{
	this->Position = Position;
	this->Scale = Scale;
	this->Rotation = Rotation;
	Color = D3DCOLOR_RGBA(255,255,255,255);
}

Transform2::Transform2(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, float Rotation, D3DCOLOR Color)
{
	this->Position = Position;
	this->Scale = Scale;
	this->Rotation = Rotation;
	this->Color = Color;
}
