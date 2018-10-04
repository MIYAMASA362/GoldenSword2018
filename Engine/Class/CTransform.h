//
//	Transform.h
//		Author:HIROMASA IKEDA	DATE:2018/09/28
//===============================================
#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include<d3dx9.h>

//===============================================
//	Transform : 3D��p�@�N���X
//===============================================
class Transform
{
private:

public :
	D3DXVECTOR3 Position;	//�ʒu
	D3DXVECTOR3 Scale;		//�T�C�Y
	D3DXVECTOR3 Rotation;	//��]
	D3DCOLOR	Color;		//�F
	
	//�R���X�g���N�^
	Transform();
	Transform(D3DXVECTOR3 Position, D3DXVECTOR3 Scale, D3DXVECTOR3 Rotation);
	Transform(D3DXVECTOR3 Position, D3DXVECTOR3 Scale, D3DXVECTOR3 Rotation, D3DCOLOR Color);

};

//===============================================
//	Transform2 : 2D��p�@�N���X
//===============================================
class Transform2
{
private:

public:
	D3DXVECTOR2 Position;	//�ʒu
	D3DXVECTOR2 Scale;		//�T�C�Y
	float Rotation;			//��]
	D3DCOLOR Color;			//�F

	//�R���X�g���N�^
	Transform2();
	Transform2(D3DXVECTOR2 Position,D3DXVECTOR2 Scale,float Rotation);
	Transform2(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, float Rotation,D3DCOLOR Color);
	
};

#endif
