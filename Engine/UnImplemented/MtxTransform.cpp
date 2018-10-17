//
//	MtxTransform.cpp
//		Author:HIROMASA IKEDA	DATE:2018/10/16
//===============================================
#include<d3dx9.h>
#include<math.h>
#include"common.h"

#include"MtxTransform.h"

#include"input.h"
#include"Camera.h"
#include"Grid.h"

#include"Player.h"

//Class
#include"CCamera.h"

//===============================================
//	�}�N����`
//===============================================

//===============================================
//	�\����
//===============================================

//===============================================
//	�O���[�o���ϐ�
//===============================================
static Camera g_Camera;							//�J����

//===============================================
//	������
//===============================================
void MtxTransformation_Initialize()
{
	Grid_Initialize();

	g_Camera.Set_Main();
}

//===============================================
//	�X�V����
//===============================================
void MtxTransformation_Update()
{
	g_Camera.Update();
}

//===============================================
//	�`�揈��
//===============================================
void MtxTransformation_Render()
{
	Grid_Render();

	Camera::Begin();
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



