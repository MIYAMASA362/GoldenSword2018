//
//	Player.h
//		Author:YU NISHIMAKI	DATE:2018/10/13
//===============================================
#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include"common.h"
#include<d3dx9.h>

//Class
#include"CGameObject.h"
#include"CCamera.h"

//===============================================
//	Player �\����
//===============================================
typedef struct PLAYER_tag
{
	D3DXVECTOR3 Position;				// �v���C���[���W
	D3DXVECTOR3 Verocity;				// ���x
	D3DXVECTOR3 vecDir;					// �����Ă������
	float AngleY;						// Y������̉�]�p�i���_�̍��E�����p�x�j
	float AngleX;						// X������̉�]�p�i���_�̋p��p�j
}PLAYER;

//===============================================
//	�N���X
//===============================================

//-------------------------------------
//	�v���C���[�J����
//-------------------------------------
class PlayerCamera:public Camera
{
private:

public:
	
	void Initialize();
	void Update();
};

//-------------------------------------
//	�v���C���[
//-------------------------------------
class Player:public GameObject
{
private:

public:

};

//===============================================
//	�֐�
//===============================================
void Player_Initialize(void);
void Player_Update(void);
void Player_Render(void);
void Player_Finalize(void);

void Player_ResetAngle(void);
const PLAYER *Player_GetPlayer(void);

#endif // !PLAYER_H