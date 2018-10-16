//
//	Component.h
//		Author:HIROMASA IKEDA	DATE:2018/09/26
//===============================================
//
//	����g������
//
//-----------------------------------------------
#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include<d3dx9.h>
#include<vector>

using namespace std;

//===============================================
//	Component �N���X
//===============================================
class Component 
{
private:
	
public:
	static vector<Component*> g_Index;	//�C���f�b�N�X

	static void g_Begin();				//����		�J�n

	static void g_Initialize();			//������	�J�n
	static void g_BeginUpdate();		//�O�X�V	�J�n
	static void g_Render();				//�`��		�J�n
	static void g_EndUpdate();			//��X�V	�J�n
	static void g_UnInitialize();		//�I������	�J�n

protected:
	virtual void Initialize()	PURE;	//������
	virtual void BeginUpdate()	PURE;	//�O�X�V
	virtual void EndUpdate()	PURE;	//��X�V
	virtual void Render()		PURE;	//�`��
	virtual void UnInitialize() PURE;	//�I��
};

#endif // !COMPONENT_H

