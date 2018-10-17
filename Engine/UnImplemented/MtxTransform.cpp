//
//	MtxTransform.cpp
//		Author:HIROMASA IKEDA	DATE:2018/10/16
//===============================================
#include<d3dx9.h>
#include<math.h>
#include"common.h"

#include"MtxTransform.h"

#include"input.h"
#include"Camera.h"
#include"Grid.h"

#include"Player.h"

//Class
#include"CCamera.h"

//===============================================
//	マクロ定義
//===============================================

//===============================================
//	構造体
//===============================================

//===============================================
//	グローバル変数
//===============================================
static Camera g_Camera;							//カメラ

//===============================================
//	初期化
//===============================================
void MtxTransformation_Initialize()
{
	Grid_Initialize();

	g_Camera.Set_Main();
}

//===============================================
//	更新処理
//===============================================
void MtxTransformation_Update()
{
	g_Camera.Update();
}

//===============================================
//	描画処理
//===============================================
void MtxTransformation_Render()
{
	Grid_Render();

	Camera::Begin();
}

//===============================================
//　終了処理
//===============================================
void MtxTransformation_Finalize()
{

}

//===============================================
//	クラス
//===============================================

//-------------------------------------
//	コンストラクタ
//-------------------------------------
MtxFormat::MtxFormat()
{
	//単位行列化
	D3DXMatrixIdentity(&MtxWorld);
	D3DXMatrixIdentity(&MtxTransform);
	D3DXMatrixIdentity(&MtxRotation);
	System_GetDevice()->SetTransform(D3DTS_WORLD, &MtxWorld);		//デバイスへ登録
}

//-------------------------------------
//	SetIdentity()
//-------------------------------------
void MtxFormat::SetIdentity(void)
{
	//単位行列化
	D3DXMatrixIdentity(&MtxWorld);
	D3DXMatrixIdentity(&MtxTransform);
	D3DXMatrixIdentity(&MtxRotation);
}

void MtxFormat::SetIdentity(D3DXMATRIX* ReSetMtx)
{
	D3DXMatrixIdentity(ReSetMtx);
}



