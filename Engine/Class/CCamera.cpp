//
//	CCamera.cpp
//		Author:HIROMASA IKEDA	DATE:2018/10/17
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

//===============================================
//	�C���N���[�h	include
//===============================================
#include<d3dx9.h>
#include"common.h"
#include"input.h"

//class
#include"CCamera.h"

//===============================================
//	�}�N����`		define
//===============================================


//===============================================
//	�O���[�o���ϐ�	global
//===============================================
Camera* Camera::MainCamera = NULL;

//===============================================
//	�J����		class
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
Camera::Camera()
{
	this->position = CAMERA_POS;
	this->at = CAMERA_AT;
	this->up = CAMERA_UP;
}

Camera::Camera(D3DXVECTOR3 Position)
{
	this->position = Position;
	this->at = CAMERA_AT;
	this->up = CAMERA_UP;
}

Camera::Camera(D3DXVECTOR3 Position, D3DXVECTOR3 At)
{
	this->position = Position;
	this->at = At;
	this->up = CAMERA_AT;
}

//-------------------------------------
//	������
//-------------------------------------
void Camera::Initialize()
{
	return;
}

//-------------------------------------
//	�X�V
//-------------------------------------
void Camera::Update()
{
	//------------------------------------
	//	�J����
	//------------------------------------
	if (Keyboard_IsPress(DIK_LSHIFT))
	{
		//-----------------------------------
		//	�����_�̈ړ�
		//-----------------------------------
		if (Mouse_IsCenterDown())
		{
			this->position += D3DXVECTOR3(Mouse_IsAccelerationX() * 0.01f, Mouse_IsAccelerationY() * 0.01f, Mouse_IsAccelerationZ() * 0.01f);
			this->at += D3DXVECTOR3(Mouse_IsAccelerationX() * 0.01f, Mouse_IsAccelerationY() * 0.01f, Mouse_IsAccelerationZ() * 0.01f);
		}
	}
	else if (Mouse_IsCenterDown())
	{
		//-----------------------------------
		//	�J�����ړ�
		//-----------------------------------
		D3DXVECTOR3 Distance;
		Distance = this->position - this->at;
		float Angles = D3DXToRadian(Mouse_IsAccelerationX() * 0.1f);
		this->position.x = this->at.x + (Distance.x * cosf(Angles) - Distance.z * sinf(Angles));
		this->position.z = this->at.z + (Distance.x * sinf(Angles) + Distance.z * cosf(Angles));

		this->position.y += Mouse_IsAccelerationY() * 0.05f;
	}



	return;
}


//-------------------------------------
//	���C���J�����ɐݒ�
//-------------------------------------
void Camera::Set_Main()
{
	this->MainCamera = this;
}

//-------------------------------------
//	���C���J�����擾
//-------------------------------------
Camera* Camera::Get_Main()
{
	return Camera::MainCamera;
}

//-------------------------------------
//	�ϊ��J�n
//-------------------------------------
bool Camera::Begin()
{
	if (MainCamera == NULL) return false;

	//------------------------------------
	//	�r���[�ϊ��s��
	//------------------------------------
	D3DXMATRIX mtxView;							//�r���[�ϊ��s��
	D3DXMatrixLookAtLH(&mtxView, &MainCamera->position, &MainCamera->at, &MainCamera->up);	//�ϊ�
	System_GetDevice()->SetTransform(D3DTS_VIEW, &mtxView);		//�f�o�C�X�֓o�^

	//------------------------------------
	//	�v���W�F�N�V�����ϊ��s��
	//------------------------------------
	D3DXMATRIX mtxProjection;		//�v���W�F�N�V�����ϊ��s��
	D3DXMatrixPerspectiveFovLH(&mtxProjection, D3DXToRadian(60), (float)WINDOWSCREEN_WIDTH / WINDOWSCREEN_HEIGHT, 0.1f, 100.0f);	//Fov�͉�p�@�ϊ�
	System_GetDevice()->SetTransform(D3DTS_PROJECTION, &mtxProjection);	//�f�o�C�X�֓o�^

	System_GetDevice()->SetRenderState(D3DRS_LIGHTING, FALSE);	//���C�e�B���O��OFF

	return true;
}



