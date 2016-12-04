#pragma once

#include "stdafx.h"
#include "config.h"

enum eDir { STOP, URIGHT = 1, DLEFT = -1, DRIGHT = -2, ULEFT = 2,  UP = 3, DOWN = -3,
	LEFT = 4, RIGHT = -4, JUMP
};

enum eVis { INVISIBLE, VISIBLE };

class GameObject
{
	bool is_visible;

	SDL_Surface* image;

protected: 
	int origin_x, origin_y;

	bool jump_is_active;

	eDir current_dir;
	Ushort velocity;

	SDL_Rect rect;
	
public:
	
	GameObject(const char * fname);
	virtual ~GameObject(); 

	/**
	*	\Sets the starting parametres for each derived class
	*/
	virtual void setStartParam(Ushort, Ushort);

	virtual void Move();

	virtual void Jump();


	/**
	*	\Returns 1 on collision, else 0
	*/
	bool HasCollision( SDL_Rect* );

	friend class Engine;
};

