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
//	グローバル変数
//===============================================

//UI表示
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
//	初期化処理
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
//	前 更新処理
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
//	描画処理
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
//	後 処理
//=============================================================
void Main_UpdateEnd()
{

}

//=============================================================
//	終了処理
//=============================================================
void Main_Finalize(void)
{
	Player_Finalize();
}
