//
//	Player.cpp
//		Author:YU NISHIMAKI	DATE:2018/10/13
//===============================================
#include<d3dx9.h>
#include"joycon_input.h"
#include"Debug_font.h"
#include"Player.h"

//===============================================
//	マクロ定義
//===============================================
#define PLAYER_MOVE_SPEED		(0.1f)				// プレイヤー移動速度
#define PLAYER_ROT_FAST_Y		(6.0f)				// プレイヤーのY軸周りの視点移動速度(高速)
#define PLAYER_ROT_SLOW_Y		(2.0f)				// プレイヤーのY軸周りの視点移動速度(低速)


//===============================================
//	グローバル変数
//===============================================
PLAYER g_Player;

//===============================================
//	初期化
//===============================================
void Player_Initialize(void)
{
	g_Player.Position = D3DXVECTOR3(0.0f, 1.0f, 0.0f);		// プレイヤー座標ベクトル
	g_Player.Verocity = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// プレイヤー速度ベクトル
	g_Player.vecDir = D3DXVECTOR3(0.0f, 0.0f, 1.0f);		// プレイヤー視点方向ベクトル
	g_Player.AngleY = 0.0f;									// コントローラ左右回転角	
	g_Player.AngleX = 0.0f;									// コントローラ上下回転角
}

//===============================================
//	更新
//===============================================
void Player_Update(void)
{
	// 移動
	D3DXVECTOR3 vecDirMove(0.0f, 0.0f, 0.0f);						// 移動方向ベクトルワーク

	vecDirMove.x = (float)JoyconInput_GetLeftStickX();				// Joy-Conのスティック入力を取得
	vecDirMove.z = (float)JoyconInput_GetLeftStickY();				// Joy-Conのスティック入力を取得
	D3DXVec3Normalize(&vecDirMove, &vecDirMove);					// vecDirの単位ベクトル化
	
	D3DXVECTOR3 vecDirForword = g_Player.vecDir;					// プレイヤーの移動方向取得
	vecDirForword.y = 0.0f;											// Y成分を0にしてXY平面に投射
	D3DXVec3Normalize(&vecDirForword, &vecDirForword);				// 単位ベクトル化

	D3DXMATRIX mtxRotationMove;										// 移動方向回転用マトリクス
	D3DXMatrixRotationY(&mtxRotationMove, atan2f(vecDirForword.x, vecDirForword.z));	// プレイヤーの移動方向に合わせて回転角を設定
	D3DXVec3TransformNormal(&vecDirMove, &vecDirMove, &mtxRotationMove);	// 回転を適用

	vecDirMove *= PLAYER_MOVE_SPEED;								// 移動速度を設定

	g_Player.Position += vecDirMove;								// プレイヤー座標に加算して反映


	// 視点変更
	g_Player.AngleY += JoyconInput_GetAVYaw() / 100.0f / 24;		// Joy-Conのヨー角速度を取得して加算
	g_Player.AngleX += JoyconInput_GetAVPitch() / 100.0f / 24;		// Joy-Conのピッチ角速度を取得して加算

	if (JoyconInput_IsTrigger(JOYCON_BUTTON_INDEX_R_ZR))			// ZRボタン入力でカメラリセット
	{
		Player_ResetAngle();
	}

	// 視点横回転移動
	D3DXVECTOR3 vecDir = g_Player.vecDir;							// 視点方向ベクトルワーク
	vecDir.y = 0.0f;												// Y成分を0に
	D3DXVec3Normalize(&vecDir, &vecDir);							// 単位ベクトル化

	float RotY = 0.0f;												// Y軸周りの回転角ワーク
	
	// プレイヤーの回転角に応じてカメラ回転速度調整
	RotY = g_Player.AngleY / 40;

	D3DXMATRIX mtxRotationY;										// ベクトル回転用マトリクス
	D3DXMatrixRotationY(&mtxRotationY, D3DXToRadian(RotY));			// 回転角分Y軸周りに回転するマトリクスを設定

	D3DXVec3TransformNormal(&vecDir, &vecDir, &mtxRotationY);		// 視点方向をY軸周りに回転
	D3DXVec3Normalize(&vecDir, &vecDir);							// 単位ベクトル化


	// 視点上下方向移動
	D3DXVECTOR3 VecDirSide(0.0f, 0.0f, 0.0f);						// 真横方向ベクトルワーク（回転軸用）
	VecDirSide.x = -vecDir.z;										// Y成分0で垂直なベクトルを設定
	VecDirSide.z = vecDir.x;
	D3DXVec3Normalize(&VecDirSide, &VecDirSide);					// 単位ベクトル化
	D3DXMATRIX mtxRotationAxis;										// 任意軸周りに回転する用のマトリクス
	float RotAxis = g_Player.AngleX / 1.2f;							// 回転角をプレイヤーの上下角から設定
	if (g_Player.AngleX > 80.0f)									// 上下方向の回転に上限を設ける
		RotAxis = 80.0f;
	else if (g_Player.AngleX < -80.0f)
		RotAxis = -80.0f;

	D3DXMatrixRotationAxis(&mtxRotationAxis, &VecDirSide,D3DXToRadian(RotAxis));	// 真横方向ベクトル周り（すなわち上下方向）に視点方向を回転させるマトリクスを設定

	D3DXVec3TransformNormal(&vecDir, &vecDir, &mtxRotationAxis);	// 回転を適用
	D3DXVec3Normalize(&vecDir, &vecDir);							// 単位ベクトル化

	g_Player.vecDir = vecDir;										// 完成した視点方向ベクトルをプレイヤー視点方向に適用
}

//===============================================
//	描画
//===============================================
void Player_Render(void)
{
	DebugFont_Draw(500, 0, "左右角度%.3f\n上下角度%.3f", g_Player.AngleY, g_Player.AngleX);
}

//===============================================
//	終了処理
//===============================================
void Player_Finalize(void)
{

}

//===============================================
//	視点初期化
//===============================================
void Player_ResetAngle(void)
{
	g_Player.AngleY = 0.0f;
	g_Player.AngleX = 0.0f;	
}

//===============================================
//	情報取得
//===============================================
const PLAYER *Player_GetPlayer(void)
{
	return &g_Player;
}