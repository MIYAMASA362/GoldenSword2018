//
//	Camera.h
//		Author:HIROMASA IEKDA	DATE:2018/09/28
//===============================================
#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include<d3dx9.h>

#define CAMERA_POS (D3DXVECTOR3(0.0f, 5.0f, 0.0f))	//カメラ位置
#define CAMERA_AT (D3DXVECTOR3(0.0f, 0.0f, 0.0f))		//カメラの注視点
#define CAMERA_UP (D3DXVECTOR3(0.0f,1.0f,0.0f))			//カメラの上方向 (どういう捩れで見るの？)

#define CAMERA_NEAR (0.1f)
#define CAMERA_WAR (100.0f)

#define SCREEN_ASPECT ((float)WINDOWSCREEN_WIDTH / WINDOWSCREEN_HEIGHT)
#define CAMERA_FOV (D3DXToRadian(60))

#endif // !CAMERA_H

