//
//	Component.cpp
//		Author:HIROMASA IKEDA	DATE:2018/09/26
//===============================================
#include"Component.h"

//===============================================
//	グローバル変数
//===============================================
vector<Component*> Component::g_Index;

//===============================================
//	関数
//===============================================

//-------------------------------------
//	コンストラクタ
//-------------------------------------
Component::Component()
{
	this->g_Index.push_back(this);
}

