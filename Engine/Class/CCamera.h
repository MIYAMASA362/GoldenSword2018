//
//	CCamera.h
//		Author:HIROMASA IKEDA	DATE:2018/10/16
//===============================================
//	変更者 Changed By
//		Name:	DATE:
//
//-----------------------------------------------

#pragma once
#ifndef CCAMERA_H
#define CCAMERA_H

//================================================
//	インクルード	include
//================================================
#include"common.h"
#include<d3dx9.h>

#include"Camera.h"
//Class
#include"CTransform.h"

//================================================
//	マクロ定義	define
//================================================


//================================================
//	列挙型		enum
//================================================


//================================================
//	構造体		struct/typedef
//================================================

//================================================
//	グローバル変数　global
//================================================

//================================================
//	クラス		class
//================================================

//-------------------------------------
//	Camera　クラス
//-------------------------------------
class Camera
{
private:
	static Camera* MainCamera;	//メインカメラ
public:

	static Camera* Get_Main();
	static bool Begin();		//描画開始

	D3DXVECTOR3 position;		//位置
	D3DXVECTOR3 at;				//視点
	D3DXVECTOR3 up;				//カメラ上

	Camera();
	Camera(D3DXVECTOR3 Position);
	Camera(D3DXVECTOR3 Position, D3DXVECTOR3 At);

 	virtual void Initialize();	//初期化
	virtual void Update();		//更新

	void Set_Main();			//メインカメラに設定

protected:

};


#endif