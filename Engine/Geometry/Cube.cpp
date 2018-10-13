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
//	�}�N��	
//===============================================
#define FVF_CUBE_VERTEX3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1 )

//===============================================
//	�\����
//===============================================
typedef struct Cube_Vertex3D_tag
{
	D3DXVECTOR3 Position;	//�ʒu
	D3DXVECTOR3 Normal;		//�@��
	D3DCOLOR	Color;		//�F
	D3DXVECTOR2 TexCoord;	//�e�N�X�`�����W
}CubeVertex3D;

//===============================================
//	�O���[�o��
//===============================================
static D3DCOLOR g_CubeColor = D3DCOLOR_RGBA(255, 255, 255, 255);
static float g_Angle;

//-------------------------------------
//	���f���f�[�^
//-------------------------------------
static CubeVertex3D Cube[]=
{
	//����
	{ { -0.5f,	 0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0,	0 } },
	{ { 0.5f,	 0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0.25, 0 } },
	{ { -0.5f,	-0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0,	 0.25 } },

	{ {  0.5f,	 0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0.25, 0 } },
	{ { 0.5f,	-0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0.25, 0.25 } },
	{ { -0.5f,	-0.5f,	-0.5f },{0.0f,0.0f,-1.0f}, g_CubeColor,{ 0,	0.25 } },
	
	//���
	{ { -0.5f,	 0.5f,	 0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{ 0.25, 0 } },
	{ { 0.5f,	 0.5f,	 0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{  0.5, 0 } },
	{ { -0.5f,	 0.5f,	-0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{  0.25, 0.25 } },
	
	{ {  0.5f,	 0.5f,	 0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{  0.5, 0 } },
	{ { 0.5f,	 0.5f,	-0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{  0.5, 0.25 } },
	{ { -0.5f,	 0.5f,	-0.5f },{0.0f,1.0f,0.0f}, g_CubeColor,{  0.25, 0.25 } },

	//�E��
	{ {	 0.5f,	 0.5f,	-0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{  0.5, 0 } },
	{ { 0.5f,	 0.5f,	 0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75, 0 } },
	{ { 0.5f,	-0.5f,  -0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{  0.5, 0.25 } },

	{ {  0.5f,	 0.5f,	0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75, 0} },
	{ { 0.5f,	-0.5f,	0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75,0.25 } },
	{ { 0.5f,	-0.5f, -0.5f },{1.0f,0.0f,0.0f}, g_CubeColor,{ 0.5,0.25 } },

	//����
	{ { -0.5f,	 0.5f,	 0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75, 0 } },
	{ { -0.5f,	 0.5f,	-0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{	   1, 0 } },
	{ { -0.5f,	-0.5f,   0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75, 0.25 } },

	{ { -0.5f,	 0.5f, -0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{ 1, 0 } },
	{ { -0.5f,	-0.5f, -0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{ 1, 0.25 } },
	{ { -0.5f,	-0.5f,  0.5f },{-1.0f,0.0f,0.0f}, g_CubeColor,{ 0.75,0.25 } },

	//����
	{ { 0.5f,	 0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0,0.25 } },
	{ { -0.5f,	 0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0.25,0.25 } },
	{ { 0.5f,	-0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0,0.5 } },
	
	{ { -0.5f,	 0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0.25,0.25 } },
	{ { -0.5f,	-0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0.25,0.5 } },
	{ { 0.5f,	-0.5f, 0.5f },{0.0f,0.0f,1.0f}, g_CubeColor,{ 0,0.5 } },
	
	//����
	{ { -0.5f,	 -0.5f,	-0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.25,0.25 } },
	{ { 0.5f,	 -0.5f,	-0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.5,0.25} },
	{ { -0.5f,	 -0.5f,	 0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.25,0.5 } },

	{ {  0.5f,	 -0.5f,	-0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.5,0.25 } },
	{ { 0.5f,	 -0.5f,	 0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.5,0.5 } },
	{ { -0.5f,	 -0.5f,	 0.5f },{0.0f,-1.0f,0.0f}, g_CubeColor,{ 0.25,0.5 } },
};

//-------------------------------------
//	�I�u�W�F�N�g�o�^
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
//	�֐�
//===============================================

//===============================================
//	������
//===============================================
void Cube_Initialize()
{

}

//===============================================
//	�X�V
//===============================================
void Cube_Update()
{
	CubeObject.transform.Rotation.y += D3DXToRadian(5);
}

//===============================================
//	�`��
//===============================================
void Cube_Render()
{
	Lighting_SetLight();
	CubeObject.Begin(FVF_CUBE_VERTEX3D,D3DPT_TRIANGLELIST, &Cube[0],sizeof(CubeVertex3D),sizeof(Cube)/sizeof(Cube[0])/3);
}

//===============================================
//	�I��
//===============================================
void Cube_Finalize()
{

}
