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
//	グローバル変数
//===============================================

//胴体
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

//アーマー
static ArmarObject Armar_01(
	&Transform
	(
		D3DXVECTOR3(0.0f, 1.0f, 0.0f),	//位置
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),	//サイズ
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),	//回転
		D3DCOLOR_RGBA(0, 0, 255, 255)	//色
	)
	//テクスチャ無し
);

//アーマー
static ArmarObject Armar_02(
	&Transform
	(
		D3DXVECTOR3(-1.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);

//アーマー
static ArmarObject Armar_03(
	&Transform
	(
		D3DXVECTOR3(1.0f, 1.0f, 0.0f),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DCOLOR_RGBA(0, 0, 255, 255)
	)
);
//ネジ
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
//	関数
//===============================================

//-------------------------------------
//	初期化
//-------------------------------------
void CTeamProt_Initialize()
{
	Screw.Set(&Armar_01, &Body);	//ネジに胴体とアーマーを設定
	Screw.Set(&Armar_02);			//ネジの胴体は決まっているので、アーマーだけ設定
	Screw.Set(&Armar_03);			//アーマー設定

}

//-------------------------------------
//	更新
//-------------------------------------
void CTeamProt_Update()
{
	ArmarObject::g_Update();	//アーマー更新
	CoreObject::g_Update();		//ネジ更新
}

//-------------------------------------
//	描画
//-------------------------------------
void CTeamProt_Render()
{
	//胴体
	Body.render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, GetModel_Cube(), sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);
	
	ArmarObject::g_Rednder();
	CoreObject::g_Render();
}

//-------------------------------------
//	終了
//-------------------------------------
void CTeamProt_Finalize()
{

}

