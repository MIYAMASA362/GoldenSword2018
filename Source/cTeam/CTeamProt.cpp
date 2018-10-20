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
#include"Grid.h"

//Class
#include"CArmorObject.h"
#include"CCoreObject.h"
#include"CBodyObject.h"
#include"CCamera.h"

#include "Debug_Sphere.h"
//===============================================
//	�O���[�o���ϐ�
//===============================================
static Camera g_Camera;							//�J����

//����
static BodyObject Body_01(
	&Transform
	(
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 0, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//�A�[�}�[
static ArmarObject Armar_10(
	&Transform
	(
		D3DXVECTOR3(0.0f, 1.0f, 0.0f),	//�ʒu
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//�T�C�Y
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//��]
		D3DCOLOR_RGBA(255, 0,0, 255)	//�F
	)
	//�e�N�X�`������
);

//�A�[�}�[
static ArmarObject Armar_11(
	&Transform
	(
		D3DXVECTOR3(-1.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255,0, 255)
	)
);

//�A�[�}�[
static ArmarObject Armar_12(
	&Transform
	(
		D3DXVECTOR3(1.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//�l�W
static CoreObject Screw_01
(
	&Transform
	(
		D3DXVECTOR3(0.0f, 0.5f, 0.5f),
		D3DXVECTOR3(1.0f, 0.5f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(100, 100, 100, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//����
static BodyObject Body_02(
	&Transform
	(
		D3DXVECTOR3(3.0f, 0.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 0, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//�A�[�}�[
static ArmarObject Armar_20(
	&Transform
	(
		D3DXVECTOR3(3.0f, 1.0f, 0.0f),	//�ʒu
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//�T�C�Y
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//��]
		D3DCOLOR_RGBA(255, 0, 0, 255)	//�F
	)
	//�e�N�X�`������
);

//�A�[�}�[
static ArmarObject Armar_21(
	&Transform
	(
		D3DXVECTOR3(2.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255, 0, 255)
	)
);

//�A�[�}�[
static ArmarObject Armar_22(
	&Transform
	(
		D3DXVECTOR3(4.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//�l�W
static CoreObject Screw_02
(
	&Transform
	(
		D3DXVECTOR3(3.0f, 0.5f, 0.5f),
		D3DXVECTOR3(1.0f, 0.5f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(100, 100, 100, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//����
static BodyObject Body_03(
	&Transform
	(
		D3DXVECTOR3(-3.0f, 0.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 0, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//�A�[�}�[
static ArmarObject Armar_30(
	&Transform
	(
		D3DXVECTOR3(-3.0f, 1.0f, 0.0f),	//�ʒu
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//�T�C�Y
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//��]
		D3DCOLOR_RGBA(255, 0, 0, 255)	//�F
	)
	//�e�N�X�`������
);

//�A�[�}�[
static ArmarObject Armar_31(
	&Transform
	(
		D3DXVECTOR3(-4.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255, 0, 255)
	)
);

//�A�[�}�[
static ArmarObject Armar_32(
	&Transform
	(
		D3DXVECTOR3(-2.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//�l�W
static CoreObject Screw_03
(
	&Transform
	(
		D3DXVECTOR3(-3.0f, 0.5f, 0.5f),
		D3DXVECTOR3(1.0f, 0.5f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(100, 100, 100, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//����
static BodyObject Body_04(
	&Transform
	(
		D3DXVECTOR3(0.0f, 3.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 0, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//�A�[�}�[
static ArmarObject Armar_40(
	&Transform
	(
		D3DXVECTOR3(0.0f, 4.0f, 0.0f),	//�ʒu
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//�T�C�Y
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//��]
		D3DCOLOR_RGBA(255, 0, 0, 255)	//�F
	)
	//�e�N�X�`������
);

//�A�[�}�[
static ArmarObject Armar_41(
	&Transform
	(
		D3DXVECTOR3(-1.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255, 0, 255)
	)
);

//�A�[�}�[
static ArmarObject Armar_42(
	&Transform
	(
		D3DXVECTOR3(1.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//�l�W
static CoreObject Screw_04
(
	&Transform
	(
		D3DXVECTOR3(0.0f, 3.5f, 0.5f),
		D3DXVECTOR3(1.0f, 0.5f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(100, 100, 100, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//����
static BodyObject Body_05(
	&Transform
	(
		D3DXVECTOR3(3.0f, 3.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 0, 255)	//�F
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//�A�[�}�[
static ArmarObject Armar_50(
	&Transform
	(
		D3DXVECTOR3(3.0f, 4.0f, 0.0f),	//�ʒu
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//�T�C�Y
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//��]
		D3DCOLOR_RGBA(0, 0, 255, 255)	//�F
	)
	//�e�N�X�`������
);

//�A�[�}�[
static ArmarObject Armar_51(
	&Transform
	(
		D3DXVECTOR3(2.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255, 0, 255)
	)
);

//�A�[�}�[
static ArmarObject Armar_52(
	&Transform
	(
		D3DXVECTOR3(4.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//�l�W
static CoreObject Screw_05
(
	&Transform
	(
		D3DXVECTOR3(3.0f, 3.5f, 0.5f),
		D3DXVECTOR3(1.0f, 0.5f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(100, 100, 100, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//����
static BodyObject Body_06(
	&Transform
	(
		D3DXVECTOR3(-3.0f, 3.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 0, 255)
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//�A�[�}�[
static ArmarObject Armar_60(
	&Transform
	(
		D3DXVECTOR3(-3.0f, 4.0f, 0.0f),	//�ʒu
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//�T�C�Y
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//��]
		D3DCOLOR_RGBA(255, 0, 0, 255)	//�F
	)
	//�e�N�X�`������
);

//�A�[�}�[
static ArmarObject Armar_61(
	&Transform
	(
		D3DXVECTOR3(-4.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255, 0, 255)
	)
);

//�A�[�}�[
static ArmarObject Armar_62(
	&Transform
	(
		D3DXVECTOR3(-2.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//�l�W
static CoreObject Screw_06
(
	&Transform
	(
		D3DXVECTOR3(-3.0f, 3.5f, 0.5f),
		D3DXVECTOR3(1.0f, 0.5f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(100,100,100, 255)
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
	Screw_01.Set(&Armar_10, &Body_01);	//�l�W�ɓ��̂ƃA�[�}�[��ݒ�
	Screw_01.Set(&Armar_11);			//�l�W�̓��̂͌��܂��Ă���̂ŁA�A�[�}�[�����ݒ�
	Screw_01.Set(&Armar_12);			//�A�[�}�[�ݒ�

	Screw_02.Set(&Armar_20, &Body_02);	//�l�W�ɓ��̂ƃA�[�}�[��ݒ�
	Screw_02.Set(&Armar_21);			//�l�W�̓��̂͌��܂��Ă���̂ŁA�A�[�}�[�����ݒ�
	Screw_02.Set(&Armar_22);			//�A�[�}�[�ݒ�

	Screw_03.Set(&Armar_30, &Body_03);	//�l�W�ɓ��̂ƃA�[�}�[��ݒ�
	Screw_03.Set(&Armar_31);			//�l�W�̓��̂͌��܂��Ă���̂ŁA�A�[�}�[�����ݒ�
	Screw_03.Set(&Armar_32);			//�A�[�}�[�ݒ�

	Screw_04.Set(&Armar_40, &Body_04);	//�l�W�ɓ��̂ƃA�[�}�[��ݒ�
	Screw_04.Set(&Armar_41);			//�l�W�̓��̂͌��܂��Ă���̂ŁA�A�[�}�[�����ݒ�
	Screw_04.Set(&Armar_42);			//�A�[�}�[�ݒ�

	Screw_05.Set(&Armar_50, &Body_05);	//�l�W�ɓ��̂ƃA�[�}�[��ݒ�
	Screw_05.Set(&Armar_51);			//�l�W�̓��̂͌��܂��Ă���̂ŁA�A�[�}�[�����ݒ�
	Screw_05.Set(&Armar_52);			//�A�[�}�[�ݒ�

	Screw_06.Set(&Armar_60, &Body_06);	//�l�W�ɓ��̂ƃA�[�}�[��ݒ�
	Screw_06.Set(&Armar_61);			//�l�W�̓��̂͌��܂��Ă���̂ŁA�A�[�}�[�����ݒ�
	Screw_06.Set(&Armar_62);			//�A�[�}�[�ݒ�
	DebugBufferManager::Init();

	Grid_Initialize();
	g_Camera.Set_Main();
}

//-------------------------------------
//	�X�V
//-------------------------------------
void CTeamProt_Update()
{
	GameObject::g_Update();
	g_Camera.Update();
}

//-------------------------------------
//	�`��
//-------------------------------------
void CTeamProt_Render()
{
	//GameObject::g_Render();

	Grid_Render();

	Camera::Begin();
	
}

//-------------------------------------
//	�I��
//-------------------------------------
void CTeamProt_Finalize()
{

}

