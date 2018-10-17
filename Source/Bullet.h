//
//	Bullet.h
//		Author:�n�� DATE:
//===============================================
//	�ύX�� Changed by
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
//	�\����
//===============================================
enum BULLET_TYPE
{
	BULLET_NORMAL,
	BULLET_MAX
};

//===============================================
//	�N���X
//===============================================

//-------------------------------------
//	Bullet
//-------------------------------------
class Bullet:public GameObject
{
private:
	bool IsEnable;							//�L���E����
	BULLET_TYPE type;						//�^�C�v
	D3DXVECTOR3 face;						//�e�̌���
public:

	ShapeSphere ColSphape;

	Bullet();
	Bullet(Transform* pTransform, Texture* pTexture);

	virtual void Update();					//�X�V
	bool GetEnable();						//�L���E�����̎擾
	void TypeSet(BULLET_TYPE type);			//�^�C�v�̐ݒ�
	void SetBullet(D3DXVECTOR3 position, D3DXVECTOR3 face, BULLET_TYPE type);	//�e���Z�b�g����
	void DisEnable();						//������
};


//===============================================
//	�֐�
//===============================================
void Bullet_Initialize();
void Bullet_Render();
void Bullet_Update();
void Bullet_Create(D3DXVECTOR3 pos,D3DXVECTOR3 face, BULLET_TYPE type);
void Bullet_Destroy(int index);
bool Bullet_IsEnable(int index);
ShapeSphere* Bullet_ColShape(int index);

#endif // !BULLET_H
