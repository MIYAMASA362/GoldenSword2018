//
//	CTeamProt.cpp
//		Author:HIROMASA IEKDA	DATE:2018/10/15
//===============================================

#include<d3dx9.h>
#include"common.h"
#include"CTeamProt.h"
#include"input.h"

//Gometry
#include"Cube.h"

//Class
#include"CArmorObject.h"
#include"CCoreObject.h"
#include"CBodyObject.h"

//===============================================
//	�O���[�o���ϐ�
//===============================================

//����
static BodyObject Body(
	&Transform
	(
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(255, 255, 255, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//�A�[�}�[
static ArmarObject Armar_01(
	&Transform
	(
		D3DXVECTOR3(0.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//�l�W
static CoreObject Screw
(
	&Transform
	(
		D3DXVECTOR3(0.0f, 0.5f, 0.5f),
		D3DXVECTOR3(1.0f, 0.5f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(255, 0, 0, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);


//===============================================
//	�֐�
//===============================================

//-------------------------------------
//	������
//-------------------------------------
void CTeamProt_Initialize()
{
	Screw.Set(&Armar_01,&Body);
}

//-------------------------------------
//	�X�V
//-------------------------------------
void CTeamProt_Update()
{
	if(Keyboard_IsTrigger(DIK_SPACE))
	{
 		Screw.Hit();
	}

	Armar_01.Update();
}

//-------------------------------------
//	�`��
//-------------------------------------
void CTeamProt_Render()
{
	Body.render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, &Cube[0], sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);
	Armar_01.render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, &Cube[0], sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);
	
	if (!Armar_01.bBreak)
	{
		Screw.render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, &Cube[0], sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);
	}
}

//-------------------------------------
//	�I��
//-------------------------------------
void CTeamProt_Finalize()
{

}

