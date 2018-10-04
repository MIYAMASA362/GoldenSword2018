//
//	CRender.h
//		Author:HIROMASA IKEDA	DATE:2018/09/29
//===============================================
#pragma once
#ifndef CRENDER_H
#define CRENDER_H

#include<d3dx9.h>
#include"CTransform.h"
#include"CTexture.h"
#include"CAnimetion.h"

//===============================================
//	��
//===============================================

//-------------------------------------
//	�`��^�C�v	�X�v���C�g
//-------------------------------------
typedef enum RENDER2D_TYPE
{
	R2D_PORIGON,
	R2D_RORIGON_ROTATE,
	R2D_TEXTURE_SIZE,
	R2D_TEXTURE_FILL,
	R2D_TEXTURE_CLIP,
	R2D_SPRITE,
	R2D_SPRITE_ROTATE
}RENDER2D_TYPE;

//-------------------------------------
//	�`��^�C�v	�X�v���C�g�A�j���[�V����
//-------------------------------------
typedef enum RENDER2DANIME_TYPE
{
	R2DA_NOLOOP,
	R2DA_LOOP,
	R2DA_LOOP_ROTATE
}RENDER2DANIME_TYPE;

//===============================================
//	�N���X
//===============================================

//-------------------------------------
//	Render
//-------------------------------------
class Render
{
private:

public:
	Transform* pTransform;
	Texture* pTexture;

	//�R���X�g���N�^
	Render();
	Render(Transform* pTransform, Texture* pTexture);

	bool Begin(DWORD SetFVF, D3DPRIMITIVETYPE PrimitiveType, void* Model, UINT DataSize, UINT PrimitiveCount);	//�`��J�n
};
typedef Render Render3D;

//-------------------------------------
//	Render2D
//-------------------------------------
class Render2D
{
private:

public:
	Transform2* pTransform;
	Texture*	pTexture;
	Animetion*	pAnimetion;

	//�R���X�g���N�^
	Render2D();
	Render2D(Transform2* pTransform, Texture* pTexture);
	Render2D(Transform2* pTransform, Texture* pTexture, Animetion* pAnimetion);

	bool Begin(RENDER2D_TYPE R2D_TYPE);
	bool Begin(RENDER2DANIME_TYPE R2DA_TYPE);
};

#endif // !CRENDER_H
