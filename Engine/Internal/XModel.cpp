//
//	XModel.cpp
//		Author:HIROMASA IKEDA	DATE:2018/10/19
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

//===============================================
//	�C���N���[�h	include
//===============================================
#include"common.h"
#include<d3dx9.h>
#include"XModel.h"
#include"System.h"

//Class


//===============================================
//	�}�N����`		define
//===============================================


//===============================================
//	�O���[�o���ϐ�	global
//===============================================
LPD3DXMESH g_pD3DXMesh;					//���b�V�����

LPD3DXBUFFER g_pD3DXAdjacenecyBuffer;	//�אڏ����󂯎��ϐ�
DWORD g_dwNumMaterials;					//�}�e���A����
LPD3DXBUFFER g_pD3DXMtrlBuffer;			//�}�e���A�����

D3DCOLORVALUE* g_pMeshColor	= NULL;
LPDIRECT3DTEXTURE9* g_pMeshTexture = NULL;
D3DMATERIAL9* g_pD3DXMaterials = NULL;

//===============================================
//	�֐�			function
//===============================================

//-------------------------------------
//	�ǂݍ���
//-------------------------------------
void XModel_Load(const char pFileName[MODEL_FILENAME_MAX])
{
	HRESULT hr;
	hr = D3DXLoadMeshFromX(
		pFileName,				//�ǂݍ��ރt�@�C����
		D3DXMESH_MANAGED | D3DXMESH_WRITEONLY,	//�e�ʏグ�@D3DXMESH_32BIT
		System_GetDevice(),
		NULL,
		&g_pD3DXMtrlBuffer,
		NULL,
		&g_dwNumMaterials,
		&g_pD3DXMesh
	);

	if(FAILED(hr))
	{
		MessageBox(*System_GethWnd(),"���f���̓ǂݍ��݂Ɏ��s���܂����B","�ǂݍ��ݎ��s",MB_OK);
		DestroyWindow(*System_GethWnd());
		return;
	}

	/*	�œK��
	hr = g_pD3DXMesh->OptimizeInplace(
		D3DXMESHOPT_COMPACT | D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_VERTEXCACHE,
		(DWORD*)g_pD3DXAdjacenecyBuffer->GetBufferPointer(),NULL,NULL,NULL
	);
	*/

	//�}�e���A�����ł̕K�v�m��
	g_pD3DXMaterials = new D3DMATERIAL9[g_dwNumMaterials];
	g_pMeshTexture = new LPDIRECT3DTEXTURE9[g_dwNumMaterials];

	D3DXMATERIAL* pD3DXMaterials = (D3DXMATERIAL*)g_pD3DXMtrlBuffer->GetBufferPointer();

	for(int i = 0; i <g_dwNumMaterials; i++)
	{
		//�}�e���A��
		g_pD3DXMaterials[i] = pD3DXMaterials[i].MatD3D;

		if(pD3DXMaterials[i].pTextureFilename == NULL)
		{
			g_pMeshTexture[i] = NULL; //�e�N�X�`������
		}
		else
		{
			//�e�N�X�`������
			hr = D3DXCreateTextureFromFile(System_GetDevice(),pD3DXMaterials[i].pTextureFilename,&g_pMeshTexture[i]);

			//�e�N�X�`������
			if(FAILED(hr))
			{
				g_pMeshTexture[i] = NULL;
			}
		}
	}

	return;
}

//-------------------------------------
//	�`��
//-------------------------------------	
void XModel_Render()
{

}

//-------------------------------------
//	������
//-------------------------------------
void XModel_Initialize()
{

}

//-------------------------------------
//	�I��
//-------------------------------------
void XModel_Finalize() 
{

}

