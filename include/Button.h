#pragma once

#include "stdafx.h"
#include "config.h"


class Button
{
private:

	TTF_Font* font;
	SDL_Rect rect;
	SDL_Texture* rect_texture;
	SDL_Texture* texture;
	SDL_Renderer* renderer;

public:
	Button(const char* name, SDL_Renderer** renderer );
	~Button();

	void setPosition( Ushort position, Ushort total_rects, Ushort y );

	/**
	*	\Sets the current rectangle button to be visible
	*/
	void setFocus();


	/**
	*	\Sets the current rectangle button to be invisible
	*/
	void setBlind();


	/**
	*	\Sets the button text texture to be visible
	*/
	void Show();


	/**
	*	\Returns 1 if texture has been made succesfuly, else 0
	*/
	bool isGood();

	friend class Engine;
};

