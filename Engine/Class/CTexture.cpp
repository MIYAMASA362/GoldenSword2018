//
//	CTexture.cpp
//		Author:HIROMASA IKEDA	DATE:2018/09/28
//===============================================
#include<d3dx9.h>
#include"Texture.h"
#include"CTexture.h"

//===============================================
//	Texture クラス
//===============================================

//-------------------------------------
//	Texture()
//-------------------------------------

Texture::Texture()
{
	Texture_index = 0;
	TexCoord = { 0,0 };
	TexScale = { 0,0 };
	Tex_Width = 0;
	Tex_Height = 0;
}

Texture::Texture(int Texture_index, TEXCOORD TexCoord, TEXSCALE TexScale)
{
	this->Texture_index = Texture_index;
	this->TexCoord = TexCoord;
	this->TexScale = TexScale;
	Tex_Width = Texture_GetWidth(Texture_index);
	Tex_Height = Texture_GetHeight(Texture_index);
}

//-------------------------------------
//	テクスチャの幅を取得
//-------------------------------------
int Texture::GetWidth()
{
	return Tex_Width;
}

//-------------------------------------
//	テクスチャの高さ取得
//-------------------------------------
int Texture::GetHeight()
{
	return Tex_Height;
}

//-------------------------------------
//	テクスチャのサイズ取得
//-------------------------------------
TEXSCALE Texture::GetTexScale()
{
	return{ Tex_Width,Tex_Height };
}