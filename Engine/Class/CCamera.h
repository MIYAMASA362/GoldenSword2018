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

//===============================================
//	マクロ定義	define
//===============================================


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
	D3DXVECTOR3 position;		//位置
	float Speed;				//移動速度

	D3DXVECTOR3 at;				//注視点
	D3DXVECTOR3 up;				//カメラ上
	D3DXVECTOR3 forward;		//カメラ前
	D3DXVECTOR3 right;			//カメラ右
	float atDistance;			//注視点までの距離
	float fov;					//画角

	Camera() :Camera(CAMERA_POS, CAMERA_AT, CAMERA_ATDISTANCE, CAMERA_FOV) {};
	Camera(D3DXVECTOR3 Position) : Camera(Position, CAMERA_AT, CAMERA_ATDISTANCE, CAMERA_FOV) {};
	Camera(D3DXVECTOR3 Position, D3DXVECTOR3 At, float AtDistance, float fov);

	static Camera* Get_Main();
	static bool Begin();		//描画開始
 	virtual void Initialize();	//初期化
	virtual void Update();		//更新
	void Set_Main();			//メインカメラに設定
};


#endif