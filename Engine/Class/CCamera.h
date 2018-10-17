//
//	CCamera.h
//		Author:HIROMASA IKEDA	DATE:2018/10/16
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

#pragma once
#ifndef CCAMERA_H
#define CCAMERA_H

//================================================
//	�C���N���[�h	include
//================================================
#include"common.h"
#include<d3dx9.h>

#include"Camera.h"
//Class
#include"CTransform.h"

//===============================================
//	�}�N����`	define
//===============================================


//================================================
//	�񋓌^		enum
//================================================


//================================================
//	�\����		struct/typedef
//================================================

//================================================
//	�O���[�o���ϐ��@global
//================================================

//================================================
//	�N���X		class
//================================================

//-------------------------------------
//	Camera�@�N���X
//-------------------------------------
class Camera
{
private:
	static Camera* MainCamera;	//���C���J����

public:
	D3DXVECTOR3 position;		//�ʒu
	float Speed;				//�ړ����x

	D3DXVECTOR3 at;				//�����_
	D3DXVECTOR3 up;				//�J������
	D3DXVECTOR3 forward;		//�J�����O
	D3DXVECTOR3 right;			//�J�����E
	float atDistance;			//�����_�܂ł̋���
	float fov;					//��p

	Camera() :Camera(CAMERA_POS, CAMERA_AT, CAMERA_ATDISTANCE, CAMERA_FOV) {};
	Camera(D3DXVECTOR3 Position) : Camera(Position, CAMERA_AT, CAMERA_ATDISTANCE, CAMERA_FOV) {};
	Camera(D3DXVECTOR3 Position, D3DXVECTOR3 At, float AtDistance, float fov);

	static Camera* Get_Main();
	static bool Begin();		//�`��J�n
 	virtual void Initialize();	//������
	virtual void Update();		//�X�V
	void Set_Main();			//���C���J�����ɐݒ�
};


#endif