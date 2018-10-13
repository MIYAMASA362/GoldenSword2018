//
//	MtxTransform.h
//		Author:HIROMASA IKEDA	DATE:2018/09/28
//===============================================
#pragma once
#ifndef MTXTRANSFORM_H
#define MTXTRANSFORM_H

#include<d3dx9.h>

//===============================================
//	�N���X�@
//===============================================

//-----------------------------------------------
//	�s��N���X
//-----------------------------------------------
class MtxFormat
{
private:
	
public:
	D3DXMATRIX MtxWorld;					//���[���h�ϊ��s��
	D3DXMATRIX MtxTransform;				//�ʒu
	D3DXMATRIX MtxRotation;					//��]
	MtxFormat(void);						//������
	void SetIdentity(void);					//�S���P�ʉ�
	void SetIdentity(D3DXMATRIX* ReSetMtx);	//�w��P�ʉ�
	void SetMatrix(void);					//�f�o�C�X�֓o�^
};

//===============================================
//	�֐�
//===============================================

void MtxTransformation_Initialize();
void MtxTransformation_Update();
void MtxTransformation_Render();
void MtxTransformation_Finalize();

#endif // !MATRIXTRANSFORM_H