//
//	Screwdrop.h
//		Author:�n��	DATE:2018/10/23
//===============================================
//	�ύX�� Changed By
//		Name:	DATE:
//
//-----------------------------------------------

#pragma once
#ifndef SCREW_DROP_H
#define SCREW_DROP_H

//================================================
//	�C���N���[�h	include
//================================================
#include"common.h"
#include"XModel.h"
#include"Bullet.h"
#include <d3dx9.h>
#include<math.h>
#include "common.h"
#include "System.h"
#include "XModel.h"

#include"Cube.h"

//================================================
//	�}�N����`	define
//================================================


//================================================
//	�񋓌^		enum
//================================================


//================================================
//	�\����		struct/typedef
//================================================

//-------------------------------------
//	Screwdrop
//-------------------------------------
typedef struct
{
	bool IsEnable;							//�L���E����
	D3DXVECTOR3 BulletPosition;				//�e�̃|�W�V����
	D3DXVECTOR3 ScrewPosition;				//�l�W�̃|�W�V����
	BULLET_TYPE bullet_type;				//�e�̃^�C�v
//	SCREW_TYPE	screw_type;					//�l�W�̃^�C�v
	MeshData BulletMesh;					//�e�̃��b�V���f�[�^
	MeshData ScrewMesh;						//�l�W�̃��b�V���f�[�^
	D3DXVECTOR3 face;						//����
	int rotation_count;						//��]�̃t���[�����Ɗp�x
}Screwdrop;
//================================================
//	�O���[�o���ϐ��@global
//================================================


//================================================
//	�֐�		function
//================================================
void Screwdrop_Render(void);
void Screwdrop_Update(void);
void Screwdrop_Init(void);
void Screwdrop_Create(D3DXVECTOR3 pos_bullet, D3DXVECTOR3 pos_screw, BULLET_TYPE type, D3DXVECTOR3 face);
void Screwdrop_DisEnable(int index);

#endif