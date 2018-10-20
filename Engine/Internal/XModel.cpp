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


D3DCOLORVALUE* g_pMeshColor	= NULL;
LPDIRECT3DTEXTURE9* g_pMeshTexture = NULL;
D3DMATERIAL9* g_pD3DXMaterials = NULL;


//===============================================
//	�֐�			function
//===============================================

//-------------------------------------
//	�ǂݍ���
//-------------------------------------
void XModel_Load(const char* pFileName)
{
	HRESULT hr;
	LPD3DXBUFFER pD3DXMtrlBuffer = NULL;			//�}�e���A�����

	hr = D3DXLoadMeshFromX(
		pFileName,				//�ǂݍ��ރt�@�C����
		D3DXMESH_MANAGED,	//�e�ʏグ�@D3DXMESH_32BIT
		System_GetDevice(),
		NULL,
		&pD3DXMtrlBuffer,
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

	D3DXMATERIAL* pD3DXMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();

	for(UINT i = 0; i <g_dwNumMaterials; i++)
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
				MessageBox(*System_GethWnd(),"�e�N�X�`���̓ǂݍ��݂Ɏ��s���܂����B","�ǂݍ��ݎ��s",MB_OK);
				DestroyWindow(*System_GethWnd());
				g_pMeshTexture[i] = NULL;
			}
		}
	}

	if(pD3DXMtrlBuffer != NULL)
	{
		pD3DXMtrlBuffer->Release();
	}

	return;
}

//-------------------------------------
//	�`��
//-------------------------------------	
void XModel_Render()
{
	for(int i= 0; i< g_dwNumMaterials; i++)
	{
		System_GetDevice()->SetMaterial(&g_pD3DXMaterials[i]);	//�}�e���A���o�^
		System_GetDevice()->SetTexture(0,g_pMeshTexture[i]);	//�e�N�X�`���o�^
		g_pD3DXMesh->DrawSubset(i);								//�`��
	}
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

