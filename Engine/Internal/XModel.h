//
//	XModel.h
//		Author:HIROMASA IKEDA	DATE:2018/10/19
//===============================================
//	�ύX�� Changed By
//		Name:Minoda Takamasa	DATE:2018/10/23
//
//-----------------------------------------------

#pragma once
#ifndef IKEDA_TEMPSOURCE_H
#define IKEDA_TEMPSOURCE_H

//================================================
//	�C���N���[�h	include
//================================================
#include"common.h"
#include<d3dx9.h>

//================================================
//	�}�N����`	define
//================================================
#define MODEL_FILENAME_MAX (64)

//================================================
//	�񋓌^		enum
//================================================
enum MeshIndex
{
	BulletIndex=0,
	ScrewIndex
};

//================================================
//	�\����		struct/typedef
//================================================
typedef struct MeshTag
{
	LPD3DXMESH pMesh;
	D3DMATERIAL9* pMeshMaterials;
	LPDIRECT3DTEXTURE9* pMeshTextures;
	DWORD dwNumMaterials;

	D3DXVECTOR3 vecPosition;
	D3DXMATRIXA16 matWorld;

}MeshData;

//================================================
//	�O���[�o���ϐ��@global
//================================================


//================================================
//	�֐�		function
//================================================
void XModel_Initialize();	//������
void XModel_Finalize();		//�I��

void XModel_Load(MeshData *pMesh, LPSTR szXFileName, D3DXVECTOR3* pvecPosition);		//���f���ǂݍ���
void XModel_Render(MeshData *pMesh);	//�`��
void XModel_Render(MeshData *pMesh, D3DXMATRIXA16 mtx);
MeshData* GetMeshData(int MeshIndex);  //���b�V���f�[�^�̎擾


#endif