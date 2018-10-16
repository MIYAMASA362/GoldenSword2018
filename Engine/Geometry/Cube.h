//
//	Cube.h
//		Author:HIROMASA IKEDA	DATE:2018/09/21
//===============================================
#pragma once
#ifndef CUBE_H
#define CUBE_H

#include<d3dx9.h>

//===============================================
//	マクロ	
//===============================================
#define FVF_CUBE_VERTEX3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1 )
#define CUBE_PRIMITIVE_TYPE (D3DPT_TRIANGLELIST)	//プリミティブタイプ
#define CUBE_PRIMITIVE_NUM	(12)					//ポリゴン数

//===============================================
//	構造体
//===============================================
typedef struct Cube_Vertex3D_tag
{
	D3DXVECTOR3 Position;	//位置
	D3DXVECTOR3 Normal;		//法線
	D3DCOLOR	Color;		//色
	D3DXVECTOR2 TexCoord;	//テクスチャ座標
}CubeVertex3D;

//===============================================
//	Cube モデルデータ
//===============================================

static D3DCOLOR g_CubeColor = D3DCOLOR_RGBA(255, 255, 255, 255);

static CubeVertex3D Cube[] =
{
	//正面
	{ { -0.5f,	 0.5f,	-0.5f },{ 0.0f,0.0f,-1.0f }, g_CubeColor,{ 0,	0 } },
	{ { 0.5f,	 0.5f,	-0.5f },{ 0.0f,0.0f,-1.0f }, g_CubeColor,{ 0.25, 0 } },
	{ { -0.5f,	-0.5f,	-0.5f },{ 0.0f,0.0f,-1.0f }, g_CubeColor,{ 0,	 0.25 } },

	{ { 0.5f,	 0.5f,	-0.5f },{ 0.0f,0.0f,-1.0f }, g_CubeColor,{ 0.25, 0 } },
	{ { 0.5f,	-0.5f,	-0.5f },{ 0.0f,0.0f,-1.0f }, g_CubeColor,{ 0.25, 0.25 } },
	{ { -0.5f,	-0.5f,	-0.5f },{ 0.0f,0.0f,-1.0f }, g_CubeColor,{ 0,	0.25 } },

	//上面
	{ { -0.5f,	 0.5f,	 0.5f },{ 0.0f,1.0f,0.0f }, g_CubeColor,{ 0.25, 0 } },
	{ { 0.5f,	 0.5f,	 0.5f },{ 0.0f,1.0f,0.0f }, g_CubeColor,{ 0.5, 0 } },
	{ { -0.5f,	 0.5f,	-0.5f },{ 0.0f,1.0f,0.0f }, g_CubeColor,{ 0.25, 0.25 } },

	{ { 0.5f,	 0.5f,	 0.5f },{ 0.0f,1.0f,0.0f }, g_CubeColor,{ 0.5, 0 } },
	{ { 0.5f,	 0.5f,	-0.5f },{ 0.0f,1.0f,0.0f }, g_CubeColor,{ 0.5, 0.25 } },
	{ { -0.5f,	 0.5f,	-0.5f },{ 0.0f,1.0f,0.0f }, g_CubeColor,{ 0.25, 0.25 } },

	//右面
	{ { 0.5f,	 0.5f,	-0.5f },{ 1.0f,0.0f,0.0f }, g_CubeColor,{ 0.5, 0 } },
	{ { 0.5f,	 0.5f,	 0.5f },{ 1.0f,0.0f,0.0f }, g_CubeColor,{ 0.75, 0 } },
	{ { 0.5f,	-0.5f,  -0.5f },{ 1.0f,0.0f,0.0f }, g_CubeColor,{ 0.5, 0.25 } },

	{ { 0.5f,	 0.5f,	0.5f },{ 1.0f,0.0f,0.0f }, g_CubeColor,{ 0.75, 0 } },
	{ { 0.5f,	-0.5f,	0.5f },{ 1.0f,0.0f,0.0f }, g_CubeColor,{ 0.75,0.25 } },
	{ { 0.5f,	-0.5f, -0.5f },{ 1.0f,0.0f,0.0f }, g_CubeColor,{ 0.5,0.25 } },

	//左面
	{ { -0.5f,	 0.5f,	 0.5f },{ -1.0f,0.0f,0.0f }, g_CubeColor,{ 0.75, 0 } },
	{ { -0.5f,	 0.5f,	-0.5f },{ -1.0f,0.0f,0.0f }, g_CubeColor,{ 1, 0 } },
	{ { -0.5f,	-0.5f,   0.5f },{ -1.0f,0.0f,0.0f }, g_CubeColor,{ 0.75, 0.25 } },

	{ { -0.5f,	 0.5f, -0.5f },{ -1.0f,0.0f,0.0f }, g_CubeColor,{ 1, 0 } },
	{ { -0.5f,	-0.5f, -0.5f },{ -1.0f,0.0f,0.0f }, g_CubeColor,{ 1, 0.25 } },
	{ { -0.5f,	-0.5f,  0.5f },{ -1.0f,0.0f,0.0f }, g_CubeColor,{ 0.75,0.25 } },

	//裏面
	{ { 0.5f,	 0.5f, 0.5f },{ 0.0f,0.0f,1.0f }, g_CubeColor,{ 0,0.25 } },
	{ { -0.5f,	 0.5f, 0.5f },{ 0.0f,0.0f,1.0f }, g_CubeColor,{ 0.25,0.25 } },
	{ { 0.5f,	-0.5f, 0.5f },{ 0.0f,0.0f,1.0f }, g_CubeColor,{ 0,0.5 } },

	{ { -0.5f,	 0.5f, 0.5f },{ 0.0f,0.0f,1.0f }, g_CubeColor,{ 0.25,0.25 } },
	{ { -0.5f,	-0.5f, 0.5f },{ 0.0f,0.0f,1.0f }, g_CubeColor,{ 0.25,0.5 } },
	{ { 0.5f,	-0.5f, 0.5f },{ 0.0f,0.0f,1.0f }, g_CubeColor,{ 0,0.5 } },

	//下面
	{ { -0.5f,	 -0.5f,	-0.5f },{ 0.0f,-1.0f,0.0f }, g_CubeColor,{ 0.25,0.25 } },
	{ { 0.5f,	 -0.5f,	-0.5f },{ 0.0f,-1.0f,0.0f }, g_CubeColor,{ 0.5,0.25 } },
	{ { -0.5f,	 -0.5f,	 0.5f },{ 0.0f,-1.0f,0.0f }, g_CubeColor,{ 0.25,0.5 } },

	{ { 0.5f,	 -0.5f,	-0.5f },{ 0.0f,-1.0f,0.0f }, g_CubeColor,{ 0.5,0.25 } },
	{ { 0.5f,	 -0.5f,	 0.5f },{ 0.0f,-1.0f,0.0f }, g_CubeColor,{ 0.5,0.5 } },
	{ { -0.5f,	 -0.5f,	 0.5f },{ 0.0f,-1.0f,0.0f }, g_CubeColor,{ 0.25,0.5 } },
};


//===============================================
//	関数
//===============================================
void Cube_Initialize();
void Cube_Update();
void Cube_Render();
void Cube_Finalize();

#endif