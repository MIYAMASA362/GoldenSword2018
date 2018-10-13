//
//	Grid.cpp
//		Author:HIROMASA IEKDA	DATE:2018/09/27
//===============================================
#include<d3dx9.h>
#include"System.h"
#include"Grid.h"
#include"Camera.h"

//===============================================
//	�}�N��	
//===============================================
#define FVF_GRID_VERTEX3D (D3DFVF_XYZ | D3DFVF_DIFFUSE)

//===============================================
//	�\����
//===============================================
typedef struct GridVertex3D
{
	D3DXVECTOR3 Position;
	D3DCOLOR Color;
}GridVertex3D;

//===============================================
//	�O���[�o���ϐ�
//===============================================
static GridVertex3D g_Grid[46] = {};

//===============================================
//	������
//===============================================
void Grid_Initialize()
{
#if !defined DISABLE_GRID
	const float Mx = GRID_WIDTH * 5.0;
	const float Mz = GRID_WIDTH * 5.0;

	//�O���b�h
	for(int i = 0; i < 11; i++)
	{
		int n = i * 4;
		g_Grid[n].Position		= D3DXVECTOR3((float)GRID_WIDTH * (i - 5),0,-Mz);
		g_Grid[n + 1].Position	= D3DXVECTOR3((float)GRID_WIDTH * (i - 5),0, Mz);
		g_Grid[n + 2].Position	= D3DXVECTOR3(-Mx,0, (float)GRID_WIDTH * (i - 5));
		g_Grid[n + 3].Position	= D3DXVECTOR3(Mx, 0, (float)GRID_WIDTH * (i - 5));

		if(i == 5)
		{
			//XZ���F
			g_Grid[n].Color		= D3DCOLOR_RGBA(0, 0, 255, 255);
			g_Grid[n + 1].Color = D3DCOLOR_RGBA(0, 0, 255, 255);
			g_Grid[n + 2].Color = D3DCOLOR_RGBA(255, 0, 0, 255);
			g_Grid[n + 3].Color = D3DCOLOR_RGBA(255, 0, 0, 255);
			continue;
		}

		g_Grid[n].Color		= GRID_COLOR;
		g_Grid[n + 1].Color = GRID_COLOR;
		g_Grid[n + 2].Color = GRID_COLOR;
		g_Grid[n + 3].Color = GRID_COLOR;
	}

	//Y��
	g_Grid[44] = { D3DXVECTOR3(0,GRID_WIDTH * 5.0f,0),D3DCOLOR_RGBA(0,255,0,255)};
	g_Grid[45] = { D3DXVECTOR3(0,-GRID_WIDTH * 5.0f,0),D3DCOLOR_RGBA(0,255,0,255) };
#endif
}

//===============================================
//	�`��
//===============================================
void Grid_Render()
{
#if !defined DISABLE_GRID

	D3DXMATRIX mtxWorld;										//���[���h�ϊ��s��
	D3DXMatrixIdentity(&mtxWorld);								//�P�ʍs��̐ݒ�
	System_GetDevice()->SetTransform(D3DTS_WORLD, &mtxWorld);	//�f�o�C�X�֓o�^

	System_GetDevice()->SetRenderState(D3DRS_LIGHTING,NULL);
	//------------------------------------
	//	�`��
	//------------------------------------
	System_GetDevice()->SetFVF(FVF_GRID_VERTEX3D);
	System_GetDevice()->DrawPrimitiveUP(D3DPT_LINELIST, 23, &g_Grid, sizeof(g_Grid[0]));

#endif
}