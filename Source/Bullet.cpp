//
//	Bullet.cpp
//		Author:ハン	DATE:
//===============================================
//	変更者 Change by
//		Author:HIROMASA IKEDA DATE:2018/10/17
//
//-----------------------------------------------
#include <d3dx9.h>
#include "Bullet.h"
#include "common.h"
#include "System.h"

#include"Cube.h"

//===============================================
//	マクロ定義
//===============================================
#define BULLET_NORMAL_SPEED (0.1f)
#define BULLET_NORMAL_RADIUS (1)		//弾の半径
#define BULLET_COUNT (256)
#define BULLET_MAX (256)

//===============================================
//	構造体
//===============================================

//===============================================
//	グローバル変数
//===============================================
Bullet g_Bullet[BULLET_MAX];

//===============================================
//	関数
//===============================================

//-------------------------------------
//	初期化
//-------------------------------------
void Bullet_Initialize()
{
	for(int i = 0; i<BULLET_MAX; i++)
	{
		g_Bullet[i].transform.Scale = {0.5f,0.5f,0.5f};
	}
}

//-------------------------------------
//	更新
//-------------------------------------
void Bullet_Update()
{
	for(int i = 0; i< BULLET_MAX; i++)
	{
		if(g_Bullet[i].GetEnable())
		{
			g_Bullet[i].Update();
		}
	}
}

/*
	////弾の無効(画面外の場合
	//for (int i = 0; i < BULLET_COUNT; i++)
	//{
	//	if (Bullet[i].pos.x >= SCREEN_WIDTH || Bullet[i].pos.x <= -SCREEN_WIDTH || 
	//		Bullet[i].pos.y <= -SCREEN_HEIGHT || Bullet[i].pos.y >= SCREEN_HEIGHT ||
	//		Bullet[i].pos.z >=||Bullet[i].pos.z <=)				//判定条件がわからない
	//	{
	//		Bullet_Destroy(i);
	//	}
	//}
*/

//-------------------------------------
//	描画
//-------------------------------------
void Bullet_Render()
{
	for(int i = 0; i < BULLET_MAX; i++)
	{
		if(g_Bullet[i].GetEnable())
		{
			g_Bullet[i].render.Begin(FVF_CUBE_VERTEX3D, CUBE_PRIMITIVE_TYPE, GetModel_Cube(), sizeof(CubeVertex3D), CUBE_PRIMITIVE_NUM);
		}
	}
}

//-------------------------------------
//	生成
//-------------------------------------
void Bullet_Create(D3DXVECTOR3 position, D3DXVECTOR3 face, BULLET_TYPE type)
{
	for(int i= 0; i< BULLET_MAX; i++)
	{
		if(!g_Bullet[i].GetEnable())
		{
			g_Bullet[i].SetBullet(position,face,type);
			return;
		}
	}
}

//-------------------------------------
//	削除
//-------------------------------------
void Bullet_Destroy(int index)
{
	g_Bullet[index].DisEnable();
}

//-------------------------------------
//	有効か
//-------------------------------------
bool Bullet_IsEnable(int index)
{
	return g_Bullet[index].GetEnable();
}

ShapeSphere Bullet_ColShape(int index)
{
	return g_Bullet[index].ColSphape;
}


//===============================================
//	Bullet クラス
//===============================================

//-------------------------------------
//	コンストラクタ
//-------------------------------------
Bullet::Bullet():ColSphape(this->transform.Position,1)
{
	IsEnable = false;
}

Bullet::Bullet(Transform* pTransform, Texture* pTexture):GameObject(pTransform,pTexture),ColSphape(pTransform->Position,1.0f)
{
	type = BULLET_NORMAL;
	Bullet();
}

//-------------------------------------
//	弾のタイプ設定
//-------------------------------------
void Bullet::TypeSet(BULLET_TYPE tyep)
{
	this->type = type;
}

//-------------------------------------
//	更新処理
//-------------------------------------
void Bullet::Update()
{
	ColSphape.Pos = this->transform.Position;

	switch (this->type)
	{
	case BULLET_NORMAL:
		this->transform.Position += this->face * BULLET_NORMAL_SPEED;
		break;
	default:
		break;
	}
}

//-------------------------------------
//	Enable取得
//-------------------------------------
bool Bullet::GetEnable()
{
	return this->IsEnable;
}

//--------------------------------------
//	弾を設定
//--------------------------------------
void Bullet::SetBullet(D3DXVECTOR3 position, D3DXVECTOR3 face, BULLET_TYPE type)
{
	D3DXVec3Normalize(&face,&face);		//単位化

	this->transform.Position = position;
	this->face = face;
	this->type = type;
	this->IsEnable = true;
}

//-------------------------------------
//	弾を無効化
//-------------------------------------
void Bullet::DisEnable()
{
	this->IsEnable = false;
}

