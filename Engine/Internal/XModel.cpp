//
//	XModel.cpp
//		Author:HIROMASA IKEDA	DATE:2018/10/19
//===============================================
//	変更者 Changed By
//		Name:	DATE:
//
//-----------------------------------------------

//===============================================
//	インクルード	include
//===============================================
#include"common.h"
#include<d3dx9.h>
#include"XModel.h"
#include"System.h"

//Class


//===============================================
//	マクロ定義		define
//===============================================


//===============================================
//	グローバル変数	global
//===============================================
LPD3DXMESH g_pD3DXMesh;					//メッシュ情報

LPD3DXBUFFER g_pD3DXAdjacenecyBuffer;	//隣接情報を受け取る変数
DWORD g_dwNumMaterials;					//マテリアル数


D3DCOLORVALUE* g_pMeshColor	= NULL;
LPDIRECT3DTEXTURE9* g_pMeshTexture = NULL;
D3DMATERIAL9* g_pD3DXMaterials = NULL;


//===============================================
//	関数			function
//===============================================

//-------------------------------------
//	読み込み
//-------------------------------------
void XModel_Load(const char* pFileName)
{
	HRESULT hr;
	LPD3DXBUFFER pD3DXMtrlBuffer = NULL;			//マテリアル情報

	hr = D3DXLoadMeshFromX(
		pFileName,				//読み込むファイル名
		D3DXMESH_MANAGED,	//容量上げ　D3DXMESH_32BIT
		System_GetDevice(),
		NULL,
		&pD3DXMtrlBuffer,
		NULL,
		&g_dwNumMaterials,
		&g_pD3DXMesh
	);

	if(FAILED(hr))
	{
		MessageBox(*System_GethWnd(),"モデルの読み込みに失敗しました。","読み込み失敗",MB_OK);
		DestroyWindow(*System_GethWnd());
		return;
	}

	/*	最適化
	hr = g_pD3DXMesh->OptimizeInplace(
		D3DXMESHOPT_COMPACT | D3DXMESHOPT_ATTRSORT | D3DXMESHOPT_VERTEXCACHE,
		(DWORD*)g_pD3DXAdjacenecyBuffer->GetBufferPointer(),NULL,NULL,NULL
	);
	*/

	//マテリアル内での必要確保
	g_pD3DXMaterials = new D3DMATERIAL9[g_dwNumMaterials];
	g_pMeshTexture = new LPDIRECT3DTEXTURE9[g_dwNumMaterials];

	D3DXMATERIAL* pD3DXMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();

	for(UINT i = 0; i <g_dwNumMaterials; i++)
	{
		//マテリアル
		g_pD3DXMaterials[i] = pD3DXMaterials[i].MatD3D;

		if(pD3DXMaterials[i].pTextureFilename == NULL)
		{
			g_pMeshTexture[i] = NULL; //テクスチャ無し
		}
		else
		{
			//テクスチャ生成
			hr = D3DXCreateTextureFromFile(System_GetDevice(),pD3DXMaterials[i].pTextureFilename,&g_pMeshTexture[i]);

			//テクスチャ無し
			if(FAILED(hr))
			{
				MessageBox(*System_GethWnd(),"テクスチャの読み込みに失敗しました。","読み込み失敗",MB_OK);
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
//	描画
//-------------------------------------	
void XModel_Render()
{
	for(int i= 0; i< g_dwNumMaterials; i++)
	{
		System_GetDevice()->SetMaterial(&g_pD3DXMaterials[i]);	//マテリアル登録
		System_GetDevice()->SetTexture(0,g_pMeshTexture[i]);	//テクスチャ登録
		g_pD3DXMesh->DrawSubset(i);								//描画
	}
}

//-------------------------------------
//	初期化
//-------------------------------------
void XModel_Initialize()
{

}

//-------------------------------------
//	終了
//-------------------------------------
void XModel_Finalize() 
{

}

