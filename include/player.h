#pragma once

#include "gameobject.h"

class Player : public GameObject
{
private:
	eDir init_dir;

public:
	Player(const char * fname);
	~Player();

	void Move();

	void Jump();

	void setStartParam( Ushort, Ushort );

};

