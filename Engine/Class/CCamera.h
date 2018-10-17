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

//================================================
//	�}�N����`	define
//================================================


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

	static Camera* Get_Main();
	static bool Begin();		//�`��J�n

	D3DXVECTOR3 position;		//�ʒu
	D3DXVECTOR3 at;				//���_
	D3DXVECTOR3 up;				//�J������

	Camera();
	Camera(D3DXVECTOR3 Position);
	Camera(D3DXVECTOR3 Position, D3DXVECTOR3 At);

 	virtual void Initialize();	//������
	virtual void Update();		//�X�V

	void Set_Main();			//���C���J�����ɐݒ�

protected:

};


#endif