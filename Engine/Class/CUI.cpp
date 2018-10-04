//
//	UI.cpp
//		Author:HIROMASA IKEDA		DATE:2018/08/28
//===============================================
#include<d3dx9.h>
#include"CUI.h"
#include"input.h"

//===============================================
//	UI クラス
//===============================================

//-------------------------------------
//	コンストラクタ
//-------------------------------------
UI::UI(Transform2* pTransform2, Texture* pTexture):Sprite(pTransform2, pTexture)
{
	
}

UI::UI(Transform2* pTransform2, Texture* pTexture, Animetion* pAnimetion): Sprite(pTransform2, pTexture, pAnimetion)
{
	
}

//-------------------------------------
//	Set()
//-------------------------------------
void UI::Set(Transform2* pTransform2)
{
	this->pTransform = pTransform2;
}

//-------------------------------------
//	Click()
//-------------------------------------
bool UI::Click()
{
	if (Hover() && Mouse_IsLeftDown())
	{
		return true;
	}
	return false;
}

//-------------------------------------
//	Hover
//-------------------------------------
bool UI::Hover()
{

	if (pTransform->Position.x - pTransform->Scale.x * 0.5f <= Mouse_IsMouseX() && Mouse_IsMouseX() <= pTransform->Position.x + pTransform->Scale.x * 0.5f)
	{
		if (pTransform->Position.y - pTransform->Scale.y * 0.5f <= Mouse_IsMouseY() && Mouse_IsMouseY() <= pTransform->Position.y + pTransform->Scale.x * 0.5f)
		{
			return true;
		}
	}

	return false;
}
