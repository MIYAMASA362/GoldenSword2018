#ifndef BULLET_H
#define BULLET_H

#include "Collision.h"
#include "d3dx9.h"

enum Bullet_Type
{
	kNORMAL,
	kMAX
};

typedef struct
{
	D3DXVECTOR3 pos;
	float r;
}Ball;

void Bullet_Init(void);
void Bullet_Draw(void);
void Bullet_Update(void);
void Bullet_Create(D3DXVECTOR3 pos,D3DXVECTOR3 face, Bullet_Type type);
void Bullet_Destroy(int index);
bool Bullet_IsEnable(int index);
const Ball * Bullet_Getcollosion(int index);

#endif // !BULLET_H
