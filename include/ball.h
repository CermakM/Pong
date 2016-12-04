#pragma once 

#include "gameobject.h"

class Ball : public GameObject
{
private:
	eDir init_dir;

	Ushort times_jumped;

public:
    Ball(const char* fname);
	~Ball();

	void Move();

	void Jump();

	void setStartParam( Ushort, Ushort );

};

