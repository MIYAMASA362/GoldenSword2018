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
//	�}�N����`
//===============================================

//===============================================
//	�\����
//===============================================

//===============================================
//	�O���[�o���ϐ�
//===============================================
static D3DXVECTOR3 CameraPos(CAMERA_POS);		//�J�����ʒu
static D3DXVECTOR3 CameraAt(CAMERA_AT);			//�J���������_
static D3DXVECTOR3 CameraUp(CAMERA_UP);			//�J������

//===============================================
//	������
//===============================================
void MtxTransformation_Initialize()
{
	Grid_Initialize();
}

//===============================================
//	�X�V����
//===============================================
void MtxTransformation_Update()
{

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
			CameraAt  += D3DXVECTOR3(Mouse_IsAccelerationX() *0.01f,	Mouse_IsAccelerationY() * 0.01f, Mouse_IsAccelerationZ() * 0.01f);
			CameraPos += D3DXVECTOR3(Mouse_IsAccelerationX() * 0.01f,	Mouse_IsAccelerationY() * 0.01f, Mouse_IsAccelerationZ() * 0.01f);
		}
	}
	else if (Mouse_IsCenterDown())
	{
		//-----------------------------------
		//	�J�����ړ�
		//-----------------------------------
		D3DXVECTOR3 Distance;
		Distance = CameraPos - CameraAt;
		float Angles = D3DXToRadian(Mouse_IsAccelerationX() * 0.1f);
		CameraPos.x = CameraAt.x + (Distance.x * cosf(Angles) - Distance.z * sinf(Angles));
		CameraPos.z = CameraAt.z + (Distance.x * sinf(Angles) + Distance.z * cosf(Angles));
		
		CameraPos.y += Mouse_IsAccelerationY() * 0.05f;
	}

	CameraPos = Player_GetPlayer()->Position;											// �J�����ʒu���v���C���[���W�ɓ���
	CameraAt = Player_GetPlayer()->Position + Player_GetPlayer()->vecDir * 5.0f;		// �J���������_���v���C���[���W�ƃv���C���[���_��������Z�o
	D3DXVECTOR3 vecDirSide(0.0f, 0.0f, 0.0f);											// �^�������x�N�g�����[�N
	vecDirSide.x = Player_GetPlayer()->vecDir.z;										// ���_�����ɐ����ȃx�N�g���𐶐�
	vecDirSide.z = -(Player_GetPlayer()->vecDir.x);										// ����
	D3DXVec3Normalize(&vecDirSide, &vecDirSide);										// �P�ʃx�N�g����
	D3DXVec3Cross(&CameraUp, &Player_GetPlayer()->vecDir, &vecDirSide);					// �O�ςɂ�莋�_�����A�^�������x�N�g���̗����ɐ����ȃx�N�g���𐶐��iCameraUp�j
	D3DXVec3Normalize(&CameraUp, &CameraUp);											// �P�ʃx�N�g����

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
	D3DXMatrixLookAtLH(&mtxView, &CameraPos, &CameraAt, &CameraUp);	//�ϊ�
	System_GetDevice()->SetTransform(D3DTS_VIEW, &mtxView);		//�f�o�C�X�֓o�^

	//------------------------------------
	//	�v���W�F�N�V�����ϊ��s��
	//------------------------------------
	D3DXMATRIX mtxProjection;		//�v���W�F�N�V�����ϊ��s��
	D3DXMatrixPerspectiveFovLH(&mtxProjection, D3DXToRadian(60), (float)WINDOWSCREEN_WIDTH / WINDOWSCREEN_HEIGHT, 0.1f, 100.0f);	//Fov�͉�p�@�ϊ�
	System_GetDevice()->SetTransform(D3DTS_PROJECTION, &mtxProjection);	//�f�o�C�X�֓o�^

	System_GetDevice()->SetRenderState(D3DRS_LIGHTING, FALSE);	//���C�e�B���O��OFF
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
MTEXTRANSFORM::MTEXTRANSFORM()
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
void MTEXTRANSFORM::SetIdentity(void)
{
	//�P�ʍs��
	D3DXMatrixIdentity(&MtxWorld);
	D3DXMatrixIdentity(&MtxTransform);
	D3DXMatrixIdentity(&MtxRotation);
}

void MTEXTRANSFORM::SetIdentity(D3DXMATRIX* ReSetMtx)
{
	D3DXMatrixIdentity(ReSetMtx);
}



