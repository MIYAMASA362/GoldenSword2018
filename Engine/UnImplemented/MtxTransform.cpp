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
#include"Cube.h"
#include"Lighting.h"

//===============================================
//	�}�N����`
//===============================================

//===============================================
//	�\����
//===============================================

//===============================================
//	�O���[�o���ϐ�
//===============================================
static D3DXVECTOR3	g_CameraPos(CAMERA_POS);	//�J�����ʒu
static D3DXVECTOR3	g_CameraAt(CAMERA_AT);		//�J���������_
static float		g_CameraFov = CAMERA_FOV;	//�J������p

static float		g_CameraAtDistance;			//�����_�܂ł̋���

static D3DXVECTOR3	g_CameraFront;				//�J�����O
static D3DXVECTOR3	g_CameraRight;				//�J�����E
static D3DXVECTOR3	g_CameraUp;					//�J������

//===============================================
//	������
//===============================================
void MtxTransformation_Initialize()
{
	g_CameraPos = CAMERA_POS;
	g_CameraAt  = CAMERA_AT;
	g_CameraUp  = CAMERA_UP;
	g_CameraFov = CAMERA_FOV;
	g_CameraAtDistance = 3.0f;

	//�O
	g_CameraFront = D3DXVECTOR3(0.0f,-0.5f,1.0f);		
	D3DXVec3Normalize(&g_CameraFront,&g_CameraFront);

	g_CameraUp = D3DXVECTOR3(0.0f,1.0f,0.0f);			
	
	//�E
	D3DXVec3Cross(&g_CameraRight,&g_CameraFront,&g_CameraUp);	
	D3DXVec3Normalize(&g_CameraRight,&g_CameraRight);

	//��
	//D3DXVec3Cross(&g_CameraUp, &g_CameraRight, &g_CameraFront);
	//D3DXVec3Normalize(&g_CameraUp,&g_CameraUp);

	Grid_Initialize();
}

//===============================================
//	�X�V����
//===============================================
void MtxTransformation_Update()
{
	if (Mouse_IsRightDown())
	{
		D3DXMATRIX mtxRotation;
		D3DXMatrixRotationY(&mtxRotation, Mouse_IsAccelerationX() * 0.001f);
		D3DXVec3TransformNormal(&g_CameraFront, &g_CameraFront, &mtxRotation);	//�x�N�g�����W�ϊ�
		D3DXVec3TransformNormal(&g_CameraRight, &g_CameraRight, &mtxRotation);
		D3DXMatrixIdentity(&mtxRotation);
		D3DXMatrixRotationAxis(&mtxRotation,&g_CameraRight,Mouse_IsAccelerationY() * -0.001f);
		D3DXVec3TransformNormal(&g_CameraFront, &g_CameraFront, &mtxRotation);	//�x�N�g�����W�ϊ�
		D3DXVec3TransformNormal(&g_CameraRight, &g_CameraRight, &mtxRotation);
	}

	//------------------------------------
	//	�J����
	//------------------------------------
	g_CameraAt.x = g_CameraFront.x * g_CameraAtDistance + g_CameraPos.x;
	g_CameraAt.y = g_CameraFront.y * g_CameraAtDistance + g_CameraPos.y;
	g_CameraAt.z = g_CameraFront.z * g_CameraAtDistance + g_CameraPos.z;

	D3DXVECTOR3 front = g_CameraFront;
	front.y = 0;
	D3DXVECTOR3 right = g_CameraRight;
	right.y = 0;

	if(Keyboard_IsPress(DIK_W))
	{
		g_CameraPos += front * 0.05f;
	}

	if(Keyboard_IsPress(DIK_S))
	{
		g_CameraPos -= front * 0.05f;
	}

	if(Keyboard_IsPress(DIK_A))
	{
		g_CameraPos += right * 0.05f;
	}

	if(Keyboard_IsPress(DIK_D))
	{
		g_CameraPos -= right * 0.05f;
	}

	/*
	//------------------------------------
	//	�J����
	//------------------------------------
	if(Keyboard_IsPress(DIK_LSHIFT))
	{
		//-----------------------------------
		//	�����_�̈ړ�
		//-----------------------------------
		if(Mouse_IsCenterDown())
		{
			g_CameraAt  += D3DXVECTOR3(Mouse_IsAccelerationX() * 0.01f,	Mouse_IsAccelerationY() * 0.01f, Mouse_IsAccelerationZ() * 0.01f);
			g_CameraPos += D3DXVECTOR3(Mouse_IsAccelerationX() * 0.01f,	Mouse_IsAccelerationY() * 0.01f, Mouse_IsAccelerationZ() * 0.01f);
		}
	}
	else if (Mouse_IsCenterDown())
	{
		//-----------------------------------
		//	�J�����ړ�
		//-----------------------------------
		D3DXVECTOR3 Distance;
		Distance = g_CameraPos - g_CameraAt;
		float Angles = D3DXToRadian(Mouse_IsAccelerationX() * 0.1f);
		g_CameraPos.x = g_CameraAt.x + (Distance.x * cosf(Angles) - Distance.z * sinf(Angles));
		g_CameraPos.z = g_CameraAt.z + (Distance.x * sinf(Angles) + Distance.z * cosf(Angles));
		
		g_CameraPos.y += Mouse_IsAccelerationY() * 0.05f;
	}
	*/
}

//===============================================
//	�`�揈��
//===============================================
void MtxTransformation_Render()
{
	Grid_Render();

	//------------------------------------
	//	�r���[�ϊ��s��
	//------------------------------------
	D3DXMATRIX mtxView;							//�r���[�ϊ��s��
	D3DXMatrixLookAtLH(&mtxView, &g_CameraPos, &g_CameraAt, &g_CameraUp);	//�ϊ�
	System_GetDevice()->SetTransform(D3DTS_VIEW, &mtxView);		//�f�o�C�X�֓o�^

	//------------------------------------
	//	�v���W�F�N�V�����ϊ��s��
	//------------------------------------
	D3DXMATRIX mtxProjection;		//�v���W�F�N�V�����ϊ��s��
	D3DXMatrixPerspectiveFovLH(&mtxProjection, g_CameraFov, SCREEN_ASPECT, CAMERA_NEAR, CAMERA_WAR);	//Fov�͉�p�@�ϊ�
	System_GetDevice()->SetTransform(D3DTS_PROJECTION, &mtxProjection);	//�f�o�C�X�֓o�^
}

//===============================================
//�@�I������
//===============================================
void MtxTransformation_Finalize()
{

}

//===============================================
//	�N���X
//===============================================

//-------------------------------------
//	�R���X�g���N�^
//-------------------------------------
MtxFormat::MtxFormat()
{
	//�P�ʍs��
	D3DXMatrixIdentity(&MtxWorld);
	D3DXMatrixIdentity(&MtxTransform);
	D3DXMatrixIdentity(&MtxRotation);
	System_GetDevice()->SetTransform(D3DTS_WORLD, &MtxWorld);		//�f�o�C�X�֓o�^
}

//-------------------------------------
//	SetIdentity()
//-------------------------------------
void MtxFormat::SetIdentity(void)
{
	//�P�ʍs��
	D3DXMatrixIdentity(&MtxWorld);
	D3DXMatrixIdentity(&MtxTransform);
	D3DXMatrixIdentity(&MtxRotation);
}

void MtxFormat::SetIdentity(D3DXMATRIX* ReSetMtx)
{
	D3DXMatrixIdentity(ReSetMtx);
}


//-------------------------------------
//	SetMaxtrix()
//-------------------------------------
void MtxFormat::SetMatrix(void)
{
	
}


