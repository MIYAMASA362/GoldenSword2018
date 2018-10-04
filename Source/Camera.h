//
//	Camera.h
//		Author:HIROMASA IEKDA	DATE:2018/09/28
//===============================================
#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include<d3dx9.h>

#define CAMERA_POS (D3DXVECTOR3(5.0f, 15.0f, -8.0f))	//カメラ位置
#define CAMERA_AT (D3DXVECTOR3(0.0f, 0.0f, 0.0f))		//カメラの注視点
#define CAMERA_UP (D3DXVECTOR3(0.0f,1.0f,0.0f))			//カメラの上方向 (どういう捩れで見るの？)

#endif // !CAMERA_H

