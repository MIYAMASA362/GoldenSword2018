//
//	Cube.cpp
//		Author:HIROMASA IKEDA	DATE:2018/09/21
//===============================================
#include<d3dx9.h>	
#include"System.h"
#include"Cube.h"
#include"CGameObject.h"
#include"input.h"
#include"Lighting.h"

//===============================================
//	マクロ	
//===============================================
#define FVF_CUBE_VERTEX3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1 )

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
//	グローバル
//===============================================
static D3DCOLOR g_CubeColor = D3DCOLOR_RGBA(255, 255, 255, 255);
static float g_Angle;

//-------------------------------------
//	モデルデータ
//-------------------------------------
static CubeVertex3D Cube[]=
{
	//正面
	{ { -0.5f,	 0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0,	0 } },
	{ { 0.5f,	 0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0.25, 0 } },
	{ { -0.5f,	-0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0,	 0.25 } },

	{ {  0.5f,	 0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0.25, 0 } },
	{ { 0.5f,	-0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0.25, 0.25 } },
	{ { -0.5f,	-0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0,	0.25 } },
	
	//上面
	{ { -0.5f,	 0.5f,	 0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{ 0.25, 0 } },
	{ { 0.5f,	 0.5f,	 0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{  0.5, 0 } },
	{ { -0.5f,	 0.5f,	-0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{  0.25, 0.25 } },
	
	{ {  0.5f,	 0.5f,	 0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{  0.5, 0 } },
	{ { 0.5f,	 0.5f,	-0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{  0.5, 0.25 } },
	{ { -0.5f,	 0.5f,	-0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{  0.25, 0.25 } },

	//右面
	{ {	 0.5f,	 0.5f,	-0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{  0.5, 0 } },
	{ { 0.5f,	 0.5f,	 0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75, 0 } },
	{ { 0.5f,	-0.5f,  -0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{  0.5, 0.25 } },

	{ {  0.5f,	 0.5f,	0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75, 0} },
	{ { 0.5f,	-0.5f,	0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75,0.25 } },
	{ { 0.5f,	-0.5f, -0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{ 0.5,0.25 } },

	//左面
	{ { -0.5f,	 0.5f,	 0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75, 0 } },
	{ { -0.5f,	 0.5f,	-0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{	   1, 0 } },
	{ { -0.5f,	-0.5f,   0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75, 0.25 } },

	{ { -0.5f,	 0.5f, -0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{ 1, 0 } },
	{ { -0.5f,	-0.5f, -0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{ 1, 0.25 } },
	{ { -0.5f,	-0.5f,  0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75,0.25 } },

	//裏面
	{ { 0.5f,	 0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0,0.25 } },
	{ { -0.5f,	 0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0.25,0.25 } },
	{ { 0.5f,	-0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0,0.5 } },
	
	{ { -0.5f,	 0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0.25,0.25 } },
	{ { -0.5f,	-0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0.25,0.5 } },
	{ { 0.5f,	-0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0,0.5 } },
	
	//下面
	{ { -0.5f,	 -0.5f,	-0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.25,0.25 } },
	{ { 0.5f,	 -0.5f,	-0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.5,0.25} },
	{ { -0.5f,	 -0.5f,	 0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.25,0.5 } },

	{ {  0.5f,	 -0.5f,	-0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.5,0.25 } },
	{ { 0.5f,	 -0.5f,	 0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.5,0.5 } },
	{ { -0.5f,	 -0.5f,	 0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.25,0.5 } },
};

//-------------------------------------
//	オブジェクト登録
//-------------------------------------
static GameObject CubeObject
(
	&Transform
	(
		D3DXVECTOR3(5.0f, 5.0f, 0.0f),
		D3DXVECTOR3(5.0f, 5.0f, 5.0f),
		D3DXVECTOR3(D3DXToRadian(0), D3DXToRadian(0), D3DXToRadian(0)),
		g_CubeColor
	),
	&Texture
	(
		CubeTexture,
		{ 0,0 },
		{ 256,256 }
	)
);

//===============================================
//	関数
//===============================================

//===============================================
//	初期化
//===============================================
void Cube_Initialize()
{

}

//===============================================
//	更新
//===============================================
void Cube_Update()
{
	CubeObject.transform.Rotation.y += D3DXToRadian(5);
}

//===============================================
//	描画
//===============================================
void Cube_Render()
{
	Lighting_SetLight();
	CubeObject.Begin(FVF_CUBE_VERTEX3D,D3DPT_TRIANGLELIST, &Cube[0],sizeof(CubeVertex3D),sizeof(Cube)/sizeof(Cube[0])/3);
}

//===============================================
//	終了
//===============================================
void Cube_Finalize()
{

}
