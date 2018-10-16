//
//	CRender.cpp
//		Author:HIROMASA IKEDA	DATE:2018/09/29
//===============================================
#include<d3dx9.h>
#include<math.h>

#include"CTransform.h"
#include"CRender.h"
#include"System.h"
#include"Texture.h"
#include"Sprite.h"
#include"Animation.h"

//===============================================
//	Render�@�N���X
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
Render::Render()
{
	pTransform = NULL;
	pTexture = NULL;
}

//-------------------------------------
//	�R���X�g���N�^	�|�C���^�^
//-------------------------------------
Render::Render(Transform* pTransform, Texture* pTexture)
{
	this->pTransform = pTransform;
	this->pTexture = pTexture;
}

//-------------------------------------
//	�`��
//-------------------------------------
bool Render::Begin(DWORD SetFVF, D3DPRIMITIVETYPE PrimitiveType, void* Model, UINT DataSize, UINT PrimitiveCount)
{
	if (pTransform == NULL) return false;

	D3DXMATRIX MtxWorld;
	D3DXMatrixIdentity(&MtxWorld);

	D3DXMATRIX MtxTransform;
	D3DXMatrixTranslation(&MtxTransform, pTransform->Position.x, pTransform->Position.y, pTransform->Position.z);

	D3DXMATRIX MtxScale;
	D3DXMatrixIdentity(&MtxScale);
	D3DXMatrixScaling(&MtxScale, pTransform->Scale.x, pTransform->Scale.y, pTransform->Scale.z);

	D3DXMATRIX MtxRotate;
	D3DXMatrixIdentity(&MtxRotate);
	D3DXMatrixRotationYawPitchRoll(&MtxRotate,pTransform->Rotation.y,pTransform->Rotation.x,pTransform->Rotation.z);

	MtxWorld *= MtxScale  * MtxRotate * MtxTransform;

	System_GetDevice()->SetTransform(D3DTS_WORLD, &MtxWorld);	//�f�o�C�X�֓o�^
	System_GetDevice()->SetFVF(SetFVF);

	if (pTexture == NULL || pTexture->Texture_index == TEXTURE_NONE)
	{
		System_GetDevice()->SetTexture(0, NULL);
	}
	else
	{
		System_GetDevice()->SetTexture(0, Texture_GetTexture(pTexture->Texture_index));
	}
	System_GetDevice()->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, Model, DataSize);

	return true;
}

//===============================================
//	Render2D �N���X
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
Render2D::Render2D()
{
	pTransform = NULL;
	pTexture = NULL;
	pAnimation = NULL;
}

//-------------------------------------
//	�R���X�g���N�^	�|�C���^�^
//-------------------------------------
Render2D::Render2D(Transform2* pTransform, Texture* pTexture)
{
	this->pTransform = pTransform;
	this->pTexture = pTexture;
	pAnimation = NULL;
}

Render2D::Render2D(Transform2* pTransform, Texture* pTexture, Animation* pAnimation)
{
	this->pTransform = pTransform;
	this->pTexture = pTexture;
	this->pAnimation = pAnimation;
}

//-------------------------------------
//	�`��@�X�v���C�g
//-------------------------------------
bool Render2D::Begin(RENDER2D_TYPE R2D_TYPE)
{
	if (pTransform == NULL || pTexture == NULL) return false;

	switch (R2D_TYPE)
	{
	case R2D_PORIGON:
		Render2D_Porigon(pTransform);
		break;
	case R2D_RORIGON_ROTATE:
		Render2D_Porigon_Rotate(pTransform);
		break;
	case R2D_TEXTURE_SIZE:
		Render2D_Texture_Size(pTransform, pTexture);
		break;
	case R2D_TEXTURE_FILL:
		Render2D_Texture_Fill(pTransform, pTexture);
		break;
	case R2D_TEXTURE_CLIP:
		Render2D_Texture_Clip(pTransform, pTexture);
		break;
	case R2D_SPRITE:
		Render2D_Sprite(pTransform, pTexture);
		break;
	case R2D_SPRITE_ROTATE:
		Render2D_Sprite_Rotate(pTransform, pTexture);
		break;
	default:
		return false;
	}

	return true;
}

//-------------------------------------
//	�`��@�X�v���C�g�A�j���[�V����
//-------------------------------------
bool Render2D::Begin(RENDER2DANIMA_TYPE R2DA_TYPE)
{
	if (pTransform == NULL || pTexture == NULL || pAnimation == NULL) return false;

	switch (R2DA_TYPE)
	{
	case R2DA_NOLOOP:
		Animation_NoLoop(pTransform, pTexture, pAnimation);
		break;
	case R2DA_LOOP:
		Animation_Loop(pTransform, pTexture, pAnimation);
		break;
	case R2DA_LOOP_ROTATE:
		Animation_Loop_Rotate(pTransform, pTexture, pAnimation);
		break;
	default:
		return false;
	}

	return true;
}




