//
//	Lighting.cpp
//		Author:HIROMASA IKEDA	DATE:2018/10/04
//===============================================
#include"Lighting.h"
#include"System.h"

//===============================================
//	�O���[�o���ϐ�
//===============================================
#define COLORVALUE_RGBA(r,g,b,a) D3DCOLORVALUE{r/255,g/255,b/255,a/255}

static D3DLIGHT9 g_DirectLight;
static D3DXVECTOR3 g_DirectLight_Direction;

//===============================================
//	������
//===============================================
void Lighting_Initialize()
{
	//------------------------------------
	//	���C�e�B���O
	//------------------------------------
	System_GetDevice()->SetRenderState(D3DRS_LIGHTING, TRUE);	//���C�e�B���O��ON

	ZeroMemory(&g_DirectLight, sizeof(g_DirectLight));
	g_DirectLight.Type = D3DLIGHT_DIRECTIONAL;

	g_DirectLight_Direction = D3DXVECTOR3(0.0f, -1.0f, 1.0f);
	D3DXVec3Normalize(&g_DirectLight_Direction, &g_DirectLight_Direction);

	g_DirectLight.Diffuse = COLORVALUE_RGBA(255,255,255,255);
	g_DirectLight.Direction = g_DirectLight_Direction;

	System_GetDevice()->SetLight(0, &g_DirectLight);
	System_GetDevice()->LightEnable(0, TRUE);
	System_GetDevice()->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);	//�@���x�N�g����P�ʃx�N�g�����F�g��E�k���̕ω�
	System_GetDevice()->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	//�A���r�G���g
	System_GetDevice()->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_RGBA(64, 64, 64, 255));
	System_GetDevice()->SetRenderState(D3DRS_AMBIENTMATERIALSOURCE, D3DMCS_COLOR1);

	/*
		D3DMCS_COLOR1 ���_�J���[���}�e���A���̐F�ɂ��܂��B
		D3DMCS_MATERIAL �}�e���A�����}�e���A���̐F�ɂ��܂��B

		���1
		 ���C�g�炩SetRenderState�̐ݒ�������B
		 �L���[�u�Ȃǂ̕`���D3DMCS_COLOR1
		 ���f���̕`���D3DMCS_MATERIAL

		���2
		 �ǂ��炩���f�t�H���g��ݒ肵��
		 �Ⴄ����������ɁA�f�t�H���g�ɖ߂�
	
		���3
		�@�S�Ă��}�e���A���ɂ���
	*/
}

//===============================================
//	���C�g�ݒ�
//===============================================
void Lighting_SetLight()
{
	System_GetDevice()->SetRenderState(D3DRS_LIGHTING, TRUE);	//���C�e�B���O��ON
}

