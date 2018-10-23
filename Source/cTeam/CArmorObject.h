//
//	ArmorObject.h
//		Author:HIROMASA IEKDA	DATE:2018/10/13
//===============================================
#pragma once
#ifndef ARMOROBJECT_H
#define ARMOROBJECT_H

#include<d3dx9.h>
#include<vector>
#include"common.h"

using namespace std;

//Class
#include"CGameObject.h"
#include"CCollisionableObject.h"

//===============================================
//	�A�[�}�[��΂����
//===============================================
enum ARMOR_DISCHARGING_TYPE
{
	FALL = 0,
	RADIALLY,
	// enum max
	ARMOR_DIS_TYPE_MAX
};

//===============================================
//	ArmarObject �N���X
//===============================================
class ArmorObject :public GameObject
{
private: // ���
	D3DXVECTOR3 Speed;
	bool bBreak;		//�o���o���t���O�@True(�o���o���ɂȂ�)
	
public:
	ARMOR_DISCHARGING_TYPE Discharging_Type;	//��ԃ^�C�v

public: // �o���o��
	void Break();
	void Break( D3DXVECTOR3 Speed, unsigned int DelayFrameForDrop );

public: // ��ʊ֐�
	void SetSpeed( D3DXVECTOR3 Vector );
	void Set_DischargingType(ARMOR_DISCHARGING_TYPE Type);

public: // �R���X�g���N�^ | �f�X�g���N�^
	ArmorObject(Transform* pTransform) :ArmorObject(pTransform, &Texture(TEXTURE_NONE, { 0,0 }, { 0,0 })) {};
	ArmorObject(Transform* pTransform, Texture* pTexture) :ArmorObject(pTransform, pTexture, FALL) {};
	ArmorObject(Transform* pTransform, Texture* pTexture,ARMOR_DISCHARGING_TYPE Type);

public:
	void Update();		//�X�V����



public: // �o���o�� �C�x���g�p
	int DelayFrameForDrop;
	
};


#endif // !ARMOROBJECT_H

