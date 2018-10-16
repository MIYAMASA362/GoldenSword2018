//
//	MtxTransform.cpp
//		Author:HIROMASA IKEDA	DATE:2018/09/28
//===============================================
#include<d3dx9.h>
#include<math.h>
#include"MtxTransform.h"
#include"System.h"
#include"input.h"
#include"Camera.h"
#include"Grid.h"

#include"Player.h"

//===============================================
//	マクロ定義
//===============================================

//===============================================
//	構造体
//===============================================

//===============================================
//	グローバル変数
//===============================================
static D3DXVECTOR3 CameraPos(CAMERA_POS);		//カメラ位置
static D3DXVECTOR3 CameraAt(CAMERA_AT);			//カメラ注視点
static D3DXVECTOR3 CameraUp(CAMERA_UP);			//カメラ上

//===============================================
//	初期化
//===============================================
void MtxTransformation_Initialize()
{
	Grid_Initialize();
}

//===============================================
//	更新処理
//===============================================
void MtxTransformation_Update()
{

	//------------------------------------
	//	カメラ
	//------------------------------------
	if(Keyboard_IsPress(DIK_LSHIFT))
	{
		//-----------------------------------
		//	注視点の移動
		//-----------------------------------
		if(Mouse_IsCenterDown())
		{
			CameraAt  += D3DXVECTOR3(Mouse_IsAccelerationX() *0.01f,	Mouse_IsAccelerationY() * 0.01f, Mouse_IsAccelerationZ() * 0.01f);
			CameraPos += D3DXVECTOR3(Mouse_IsAccelerationX() * 0.01f,	Mouse_IsAccelerationY() * 0.01f, Mouse_IsAccelerationZ() * 0.01f);
		}
	}
	else if (Mouse_IsCenterDown())
	{
		//-----------------------------------
		//	カメラ移動
		//-----------------------------------
		D3DXVECTOR3 Distance;
		Distance = CameraPos - CameraAt;
		float Angles = D3DXToRadian(Mouse_IsAccelerationX() * 0.1f);
		CameraPos.x = CameraAt.x + (Distance.x * cosf(Angles) - Distance.z * sinf(Angles));
		CameraPos.z = CameraAt.z + (Distance.x * sinf(Angles) + Distance.z * cosf(Angles));
		
		CameraPos.y += Mouse_IsAccelerationY() * 0.05f;
	}

	CameraPos = Player_GetPlayer()->Position;											// カメラ位置をプレイヤー座標に同期
	CameraAt = Player_GetPlayer()->Position + Player_GetPlayer()->vecDir * 5.0f;		// カメラ注視点をプレイヤー座標とプレイヤー視点方向から算出
	D3DXVECTOR3 vecDirSide(0.0f, 0.0f, 0.0f);											// 真横方向ベクトルワーク
	vecDirSide.x = Player_GetPlayer()->vecDir.z;										// 視点方向に垂直なベクトルを生成
	vecDirSide.z = -(Player_GetPlayer()->vecDir.x);										// 同上
	D3DXVec3Normalize(&vecDirSide, &vecDirSide);										// 単位ベクトル化
	D3DXVec3Cross(&CameraUp, &Player_GetPlayer()->vecDir, &vecDirSide);					// 外積により視点方向、真横方向ベクトルの両方に垂直なベクトルを生成（CameraUp）
	D3DXVec3Normalize(&CameraUp, &CameraUp);											// 単位ベクトル化

}

//===============================================
//	描画処理
//===============================================
void MtxTransformation_Render()
{
	Grid_Render();

	//------------------------------------
	//	ビュー変換行列
	//------------------------------------
	D3DXMATRIX mtxView;							//ビュー変換行列
	D3DXMatrixLookAtLH(&mtxView, &CameraPos, &CameraAt, &CameraUp);	//変換
	System_GetDevice()->SetTransform(D3DTS_VIEW, &mtxView);		//デバイスへ登録

	//------------------------------------
	//	プロジェクション変換行列
	//------------------------------------
	D3DXMATRIX mtxProjection;		//プロジェクション変換行列
	D3DXMatrixPerspectiveFovLH(&mtxProjection, D3DXToRadian(60), (float)WINDOWSCREEN_WIDTH / WINDOWSCREEN_HEIGHT, 0.1f, 100.0f);	//Fovは画角　変換
	System_GetDevice()->SetTransform(D3DTS_PROJECTION, &mtxProjection);	//デバイスへ登録

	System_GetDevice()->SetRenderState(D3DRS_LIGHTING, FALSE);	//ライティングをOFF
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
MTEXTRANSFORM::MTEXTRANSFORM()
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
void MTEXTRANSFORM::SetIdentity(void)
{
	//単位行列化
	D3DXMatrixIdentity(&MtxWorld);
	D3DXMatrixIdentity(&MtxTransform);
	D3DXMatrixIdentity(&MtxRotation);
}

void MTEXTRANSFORM::SetIdentity(D3DXMATRIX* ReSetMtx)
{
	D3DXMatrixIdentity(ReSetMtx);
}



