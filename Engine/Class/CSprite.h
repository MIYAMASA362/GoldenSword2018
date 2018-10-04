//
//	CSprite.h
//		Author:HIROMASA IEKDA	DATE:2018/10/01
//===============================================
#pragma once
#include<d3dx9.h>
#include"CTransform.h"
#include"CAnimetion.h"
#include"CRender.h"

//===============================================
//	Sprite クラス
//===============================================
class Sprite:public Render2D
{
private:

public:
	Transform2 transform;	//位置
	Texture texture;		//テクスチャ
	Animetion animetion;	//アニメーションステータス

	//コンストラクタ
	Sprite();
	Sprite(Transform2* pTransform2,Texture* pTexture);
	Sprite(Transform2* pTransform2,Texture* pTexture,Animetion* pAnimetion);

};


