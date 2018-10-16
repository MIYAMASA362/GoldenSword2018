//
//	Main.cpp
//		Author:HIROMASA IKEDA		Date:2018/09/13
//================================================
#include"common.h"
#include"System.h"
#include"input.h"
#include"Texture.h"
#include"Fade.h"
#include"FileData.h"
#include"Sprite.h"

#include"Cube.h"
#include"MtxTransform.h"
#include"Lighting.h"

#include"CTeamProt.h"
#include"Player.h"
#include"Bullet.h"

//Class
#include"CUI.h"

#define VECTOR3_ONE (D3DXVECTOR3(1.0f,1.0f,1.0f))
#define VECTOR3(x)  (D3DXVECTOR3(x,x,x))

//===============================================
//	�O���[�o���ϐ�
//===============================================

//UI�\��
static UI uiSprite(
	&Transform2
	(
		D3DXVECTOR2(60.0f, 60.0f),
		D3DXVECTOR2(100.0f, 100.0f),
		0,
		D3DCOLOR_RGBA(255, 255, 0, 255)
	),
	&Texture
	(
		CubeTexture,
		{ 0,0 },
		{ 256,256 }
	)
);

//=============================================================
//	����������
//=============================================================
void Main_Initialize(void)
{
	MtxTransformation_Initialize();
	Lighting_Initialize();

	CTeamProt_Initialize();
	Bullet_Init();
	Player_Initialize();

	uiSprite = uiSprite;
}

//=============================================================
//	�O �X�V����
//=============================================================
void Main_UpdateBegin(void)
{
	MtxTransformation_Update();
	Cube_Update();

	CTeamProt_Update();
	Bullet_Update();
	Player_Update();
}

//=============================================================
//	�`�揈��
//=============================================================
void Main_Render(void)
{
	
	MtxTransformation_Render();
	Cube_Render();
	CTeamProt_Render();
	uiSprite.Begin(R2D_SPRITE_ROTATE);
	Bullet_Draw();
	Player_Render();
}


//=============================================================
//	�� ����
//=============================================================
void Main_UpdateEnd()
{

}

//=============================================================
//	�I������
//=============================================================
void Main_Finalize(void)
{
	Player_Finalize();
}
