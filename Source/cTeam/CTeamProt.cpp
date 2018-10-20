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
//	グローバル変数
//===============================================
static Camera g_Camera;							//カメラ

//胴体
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

//アーマー
static ArmarObject Armar_10(
	&Transform
	(
		D3DXVECTOR3(0.0f, 1.0f, 0.0f),	//位置
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//サイズ
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//回転
		D3DCOLOR_RGBA(255, 0,0, 255)	//色
	)
	//テクスチャ無し
);

//アーマー
static ArmarObject Armar_11(
	&Transform
	(
		D3DXVECTOR3(-1.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255,0, 255)
	)
);

//アーマー
static ArmarObject Armar_12(
	&Transform
	(
		D3DXVECTOR3(1.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//ネジ
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

//胴体
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

//アーマー
static ArmarObject Armar_20(
	&Transform
	(
		D3DXVECTOR3(3.0f, 1.0f, 0.0f),	//位置
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//サイズ
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//回転
		D3DCOLOR_RGBA(255, 0, 0, 255)	//色
	)
	//テクスチャ無し
);

//アーマー
static ArmarObject Armar_21(
	&Transform
	(
		D3DXVECTOR3(2.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255, 0, 255)
	)
);

//アーマー
static ArmarObject Armar_22(
	&Transform
	(
		D3DXVECTOR3(4.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//ネジ
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

//胴体
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

//アーマー
static ArmarObject Armar_30(
	&Transform
	(
		D3DXVECTOR3(-3.0f, 1.0f, 0.0f),	//位置
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//サイズ
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//回転
		D3DCOLOR_RGBA(255, 0, 0, 255)	//色
	)
	//テクスチャ無し
);

//アーマー
static ArmarObject Armar_31(
	&Transform
	(
		D3DXVECTOR3(-4.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255, 0, 255)
	)
);

//アーマー
static ArmarObject Armar_32(
	&Transform
	(
		D3DXVECTOR3(-2.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//ネジ
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

//胴体
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

//アーマー
static ArmarObject Armar_40(
	&Transform
	(
		D3DXVECTOR3(0.0f, 4.0f, 0.0f),	//位置
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//サイズ
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//回転
		D3DCOLOR_RGBA(255, 0, 0, 255)	//色
	)
	//テクスチャ無し
);

//アーマー
static ArmarObject Armar_41(
	&Transform
	(
		D3DXVECTOR3(-1.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255, 0, 255)
	)
);

//アーマー
static ArmarObject Armar_42(
	&Transform
	(
		D3DXVECTOR3(1.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//ネジ
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

//胴体
static BodyObject Body_05(
	&Transform
	(
		D3DXVECTOR3(3.0f, 3.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 0, 255)	//色
	),
	&Texture
	(
		TEXTURE_NONE,
		{ 0,0 },
		{ 0,0 }
	)
);

//アーマー
static ArmarObject Armar_50(
	&Transform
	(
		D3DXVECTOR3(3.0f, 4.0f, 0.0f),	//位置
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//サイズ
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//回転
		D3DCOLOR_RGBA(0, 0, 255, 255)	//色
	)
	//テクスチャ無し
);

//アーマー
static ArmarObject Armar_51(
	&Transform
	(
		D3DXVECTOR3(2.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255, 0, 255)
	)
);

//アーマー
static ArmarObject Armar_52(
	&Transform
	(
		D3DXVECTOR3(4.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//ネジ
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

//胴体
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

//アーマー
static ArmarObject Armar_60(
	&Transform
	(
		D3DXVECTOR3(-3.0f, 4.0f, 0.0f),	//位置
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//サイズ
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//回転
		D3DCOLOR_RGBA(255, 0, 0, 255)	//色
	)
	//テクスチャ無し
);

//アーマー
static ArmarObject Armar_61(
	&Transform
	(
		D3DXVECTOR3(-4.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 255, 0, 255)
	)
);

//アーマー
static ArmarObject Armar_62(
	&Transform
	(
		D3DXVECTOR3(-2.0f, 4.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//ネジ
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
//	関数
//===============================================

//-------------------------------------
//	初期化
//-------------------------------------
void CTeamProt_Initialize()
{
	Screw_01.Set(&Armar_10, &Body_01);	//ネジに胴体とアーマーを設定
	Screw_01.Set(&Armar_11);			//ネジの胴体は決まっているので、アーマーだけ設定
	Screw_01.Set(&Armar_12);			//アーマー設定

	Screw_02.Set(&Armar_20, &Body_02);	//ネジに胴体とアーマーを設定
	Screw_02.Set(&Armar_21);			//ネジの胴体は決まっているので、アーマーだけ設定
	Screw_02.Set(&Armar_22);			//アーマー設定

	Screw_03.Set(&Armar_30, &Body_03);	//ネジに胴体とアーマーを設定
	Screw_03.Set(&Armar_31);			//ネジの胴体は決まっているので、アーマーだけ設定
	Screw_03.Set(&Armar_32);			//アーマー設定

	Screw_04.Set(&Armar_40, &Body_04);	//ネジに胴体とアーマーを設定
	Screw_04.Set(&Armar_41);			//ネジの胴体は決まっているので、アーマーだけ設定
	Screw_04.Set(&Armar_42);			//アーマー設定

	Screw_05.Set(&Armar_50, &Body_05);	//ネジに胴体とアーマーを設定
	Screw_05.Set(&Armar_51);			//ネジの胴体は決まっているので、アーマーだけ設定
	Screw_05.Set(&Armar_52);			//アーマー設定

	Screw_06.Set(&Armar_60, &Body_06);	//ネジに胴体とアーマーを設定
	Screw_06.Set(&Armar_61);			//ネジの胴体は決まっているので、アーマーだけ設定
	Screw_06.Set(&Armar_62);			//アーマー設定
	DebugBufferManager::Init();

	Grid_Initialize();
	g_Camera.Set_Main();
}

//-------------------------------------
//	更新
//-------------------------------------
void CTeamProt_Update()
{
	GameObject::g_Update();
	g_Camera.Update();
}

//-------------------------------------
//	描画
//-------------------------------------
void CTeamProt_Render()
{
	//GameObject::g_Render();

	Grid_Render();

	Camera::Begin();
	
}

//-------------------------------------
//	終了
//-------------------------------------
void CTeamProt_Finalize()
{

}

