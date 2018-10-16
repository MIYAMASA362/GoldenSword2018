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
//	�O���[�o��
//===============================================
static float g_Angle;

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

//-------------------------------------
//	������
//-------------------------------------
void Cube_Initialize()
{

}

//-------------------------------------
//	�X�V
//-------------------------------------
void Cube_Update()
{
	CubeObject.transform.Rotation.y += D3DXToRadian(5);
}

//-------------------------------------
//	�`��
//-------------------------------------
void Cube_Render()
{
	Lighting_SetLight();
	CubeObject.Begin(FVF_CUBE_VERTEX3D,CUBE_PRIMITIVE_TYPE, &Cube[0],sizeof(CubeVertex3D),CUBE_PRIMITIVE_NUM);
}

//-------------------------------------
//	�I��
//-------------------------------------
void Cube_Finalize()
{

}
