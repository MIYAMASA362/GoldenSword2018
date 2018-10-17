//
//	Bullet.h
//		Author:ハン DATE:
//===============================================
//	変更者 Changed by
//		Author:HIROMASA IKEDA	DATE:2018/10/17
//
//-----------------------------------------------
#ifndef BULLET_H
#define BULLET_H

#include"common.h"
#include <d3dx9.h>

//Class
#include"CGameObject.h"
#include"CCollisionableObject.h"

//===============================================
//	構造体
//===============================================
enum BULLET_TYPE
{
	BULLET_NORMAL,
	BULLET_MAX
};

//===============================================
//	クラス
//===============================================

//-------------------------------------
//	Bullet
//-------------------------------------
class Bullet:public GameObject
{
private:
	bool IsEnable;							//有効・無効
	BULLET_TYPE type;						//タイプ
	D3DXVECTOR3 face;						//弾の向き
public:

	ShapeSphere ColSphape;

	Bullet();
	Bullet(Transform* pTransform, Texture* pTexture);

	virtual void Update();					//更新
	bool GetEnable();						//有効・無効の取得
	void TypeSet(BULLET_TYPE type);			//タイプの設定
	void SetBullet(D3DXVECTOR3 position, D3DXVECTOR3 face, BULLET_TYPE type);	//弾をセットする
	void DisEnable();						//無効化
};


//===============================================
//	関数
//===============================================
void Bullet_Initialize();
void Bullet_Render();
void Bullet_Update();
void Bullet_Create(D3DXVECTOR3 pos,D3DXVECTOR3 face, BULLET_TYPE type);
void Bullet_Destroy(int index);
bool Bullet_IsEnable(int index);
ShapeSphere* Bullet_ColShape(int index);

#endif // !BULLET_H
