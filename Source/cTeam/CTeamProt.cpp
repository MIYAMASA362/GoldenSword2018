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
		D3DXVECTOR3(0.0f, 1.0f, 0.0f),	//�ʒu
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//�T�C�Y
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//��]
		D3DCOLOR_RGBA(0, 0, 255, 255)	//�F
	)
	//�e�N�X�`������
);

//�A�[�}�[
static ArmarObject Armar_02(
	&Transform
	(
		D3DXVECTOR3(-1.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);

//�A�[�}�[
static ArmarObject Armar_03(
	&Transform
	(
		D3DXVECTOR3(1.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
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
	Screw.Set(&Armar_01, &Body);	//�l�W�ɓ��̂ƃA�[�}�[��ݒ�
	Screw.Set(&Armar_02);			//�l�W�̓��̂͌��܂��Ă���̂ŁA�A�[�}�[�����ݒ�
	Screw.Set(&Armar_03);			//�A�[�}�[�ݒ�

}

//-------------------------------------
//	�X�V
//-------------------------------------
void CTeamProt_Update()
{
	ArmarObject::g_Update();	//�A�[�}�[�X�V
	CoreObject::g_Update();		//�l�W�X�V
}

//-------------------------------------
//	�`��
//-------------------------------------
void CTeamProt_Render()
{
	//����
	Body.render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, GetModel_Cube(), sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);
	
	ArmarObject::g_Rednder();
	CoreObject::g_Render();
}

//-------------------------------------
//	�I��
//-------------------------------------
void CTeamProt_Finalize()
{

}

