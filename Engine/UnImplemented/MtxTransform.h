//
//	MtxTransform.h
//		Author:HIROMASA IKEDA	DATE:2018/09/28
//===============================================
#pragma once
#ifndef MTXTRANSFORM_H
#define MTXTRANSFORM_H

#include<d3dx9.h>

//===============================================
//	クラス　
//===============================================

//-----------------------------------------------
//	行列クラス
//-----------------------------------------------
class MtxFormat
{
private:
	
public:
	D3DXMATRIX MtxWorld;					//ワールド変換行列
	D3DXMATRIX MtxTransform;				//位置
	D3DXMATRIX MtxRotation;					//回転
	MtxFormat(void);						//初期化
	void SetIdentity(void);					//全部単位化
	void SetIdentity(D3DXMATRIX* ReSetMtx);	//指定単位化
	void SetMatrix(void);					//デバイスへ登録
};

//===============================================
//	関数
//===============================================

void MtxTransformation_Initialize();
void MtxTransformation_Update();
void MtxTransformation_Render();
void MtxTransformation_Finalize();

#endif // !MATRIXTRANSFORM_H