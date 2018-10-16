//
//	Component.h
//		Author:HIROMASA IKEDA	DATE:2018/09/26
//===============================================
//
//	今後使うかも
//
//-----------------------------------------------
#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include<d3dx9.h>
#include<vector>

using namespace std;

//===============================================
//	Component クラス
//===============================================
class Component 
{
private:
	
public:
	static vector<Component*> g_Index;	//インデックス

	static void g_Begin();				//処理		開始

	static void g_Initialize();			//初期化	開始
	static void g_BeginUpdate();		//前更新	開始
	static void g_Render();				//描画		開始
	static void g_EndUpdate();			//後更新	開始
	static void g_UnInitialize();		//終了処理	開始

protected:
	virtual void Initialize()	PURE;	//初期化
	virtual void BeginUpdate()	PURE;	//前更新
	virtual void EndUpdate()	PURE;	//後更新
	virtual void Render()		PURE;	//描画
	virtual void UnInitialize() PURE;	//終了
};

#endif // !COMPONENT_H

