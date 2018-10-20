//
//	Transform.h
//		Author:HIROMASA IKEDA	DATE:2018/09/28
//===============================================
#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include<d3dx9.h>

//===============================================
//	MatrixTransform : �s�� �N���X
//===============================================
class MatrixTransform
{
private:
	D3DXMATRIX MtxWorld;					//���[���h�ϊ��s��
	D3DXMATRIX MtxTransform;				//�ʒu
	D3DXMATRIX MtxRotation;					//��]
	D3DXMATRIX MtxScale;					//�g��E�k��
public:
	MatrixTransform();
};

//===============================================
//	Transform : 3D��p�@�N���X
//===============================================
class Transform
{
private:
	D3DXMATRIX* pParent_Matrix = NULL;	//�e�ϊ��s��
public :
	//��{���
	D3DXVECTOR3 Position;	//�ʒu
	D3DXVECTOR3 Scale;		//�T�C�Y
	D3DXVECTOR3 Rotation;	//��]
	D3DCOLOR	Color;		//�F
	
	//������
	D3DXVECTOR3 up;			//��
	D3DXVECTOR3 forward;	//�O
	D3DXVECTOR3 right;		//�E

	//�R���X�g���N�^
	Transform() :Transform({ 0.0f,0.0f,0.0f }, { 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, D3DCOLOR_RGBA(255, 255, 255, 255)){};
	Transform(D3DXVECTOR3 Position, D3DXVECTOR3 Scale, D3DXVECTOR3 Rotation) :Transform(Position, Scale, Rotation, D3DCOLOR_RGBA(255, 255, 255, 255)) {};
	Transform(D3DXVECTOR3 Position, D3DXVECTOR3 Scale, D3DXVECTOR3 Rotation, D3DCOLOR Color);

	~Transform();

	void Set_ParentMatrix(D3DXMATRIX Matrix);
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
