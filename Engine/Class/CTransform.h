//
//	Transform.h
//		Author:HIROMASA IKEDA	DATE:2018/09/28
//===============================================
#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include<d3dx9.h>

//===============================================
//	Transform : 3D専用　クラス
//===============================================
class Transform
{
private:

public :
	D3DXVECTOR3 Position;	//位置
	D3DXVECTOR3 Scale;		//サイズ
	D3DXVECTOR3 Rotation;	//回転
	D3DCOLOR	Color;		//色
	
	//コンストラクタ
	Transform();
	Transform(D3DXVECTOR3 Position, D3DXVECTOR3 Scale, D3DXVECTOR3 Rotation);
	Transform(D3DXVECTOR3 Position, D3DXVECTOR3 Scale, D3DXVECTOR3 Rotation, D3DCOLOR Color);

};

//===============================================
//	Transform2 : 2D専用　クラス
//===============================================
class Transform2
{
private:

public:
	D3DXVECTOR2 Position;	//位置
	D3DXVECTOR2 Scale;		//サイズ
	float Rotation;			//回転
	D3DCOLOR Color;			//色

	//コンストラクタ
	Transform2();
	Transform2(D3DXVECTOR2 Position,D3DXVECTOR2 Scale,float Rotation);
	Transform2(D3DXVECTOR2 Position, D3DXVECTOR2 Scale, float Rotation,D3DCOLOR Color);
	
};

#endif
